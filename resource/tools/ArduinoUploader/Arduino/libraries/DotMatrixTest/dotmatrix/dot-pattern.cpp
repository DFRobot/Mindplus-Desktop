/*
 * dot-pattern.cpp
 *
 *  Created on: 2012-7-1
 *      Author: Agu
 */

#include "dot-pattern.h"

DotPattern::DotPattern(DotMatrix & dm) :
		_dm(dm)
{

}

DotPattern::~DotPattern()
{

}

void DotPattern::print()
{

}

void DotPattern::postAt(byte col, byte row)
{
	//this->print();
	uint8_t *p = _pattern;
	for (byte r = _row_count; r--;)
	{
		for (byte cl = col, c = _byte_in_row; c--;)
		{
			_dm.putByte(cl, row, *(p++));
			cl += 8;
		}
		row++;
	}
}

void DotPattern::setPattern(uint8_t * pattern, int length, byte byte_in_row)
{
	_pattern = pattern;
	_length = length;
	_byte_in_row = byte_in_row;
	_row_count = _length / byte_in_row;
}
