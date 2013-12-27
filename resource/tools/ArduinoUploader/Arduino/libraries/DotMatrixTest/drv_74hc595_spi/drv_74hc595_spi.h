/*
 * drv_74hc595_spi.h
 *
 *  Created on: 2012-7-16
 *      Author: Agu
 */

#ifndef DRV_74HC595_SPI_H_
#define DRV_74HC595_SPI_H_

#include "Arduino.h"
#include "SPI.h"
#include "pin_op.h"

class Drv74hc595Spi
{
public:

	Drv74hc595Spi(SPIClass & spi, uint8_t pin_ST, uint8_t pin_OE);
	virtual ~Drv74hc595Spi();

	void setShiftSendMode(byte mode = MSBFIRST);
	void shiftSend(byte *p, byte length) const;
	void shiftSendRev(byte *p, byte length) const;

	void shiftLatch() const;
	void setOE(bool high) const;

protected:

	const SPIClass & _spi;

private:

	const uint8_t _pin_st;
	const uint8_t _pin_oe;

};

#endif /* DRV_74HC595_SPI_H_ */
