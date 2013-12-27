/*
 *	dot-matrix-3d8.cpp
 *
 *  Created on: 2012-05-29
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#include "dot-matrix-3d8.h"

DotMatrix3d8::DotMatrix3d8() :
		DotMatrix(BLOCK_COLUMN_COUNT, BLOCK_EDGE_LENGTH)
{

}

DotMatrix3d8::~DotMatrix3d8()
{
}

void DotMatrix3d8::setDot(byte x, byte y, byte z, bool on)
{
	if (y >= BLOCK_EDGE_LENGTH || z >= BLOCK_EDGE_LENGTH)
		return;

	byte col = this->convertCol(x, z);
	this->DotMatrix::setDot(col, y, on);
}

byte DotMatrix3d8::convertCol(byte x, byte z)
{
	return ((x << 3) + z);
}

void DotMatrix3d8::setMoveDirection(Direction3D d)
{
	switch (d)
	{
	case Z_NEGA:
		_funMoveDirection = &DotMatrix3d8::moveBitInByteNega;
		break;
	case Z_POSI:
		_funMoveDirection = &DotMatrix3d8::moveBitInBytePosi;
		break;
	case Y_NEGA:
		_funMoveDirection = &DotMatrix3d8::moveBitInRowNega;
		break;
	case Y_POSI:
		_funMoveDirection = &DotMatrix3d8::moveBitInRowPosi;
		break;
	case X_NEGA:
		_funMoveDirection = &DotMatrix3d8::moveByteInColNega;
		break;
	case X_POSI:
		_funMoveDirection = &DotMatrix3d8::moveByteInColPosi;
		break;
	}
}

void DotMatrix3d8::rotate(byte index, bool recycle, bool clockwise)
{
	if (index > 3)
		return;

	byte length = pgm_read_byte_near(ROLL_LENGTH+index);
	byte indent = 0;
	for (byte i = 0; i < index; i++)
	{
		indent += pgm_read_byte_near(ROLL_LENGTH+i);
	}

	if (clockwise)
	{
		byte temp =
				recycle ?
						this->getByte(pgm_read_byte_near(ROLL_INDEX+indent)) :
						0x00;
		for (byte i = 1; i < length; i++)
		{
			this->setByte(pgm_read_byte_near(ROLL_INDEX+indent+i-1),
					this->getByte(pgm_read_byte_near(ROLL_INDEX+indent+i)));
		}
		this->setByte(pgm_read_byte_near(ROLL_INDEX+indent+length-1), temp);
	}
	else
	{
		byte temp =
				recycle ?
						this->getByte(
								pgm_read_byte_near(ROLL_INDEX+indent+length-1)) :
						0x00;
		for (byte i = length - 1; i; i--)
		{
			this->setByte(pgm_read_byte_near(ROLL_INDEX+indent+i),
					this->getByte(pgm_read_byte_near(ROLL_INDEX+indent+i-1)));
		}
		this->setByte(pgm_read_byte_near(ROLL_INDEX+indent), temp);
	}

}

void DotMatrix3d8::rotateSync(bool recycle, bool clockwise)
{
	static byte step = 0;
	for (byte i = 0; i < 4; i++)
	{
		if (pgm_read_byte_near(ROLL_STEP+i) & _BV(step))
			this->rotate(i, recycle, clockwise);
	}
	if (++step == 7)
		step = 0;
}

