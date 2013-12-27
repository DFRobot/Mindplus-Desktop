/*
 *	drvdm_pcd8544.h
 *	DrvPcd8544Dm Class for dot-matrix printing on liquid crystal display driven by PCD8544, namely Nokia 8544
 *	Created on: 2012-05-30
 *
 *	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DRV_DM_PCD8544_H_
#define DRV_DM_PCD8544_H_

#include "Arduino.h"
#include "dot-matrix.h"
#include "drv_pcd8544.h"

#define COMMAND	false
#define DATA	true

class DrvDmPcd8544: public DrvPcd8544
{
public:

	DrvDmPcd8544(uint8_t pin_sce, uint8_t pin_rst, uint8_t pin_dc, uint8_t pin_din, uint8_t pin_sclk);
	virtual ~DrvDmPcd8544();

	void putDM();
	DotMatrix & getDM();

private:
	DotMatrix _dm;
};

#endif /* DRV_DM_PCD8544_H_ */
