/*
 *	Driver_HD44780_Basic.cpp
 *	Driver_HD44780_Basic Class, arduino driver for liquid crystal display driven by HD47780, namely 1602/1604
 *	Created on: 2012-06-01
 *
 *	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#include "drv_hd44780.h"

DrvHd44780::DrvHd44780(uint8_t pin_rs, uint8_t pin_en, uint8_t pin_d4,
		uint8_t pin_d5, uint8_t pin_d6, uint8_t pin_d7, byte row_count,
		byte col_count) :
		DrvHd44780Basic(row_count, col_count), _pin_rs(pin_rs), _pin_en(pin_en)
{

	_pin_dt[0] = pin_d4;
	_pin_dt[1] = pin_d5;
	_pin_dt[2] = pin_d6;
	_pin_dt[3] = pin_d7;

	pinMode(_pin_rs, OUTPUT);
	pinMode(_pin_en, OUTPUT);

	for (byte i = 0; i < 4; i++)
		pinMode(_pin_dt[i], OUTPUT);

	pinClear(_pin_rs);
	pinClear(_pin_en);
}

DrvHd44780::~DrvHd44780()
{

}

/////////////////////////////////////////////////

void DrvHd44780::setDT(byte c, bool b) const
{
	if (b)
		c >>= 4;

	for (byte i = 0; i < 4; i++)
		pinWrite(_pin_dt[i], bit_is_set(c, i));

	pinSet(_pin_en);
	pinClear(_pin_en);
	delayMicroseconds(0x20);
}

void DrvHd44780::setData(byte c) const
{
	this->setDT(c, true);
	this->setDT(c, false);
}

void DrvHd44780::transmit(bool isData, byte val) const
{
	pinWrite(_pin_rs, isData);
	this->setData(val);
}

void DrvHd44780::initHardware() const
{
	delayMicroseconds(40000);

	this->setDT(0x30, true);
	delayMicroseconds(4500);

	this->setDT(0x30, true);
	delayMicroseconds(150);

	this->setDT(0x30, true);
	this->setDT(0x20, true);

	this->configureFunction();
	this->configureDisplay(false, false, false);

	this->clear();
	this->configureInput();
	this->rst();
}
