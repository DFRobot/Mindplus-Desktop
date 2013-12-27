/*
 * drv_ld4812.cpp
 *
 *  Created on: 2012-9-4
 *      Author: agu
 */

#include "drvdm_ld4812.h"

DrvDmLd4812::DrvDmLd4812(uint8_t pin_col, uint8_t pin_row, uint8_t pin_sh,
		uint8_t pin_st, uint8_t pin_oe) :
		_dm(48, 12), _pin_col(pin_col), _pin_row(pin_row), _pin_sh(pin_sh), _pin_st(
				pin_st), _pin_oe(pin_oe)
{
	pinMode(_pin_col, OUTPUT);
	pinMode(_pin_row, OUTPUT);
	pinMode(_pin_sh, OUTPUT);
	pinMode(_pin_st, OUTPUT);
	pinMode(_pin_oe, OUTPUT);

	this->setBrightness();
}

DrvDmLd4812::~DrvDmLd4812()
{

}

void DrvDmLd4812::shiftLatch() const
{
	pinSet(_pin_st);
	pinClear(_pin_st);
}

void DrvDmLd4812::shiftClock() const
{
	pinSet(_pin_sh);
	pinClear(_pin_sh);
}

void DrvDmLd4812::display() const
{
	static byte r = 0;

	byte *p2 = _dm.output() + pgm_read_byte_near(LD4812_ROW_ADDRESS+r);
	for (byte i = 3, j = 0; i--;)
	{
		byte tmp = *p2++;
		for (byte c = 8; c--; j++)
		{
			pinWrite(_pin_col, tmp&0x80);
			pinWrite(_pin_row, j!=r);
			// row on when it is LOW
			this->shiftClock();
			tmp <<= 1;
		}
	}
	this->shiftLatch();

	r++;
	if (r == LD4812_WIDTH)
		r = 0;
}

DotMatrix & DrvDmLd4812::getDotMatrix()
{
	return _dm;
}

void DrvDmLd4812::setBrightness(byte brightness)
{
	analogWrite(_pin_oe, 0xff - brightness);
}
