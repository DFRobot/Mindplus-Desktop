/*
 *	drvdm_pcd8544.cpp
 *	DrvPcd8544Dm Class for dot-matrix printing on liquid crystal display driven by PCD8544, namely Nokia 8544
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

#include "drvdm_pcd8544.h"

DrvDmPcd8544::DrvDmPcd8544(uint8_t pin_sce, uint8_t pin_rst, uint8_t pin_dc,
		uint8_t pin_din, uint8_t pin_sclk) :
		DrvPcd8544(pin_sce, pin_rst, pin_dc, pin_din, pin_sclk), _dm(
				48, 84)
{

}

DrvDmPcd8544::~DrvDmPcd8544()
{

}

void DrvDmPcd8544::putDM()
{
	byte *p = _dm.output();
	this->setRamAddress(0, 0);

	byte j = _dm.countRow();
	while (j--)
	{
		p += BYTES_PER_COLUMN;

		byte i = BYTES_PER_COLUMN;

		while (i--)
			this->transmit(*(--p), DATA);

		p += BYTES_PER_COLUMN;
	}
}

DotMatrix & DrvDmPcd8544::getDM()
{
	return _dm;
}
