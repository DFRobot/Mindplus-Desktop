/*
	vfont_7x3.h
	Customized ASCII 7x3 Font of Dot Matrix

	Created on: 2012-04-18
	Updated on: 2012-05-14

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */
#ifndef FONT_0703_H_
#define FONT_0703_H_

#include <avr/pgmspace.h>

#ifdef PROGMEM
  #undef PROGMEM
  #define PROGMEM __attribute__((section(".progmem.data")))
#endif

extern const uint8_t PROGMEM VFONT_7X3_STATE[];
extern const uint8_t PROGMEM VFONT_7X3[];

#endif /* FONT_0703_H_ */
