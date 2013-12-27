/*
 * bit_op.h
 *
 *  Created on: Dec 13, 2012
 *      Author: agu
 */

#ifndef BIT_OP
#define BIT_OP

#define readLowBitInByte(value, bit) ((value) & _BV(bit))
#define setLowBitInByte(value, bit) ((value) |= _BV(bit))
#define clearLowbitInByte(value, bit) ((value) &= ~_BV(bit))
#define writeLowBitInByte(value, bit, bitvalue) (bitvalue ? setLowBitInByte(value, bit) : clearLowbitInByte(value, bit))

#define readHighBitInByte(value, bit) ((value) & (0x80 >> (bit)))
#define setHighBitInByte(value, bit) ((value) |= (0x80 >> (bit)))
#define clearHighBitInByte(value, bit) ((value) &= ~(0x80 >> (bit)))
#define writeHighBitInByte(value, bit, bitvalue) (bitvalue ? setHighBitInByte(value, bit) : clearHighBitInByte(value, bit))

#endif

