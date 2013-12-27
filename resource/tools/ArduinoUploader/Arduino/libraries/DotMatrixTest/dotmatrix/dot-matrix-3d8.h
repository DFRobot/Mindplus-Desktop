/*
 *	dot-matrix-3d8.h
 *
 *  Created on: 2012-5-29
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DOTMATRIX_3D8_H_
#define DOTMATRIX_3D8_H_

#include "dot-matrix.h"

const uint8_t PROGMEM ROLL_INDEX[] =
{
		0, 1, 2, 3, 4, 5, 6,
		7, 15, 23, 31, 39, 47, 55,
		63, 62, 61, 60, 59, 58, 57,
		56,	48, 40, 32, 24, 16,	8,
		9, 	10, 11, 12, 13,
		14, 22, 30, 38, 46,
		54, 53, 52, 51, 50,
		49, 41, 33, 25, 17,
		18, 19, 20,
		21, 29, 37,
		45, 44, 43,
		42, 34, 26,
		27,
		28,
		36,
		35,
};

const uint8_t PROGMEM ROLL_LENGTH[] = {28,20,12,4};

const uint8_t PROGMEM ROLL_STEP[] = {0x7f, 0x5d, 0x2a, 0x08};

class DotMatrix3d8: public DotMatrix
{
public:
	DotMatrix3d8();
	virtual ~DotMatrix3d8();
	void setDot(byte x, byte y, byte z, bool on = true);

	enum Direction3D
	{
		Z_NEGA,
		Z_POSI,
		Y_NEGA,
		Y_POSI,
		X_NEGA,
		X_POSI,
	};

	void setMoveDirection(Direction3D direction);
	void rotate(byte index, bool recycle = true, bool clockwise = true);
	void rotateSync(bool recycle = true, bool clockwise = true);

private:

	static const byte BLOCK_EDGE_LENGTH = 8;
	static const byte BLOCK_COLUMN_COUNT = 64;

	byte convertCol(byte x, byte y);
};

#endif /* DOTMATRIX_3D8_H_ */
