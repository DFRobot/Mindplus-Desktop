/*
 * 	drvdm_3d8.h
 *
 *	A3D8 (3D8S) 8x8x8 cubic led display driver
 *
 *  Created on: 2012-6-14
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DRV_DM_3D8_H_
#define DRV_DM_3D8_H_

#include "dot-matrix.h"
#include "drvdm_tb62726x74hc138.h"

class DrvDm3d8: public DrvDmTb62726X74hc138
{
public:
	DrvDm3d8(DotMatrix & dm, uint8_t pin_din, uint8_t pin_clk,
			uint8_t pin_latch, uint8_t pin_en, uint8_t pin_rext, uint8_t pin_a2,
			uint8_t pin_a1, uint8_t pin_a0, uint16_t scan_speed = 0x600);

	virtual ~DrvDm3d8();

	enum ScanMode
	{
		XYZ = 0x00, YZX = 0x01, ZXY = 0x02, OLD = 0x03
	};

	void display(byte times = 0x01) const;

	void setMode(ScanMode mode = XYZ);

private:

	void (DrvDm3d8::*_setCol)(byte row) const;

	void setColxyz(byte row) const;
	void setColzxy(byte row) const;
	void setColyzx(byte row) const;
};

#endif /* DRV_DM_3D8_H_ */
