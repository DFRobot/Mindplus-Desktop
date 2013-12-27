/*
 * dot-pattern.h
 *
 *  Created on: 2012-7-1
 *      Author: Agu
 */

#ifndef DOTPATTERN_H_
#define DOTPATTERN_H_

#include "Arduino.h"
#include "dot-matrix.h"

class DotPattern
{
public:
	DotPattern(DotMatrix & dm);
	virtual ~DotPattern();
	void setPattern(uint8_t * pattern, int length, byte byte_in_row);
	void postAt(byte col, byte row);

private:
	DotMatrix & _dm;
	byte _byte_in_row;
	byte _row_count;

	int _length;
	uint8_t *_pattern;
	void print();
};

#endif /* DOTPATTERN_H_ */
