/*
AudioAnalyzer.cpp - Library for audio spectrum analyzer.
Created by Lauren Pan,Dec 5, 2012.
E-Mail: Lauren.pan@dfrobot.com

Version 1.3

Log:
2012.12.05
Improve the code to make it compatible with the Arduino IDE 1.0 or later

2010.11.06
Add optional analog pin
*/

#ifndef AudioAnalyzer_h
#define AudioAnalyzer_h
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define Maxband 7


class Analyzer{
public:
	Analyzer();
	Analyzer(int,int,int);
	void Init();
	void ReadFreq(int *);

private:
	int _DCPin;
	int _StrobePin;
	int _RSTPin;
	void RstModule();
	unsigned long _TimepointSt;
	unsigned long _TimepointNow;
};

#endif