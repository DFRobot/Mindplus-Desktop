/*
 *	ctl_3d8.cpp
 *	Basic A3D8 Controller Class for managing animation remotely on arduino to 3D8S 8x8x8 led cubic display
 *	Created on: 2012-07-03
 *
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#include "ctl_3d8.h"

Ctl3d8::Ctl3d8(HardwareSerial & sp, unsigned long baud_rate,
		byte length) :
		_sp(sp), _length(length)
{
	_sp.begin(baud_rate);
}

Ctl3d8::~Ctl3d8()
{

}

void Ctl3d8::sendGlobal(byte c)
{
	_sp.write(0xf0);
	_sp.write(c);
}

void Ctl3d8::sendColumn(byte col, byte value)
{
	_sp.write(0xf1);
	_sp.write(col);
	_sp.write(value);
}

void Ctl3d8::sendBatch(const byte *p, byte length)
{
	_sp.write(0xf2);
	_sp.Print::write(p, min(_length, length));
}

void Ctl3d8::sendMode(InputMode mode)
{
	_sp.write(0xf3);
	_sp.write((byte)mode);
}

void Ctl3d8::sendBrightness(byte brightness)
{
	_sp.write(0xf4);
	_sp.write(brightness);
}

void Ctl3d8::sendBgLed(byte bg_led_configure)
{
	_sp.write(0xf5);
	_sp.write(bg_led_configure);
}
