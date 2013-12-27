/*
 * drv_hd44780_basic.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: agu
 */

#include "drv_hd44780_basic.h"

const uint8_t PROGMEM HD44780_BAR[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 00000000
	0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 11000000
	0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, // 00011000
	0x1f, 0x1f, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, // 11011000
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, // 00000011
	0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, // 11000011
	0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, // 00011011
	0x1f, 0x1f, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, // 11011011
};

const uint8_t PROGMEM HD44780_ROW_ADDRESS_16[] =
{ 0x00, 0x40, 0x10, 0x50 };
const uint8_t PROGMEM HD44780_ROW_ADDRESS_20[] =
{ 0x00, 0x40, 0x14, 0x54 };

DrvHd44780Basic::DrvHd44780Basic(byte row_count, byte col_count) :
		_row_count(row_count), _col_count(col_count)
{
	_cache_length = _row_count * _col_count + 1;
	_cache = (char *) malloc(sizeof(char) * _cache_length);
	this->setCache();
}

DrvHd44780Basic::~DrvHd44780Basic()
{
	free(_cache);
}

void DrvHd44780Basic::setCache(byte value)
{
	memset(_cache, value, _cache_length);
}

void DrvHd44780Basic::setCache(byte index, byte value)
{
	if (index >= _cache_length)
		return;

	_cache[index] = value;
}

void DrvHd44780Basic::putString(byte address, char *p, byte length) const
{
	char *pp = p;

	this->setCursor(address);

	while (length--)
	{
		transmit(true, *pp++);
	}
}

void DrvHd44780Basic::putChar(byte address, char c) const
{
	this->putString(address, &c, 1);
}

void DrvHd44780Basic::init()
{
	this->initHardware();

	byte *bar = (byte*) malloc(64);
	memcpy_P(bar, HD44780_BAR, 64);
	this->setCGRam(bar, 64);
	free(bar);

	this->configureDisplay(true, false, false);
}

void DrvHd44780Basic::putCache() const
{
	for (byte r = 0; r < _row_count; r++)
		this->putString(
				pgm_read_byte_near((_col_count<=16?HD44780_ROW_ADDRESS_16:HD44780_ROW_ADDRESS_20) + r),
				_cache + _col_count * r, _col_count);
}

void DrvHd44780Basic::printf(byte index, const char *__fmt, ...)
{
	if (index >= _cache_length)
		return;

	va_list ap;
	va_start(ap, __fmt);
	vsnprintf(_cache + index, _cache_length - index, __fmt, ap);
	va_end(ap);
}

void DrvHd44780Basic::printf(const char *__fmt, ...)
{
	va_list ap;
	va_start(ap, __fmt);
	vsnprintf(_cache, _cache_length, __fmt, ap);
	va_end(ap);
}

void DrvHd44780Basic::clear() const // 0x01
{
	transmit(false, 0x01);
	delayMicroseconds(2000);
}

void DrvHd44780Basic::rst() const // 0x02
{
	transmit(false, 0x02);
	delayMicroseconds(2000);
}

void DrvHd44780Basic::configureInput(bool ac, bool screen_move) const // 0x04
{
	byte cmd = 0x04;

	if (ac)
		cmd |= 0x02;
	if (screen_move)
		cmd |= 0x01;

	transmit(false, cmd);
}

void DrvHd44780Basic::configureDisplay(bool display_on, bool cursor,
		bool blink) const // 0x08
{
	byte cmd = 0x08;
	if (display_on)
		cmd |= 0x04;
	if (cursor)
		cmd |= 0x02;
	if (blink)
		cmd |= 0x01;

	transmit(false, cmd);
}

void DrvHd44780Basic::moveCursor(bool right) const // 0x10
{
	byte cmd = 0x10;
	if (right)
		cmd |= 0x04;
	transmit(false, cmd);
}

void DrvHd44780Basic::moveScreen(bool right) const // 0x11
{
	byte cmd = 0x11;
	if (right)
		cmd |= 0x04;
	transmit(false, cmd);
}

void DrvHd44780Basic::configureFunction(bool interface8, bool doubleline,
		bool font5x10) const // 0x20
{
	byte cmd = 0x20;
	if (interface8)
		cmd |= 0x10;
	if (doubleline)
		cmd |= 0x08;
	if (font5x10)
		cmd |= 0x04;
	transmit(false, cmd);
}

void DrvHd44780Basic::setCGRam(byte *pFont, byte length) const
{
	this->configureInput(true, false);
	transmit(false, 0x40);

	for (byte i = 0; i < length; i++)
	{
		transmit(true, pFont[i]);
	}
}

void DrvHd44780Basic::setCursor(byte address) const // 0x80
{
	transmit(false, address | 0x80);
}
