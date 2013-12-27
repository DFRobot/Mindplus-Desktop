/*
 * drv_tb62726_spi.h
 *
 *  Created on: 2012-7-16
 *      Author: Agu
 */

#ifndef DRV_TB62726_SPI_H_
#define DRV_TB62726_SPI_H_

#include "Arduino.h"
#include "drv_74hc595_spi.h"

class DrvTb62726Spi: public Drv74hc595Spi
{
public:

	DrvTb62726Spi(SPIClass & spi, uint8_t pin_latch, uint8_t pin_oe, uint8_t pin_rext);
	virtual ~DrvTb62726Spi();

	void setBrightness(byte brg);
	void shiftSendCoupleFromLSB(byte *p, byte length) const;

private:

	const uint8_t _pin_rext;
};

#endif /* DRV_TB62726_SPI_H_ */
