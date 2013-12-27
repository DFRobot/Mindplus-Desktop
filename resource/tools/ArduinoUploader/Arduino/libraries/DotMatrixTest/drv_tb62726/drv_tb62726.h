/*
 * drv_tb62726.h
 *
 *  Created on: 2012-7-10
 *      Author: Agu
 */

#ifndef DRV_TB62726_H_
#define DRV_TB62726_H_

#include "Arduino.h"
#include "drv_74hc595.h"

class DrvTb62726: public Drv74hc595
{
public:

	DrvTb62726(uint8_t pin_din, uint8_t pin_clk, uint8_t pin_latch, uint8_t pin_oe, uint8_t pin_rext);
	virtual ~DrvTb62726();
	void setBrightness(byte brg);
	void shiftSendCoupleFromLSB(byte *p, byte length) const;

private:

	const uint8_t _pin_rext;

};

#endif /* DRV_TB62726_H_ */
