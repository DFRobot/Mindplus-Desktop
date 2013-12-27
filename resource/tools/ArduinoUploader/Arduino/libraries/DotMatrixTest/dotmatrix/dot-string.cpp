/*
	DotString.cpp
	DotString Class for string printing with DotFont
	Created on: 2012-01-25
	Updated on: 2012-05-14

	library for Arduino for Dot Matrix Display, support driver by 74HC595 and 74HC138, ST7920, HD47780
	Author: Weihong Guan
	Blog: http://aguegu.net
	E-mail: weihong.guan@gmail.com
	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
	http://creativecommons.org/licenses/by-nc-sa/3.0/

	source host: https://github.com/aguegu/dot-matrix
 */
#include "dot-string.h"


DotString::DotString(DotFont & df, byte length, bool smart_width) :
		_df(df)
{
	_length = length;
	_smart_width = smart_width;
	_p = (char *) malloc(sizeof(char) * _length);
}

DotString::~DotString()
{
	free(_p);
}

void DotString::printf(const char *__fmt, ...)
{
	va_list ap;
	va_start(ap, __fmt);
	vsnprintf(_p, _length, __fmt, ap);
	va_end(ap);
}

void DotString::postAt(byte col, byte row)
{
	byte cursor;

	if (row > (_df.getVertical()? _df.getMaxRow() : _df.getMaxCol())) return;

	char *p = _p;

	cursor = col;
	while (*p)
	{
		_df.setChar(*p++);
		_df.postAt(cursor, row);
		cursor +=
				_smart_width ? _df.calcFontRealWidth() + 1 : _df.getWidth() + 1;
		if (cursor > (_df.getVertical()? _df.getMaxCol() : _df.getMaxRow()))
			break;
	}
}

void DotString::setChar(byte index, char chr)
{
	if (index >= _length) return;

	*(_p + index) = chr;
}

char * DotString::getString()
{
	return _p;
}
