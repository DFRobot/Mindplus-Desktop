/*
  Arduino2Weibo.h - Aruino2Weibo:Remote control your Arduino via weibo.
  Copyright (c) naozhendang.com 2011-2012. 
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 
  More information can be found at:  http://arduino2weibo.sinaapp.com
*/

// ver0.3 - Control arduino via Weibo
// ver0.2 - Support IDE 1.0

#ifndef ARDUINO2WEIBO_H
#define ARDUINO2WEIBO_H

#include <inttypes.h>
#include <avr/pgmspace.h>
#if defined(ARDUINO) && ARDUINO > 18   // Arduino 0019 or later
#include <SPI.h>
#endif
#include <Ethernet.h>
#if defined(ARDUINO) && ARDUINO < 100  // Earlier than Arduino 1.0
#include <EthernetDNS.h>
#endif

class Weibo
{
private:
	const char *username;
	const char *password;
#if defined(ARDUINO) && ARDUINO < 100
	Client client;
#else
	EthernetClient client;
#endif
	
public:
	Weibo(const char *username, const char *password);
	
	//Http requests
	bool post(const char *msg);
	bool repost(const char *id, const char *msg = NULL);
	bool atme(const char *sid = NULL);
	
	//Data parsers
	char* return_data(); 
	int json_length(char* json);
	int value_length(char* json);
	char* value_pointer(char* key, char* json);
	short compare_strings(char* string1, char* string2);
	short compare_ids(char* string1, char* string2);
	char* find_substring(char* string1, char* string2);

	//Other tools 
    void printProgStr(const prog_char* str);
};

#endif	//ARDUINO2WEIBO_H
