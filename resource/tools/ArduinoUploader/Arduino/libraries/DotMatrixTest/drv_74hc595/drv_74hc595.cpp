/*
 * Driver_74HC595.cpp
 *
 *  Created on: 2012-7-9
 *      Author: Agu
 */

#include "drv_74hc595.h"

Drv74hc595::Drv74hc595(uint8_t pin_ds, uint8_t pin_sh, uint8_t pin_st,
		uint8_t pin_oe) :
		_pin_ds(pin_ds), _pin_sh(pin_sh), _pin_st(pin_st), _pin_oe(pin_oe)
{
	pinMode(_pin_ds, OUTPUT);
	pinMode(_pin_sh, OUTPUT);
	pinMode(_pin_st, OUTPUT);
	pinMode(_pin_oe, OUTPUT);

	this->setShiftMode();
}

Drv74hc595::~Drv74hc595()
{

}

void Drv74hc595::setShiftMode(byte mode)
{
	if (mode)
		_shiftSend = &Drv74hc595::shiftSendFromMSB;
	else
		_shiftSend = &Drv74hc595::shiftSendFromLSB;
}

void Drv74hc595::setDS(bool high) const
{
	pinWrite(_pin_ds, high);
}

void Drv74hc595::shiftClock() const
{
	pinSet(_pin_sh);
	pinClear(_pin_sh);
}

void Drv74hc595::shiftSendFromLSB(byte c) const
{
	byte i = BIT_IN_BYTE;

	while (i--)
	{
		this->setDS(c & 0x01);
		this->shiftClock();
		c >>= 1;
	}
}

void Drv74hc595::shiftSendFromMSB(byte c) const
{
	byte i = BIT_IN_BYTE;

	while (i--)
	{
		this->setDS(c & 0x80);
		this->shiftClock();
		c <<= 1;
	}
}

void Drv74hc595::shiftSend(byte * p, byte length) const
{
	for (byte i = length; i--;)
		(this->*_shiftSend)(*(p++));

}

void Drv74hc595::shiftSendRev(byte * p, byte length) const
{
	for (byte i = length; i--;)
		(this->*_shiftSend)(~(*(p++)));
}

void Drv74hc595::shiftLatch() const
{
	pinSet(_pin_st);
	pinClear(_pin_st);
}

void Drv74hc595::setOE(bool high) const
{
	pinWrite(_pin_oe, high);
}
