/*
 * drv_ld4812.h
 *
 *  Created on: 2012-9-4
 *      Author: agu
 */

#ifndef DRV_DM_LD4812_H_
#define DRV_DM_LD4812_H_

#include <avr/io.h>
#include "Arduino.h"
#include "pin_op.h"
#include "dot-matrix.h"

#define LD4812_WIDTH	24

const uint8_t PROGMEM LD4812_ROW_ADDRESS[] =
{
	24, 30, 36, 42,
	48, 54, 60, 66,
	51, 57, 63, 69,
	0, 6, 12, 18,
	3, 9, 15, 21,
	27, 33, 39, 45,
};

class DrvDmLd4812
{
public:

	DrvDmLd4812(uint8_t pin_col, uint8_t pin_row, uint8_t pin_sh, uint8_t pin_st, uint8_t pin_oe);
	virtual ~DrvDmLd4812();
	void display() const;
	DotMatrix & getDotMatrix();

	void setBrightness(byte brightness=0x70);

private:

	DotMatrix _dm;

	const uint8_t _pin_col;
	const uint8_t _pin_row;
	const uint8_t _pin_sh;
	const uint8_t _pin_st;
	const uint8_t _pin_oe;

	inline void shiftLatch() const;
	inline void shiftClock() const;
};

#endif /* DRV_DM_LD4812_H_ */
