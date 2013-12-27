/*
	drv_74hc595x74hc138.h
	Drv74hc595X74hc138 Class for dot-matrix printing on matrix driven by 74HC595 and 74HC138
	Created on: 2012-01-25
	Updated on: 2012-06-05

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DRV_DM_74HC595_X_74HC138_H_
#define DRV_DM_74HC595_X_74HC138_H_

#include "Arduino.h"
#include "drv_74hc138.h"
#include "drv_74hc595.h"
#include "dot-matrix.h"

class DrvDm74hc595X74hc138
{
public:

	DrvDm74hc595X74hc138(DotMatrix & dm, uint8_t pin_c_in,
			uint8_t pin_c_oe, uint8_t pin_c_st, uint8_t pin_c_sh, uint8_t pin_r_oe,
			uint8_t pin_r_a2, uint8_t pin_r_a1, uint8_t pin_r_a0, uint16_t scan_span = 0x400);
	virtual ~DrvDm74hc595X74hc138();
	void display();
	void setShiftMode(byte mode = MSBFIRST);

protected:

	const DotMatrix & _dm;

	Drv74hc595 _chip_col;
	Drv74hc138 _chip_row;

	byte _row_count;
	byte _bytes_per_row;
};

#endif /* DRV_DM_74HC595_X_74HC138_H_ */
