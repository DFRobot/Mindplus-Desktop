/*
 *  ctldm_3d8.h
 *
 *  Created on: 2012-7-3
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef CTL_DM_3D8_H_
#define CTL_DM_3D8_H_

#include "ctl_3d8.h"
#include "dot-matrix-3d8.h"
#include "byte-reverse.h"

class CtlDm3d8: public Ctl3d8
{
public:
	CtlDm3d8(DotMatrix3d8 & dm, HardwareSerial & sp, unsigned long baud_rate =
			57600);
	virtual ~CtlDm3d8();

	void putDM();
	void putDMrevZ();
	void putReverseDM();

private:
	DotMatrix & _dm;
};

#endif /* CTL_DM_3D8_H_ */
