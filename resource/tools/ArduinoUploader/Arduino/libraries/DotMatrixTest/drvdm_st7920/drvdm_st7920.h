/*
 drv_st7920_dm.h
 DrvSt7920Dm Class, for DotMatrix printing on liquid crystal display driven by ST7920, namely 12864
 Created on: 2012-06-01

 library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 Author: Weihong Guan
 Blog: http://aguegu.net
 E-mail: weihong.guan@gmail.com
 Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 http://creativecommons.org/licenses/by-nc-sa/3.0/

 source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DRV_DM_ST7920_H_
#define DRV_DM_ST7920_H_

#include "Arduino.h"
#include "drv_st7920.h"
#include "dot-matrix.h"

class DrvDmSt7920: public DrvSt7920
{

public:
	DrvDmSt7920(uint8_t pin_rs, uint8_t pin_en, uint8_t pin_d4, uint8_t pin_d5, uint8_t pin_d6, uint8_t pin_d7);
	virtual ~DrvDmSt7920();
	void putDM();
	DotMatrix & getDotMatrix();

private:
	DotMatrix _dm;
};

#endif /* DRV_ST7920_DM_H_ */
