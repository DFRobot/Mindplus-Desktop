/*
 	vfont_8x3.c
	Customized Digital Font of 8x3 Dot Matrix

	Created on: 2012-05-14
	Updated on: 2012-05-14

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */

#include "vfont_8x3.h"

const uint8_t PROGMEM VFONT_8X3_STATE[] = {3, 8, 0x30, 10};

const uint8_t PROGMEM VFONT_8X3[]  =
{
	0xff, 0x81, 0xff,	//0
	0x82, 0xff, 0x80,	//1
	0xf9, 0x89, 0x8f,	//2
	0x89, 0x89, 0xff,	//3
	0x3f, 0x20, 0xff,	//4
	0x8f, 0x89, 0xf9,	//5
	0xff, 0x89, 0xf9,	//6
	0x01, 0x01, 0xff,	//7
	0xff, 0x89, 0xff,	//8
	0x9f, 0x91, 0xff,	//9
};



