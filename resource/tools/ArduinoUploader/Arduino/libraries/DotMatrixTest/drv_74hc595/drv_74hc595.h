/*
 * drv_74hc595.h
 *
 *  Created on: 2012-7-9
 *      Author: Agu
 */

#ifndef DRV_74HC595_H_
#define DRV_74HC595_H_

#include "Arduino.h"
#include "pin_op.h"

#ifndef BIT_IN_BYTE
#define BIT_IN_BYTE 8
#endif

class Drv74hc595
{
public:

	Drv74hc595(uint8_t pin_DS, uint8_t pin_SH, uint8_t pin_ST, uint8_t pin_OE);
	virtual ~Drv74hc595();

	void setShiftMode(byte mode = MSBFIRST);

	void shiftSend(byte *p, byte length) const;
	void shiftSendRev(byte *p, byte length) const;

	void shiftLatch() const;
	void setOE(bool high = true) const;

protected:

	inline void setDS(bool high) const;
	inline void shiftClock() const;

	void shiftSendFromLSB(byte c) const;
	void shiftSendFromMSB(byte c) const;

private:

	const uint8_t _pin_ds;
	const uint8_t _pin_sh;
	const uint8_t _pin_st;
	const uint8_t _pin_oe;

	void (Drv74hc595::*_shiftSend)(byte c) const;
};

#endif /* DRV_74HC595_H_ */
