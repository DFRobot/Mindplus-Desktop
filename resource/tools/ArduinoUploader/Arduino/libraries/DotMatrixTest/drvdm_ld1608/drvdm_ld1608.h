/*
 * drvdm_ld1608.h
 *
 *  Created on: 2012-8-31
 *      Author: agu
 */

#ifndef DRV_DM_LD1608_H_
#define DRV_DM_LD1608_H_

#include "Arduino.h"
#include "drv_74hc595_spi.h"
#include "dot-matrix.h"

class DrvDmLd1608
{
public:
	DrvDmLd1608();
	virtual ~DrvDmLd1608();
	void display(byte times = 1);
	void setScanSpan(uint16_t scan_span = 0x800);
	DotMatrix & getDotMatrix();
private:
	DotMatrix _dm;
	Drv74hc595Spi chip;
	uint16_t _scan_span;
};

#endif /* DRV_DM_LD1608_H_ */
