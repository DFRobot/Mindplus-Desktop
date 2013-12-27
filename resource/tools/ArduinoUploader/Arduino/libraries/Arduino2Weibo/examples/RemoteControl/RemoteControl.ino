/*
  RemoteControl.ino - Aruino2Weibo:Remote control your Arduino via weibo.
  Copyright (c) naozhendang.com 2011-2012. 
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 
  More information can be found at:  http://arduino2weibo.sinaapp.com
  
  ******Remote Control****** 
  Light/Dim an LED according to weibo commands
  
  Circuit:
  * Ethernet shield attached
  * an LED on pin 9
*/


#if defined(ARDUINO) && ARDUINO > 18   // Arduino 0019 or later
#include <SPI.h>
#endif
#include <Ethernet.h>
//#include <EthernetDNS.h>  //Only needed in Arduino 0023 or earlier
#include <Arduino2Weibo.h>

// Ethernet Shield Settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Substitute an address on your own network here
byte ip[] = { 192, 168, 1, 106 };

// Weibo Account for your Arduino
Weibo weibo("YOUR-USERNAME-HERE","YOUR-PASSWORD-HERE");

// Messages
// Chinese Character Tool: http://arduino2weibo.sinaapp.com/encode.php 
char msg_on[] = "Roger:ON";
char msg_off[] = "Roger:OFF";
char msg_unknown[] = "Unknown Command";

//Anchor ID
char sid[20];

void setup()
{
  delay(1000);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  
  //Ethernet Shield will use digital pin 13,12,11,10,2 and analog pin 0, 1
  //Let's use pin 9
  pinMode(9, OUTPUT);
}

void loop()
{  
  checkMen();
  delay(60000);
}

void checkMen(){
   
  Serial.println("Connecting ...");

  if (weibo.atme(sid)) {
  
     //Read the JSON data
     char* json = weibo.return_data();  
     
     if(json){
        //Error check
        char* error = weibo.value_pointer("error",json);
        
        if(!error){
            //Locate different values
            char* id = weibo.value_pointer("id",json);
            char* text = weibo.value_pointer("text",json);
            char* uid = weibo.value_pointer("uid",json);
            char* user = weibo.value_pointer("user",json);
			
			//Store the id as an anchor
			int count = weibo.value_length(id);
			memcpy(sid,id,count);
			sid[count] ='\0';
            
            //Match the uid 
			//How to find the uid: http://arduino2weibo.sinaapp.com/uid.php
            if(weibo.compare_ids(uid,"COMMAND-UID")){ //Enter the UID sends commands.
			    
				//Match commands
				// Chinese Character Tool: http://arduino2weibo.sinaapp.com/encode.php
				if(weibo.find_substring(text,"ON")){
					//You can replace it with your own command
					digitalWrite(9, HIGH);
					
					//Free(json) before echo 
					//Since we used malloc() in return_data()
					free(json);
					json = 0;
					
					echo(id,msg_on);
					Serial.println(msg_on);
				} else if (weibo.find_substring(text,"OFF")){
					//You can replace it with your own command
					digitalWrite(9, LOW);
					
					//Free(json) before echo 
					//Since we used malloc() in return_data()
					free(json);
					json = 0;
					
					echo(id,msg_off);
					Serial.println(msg_off);
				} else {
					//Unknown command
					//Free(json) before echo 
					//Since we used malloc() in return_data()
					free(json);
					json = 0;
					
					echo(id,msg_unknown);
					Serial.println(msg_unknown);
				}
            }
        } else {
            //Print out the error
            for(int i= 0; i < weibo.value_length(error); i++){
              Serial.print(error[i]);
            }
            Serial.println();
        }
     } else {
       Serial.println("No new @ for me");
     };
	 
	 //*******Important***********
     //Since we used malloc() in return_data()
     //We need to free() the memory
     free(json);
     json = 0;
  
  } else {
    Serial.println("Connection failed.");
  } 

}

void echo(const char *id, const char *msg){

  Serial.println("Echoing ...");
  
  if (weibo.repost(id,msg)) {
    //Read return json data
     char* json = weibo.return_data(); 
     
     if(json){
        //Error check
        char* error = weibo.value_pointer("error",json);
        
        if(!error){
            //If it succeeds, we could find the post id
            char* id = weibo.value_pointer("id",json);           
            if(id){
              Serial.println("Echo done");
            } else {
              Serial.println("Unknown error");
            }
        } else {
            //Print out the error
            for(int i= 0; i < weibo.value_length(error); i++){
              Serial.print(error[i]);
            }
            Serial.println();
        }
     } else {
       Serial.println("No return from Weibo API");
     };

     //*******Important***********
     //Since we used malloc() in return_data()
     //We need to free() the memory
     free(json);
     json = 0;
        
  } else {
    Serial.println("Echo failed");
  }

}