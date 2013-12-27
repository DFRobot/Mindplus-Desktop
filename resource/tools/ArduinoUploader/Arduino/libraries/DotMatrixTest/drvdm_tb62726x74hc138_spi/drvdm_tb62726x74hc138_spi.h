/*
 * drv_tb62726x74hc138_spi.h
 *
 *  Created on: 2012-7-26
 *      Author: Agu
 */

#ifndef DRV_DM_TB62726_X_74HC138_SPI_H_
#define DRV_DM_TB62726_X_74HC138_SPI_H_

#include "Arduino.h"
#include "dot-matrix.h"
#include "SPI.h"
#include "drv_tb62726_spi.h"
#include "drv_74hc138.h"

class DrvDmTb62726X74hc138Spi
{
public:
	DrvDmTb62726X74hc138Spi(DotMatrix & dm, SPIClass & spi, uint8_t pin_latch,
			uint8_t pin_en, uint8_t pin_rext, uint8_t pin_a2, uint8_t pin_a1,
			uint8_t pin_a0, uint8_t pin_oe, uint16_t scan_speed = 0x600);

	virtual ~DrvDmTb62726X74hc138Spi();

	void setSpeed(uint16_t scan_span);
	void setSize();
	void setBrightness(byte brg = 0xff);

	void display(byte times = 0x01) const;

protected:

	const DotMatrix & _dm;
	DrvTb62726Spi chip_col;
	Drv74hc138 chip_row;

	word _scan_span;

	byte _row_count;
	byte _word_per_row;
	byte _byte_per_row;

	void setCol(byte row) const;
};

#endif /* DRV_DM_TB62726_X_74HC138_SPI_H_ */
