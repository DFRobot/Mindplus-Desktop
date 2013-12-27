/*
||
|| @author Alexander Brevig
|| @version 1.0
||
*/

#ifndef SHIFTREGISTER595_H
#define SHIFTREGISTER595_H

#include "WProgram.h"
#include "ShiftRegister.h"

class ShiftRegister595 : public ShiftRegister{
	public:
		ShiftRegister595( byte userLatchPin, byte userClockPin, byte userDataPin );	
		
		virtual void buffer(byte out);
		virtual void write();
		virtual void write(byte out);
			
	private:
		void shiftOut(byte out);
		byte latchPin;
		byte clockPin;
		byte dataPin;
		byte bufferByte;
};

#endif

/*
|| Changelog:
||
|| 1.0 2009-04-13 - Alexander Brevig : Initial Release
*/