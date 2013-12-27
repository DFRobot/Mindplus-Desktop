/*
	drv_st7920.h
	DrvSt7920 Class, Arduino Driver for liquid crystal display driven by ST7920, namely 12864
	Created on: 2012-03-04
	Updated on: 2012-06-01

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DRV_ST7920_H_
#define DRV_ST7920_H_

#include "Arduino.h"
#include "dot-matrix.h"
#include "pin_op.h"

class DrvSt7920
{
public:
	DrvSt7920(uint8_t pin_rs, uint8_t pin_en, uint8_t pin_d4, uint8_t pin_d5, uint8_t pin_d6, uint8_t pin_d7);
	virtual ~DrvSt7920();

	void init();

	void printWord(char *);
	void clear();
	void home();
	void configureEntry(bool right = true);
	void configureDisplay(bool display = true, bool cursor = false, bool blink = false);
	void moveCursor(bool right = true);
	void moveDisplay(bool right = true);
	void configureFunction(bool interface8 = false, bool re = false, bool graphic = false);

protected:

	void setDdRam(byte address); // Set address in Text Mode
	void writeData(byte c);

private:

	const uint8_t _pin_rs;
	const uint8_t _pin_en;
	uint8_t _pin_d[4];

	void initPin();
	inline void pulseEn();
	inline void setDB2(byte c, bool high);

	void setCgRam(byte value);

	void writeCmd(byte c);

};

#endif /* DRV_ST7920_H_ */
