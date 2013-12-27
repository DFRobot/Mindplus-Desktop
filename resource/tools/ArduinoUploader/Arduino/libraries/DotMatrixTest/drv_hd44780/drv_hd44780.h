/*
 *	drv_hd44780.h
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

#ifndef DRV_HD44780_H_
#define DRV_HD44780_H_

#include "Arduino.h"
#include "pin_op.h"
#include "drv_hd44780_basic.h"

class DrvHd44780: public DrvHd44780Basic
{
public:
	DrvHd44780(uint8_t pin_rs, uint8_t pin_en, uint8_t pin_d4, uint8_t pin_d5,
			uint8_t pin_d6, uint8_t pin_d7, byte row_count = 4, byte col_count =
					16);
	virtual ~DrvHd44780();

private:

	const uint8_t _pin_rs;
	const uint8_t _pin_en;
	uint8_t _pin_dt[4];

	void setDT(byte c, bool b) const;
	void setData(byte c) const;

	void transmit(bool isData, byte val) const;

	void initHardware() const;
};

#endif /* DRV_HD44780_H_ */
