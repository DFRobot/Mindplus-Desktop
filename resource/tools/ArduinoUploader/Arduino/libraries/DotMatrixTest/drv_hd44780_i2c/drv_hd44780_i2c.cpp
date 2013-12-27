/*
 * drv_hd44780_i2c.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: agu
 */

#include "drv_hd44780_i2c.h"

DrvHd44780I2c::DrvHd44780I2c(byte address, byte row_count, byte col_count) :
		DrvHd44780Basic(row_count, col_count), _address(address)
{
	_backlight = true;
	twi.init();
}

DrvHd44780I2c::~DrvHd44780I2c()
{
	free(_cache);
}

void DrvHd44780I2c::initHardware() const
{
	delayMicroseconds(40000);

	twi.writeTo(_address, 0x30 | _BV(PIN_EN));
	twi.writeTo(_address, 0x30);
	delayMicroseconds(4500);

	twi.writeTo(_address, 0x30 | _BV(PIN_EN));
	twi.writeTo(_address, 0x30);
	delayMicroseconds(150);

	twi.writeTo(_address, 0x30 | _BV(PIN_EN));
	twi.writeTo(_address, 0x30);

	twi.writeTo(_address, 0x20 | 0x04);
	twi.writeTo(_address, 0x20);

	this->configureFunction();
	this->configureDisplay(false, false, false);

	this->clear();
	this->configureInput();
	this->rst();
}

void DrvHd44780I2c::transmit(bool isData, byte c) const
{
	byte val = 0;
	bitWrite(val, PIN_BL, _backlight);
	bitWrite(val, PIN_RS, isData);

	val |= c & 0xf0;

	bitSet(val, PIN_EN);
	twi.writeTo(_address, val);

	bitClear(val, PIN_EN);
	twi.writeTo(_address, val);

	val &= 0x0f;
	val |= c << 4;

	bitSet(val, PIN_EN);
	twi.writeTo(_address, val);

	bitClear(val, PIN_EN);
	twi.writeTo(_address, val);
}

void DrvHd44780I2c::setBackLight(bool on)
{
	_backlight = on;
	twi.writeTo(_address, _backlight ? 0x08 : 0x00);
}
