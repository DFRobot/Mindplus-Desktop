/*
 * Driver_74HC595_SPI.cpp
 *
 *  Created on: 2012-7-16
 *      Author: Agu
 */

#include "drv_74hc595_spi.h"

Drv74hc595Spi::Drv74hc595Spi(SPIClass & spi, uint8_t pin_st, uint8_t pin_oe)
: _spi(spi), _pin_st(pin_st), _pin_oe(pin_oe)
{
	pinMode(_pin_st, OUTPUT);
	pinMode(_pin_oe, OUTPUT);

	this->setShiftSendMode();
	_spi.setDataMode(SPI_MODE0);
	_spi.setClockDivider(SPI_CLOCK_DIV2);
	_spi.begin();
}

Drv74hc595Spi::~Drv74hc595Spi()
{

}

void Drv74hc595Spi::setShiftSendMode(byte mode)
{
	_spi.setBitOrder(mode);
}


void Drv74hc595Spi::shiftSendRev(byte *p, byte length) const
{
	while(length--)
		_spi.transfer(~*(p++));
}

void Drv74hc595Spi::shiftSend(byte *p, byte length) const
{
	while(length--)
		_spi.transfer(*(p++));
}

void Drv74hc595Spi::shiftLatch() const
{
	pinSet(_pin_st);
	pinClear(_pin_st);
}

void Drv74hc595Spi::setOE(bool high) const
{
	pinWrite(_pin_oe, high);
}
