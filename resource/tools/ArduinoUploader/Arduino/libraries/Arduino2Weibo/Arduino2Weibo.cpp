/*
  Arduino2Weibo.cpp - Aruino2Weibo:Remote control your Arduino via weibo.
  Copyright (c) naozhendang.com 2011-2012. 
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 
  More information can be found at:  http://arduino2weibo.sinaapp.com
*/

// ver0.3 - Control arduino via Weibo
// ver0.2 - Support IDE 1.0


#include <string.h>
#include <inttypes.h>
#include <avr/pgmspace.h>	//Use PROGMEM to save memory
#include "Arduino2Weibo.h"

#define DEBUG
#define LIB_DOMAIN "arduino2weibo.sinaapp.com"

//Define PROGMEM strings in flash
const prog_char PROGMEM DNS_FAILED[] = "DNS failed\n";
const prog_char PROGMEM CONNECTED[] = "Connected\n";
const prog_char PROGMEM MEMORY_OVERFLOW[] = "Out of memory\n"; 
const prog_char PROGMEM DISCONNECTED[] = "Disconnected\n";
const prog_char PROGMEM TARGET_IP[] = "Target IP address is\n";  

#if defined(ARDUINO) && ARDUINO < 100
static uint8_t server[] = {0,0,0,0}; // IP address of LIB_DOMAIN
Weibo::Weibo(const char *username, const char *password) : client(server, 80), username(username), password(password) 
{
}
#else
Weibo::Weibo(const char *username, const char *password) : username(username), password(password) 
{
}
#endif

//Post new weibo
bool Weibo::post(const char *msg)
{
#if defined(ARDUINO) && ARDUINO < 100
	DNSError err = EthernetDNS.resolveHostName(LIB_DOMAIN, server);
	if (err = DNSSuccess){
		#if defined(DEBUG)
			printProgStr(TARGET_IP);
    		Serial.print(server[0],DEC);
    		Serial.print('.');
			Serial.print(server[1],DEC);
    		Serial.print('.');
    		Serial.print(server[2],DEC);
    		Serial.print('.');
    		Serial.print(server[3],DEC);
    		Serial.println();
		#endif 
	} else {
		return false;
		#if defined(DEBUG)
		printProgStr(DNS_FAILED); //DNS failed
		#endif
	}
#endif

#if defined(ARDUINO) && ARDUINO < 100
	if (client.connect()) {
#else
	if (client.connect(LIB_DOMAIN, 80)) {
#endif
		#if defined(DEBUG)
		printProgStr(CONNECTED);
		#endif
		client.println("POST http://" LIB_DOMAIN "/update.php HTTP/1.0");
		client.println("Host: " LIB_DOMAIN);
		client.println("Connection: Close");
		client.println("Content-Type: application/x-www-form-urlencoded");
		client.print("Content-Length: ");
		client.println(strlen(username)+strlen(password)+strlen(msg)+27);
		client.println();
		client.print("username=");
		client.print(username);
		client.print("&password=");
		client.print(password);
		client.print("&status=");
		client.println(msg);
	} else {
		return false;
	}
	return true;            
}


//Repost
bool Weibo::repost(const char *id,const char *msg)
{
#if defined(ARDUINO) && ARDUINO < 100
	DNSError err = EthernetDNS.resolveHostName(LIB_DOMAIN, server);
	if (err = DNSSuccess){
		#if defined(DEBUG)
			printProgStr(TARGET_IP);
    		Serial.print(server[0],DEC);
    		Serial.print('.');
			Serial.print(server[1],DEC);
    		Serial.print('.');
    		Serial.print(server[2],DEC);
    		Serial.print('.');
    		Serial.print(server[3],DEC);
    		Serial.println();
		#endif 
	} else {
		return false;
		#if defined(DEBUG)
		printProgStr(DNS_FAILED); //DNS failed
		#endif
	}
#endif

#if defined(ARDUINO) && ARDUINO < 100
	if (client.connect()) {
#else
	if (client.connect(LIB_DOMAIN, 80)) {
#endif
		#if defined(DEBUG)
		printProgStr(CONNECTED);
		#endif
		client.println("POST http://" LIB_DOMAIN "/repost.php HTTP/1.0");
		client.println("Host: " LIB_DOMAIN);
		client.println("Connection: Close");
		client.println("Content-Type: application/x-www-form-urlencoded");
		client.print("Content-Length: ");
		client.println(strlen(username)+strlen(password)+strlen(id)+strlen(msg)+31);
		client.println();
		client.print("username=");
		client.print(username);
		client.print("&password=");
		client.print(password);
		client.print("&id=");
		client.print(id);
		client.print("&status=");
		client.println(msg);
	} else {
		return false;
	}
	return true;            
}

//Mentions
bool Weibo::atme(const char *sid)
{
#if defined(ARDUINO) && ARDUINO < 100
	DNSError err = EthernetDNS.resolveHostName(LIB_DOMAIN, server);
	if (err = DNSSuccess){
		#if defined(DEBUG)
			printProgStr(TARGET_IP);
    		Serial.print(server[0],DEC);
    		Serial.print('.');
			Serial.print(server[1],DEC);
    		Serial.print('.');
    		Serial.print(server[2],DEC);
    		Serial.print('.');
    		Serial.print(server[3],DEC);
    		Serial.println();
		#endif 
	} else {
		return false;
		#if defined(DEBUG)
		printProgStr(DNS_FAILED); //DNS failed
		#endif
	}
#endif

#if defined(ARDUINO) && ARDUINO < 100
	if (client.connect()) {
#else
	if (client.connect(LIB_DOMAIN, 80)) {
#endif
		#if defined(DEBUG)
		printProgStr(CONNECTED);
		#endif
		client.print("GET /atme.php?username=");
		client.print(username);
		client.print("&password=");
		client.print(password);
		if(sid){
		  client.print("&since_id=");
		  client.print(sid);
		}
		client.print(" HTTP/1.0");
		client.println();
		client.println("Host: " LIB_DOMAIN);
		client.println();
	} else {
		return false;
	}
	return true;  
}


// This will wait for some input, then read it to make sure it is an open	
// brace "{" (discarding it if not) and reading all of the input up to a
// corresponding close brace "}".Nested sets of braces are allowed.
// Returns a pointer to whatever it's read.
// modified from http://gitorious.org/arduino-json-client/
char* Weibo::return_data()
{
	char* result = NULL;
	while (client.connected()){
	   	if(client.available()){
			char c = client.read();

			while (c != '{')	
  			{	
    			// Uh oh, this isn't JSON
				// Discard it and try again...
				c = client.read();
				
				//If there's no return data
				if(c < 0){
					client.flush();
					client.stop();
					#if defined(DEBUG)
					printProgStr(DISCONNECTED);	
					#endif
					return 0;
				}
  			}	
					
			int nested_count = 1; // Keep track of how deeply nested our braces are
			int pointer_size = 2; // The size of our char pointer (must be >= 2, for '{' and '}')	
  			int read_so_far = 1;     // How much data we've read (used to ensure our pointer is big enough)	
  			result = (char*) malloc(sizeof(char)*pointer_size);    // This pointer will be our return value		
			char* new_result = NULL;    // Used during pointer reallocation	
  			result[0] = c;    // Set the first value to the '{' that we found
 			
			// There are a few exceptions to the simple braced structure...
			short in_quote = 0;    // "strings"	
  			short in_escape = 0;   // \escaped characters
			
			// Loop until we've closed that first brace
			while (nested_count > 0)    			
			{
				// Wait for input then read it
				c = client.read();
				//Serial.print(c);
				// See if we've got enough room to store it
				read_so_far++;
				
				if (read_so_far > pointer_size)
				{
					// Try to increase the size of our JSON pointer
					// NOTE: There are various strategies we could use here
					// depending on what we want to conserve. Since we only
					// build one JSON string at a time, and free it after
					// we're done with it, we don't need to be massively
					// conservative in our memory usage
					char* new_result = (char*) realloc(result, (pointer_size*2));
					if (new_result)
					{	
						// We succeeded in allocating enough memory. Let's use it.
						result = new_result;
						pointer_size = pointer_size * 2;
					} else {
        					// Out of memory. Abort.
        					free(result);
						result = NULL;
						#if defined(DEBUG)
						printProgStr(MEMORY_OVERFLOW);
						#endif
						return 0;
					}
				}
				
				// Store this character
				result[read_so_far-1] = c;
	
    				// Handle this character
				if (in_quote) {
					// String semantics: read in everything up to a non-escaped '"'
					if (in_escape) {
						// Apply escaping; ie. ignore the character, just unset in_escape
						in_escape = 0;
					} else {
						if (c == '"') {	
          						in_quote = 0;    // Our matching close quote	
       						 }	
        					if (c == '\\') {	
          						in_escape = 1;   // Ignore whatever the next character is	
       						 }	
      					}	
    				} else {	
      					// Object semantics: Read in everything up to a non-matched '}'
      	
      					if (c == '{') {	
       						 nested_count++;    // Recurse down a level	
     					 } else {	
       						 if (c == '}') {	
         						 nested_count--;  // Come back up a level	
       						 } else {	
         						 if (c == '"') {	
            							in_quote = 1;  // Start a string	
          						} else {	
            							// Some other character	
          						}	
        					}	
      					}	
    				}	
			}
			result[read_so_far] = '\0'; //Null terminate		
		}		
	}
	client.flush();
	client.stop();
	#if defined(DEBUG)
	printProgStr(DISCONNECTED);	
	#endif
	return result;
}

// Give this a pointer to some JSON data and it will
// return the length of that JSON.	
int Weibo::json_length(char* json) {
	if (json == 0) {
		return 0;    // Null pointer
	}
  
	if (json[0] != '{') {
		return 0;    // Not JSON	
	}
	// Now that we know we have a JSON object, we defer
	// the actual calculation to value_length
	return value_length(json);
}

// This is given a fragment of JSON and returns how
// many characters it contains. This fragment might
// be an object, a number, a string , etc.
int Weibo::value_length(char* json) {
  if (json == 0) {
    return 0;    // Null pointer
  }
  
  // Switch over each possibility
  int index = 0;
  switch (json[index]) {
    case '{':
        // This is a JSON object. Find the matching '}'
        do {
          index++;    // Read ahead
          if (json[index] == '"') {
            // Skip strings, as they may contain unwanted '}'
            index = index + value_length(json+index);
          }
          if (json[index] == '{') {
            // Recurse past nested objects
            index = index + value_length(json+index);
          }
        } while (json[index] != '}');
        return index + 1;    // Include the '{' and '}' in the length
    case '"':
      // This is a string. Scan ahead to the first unescaped '"'
      do {
        if (json[index] == '\\') {
          index++; // Skip escaped quotes
        }
        index++;    // Read ahead
      } while (json[index] != '"');
      return index+1;    // Include the quotes in the string's length
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '-':
      // We're a number. Loop forever until we find a non-number character.
      // Note, this is a simplistic parser that is equivalent to the regex	
      // [0123456789-][0123456789.eE]* This allows malformed numbers like
      // 0.0.0.0e0.0e.0
      do {
        index++;
        switch (json[index]) {
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
          case '.':
          case 'e':
          case 'E':
            break;    // Numeric
          default:
            return index;    // Non-numeric. Stop counting.
        }
      } while (1);
    default:
      // Unknown. Ignore it.
      return 0;
  }
}

// Takes a JSON string and looks for any commands it
// contains. These are "key":value pairs, which are
// sent as arguments to the "command" function as
// they are encountered.
char* Weibo::value_pointer(char* key, char* json) {
  int length = json_length(json);
  int index = 0;    // Used to loop through the contents
  int temp;    // Our parsing uses lookahead, this stores how far we've gone
  char* value = 0;
  
  // Only bother doing something if json has some contents.
  // When this condition is false, it's essentially the
  // escape clause of our recursion.
  if (length > 2) {    // 2 == empty, since we have '{' and '}'
    index++;    // Skip past the '{' to get at the contents
    while (index < length) {
      switch (json[index]) {
        case ' ':
          // Whitespace is insignificant
          index++;
          break;
        case '{':
          // We have an object in an object, let's recurse
          value_pointer(key, json+index);
          index = index + json_length(json+index);
          break;
        case '"':
          // A string. This should be part of a key:value pair
          if (index + 2 >= length) {
            // JSON can't end with an opening quote. Bail out.
            break;
          }

          // Look one character ahead, then keep going until
          // we find our matching close quote
          temp = index+1;
          while ((json[temp] != '"') && (temp < length)) {
            // We've not found our close quote, so look ahead
            if (json[temp] == '\\') {
              // Increment twice to skip over escaped characters
              temp++;
            }
            temp++;
          }
          if (temp >= length-2) {
            // We've reached the end of the JSON without finding
            // a close quote. Bail out.
            break;
          }   
          // Now we've read our name, find our associated value
          temp++;    // It must start after the close quote
          while ((json[temp] == ' ') && (temp < length)) {
            temp++;    // Skip whitespace
          }
          if (json[temp] != ':') {
            // We must have a colon between the name and the value
            // Bail out if not
            break;
          }
          temp++;    // We don't need the colon, skip it
          while ((json[temp] == ' ') && (temp < length)) {
            temp++;    // Skip whitespace
          }
          
          // Wherever we are, we must have found our value
          // Tell run_command what we've found
          //run_command(json+index, json+temp);
		  if (compare_strings(json+index,key)) {
				value = json+temp;    // Read pin values
		  }
		  
          
          // Now let's get our parser ready for the next value
          index = temp + value_length(json+temp);    // Skip the value
          while ((json[index] == ' ') && (index < length)) {
            index++;    // Skip whitespace
          }
          if (json[index] == ',') {
            // Skip commas between name:value pairs
            index++;
          }
          break;    // Done
        default:
          // Unknown input. Oops.
          index++;
      }
    }
  }
  return value;
}

// Compare the first character array, which is not
// null-terminated and is in quotes, to the second
// which can be null-terminated and without quotes
short Weibo::compare_strings(char* string1, char* string2) {
  int first_size = value_length(string1);
  int second_size;
  for (second_size = 0; string2[second_size] != '\0'; second_size++) {
    // Do nothing. The loop parameters count the string for us.
  }
  
	  // if first_size includes quotes, we don't include them
	  // in our check
	  if (first_size - 2 != second_size) {
		// The size is different, so the strings are different
		return 0;
	  }
	  
	  // Now do a lexicographical comparison
	  int index;
	  for (index = 0; index < first_size - 2; index++) {
		if (string1[index+1] != string2[index]) {
		  return 0;    // Mismatch
		}
	  }

    
  // If we're here then our tests couldn't find any different
  return 1;	
}


// Compare the first number array, which is not
// null-terminated, to the second which can be
// null-terminated and without quotes
short Weibo::compare_ids(char* string1, char* string2) {
  int first_size = value_length(string1);
  int second_size;
  for (second_size = 0; string2[second_size] != '\0'; second_size++) {
    // Do nothing. The loop parameters count the string for us.
  }
  
	if (first_size!= second_size) {
		// The size is different, so the strings are different
		return 0;
	}
	  
	// Now do a lexicographical comparison
	int index;
	for (index = 0; index < first_size ; index++) {
		if (string1[index] != string2[index]) {
			return 0;    // Mismatch
		}
	}
    
  // If we're here then our tests couldn't find any different
  return 1;	
}

//Locate substring
//Returns a pointer to the first occurrence of str2 in str1, 
//or a null pointer if str2 is not part of str1.
//The matching process does not include the terminating null-characters.
char* Weibo::find_substring(char* string1, char* string2){
  int second_size;
  for (second_size = 0; string2[second_size] != '\0'; second_size++) {
    // Do nothing. The loop parameters count the string for us.
  }
	
  if (!second_size){
	return (char *)string1;
  }

  int first_size = value_length(string1);
  while (first_size >= second_size){
	first_size--;
	if (!memcmp(string1, string2, second_size))
            return (char *)string1;
        string1++;
  }
  return NULL;
}


// given a PROGMEM string, use Serial.print() to send it out
// this is needed to save precious memory
// http://todbot.com/blog/category/programming/
void Weibo::printProgStr(const prog_char* str) {
  char c;
  if (!str) {
    return;
  }
  while ((c = pgm_read_byte(str))) {
	#if defined(ARDUINO) && ARDUINO < 100
	Serial.print(c, BYTE);
	#else
	Serial.write(c);
	#endif
    str++;
  }
}
