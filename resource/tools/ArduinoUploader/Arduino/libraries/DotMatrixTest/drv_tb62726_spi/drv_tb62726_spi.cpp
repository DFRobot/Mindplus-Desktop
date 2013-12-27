/*
 * drv_tb62726_spi.cpp
 *
 *  Created on: 2012-7-16
 *      Author: Agu
 */

#include "drv_tb62726_spi.h"

DrvTb62726Spi::DrvTb62726Spi(SPIClass & spi, uint8_t pin_latch,
		uint8_t pin_oe, uint8_t pin_rext) :
		Drv74hc595Spi(spi, pin_latch, pin_oe), _pin_rext(pin_rext)
{

}

void DrvTb62726Spi::setBrightness(byte brg)
{
	analogWrite(_pin_rext, brg);
}

DrvTb62726Spi::~DrvTb62726Spi()
{

}

void DrvTb62726Spi::shiftSendCoupleFromLSB(byte *p, byte length) const
{
	for (byte i = length >> 1; i--;)
	{
		_spi.setBitOrder(LSBFIRST);
		_spi.transfer(*(p++));
		_spi.setBitOrder(MSBFIRST);
		_spi.transfer(*(p++));
	}
}
