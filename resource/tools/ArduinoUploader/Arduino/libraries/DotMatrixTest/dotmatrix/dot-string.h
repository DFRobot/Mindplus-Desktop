/*
	DotString.h
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

#ifndef DOTSTRING_H_
#define DOTSTRING_H_

#include "dot-matrix.h"
#include "dot-font.h"

class DotString
{
public:
	DotString(DotFont & df, byte length, bool smart_width = false);
	virtual ~DotString();

	void postAt(byte col, byte row);
	void printf(const char *__fmt, ...);
	void setChar(byte index, char chr);
	char * getString();
private:
	DotFont & _df;
	char *_p;
	boolean _smart_width;
	byte _length;
};

#endif /* DOTSTRING_H_ */
