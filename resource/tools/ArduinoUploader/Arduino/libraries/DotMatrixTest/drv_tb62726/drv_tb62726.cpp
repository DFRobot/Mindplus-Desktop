/*
 * drv_tb62726.cpp
 *
 *  Created on: 2012-7-10
 *      Author: Agu
 */

#include "drv_tb62726.h"

DrvTb62726::DrvTb62726(uint8_t pin_din, uint8_t pin_clk,
		uint8_t pin_latch, uint8_t pin_oe, uint8_t pin_rext) :
		Drv74hc595(pin_din, pin_clk, pin_latch, pin_oe), _pin_rext(pin_rext)
{

}

DrvTb62726::~DrvTb62726()
{

}

void DrvTb62726::setBrightness(byte brg)
{
	analogWrite(_pin_rext, brg);
}

void DrvTb62726::shiftSendCoupleFromLSB(byte *p, byte length) const
{
	for (byte i = length >> 1; i--;)
	{
		this->Drv74hc595::shiftSendFromLSB(*(p++));
		this->Drv74hc595::shiftSendFromMSB(*(p++));
	}
}

