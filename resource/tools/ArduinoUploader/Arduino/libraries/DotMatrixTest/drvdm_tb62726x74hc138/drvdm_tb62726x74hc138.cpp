/*
 * 	drv_tb62726x74hc138.cpp
 *
 *	DotMatrix driver for led matrix driven by 74HC138 and TB62726(TM1818)
 *
 *  Created on: 2012-5-28
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#include "drvdm_tb62726x74hc138.h"

DrvDmTb62726X74hc138::DrvDmTb62726X74hc138(DotMatrix & dm, uint8_t pin_din, uint8_t pin_clk, uint8_t pin_latch, uint8_t pin_en, uint8_t pin_rext,
		uint8_t pin_a2, uint8_t pin_a1, uint8_t pin_a0, uint8_t pin_oe, uint16_t scan_speed):
		_dm(dm),
		chip_col(pin_din, pin_clk, pin_latch,pin_en, pin_rext),
		chip_row(pin_a2, pin_a1, pin_a0, pin_oe)
{
	this->setBrightness();
	this->setSpeed(scan_speed);
	this->setSize();
}

DrvDmTb62726X74hc138::~DrvDmTb62726X74hc138()
{

}

void DrvDmTb62726X74hc138::setSpeed(uint16_t scan_span)
{
	_scan_span = scan_span;
}

void DrvDmTb62726X74hc138::setSize()
{
	_row_count = _dm.countRow();
	_byte_per_row = _dm.countBytePerRow();
	_word_per_row = _byte_per_row / 2;
}

void DrvDmTb62726X74hc138::setBrightness(byte brg)
{
	chip_col.setBrightness(brg);
}

void DrvDmTb62726X74hc138::setCol(byte row) const
{
	byte * p = _dm.output();
	p += _byte_per_row * row;

	chip_col.shiftSend(p, _byte_per_row);
}

void DrvDmTb62726X74hc138::display(byte times) const
{
	while (times--)
	{
		for (byte r = 0; r < _row_count; r++)
		{
			this->setCol(r);

			chip_col.setOE(true);
			chip_col.shiftLatch();
			chip_row.setValue(r);
			chip_col.setOE(false);

			delayMicroseconds(_scan_span);
		}
	}
}
