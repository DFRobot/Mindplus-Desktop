/*
 * ctldm_3d8.cpp
 *
 *  Created on: 2012-7-3
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 *
 */

#include "ctldm_3d8.h"

CtlDm3d8::CtlDm3d8(DotMatrix3d8 & dm, HardwareSerial & sp,
		unsigned long baud_rate) :
		Ctl3d8(sp, baud_rate, dm.countBytes()), _dm(dm)
{

}

CtlDm3d8::~CtlDm3d8()
{

}

void CtlDm3d8::putDM()
{
	this->sendBatch(_dm.output(), _length);
}

void CtlDm3d8::putDMrevZ()
{
	_sp.write(0xf2);
	byte *p = _dm.output();
	for (byte i = _length; i--;)
		_sp.write(reverseByte(*p++));
}

void CtlDm3d8::putReverseDM()
{
	_sp.write(0xf2);
	byte *p = _dm.output();
	for (byte i = _length; i--;)
		_sp.write(~(*p++));
}
