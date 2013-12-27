#ifndef URMSerial_h
#define URMSerial_h

/*
	URMSerial.h - URM 37 Control Library Version 2.0.0
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

*/
#include <wiring.h>
#include <hardwareSerial.h>
#include "NewSoftSerial.h"
#include <inttypes.h>
#include <stdio.h>
#include <WProgram.h>

// The measurement we're taking
#define DISTANCE 1
#define TEMPERATURE 2
#define ERROR 3
#define NOTREADY 4
#define TIMEOUT 5


// Commands the device responds to
#define COMMAND_TEMP 0x11
#define COMMAND_DISTANCE 0x22
#define COMMAND_EEPROMREAD 0x33
#define COMMAND_EEPROMWRITE 0x44

#define Header 0
#define HighByte 1
#define LowByte 2
#define Sum 3

// Serial is TTL
#define MODE_SERIAL 0x00
#define MODE_AUTO 0x01
#define MODE_PWM 0x02
// Note: This library does not support PWM mode 

class URMSerial
{
	private:
	long timeRequested;


	// Software Serial Instance
	NewSoftSerial* serial;

	byte servoAngle; // 0-46 maps to 0-180 degrees
	byte servoMax; //180
	byte servoMin; // 0
	
	// We have already requested a distance
	bool distanceRequested;
	bool temperatureRequested;

    // Contains serial data
	byte serialData[4];

	// Send a series of bytes via serial
	void sendCommand(byte*);

	// validate the serial stream. true if in error (happens in a measurement cannot be validated)
	bool hasError();

    // Populate serial data array with 3 bytes
	void readSerial();

	// Contains the processing code for associated measurements
	byte processDistance(int&);
	byte processTemperature(int&);
	
	uint8_t timeout; 

	// Force reset
    void forceReset();
	
	// Request a read (and return) from EEPROM
	byte read(byte);
	
	// Write to EEPROM
	bool write(byte, byte); // command, data **WARNING DANGEROUS**

	public:
	// Constructor, doesn't do anything
	URMSerial();

	// RX Pin, TX Pin, Baud Speed
	void begin(uint8_t, uint8_t, long);

	// Does the URM have a reading
	bool hasReading();

	// Has this request timedout?
	bool reqTimeout();

	// Read in Temperature, return the type with the value populated by reference variable
	byte getMeasurement(int&);

	// Send command for measurement request
	bool requestMeasurement(byte); // Returns success

	// As request measurement, blocks till it times out or retreives meassge
	byte requestMeasurementOrTimeout(byte, int&);
	
	// Set servo position
	void setServo(uint8_t);
	
	// Set servo bounds
	void setServoMax(uint8_t);
	void setServoMin(uint8_t);
	
	void setTimeout(uint8_t);
	
		
	// Set automatic detction thresholds
	bool setSensorThresholdMin(byte); 
	bool setSensorThresholdMax(byte);
	
	byte getSensorThresholdMin(); 
	byte getSensorThresholdMax();
	
	// Set operating mode
	bool setMode(byte);

};
#endif
