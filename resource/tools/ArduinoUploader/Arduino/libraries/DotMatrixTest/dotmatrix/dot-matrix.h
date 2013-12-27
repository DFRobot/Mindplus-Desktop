/*
 DotMatrix.h
 DotMatrix Class for modeling on the Dot Matrix, providing methods like dot control, draw rectangle, line
 Created on: 2012-01-16

 library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 Author: Weihong Guan
 Blog: http://aguegu.net
 E-mail: weihong.guan@gmail.com
 Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 http://creativecommons.org/licenses/by-nc-sa/3.0/

 source host: https://github.com/aguegu/dot-matrix
 */

#ifndef DOTMATRIX_H_
#define DOTMATRIX_H_

#include "Arduino.h"
#include "bit_op.h"

class DotMatrix
{
public:
	DotMatrix(byte col_count, byte row_count);
	virtual ~DotMatrix();

	void clear(byte c = 0x00);
	void setByte(word index, byte value);
	void putByte(byte col, byte row, byte value);
	byte getByte(word index);

	void reverseDot(byte col, byte row);
	void setDot(byte col, byte row, boolean b = true);
	byte getDot(byte col, byte row) const;

	void setLine(byte cA, byte rA, byte cB, byte rB, bool on = true);
	void setRect(byte cA, byte rA, byte cB, byte rB, bool on = true);

	enum Direction
	{
		BIT_IN_COL_NEGA,
		BIT_IN_COL_POSI,
		BIT_IN_ROW_NEGA,
		BIT_IN_ROW_POSI,
		BYTE_IN_COL_NEGA,
		BYTE_IN_COL_POSI,
		BIT_IN_BYTE_NEGA,
		BIT_IN_BYTE_POSI
	};

	void move(bool recycle = false);
	void setMoveDirection(Direction d);

	byte * output() const;
	byte countCol() const;
	byte countRow() const;
	word countBytes() const;
	byte countBytePerRow() const;

	byte orValue();
	byte andValue();

protected:

	void moveBitInColNega(bool recycle);
	void moveBitInColPosi(bool recycle);
	void moveBitInRowNega(bool recycle);
	void moveBitInRowPosi(bool recycle);

	void moveByteInColNega(bool recycle);
	void moveByteInColPosi(bool recycle);

	void moveBitInByteNega(bool recycle);
	void moveBitInBytePosi(bool recycle);

	void (DotMatrix::*_funMoveDirection)(bool);

private:

	byte _col_count;
	byte _row_count;
	byte _bytes_per_row;
	word _bytes_length;

	byte * _pScreen;

	word getIndex(byte col, byte row) const;

};

#endif /* DOTMATRIX_H_ */
