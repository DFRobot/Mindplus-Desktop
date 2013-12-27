/*
 * drv_74hc138.cpp
 *
 *  Created on: 2012-7-9
 *      Author: Agu
 */

#include "drv_74hc138.h"

Drv74hc138::Drv74hc138(uint8_t pin_A2, uint8_t pin_a1, uint8_t pin_a0,
		uint8_t pin_oe)
:_pin_a2(pin_A2),_pin_a1(pin_a1),_pin_a0(pin_a0),_pin_oe(pin_oe)
{
	pinMode(_pin_a2, OUTPUT);
	pinMode(_pin_a1, OUTPUT);
	pinMode(_pin_a0, OUTPUT);
	pinMode(_pin_oe, OUTPUT);
}

Drv74hc138::~Drv74hc138()
{

}

void Drv74hc138::setValue(byte r) const
{
	pinWrite(_pin_a0, r & 0x01);
	pinWrite(_pin_a1, r & 0x02);
	pinWrite(_pin_a2, r & 0x04);
}

void Drv74hc138::setOE(bool on) const
{
	pinWrite(_pin_oe, on);
}

