/*
 * drvdm_tb62726x74hc138_spi.cpp
 *
 *  Created on: 2012-7-26
 *      Author: Agu
 */

#include "drvdm_3d8_spi.h"

DrvDm3d8Spi::DrvDm3d8Spi(DotMatrix & dm, SPIClass & spi,
		uint8_t pin_latch, uint8_t pin_en, uint8_t pin_rext, uint8_t pin_a2,
		uint8_t pin_a1, uint8_t pin_a0, uint16_t scan_speed) :
		DrvDmTb62726X74hc138Spi(dm, spi, pin_latch, pin_en, pin_rext, pin_a2,
				pin_a1, pin_a0, 255, scan_speed)
{
	this->setMode();
}

DrvDm3d8Spi::~DrvDm3d8Spi()
{

}

void DrvDm3d8Spi::setMode(ScanMode mode)
{
	switch (mode)
	{
	case ZXY:
		_setCol = &DrvDm3d8Spi::setColzxy;
		break;
	case YZX:
		_setCol = &DrvDm3d8Spi::setColyzx;
		break;
	default:
		_setCol = &DrvDm3d8Spi::setColxyz;
		break;
	}
}

void DrvDm3d8Spi::setColxyz(byte row) const
{
	byte * p = _dm.output();
	p += _byte_per_row * row;

	chip_col.shiftSendCoupleFromLSB(p, _byte_per_row);
}

void DrvDm3d8Spi::display(byte times) const
{
	while (times--)
	{
		for (byte r = 0; r < _row_count; r++)
		{
			(this->*_setCol)(r);

			chip_col.setOE(true);
			chip_col.shiftLatch();
			chip_row.setValue(r);
			chip_col.setOE(false);

			delayMicroseconds (_scan_span);
		}
	}
}

void DrvDm3d8Spi::setColzxy(byte row) const
{
	byte * p = _dm.output();
	for (byte j = 0; j < _word_per_row; j++)
	{
		byte cache[2];
		byte *p2 = p + _byte_per_row + _byte_per_row;

		for (byte i = 8; i--;)
		{
			cache[0] <<= 1;
			if (bitRead(*(p++), row))
				cache[0] |= 0x01;

			cache[1] <<= 1;
			if (bitRead(*(--p2), row))
				cache[1] |= 0x01;
		}
		p += _byte_per_row;
		chip_col.shiftSend(cache, 2);
	}
}

void DrvDm3d8Spi::setColyzx(byte row) const
{
	byte *p = _dm.output() + row;
	for (byte j = 0; j < _byte_per_row; j++) // z
	{
		byte cache;

		for (byte i = 8; i--;)
		{
			cache <<= 1;

			if (j & 0x01)
				p -= _byte_per_row;
			if (bitRead(*p, j))
				cache |= 0x01;
			if (!(j & 0x01))
				p += _byte_per_row;
		}

		chip_col.shiftSend(&cache, 1);
	}
}
