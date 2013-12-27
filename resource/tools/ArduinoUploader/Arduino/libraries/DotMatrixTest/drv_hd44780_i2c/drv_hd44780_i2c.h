/*
 * drv_hd44780_i2c.h
 *
 *  Created on: Jan 8, 2013
 *      Author: agu
 *
 *  HD44780 LiquidCtrystal display on i2c bus 8-bit I/O expander PCF8574
 *
 *  PCF8574 -	HD44780
 *  P7	-	D7
 *  P6	-	D6
 *  P5	-	D5
 *  P4	-	D4
 *  P3	-	Background Led, on when high
 *  P2	-	E
 *  P1	-	RW
 *  P0	-	RS
 */

#ifndef DRV_HD44780_I2C_H_
#define DRV_HD44780_I2C_H_

#include "Arduino.h"
#include "drv_hd44780_basic.h"
#include "Twi.h"
// The twi library is my substitute of the Wire library,
// host on https://github.com/aguegu/Arduino/tree/master/libraries/Twi

#define PIN_RS	0
#define PIN_RW	1
#define PIN_EN	2
#define PIN_BL	3	// backlight, background LED

class DrvHd44780I2c: public DrvHd44780Basic
{
public:
	DrvHd44780I2c(byte address, byte row_count = 2, byte col_count = 16);
	virtual ~DrvHd44780I2c();

	void setBackLight(bool bl);

private:

	const byte _address;
	bool _backlight;

	void initHardware() const;
	void transmit(bool isData, byte val) const;
};

#endif /* DRV_HD44780_I2C_H_ */
