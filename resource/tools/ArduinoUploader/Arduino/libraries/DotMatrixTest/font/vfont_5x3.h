/*
	FONT_0503.h
	Customized Digital Font of 5x3 Dot Matrix

	Created on: 2012-01-25
	Updated on: 2012-05-14

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef VFONT_5X3_H_
#define VFONT_5X3_H_

#include <avr/pgmspace.h>

#ifdef PROGMEM
  #undef PROGMEM
  #define PROGMEM __attribute__((section(".progmem.data")))
#endif

extern const uint8_t PROGMEM VFONT_5X3_STATE[] ;

extern const uint8_t PROGMEM VFONT_5X3[] ;



#endif /* VFONT_5X3_H_ */
