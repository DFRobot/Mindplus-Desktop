/*
||
|| @author Alexander Brevig
|| @version 1.0
||
|| @inspiration http://arduino.cc/en/Tutorial/ShftOut11
||
*/

#include "ShiftRegister595.h"

byte latchPin = 8;  //Pin connected to ST_CP of 74HC595
byte clockPin = 12; //Pin connected to SH_CP of 74HC595
byte dataPin = 11;  //Pin connected to DS    of 74HC595

ShiftRegister595 shiftRegister595 = ShiftRegister595( latchPin , clockPin , dataPin );


void setup() {
}

void loop() {
  //count up routine
  for (int j = 0; j < 256; j++) {
    shiftRegister595.write(i);
    delay(1000);
  }
}