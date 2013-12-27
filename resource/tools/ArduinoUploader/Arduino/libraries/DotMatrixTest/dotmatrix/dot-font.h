/*
	DotFont.h
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

#ifndef DOTFONT_H_
#define DOTFONT_H_
#include "Arduino.h"
#include "dot-matrix.h"

class DotFont
{
public:

	DotFont(DotMatrix & dm);
	virtual ~DotFont();

	void setPattern(const uint8_t * pattern, const uint8_t * pattern_state);
	void setChar(const char chr);
	void setVertical(const boolean vertial = true);
	void postAt(const byte col, const byte row);
	void clear(const bool on = false) const;

	byte calcFontRealWidth() const;
	byte getWidth() const;
	byte getHeight() const;
	boolean getVertical() const;
	byte getMaxCol() const;
	byte getMaxRow() const;

private:

	void print() const;
	void printH() const;
	void printV() const;

	DotMatrix & _dm;
	const uint8_t *_pattern;
	byte _unit_width;
	byte _unit_height;
	byte _pattern_indent;
	byte _pattern_length;

	byte _col;
	byte _row;
	byte _index;
	boolean _vertical;
	word _indent;
};

#endif /* DOTFONT_H_ */
