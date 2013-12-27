/*
	URMSerial.cpp - URM 37 Control Library Version 2.0.0
	Author: Miles Burton, miles@mnetcs.com
	Copyright (c) 2009 Miles Burton All Rights Reserved

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


	Ultrasound Sensor
	------------------
	* URM V3.2 ultrasonic sensor TTL connection with Arduino
	* Reads values (0-300) from an ultrasound sensor (3m sensor)
	* and writes the values to the serial->port.
	* Pin12 (Arduino). Pin 1 VCC (URM V3.2)
	* GND (Arduino) . Pin 2 GND (URM V3.2)
	* Pin11 (Arduino) . Pin 7 (URM V3.2)
	* Pin 0 (Arduino) . Pin 9 (URM V3.2)
	* Pin 1 (Arduino) . Pin 8 (URM V3.2)
	* www.yerobot.com
	* Last modified 20/04/2009
	*
	* URM37 Library by Miles Burton 2009.
	* Original code from Yerobot/DFRobot (thanks guys!)

	
	Commands
	
	0x11 + NC + NC + SUM = Temperature = 0x11 + HIGH + LOW + SUM
	0x22 + DEGREE + NC+ SUM = Distance, Degree = Servo angle = 0x22 + HIGH  + low + sum
	0x33 + ADD + NC + SUM = Read from EEPROM = 0x33+Add+Data+Summ
	0x44 + Add + DATA + SUM = Write to EEPROM = 0x44+Add+Data+Sum
	
*/

#include "URMSerial.h"
#include <HardwareSerial.h>

URMSerial::URMSerial(void)
{
}

// See whether the serial port has sufficient data for a 'reading'
bool URMSerial::hasReading(void)
{
	// We require at least 3 bytes before it can be considered a valid reading
	return (serial->available()>3);
}

// Read in serial data (max four bytes)
void URMSerial::readSerial(void)
{
    for(int i=0;i<4;i++) serialData[i] = serial->read();
}

// Recieve distance from URM device
byte URMSerial::getMeasurement(int& value)
{
  if(!hasReading()) return NOTREADY;
  
  if(reqTimeout()) return TIMEOUT;
  

	// Read in data
	readSerial();

    // Validate the reading type
    switch(serialData[Header]) // Three types of command responses. 0x11 is a temperature, 0x22 Distance, 0x33 EEPROM
    {
     case COMMAND_DISTANCE:
        return processDistance(value);

     break;
     case COMMAND_TEMP:
        return processTemperature(value);
     break;
    }

    // Strange return result!
	distanceRequested = temperatureRequested = false; // This is a bug fix. If an error was returned (conrrupt byte array), reset distance measurements so we can re-request
    value = 0;
    return ERROR;
}

void URMSerial::forceReset(void)
{
	distanceRequested = temperatureRequested = false; // This is a bug fix. If an error was returned (conrrupt byte array), reset distance measurements so we can re-request
}


// Process the 4 byte serial data and see whether the device reported an error (happens occationally)
bool URMSerial::hasError()
{
    return((serialData[HighByte] & serialData[LowByte])==255); // If the High and Low byte are both 255: error
}

byte URMSerial::processDistance(int& value)
{
    distanceRequested = false;

	// If the serial data returned an error, quit
	if(hasError()) return ERROR;

	


    // 1x16bit value wrapped over two bytes
    // HighByte must be multiplied by 255 to represent the correct byte
    // Both are added together to calculate the value in Centimeters (I believe)
    value = serialData[HighByte]*255+serialData[LowByte];

	return DISTANCE;
}

byte URMSerial::processTemperature(int& value)
{
    temperatureRequested = false;

	// If the serial data returned an error, quit
	if(hasError()) return ERROR;

    // If 0, the value is the same regardless
    if(serialData[LowByte]==0)
    {
        value = 0;
    }else{

		// Below 0
		if(serialData[HighByte]==0x255)
		{
			value = -serialData[LowByte];
		}else{ // above zero
			value = serialData[LowByte]; // Consider below zero 1111
		}
	}

	return TEMPERATURE;
    //value = value >> 1; // Note: Bad practise, decimal value truncated
}

// Has the current request timed out?
bool URMSerial::reqTimeout()
{
    if(temperatureRequested || distanceRequested)
    {
        int tDelta = millis() - timeRequested;
        // If we've waited to long
        if(tDelta>timeout || tDelta < 0) // If the delta is greater than our timeout or if it has wrapped around
        {
			
            return true;
        }else{
		
            return false;
        }
    }else{
	
        // No pending requests
        return true; // Return true anyway
    }
}

// send the temperature request to the serial port [*note, no delay]
bool URMSerial::requestMeasurement(byte mType)
{
    if(!reqTimeout()) return false;

    timeRequested = millis(); // store request time

	byte ttlCOMMAND[3] = {0,0,0};
    // Select appropriate memory addresses
    switch(mType)
    {
         case TEMPERATURE:
			ttlCOMMAND[Header] = COMMAND_TEMP;
            sendCommand(ttlCOMMAND);
            temperatureRequested = true;
            return true;
         break;
         case DISTANCE:
			ttlCOMMAND[Header] = COMMAND_DISTANCE;
			ttlCOMMAND[HighByte] = servoAngle;
			
            sendCommand(ttlCOMMAND);
            distanceRequested = true;
            return true;
         break;
         default:
         // Do nothing
            return false;
         break;
    }
}

byte URMSerial::requestMeasurementOrTimeout(byte mType, int& value)
{
    // Request measurement or fail
    if(!requestMeasurement(mType))
    {
        return NOTREADY;
    }

    // Wait until we either timeout or we have a reading
    while(!reqTimeout() && !hasReading())
    {
        delay(10); // Wait a bit
    }

    // Request has timed out, FAIL
    if(reqTimeout()) return TIMEOUT;

    // Pass control to getMeasurement which will return the requested measurement
    return getMeasurement(value);

}

void URMSerial::sendCommand(byte* pCommand)
{
	byte sum = 0;
    // Send command
    for(int i=0;i<3;i++)
	{
		serial->print(pCommand[i],BYTE);
		sum += pCommand[i];
	}
	serial->print(sum,BYTE);
	
	
}


// Setup our serial-> connection
void URMSerial::begin(uint8_t rxPin, uint8_t txPin, long baud)
{
    // Initalise measurements
	distanceRequested = false;
	temperatureRequested = false;
	
	servoAngle = 23; // 90*
	servoMin = 0;
	servoMax = 30;
	
	timeout = 200;

    // Initalise serial data
    for(int i=0; i<4;i++) serialData[i]=0;

    // Initalise the software serial to handle our serial communication
    // Please note: using software serial over hardware-serial has some potential issues.
	serial = new NewSoftSerial(rxPin, txPin);
	serial->begin(baud);
}


void URMSerial::setServo(byte angle)
{
	
	angle = map(angle, 0, 270, 0, 46); // Map decimal to URM37
	angle = constrain(angle, servoMin, servoMax);

	servoAngle = angle;
}

void URMSerial::setServoMax(byte val)
{
	servoMax = (byte)map(val, 0, 270, 0, 46);
}

void URMSerial::setServoMin(byte val)
{
	servoMin = (byte)map(val, 0, 270, 0, 46);
}

void URMSerial::setTimeout(byte val)
{
	timeout = val;
}

// Send a request to the URM37
bool URMSerial::write(byte command, byte data)
{
 
	// WARNING. VERY DANGEROUS. You can set the wrong mode
	byte ttlCOMMAND[3] = {COMMAND_EEPROMWRITE,command,data};
	sendCommand(ttlCOMMAND);
	// Response should be immediate
	while(!hasReading());
	readSerial();
	
	// Return whether the command was echoed
	return  ttlCOMMAND[0] == serialData[0] 
		&&	ttlCOMMAND[1] == serialData[1] 
		&&	ttlCOMMAND[2] == serialData[2];
}

// Read data from EEPROM
byte URMSerial::read(byte command)
{
	byte ttlCOMMAND[3] = {COMMAND_EEPROMREAD,command,0};
	sendCommand(ttlCOMMAND);
	// Response should be immediate
	while(!hasReading());
	readSerial();

	// Return result
	return ttlCOMMAND[LowByte];
}

// Set the threshold at which the sensor will pull low
bool URMSerial::setSensorThresholdMin(byte val)
{
	return write(0x00, val); 
}

// Set the threshold at which the sensor will pull low
bool URMSerial::setSensorThresholdMax(byte val)
{
	return write(0x01, val);
}

// Fetch the threshold value
byte URMSerial::getSensorThresholdMin()
{
	return read(0x00);
}

// Fetch the threshold value
byte URMSerial::getSensorThresholdMax()
{
	return read(0x01);
}

// Enable the user to set which mode the URL37 operates in. MODE_SERIAL is default (and recommended)
bool URMSerial::setMode(byte mode)
{
	// Make sure we catch the right more
	if(mode==MODE_SERIAL || mode==MODE_AUTO) 
	{
		return write(0x02, mode);
	}else{
		return false;
	}
}