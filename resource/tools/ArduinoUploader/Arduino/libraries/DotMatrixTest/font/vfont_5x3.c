/*
	FONT_0503.c
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

#include "vfont_5x3.h"

const uint8_t PROGMEM VFONT_5X3_STATE[] = {3, 5, 0x30, 10};

const uint8_t PROGMEM VFONT_5X3[]  =
{
	0x1f, 0x11, 0x1f,	//0
	0x00, 0x1f, 0x00,	//1
	0x1d, 0x15, 0x17,	//2
	0x15, 0x15, 0x1f,	//3
	0x0f, 0x08, 0x1f,	//4
	0x17, 0x15, 0x1d,	//5
	0x1f, 0x15, 0x1d,	//6
	0x01, 0x01, 0x1f,	//7
	0x1f, 0x15, 0x1f,	//8
	0x17, 0x15, 0x1f,	//9
};


