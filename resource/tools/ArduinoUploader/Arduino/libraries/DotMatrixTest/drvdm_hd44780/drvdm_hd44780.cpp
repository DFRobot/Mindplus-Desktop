/*
 drvdm_hd44780.cpp
 DrvDmHd44780 Class for dot-matrix printing on liquid crystal display driven by HD47780, namely 1602/1604
 Created on: 2012-02-29
 Updated on: 2012-06-01

 library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 Author: Weihong Guan
 Blog: http://aguegu.net
 E-mail: weihong.guan@gmail.com
 Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 http://creativecommons.org/licenses/by-nc-sa/3.0/

 source host: https://github.com/aguegu/dot-matrix
 */

#include "drvdm_hd44780.h"

DrvDmHd44780::DrvDmHd44780(uint8_t pin_rs, uint8_t pin_en, uint8_t pin_d4, uint8_t pin_d5, uint8_t pin_d6, uint8_t pin_d7, byte row_count, byte col_count)
:DrvHd44780(pin_rs, pin_en, pin_d4, pin_d5, pin_d6, pin_d7, row_count, col_count), _dm(col_count, row_count * 3)
{

}

DrvDmHd44780::~DrvDmHd44780()
{

}

void DrvDmHd44780::convertDotMatrixToCache()
{
	this->setCache();

	for (byte c = 0; c < _dm.countCol(); c++)
	{
		for (byte r = 0; r < _dm.countRow(); r++)
		{
			bitWrite(*(_cache + _col_count * (r/3) + c), r % 3,
					_dm.getDot(c, r));
		}
	}
}

DotMatrix & DrvDmHd44780::getDotMatrix()
{
	return _dm;
}
