/*
 * 	drv_tb62726x74hc138.h
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

#ifndef DRV_DM_TB62726_X_74HC138_H_
#define DRV_DM_TB62726_X_74HC138_H_

#include "dot-matrix.h"
#include "drv_tb62726.h"
#include "drv_74hc138.h"

class DrvDmTb62726X74hc138
{
public:
	DrvDmTb62726X74hc138(DotMatrix & dm, uint8_t pin_din, uint8_t pin_clk,
			uint8_t pin_latch, uint8_t pin_en, uint8_t pin_rext, uint8_t pin_a2,
			uint8_t pin_a1, uint8_t pin_a0, uint8_t pin_oe,
			uint16_t scan_speed = 0x600);

	virtual ~DrvDmTb62726X74hc138();

	void setSpeed(uint16_t scan_span);
	void setSize();
	void setBrightness(byte brg = 0xff);

	void display(byte times = 0x01) const;

protected:

	const DotMatrix & _dm;
	DrvTb62726 chip_col;
	Drv74hc138 chip_row;

	word _scan_span;

	byte _row_count;
	byte _word_per_row;
	byte _byte_per_row;

	void setCol(byte row) const;
};

#endif /* DRV_DM_TB62726_X_74HC138_H_ */
