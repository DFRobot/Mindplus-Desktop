/*
 DotFont.cpp
 DotFont Class for printing characters on DotMatrix
 Created on: 2012-01-22
 Updated on: 2012-05-14

 library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
 Author: Weihong Guan
 Blog: http://aguegu.net
 E-mail: weihong.guan@gmail.com
 Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 http://creativecommons.org/licenses/by-nc-sa/3.0/

 source host: https://github.com/aguegu/dot-matrix
 */

#include "dot-font.h"

DotFont::DotFont(DotMatrix & dm) :
		_dm(dm)
{
	_col = _row = _index = 0;
	_vertical = true;
}


byte DotFont::getWidth() const
{
	return _unit_width;
}

byte DotFont::getHeight() const
{
	return _unit_height;
}

boolean DotFont::getVertical() const
{
	return _vertical;
}

byte DotFont::getMaxCol() const
{
	return _dm.countCol() - 1;
}

byte DotFont::getMaxRow() const
{
	return _dm.countRow() - 1;
}


DotFont::~DotFont()
{
	// TODO Auto-generated destructor stub
}

void DotFont::setPattern(const uint8_t * pattern, const uint8_t * pattern_state)
{
	_pattern = pattern;
	_unit_width = pgm_read_byte_near(pattern_state);
	_unit_height = pgm_read_byte_near(pattern_state + 1);
	_pattern_indent = pgm_read_byte_near(pattern_state + 2);
	_pattern_length = pgm_read_byte_near(pattern_state + 3);
}

void DotFont::setChar(const char chr)
{
	if (chr < _pattern_indent || chr >= _pattern_indent + _pattern_length)
		_index = _pattern_length;
	else
		_index = chr - _pattern_indent;

	_indent = _index * _unit_width;
}

void DotFont::setVertical(const boolean vertical)
{
	_vertical = vertical;
}

void DotFont::postAt(const byte col, const byte row)
{
	_col = col;
	_row = row;
	this->print();
}

void DotFont::clear(const bool on) const
{
	if (_vertical)
		_dm.setRect(_col, _row, _col + _unit_width, _row + _unit_height, on);
	else
		_dm.setRect(_row, this->getMaxRow() - _col, _row + _unit_height,
				this->getMaxCol() - _col - _unit_width, on);
}

void DotFont::print() const
{
	if (_index == _pattern_length)
		this->clear(false);
	else
		_vertical ? printV() : printH();
}

void DotFont::printH() const
{
	for (byte c = 0; c < _unit_width; c++)
	{
		for (byte r = 0; r < _unit_height; r++)
		{
			if (boolean b =
					bitRead(pgm_read_byte_near(_pattern + _indent + c), r))
				_dm.setDot(_row + r, _dm.countRow() - _col - 1 - c, b);
		}
	}
}

void DotFont::printV() const
{
	for (byte c = 0; c < _unit_width && c + _col < _dm.countCol(); c++)
	{
		for (byte r = 0; r < _unit_height; r++)
		{
			if (boolean b =
					bitRead(pgm_read_byte_near(_pattern + _indent + c), r))
				_dm.setDot(_col + c, _row + r, b);
		}
	}
}

byte DotFont::calcFontRealWidth() const
{
	if (_index == _pattern_length)
		return _unit_width;

	byte i = _unit_width - 1;

	while (pgm_read_byte_near(_pattern + _indent + i) == 0 && i--)
		;

	return i + 1;
}

