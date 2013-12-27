/*
  SimplePost.ino - Aruino2Weibo:Remote control your Arduino via weibo.
  Copyright (c) naozhendang.com 2011-2012. 
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 
  More information can be found at:  http://arduino2weibo.sinaapp.com
  
  ******Simple Post****** 
  Post a new status
  
  Circuit:
  * Ethernet shield attached
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

// Message to post
// Chinese Character Tool: http://arduino2weibo.sinaapp.com/encode.php
char msg[] = "Hello Weibo, I'm Arduino!";

void setup()
{
  delay(1000);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  
  Serial.println("Connecting ...");
  if (weibo.post(msg)) {
    //Read return json data
     char* json = weibo.return_data(); 
     
     if(json){
        //Error check
        char* error = weibo.value_pointer("error",json);
        
        if(!error){
            //If it succeeds, we could find the post id
            char* id = weibo.value_pointer("id",json);           
            if(id){
              Serial.println("Done");
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
       Serial.println("No return data from Weibo API");
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

void loop()
{
}