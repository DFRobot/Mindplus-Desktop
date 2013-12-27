/*
 DotMatrix.cpp
 DotMatrix Class for modeling on the Dot Matrix, providing methods like dot control, draw rectangle, line
 Created on: 2012-01-16
 Updated on: 2012-05-14

 library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 Author: Weihong Guan
 Blog: http://aguegu.net
 E-mail: weihong.guan@gmail.com
 Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 http://creativecommons.org/licenses/by-nc-sa/3.0/

 source host: https://github.com/aguegu/dot-matrix
 */

#include "dot-matrix.h"

DotMatrix::DotMatrix(byte colCount, byte rowCount)
{
	_col_count = colCount;
	_row_count = rowCount;

	_bytes_per_row = _col_count / 8;
	if (_col_count % 8)
		_bytes_per_row++;

	_bytes_length = _bytes_per_row * _row_count;

	_pScreen = (byte *) malloc(sizeof(byte) * (_bytes_length + 1));
	setMoveDirection(this->BYTE_IN_COL_POSI);
}

DotMatrix::~DotMatrix()
{
	free(_pScreen);
}

void DotMatrix::clear(byte c)
{
	memset(_pScreen, c, _bytes_length);
}

void DotMatrix::reverseDot(byte col, byte row)
{
	this->setDot(col, row, !getDot(col, row));
}

void DotMatrix::setDot(byte col, byte row, boolean b)
{
	word i = getIndex(col, row);

	writeHighBitInByte(*(_pScreen+i), col & 0x07, b);
}

void DotMatrix::setLine(byte cA, byte rA, byte cB, byte rB, bool on)
{
	byte cMin, cMax, rMin, rMax;

	cMin = min(cA, cB);
	cMin = max(cMin, 0);

	cMax = max(cA, cB);
	cMax = min(cMax, _col_count - 1);

	rMin = min(rA, rB);
	rMin = max(rMin, 0);

	rMax = max(rA, rB);
	rMax = min(rMax, _row_count - 1);

	if (cMax - cMin >= rMax - rMin)
	{
		for (byte c = cMin; c <= cMax; c++)
		{
			int d = 32767;
			for (byte r = rMin; r <= rMax; r++)
			{
				int k = abs((c - cA) * (rA - rB) - (r - rA) * (cA - cB));
				if (d > k)
					d = k;
			}

			for (byte r = rMin; r <= rMax; r++)
			{
				if (abs((c - cA) * (rA - rB) - (r - rA) * (cA - cB))
						== d)
					this->setDot(c, r, on);
			}
		}
	}
	else
	{
		for (byte r = rMin; r <= rMax; r++)
		{
			int d = 32767;
			for (byte c = cMin; c <= cMax; c++)
			{
				int k = abs((c - cA) * (rA - rB) - (r - rA) * (cA - cB));
				if (d > k)
					d = k;
			}

			for (byte c = cMin; c <= cMax; c++)
			{
				if (abs((c - cA) * (rA - rB) - (r - rA) * (cA - cB))
						== d)
					this->setDot(c, r, on);
			}
		}
	}
}

void DotMatrix::setRect(byte cA, byte rA, byte cB, byte rB, bool on)
{
	byte cMin, cMax, rMin, rMax;

	cMin = min(cA, cB);
	cMin = max(cMin, 0);

	cMax = max(cA, cB);
	cMax = min(cMax, this->_col_count - 1);

	rMin = min(rA, rB);
	rMin = max(rMin, 0);

	rMax = max(rA, rB);
	rMax = min(rMax, this->_row_count - 1);

	for (uint16_t c = cMin; c <= cMax; c++)
		for (uint16_t r = rMin; r <= rMax; r++)
		{
			this->setDot(c, r, on);
		}
}

word DotMatrix::getIndex(byte col, byte row) const
{
	word index = row * _bytes_per_row + (col >> 3);
	return index < _bytes_length ? index : 0;
}

byte DotMatrix::getDot(byte col, byte row) const
{
	word i = getIndex(col, row);
	return readHighBitInByte(_pScreen[i], col & 0x07);
}

byte * DotMatrix::output() const
{
	return _pScreen;
}

byte DotMatrix::countCol() const
{
	return _col_count;
}

byte DotMatrix::countRow() const
{
	return _row_count;
}

byte DotMatrix::countBytePerRow() const
{
	return _bytes_per_row;
}

word DotMatrix::countBytes() const
{
	return _bytes_length;
}

void DotMatrix::setByte(word index, byte value)
{
	if (index >= _bytes_length)
		return;
	_pScreen[index] = value;
}

void DotMatrix::putByte(byte col, byte row, byte value)
{
	word i = getIndex(col, row);
	byte j = col & 0x07;
	_pScreen[i] |= value >> j;
	_pScreen[i + 1] |= value << (8 - j);
}

byte DotMatrix::getByte(word index)
{
	return index >= _bytes_length ? 0 : _pScreen[index];
}

void DotMatrix::moveBitInColNega(bool recycle)
{
	byte *p = _pScreen;
	for (byte r = _row_count; r--;)
	{
		bool b0 = readHighBitInByte(*p, 0);
		for (byte i = _bytes_per_row - 1; i--;)
		{
			boolean b = readHighBitInByte(*(p+1), 0);
			*p <<= 1;
			writeLowBitInByte(*p, 0, b);
			p++;
		}

		*p <<= 1;
		if (recycle)
			writeLowBitInByte(*p, 0, b0);

		p++;
	}
}

void DotMatrix::moveBitInColPosi(bool recycle)
{
	byte *p = _pScreen + _bytes_per_row - 1;
	for (byte r = _row_count; r--;)
	{
		boolean b0 = readLowBitInByte(*p, 0);
		for (byte i = _bytes_per_row - 1; i--;)
		{
			boolean b = readLowBitInByte(*(p-1), 0);
			*p >>= 1;
			writeHighBitInByte(*p, 0, b);
			p--;
		}

		*p >>= 1;
		if (recycle)
			writeHighBitInByte(*p, 0, b0);

		p += _bytes_per_row + _bytes_per_row - 1;
	}
}

void DotMatrix::moveBitInRowNega(bool recycle)
{
	byte pTemp[_bytes_per_row];
	memcpy(pTemp, _pScreen, _bytes_per_row);

	memcpy(_pScreen, _pScreen + _bytes_per_row, _bytes_length - _bytes_per_row);

	recycle ?
			memcpy(_pScreen + _bytes_length - _bytes_per_row, pTemp,
					_bytes_per_row) :
			memset(_pScreen + _bytes_length - _bytes_per_row, 0x00,
					_bytes_per_row);
}

void DotMatrix::moveBitInRowPosi(bool recycle)
{
	byte pTemp[_bytes_per_row];
	memcpy(pTemp, _pScreen + _bytes_length - _bytes_per_row, _bytes_per_row);

	memmove(_pScreen + _bytes_per_row, _pScreen,
			_bytes_length - _bytes_per_row);

	recycle ?
			memcpy(_pScreen, pTemp, _bytes_per_row) :
			memset(_pScreen, 0x00, _bytes_per_row);
}

void DotMatrix::moveByteInColNega(bool recycle)
{
	byte * p = _pScreen;
	for (byte r = _row_count; r--;)
	{
		byte temp = recycle ? *p : 0x00;
		memcpy(p, p + 1, _bytes_per_row - 1);

		p += _bytes_per_row;
		*(p - 1) = temp;
	}
}

void DotMatrix::moveByteInColPosi(bool recycle)
{
	byte *p = _pScreen;
	for (byte r = _row_count; r--;)
	{
		byte temp = recycle ? *(p + _bytes_per_row - 1) : 0x00;
		memmove(p + 1, p, _bytes_per_row - 1);
		*p = temp;
		p += _bytes_per_row;
	}
}

void DotMatrix::moveBitInByteNega(bool recycle)
{
	byte *p = _pScreen;
	for (word index = _bytes_length; index--; p++)
	{
		bool temp = *p & 0x80;
		*p <<= 1;
		if (recycle && temp)
			*p |= 0x01;
	}
}

void DotMatrix::moveBitInBytePosi(bool recycle)
{
	byte *p = _pScreen;
	for (word index = _bytes_length; index--; p++)
	{
		bool temp = *p & 0x01;
		*p >>= 1;
		if (recycle && temp)
			*p |= 0x80;
	}
}

void DotMatrix::setMoveDirection(Direction d)
{
	switch (d)
	{
	case BIT_IN_COL_NEGA:
		_funMoveDirection = &DotMatrix::moveBitInColNega;
		break;
	case BIT_IN_COL_POSI:
		_funMoveDirection = &DotMatrix::moveBitInColPosi;
		break;
	case BIT_IN_ROW_NEGA:
		_funMoveDirection = &DotMatrix::moveBitInRowNega;
		break;
	case BIT_IN_ROW_POSI:
		_funMoveDirection = &DotMatrix::moveBitInRowPosi;
		break;
	case BYTE_IN_COL_NEGA:
		_funMoveDirection = &DotMatrix::moveByteInColNega;
		break;
	case BYTE_IN_COL_POSI:
		_funMoveDirection = &DotMatrix::moveByteInColPosi;
		break;
	case BIT_IN_BYTE_NEGA:
		_funMoveDirection = &DotMatrix::moveBitInByteNega;
		break;
	case BIT_IN_BYTE_POSI:
		_funMoveDirection = &DotMatrix::moveBitInBytePosi;
		break;
	}
}

void DotMatrix::move(bool recycle)
{
	(this->*_funMoveDirection)(recycle);
}

byte DotMatrix::orValue()
{
	byte c = 0x00;
	for (word i = _bytes_length; i--;)
	{
		c |= _pScreen[i];
	}

	return c;
}

byte DotMatrix::andValue()
{
	byte c = 0xff;
	for (word i = _bytes_length; i--;)
	{
		c &= _pScreen[i];
	}

	return c;
}
