/*
 *	drv_pcd8544.cpp
 *	DrvPcd8544 Class for dot-matrix printing on liquid crystal display driven by HD47780, namely 1602/1604
 *	Created on: 2012-05-30
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

#include "drv_pcd8544.h"

DrvPcd8544::DrvPcd8544(uint8_t pin_sce, uint8_t pin_rst, uint8_t pin_dc,
		uint8_t pin_din, uint8_t pin_sclk) :
		_pin_sce(pin_sce), _pin_rst(pin_rst), _pin_dc(pin_dc), _pin_din(
				pin_din), _pin_sclk(pin_sclk)
{
	pinMode(_pin_sce, OUTPUT);
	pinMode(_pin_rst, OUTPUT);
	pinMode(_pin_dc, OUTPUT);
	pinMode(_pin_din, OUTPUT);
	pinMode(_pin_sclk, OUTPUT);
}

DrvPcd8544::~DrvPcd8544()
{

}

void DrvPcd8544::transmit(byte c, bool b)
{
	pinClear(_pin_sce);

	pinWrite(_pin_dc, b);

	for (byte i = 8; i--;)
	{
		pinWrite(_pin_din, bitRead(c, 7));
		pinClear(_pin_sclk);
		pinSet(_pin_sclk);
		c <<= 1;
	}
	pinSet(_pin_sce);
}

void DrvPcd8544::init()
{
	digitalWrite(_pin_sce, LOW);
	digitalWrite(_pin_rst, LOW);
	delay(0x40);
	digitalWrite(_pin_rst, HIGH);
	digitalWrite(_pin_sce, HIGH);

	this->configureHardware();
	this->configureDisplay();
}

void DrvPcd8544::configureFunction(bool active, bool vertical_addressing,
		bool extend_command)
{
	this->transmit(
			0x20 | (active ? 0x00 : 0x04) | (vertical_addressing ? 0x02 : 0x00)
					| (extend_command ? 0x01 : 0x00), COMMAND);
}

void DrvPcd8544::configureHardware(byte tc, byte bias, byte vop)
{
	this->configureFunction(true, true, true);
	this->transmit(0x04 | (tc & 0x03), COMMAND);
	this->transmit(0x10 | (bias & 0x07), COMMAND);
	this->transmit(0x80 | (vop & 0x7f), COMMAND);
	this->configureFunction(true, true, false);
}

void DrvPcd8544::configureDisplay(bool display_on, bool reverse)
{
	this->transmit(0x08 | (display_on ? 0x04 : 0x00) | (reverse ? 0x01 : 0x00),
			COMMAND);
}

void DrvPcd8544::setRamAddress(byte x, byte y)
{
	x %= CLOLUMN_COUNT;
	y %= BYTES_PER_COLUMN;
	this->transmit(0x80 | x, COMMAND);
	this->transmit(0x40 | y, COMMAND);
}
