/*
 * ReverseByte.c
 *
 *  Created on: Dec 12, 2012
 *      Author: agu
 */

#include "byte-reverse.h"

const uint8_t PROGMEM REVERSE[] =
{
		0x00, 0x08, 0x04, 0x0c,
		0x02, 0x0a, 0x06, 0x0e,
		0x01, 0x09, 0x05, 0x0d,
		0x03, 0x0b, 0x07, 0x0f
};


byte reverseByte(byte c)
{
	return (pgm_read_byte_near(REVERSE + (c & 0x0f)) << 4) ^ (pgm_read_byte_near(REVERSE + (c >> 4)) & 0x0f);
}


