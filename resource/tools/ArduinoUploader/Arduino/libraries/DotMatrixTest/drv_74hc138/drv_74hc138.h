/*
 * drv_74hc138.h
 *
 *  Created on: 2012-7-9
 *      Author: Agu
 */

#ifndef DRV_74HC138_H_
#define DRV_74HC138_H_

#include "Arduino.h"
#include "pin_op.h"

class Drv74hc138
{
public:
	Drv74hc138(uint8_t pin_a2, uint8_t pin_a1, uint8_t pin_a0,
			uint8_t pin_oe);
	virtual ~Drv74hc138();
	void setValue(byte r) const;
	void setOE(bool on) const;
private:
	const uint8_t _pin_a2;
	const uint8_t _pin_a1;
	const uint8_t _pin_a0;
	const uint8_t _pin_oe;
};

#endif /* DRIVER_74HC138_H_ */
