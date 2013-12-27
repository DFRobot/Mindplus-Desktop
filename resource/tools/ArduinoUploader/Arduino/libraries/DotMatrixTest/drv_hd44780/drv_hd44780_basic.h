/*
 * drv_hd44780_basic.h
 *
 *  Created on: Jan 22, 2013
 *      Author: agu
 */

#ifndef DRV_HD44780_BASIC_H_
#define DRV_HD44780_BASIC_H_

#include "Arduino.h"

#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif

class DrvHd44780Basic
{
public:
	DrvHd44780Basic(byte row_count = 2, byte col_count = 16);
	virtual ~DrvHd44780Basic();

	void init();
	void clear() const;
	void rst() const;

	void setCursor(byte address) const;
	void moveCursor(bool right) const;
	void moveScreen(bool right) const;

	void configureDisplay(bool display_on = true, bool cursor = true,
			bool blink = true) const;
	void setCGRam(byte *pFont, byte length) const;

	void putString(byte address, char *p, byte length) const;
	void putChar(byte address, char c) const;
	void putCache() const;

	void setCache(byte value = 0x00);
	void setCache(byte index, byte value);
	void printf(const char *__fmt, ...);
	void printf(byte index, const char *__fmt, ...);

protected:

	const byte _row_count;
	const byte _col_count;
	byte _cache_length;
	char * _cache;

	virtual void initHardware() const = 0;

	virtual void transmit(bool isData, byte val) const = 0;

	void configureInput(bool ac = true, bool screen_move = false) const;
	void configureFunction(bool interface8 = false, bool doubleline = true,
			bool font5x10 = false) const;

};

#endif /* DRV_HD44780_BASIC_H_ */
