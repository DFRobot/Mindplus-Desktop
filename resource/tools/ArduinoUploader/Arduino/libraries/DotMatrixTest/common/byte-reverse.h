/*
 * ReverseByte.h
 *
 *  Created on: Dec 12, 2012
 *      Author: agu
 */

#ifndef REVERSE_BYTE

#define REVERSE_BYTE

#include "Arduino.h"

#ifdef PROGMEM
  #undef PROGMEM
  #define PROGMEM __attribute__((section(".progmem.data")))
#endif

extern const uint8_t PROGMEM REVERSE[];

byte reverseByte(byte c);

#endif



