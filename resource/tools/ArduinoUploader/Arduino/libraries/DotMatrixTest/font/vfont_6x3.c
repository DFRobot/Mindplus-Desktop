/*
	FONT_0603.c
	Customized Digital Font of 6x3 Dot Matrix

	Created on: 2012-03-03
	Updated on: 2012-05-14

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */

#include "vfont_6x3.h"

//const uint8_t PROGMEM ROW_INDEX[]  = {0x00, 0x40, 0x10, 0x50};

const uint8_t PROGMEM VFONT_6X3_STATE[] = {3, 6, 0x30, 10};

const uint8_t PROGMEM VFONT_6X3[] =
{
	// 0-9
	0x3f, 0x21, 0x3f,
	0x22, 0x3f, 0x20,
	0x3d, 0x25, 0x27,
	0x25, 0x25, 0x3f,

	0x1f, 0x10, 0x3f,
	0x27, 0x25, 0x3d,
	0x3f, 0x25, 0x3d,
	0x01, 0x01, 0x3f,

	0x3f, 0x25, 0x3f,
	0x2f, 0x29, 0x3f,
};
