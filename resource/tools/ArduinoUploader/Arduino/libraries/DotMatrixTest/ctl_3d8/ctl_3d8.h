/*
 *	ctl_3d8.h
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

#ifndef CTL_3D8_H
#define CTL_3D8_H

#include "Arduino.h"

class Ctl3d8
{
public:

	enum InputMode
	{
		XYZ = 0x00, YZX = 0x01, ZXY = 0x02
	};

	Ctl3d8(HardwareSerial & sp, unsigned long baud_rate = 57600,
			byte length = 64);
	virtual ~Ctl3d8();
	void sendGlobal(byte c);
	void sendColumn(byte col, byte value);
	void sendBatch(const byte *p, byte length);
	void sendMode(InputMode mode = XYZ);
	void sendBrightness(byte brightness);
	void sendBgLed(byte bg_led_configure);

protected:

	HardwareSerial & _sp;
	const byte _length;

};

#endif /* CTL_3D8_H */
