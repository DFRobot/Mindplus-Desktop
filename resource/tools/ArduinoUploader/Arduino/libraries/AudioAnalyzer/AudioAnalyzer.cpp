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

#include "AudioAnalyzer.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/**************************** Init Analyzer connecter Pin ****************************/
Analyzer::Analyzer(void)
{
	_StrobePin = 4;
	_RSTPin = 5;
	_DCPin = 0;
}

Analyzer::Analyzer(int StrobePin,int RstPin,int AnalogPin)
{
	_StrobePin = StrobePin;
	_RSTPin = RstPin;
	_DCPin = AnalogPin;
}

void Analyzer::Init()
{
	pinMode(_StrobePin,OUTPUT);
	pinMode(_RSTPin,OUTPUT);
	RstModule();
}
/**************************** Reset analyzer module ****************************/
void Analyzer::RstModule()
{
	digitalWrite(_StrobePin,LOW);
	digitalWrite(_RSTPin,HIGH);
	digitalWrite(_StrobePin,HIGH);
	digitalWrite(_StrobePin,LOW);
	digitalWrite(_RSTPin,LOW);
	delayMicroseconds(72);  
}

/**************************** Read DC out value ****************************/
void Analyzer::ReadFreq(int *value)
{
	static boolean RstState = false;
	if(!RstState)
	{
		_TimepointSt = millis();
		RstState = true;
	}
	else
	{
		_TimepointNow = millis();
		if(_TimepointNow - _TimepointSt > 3000)
		{
			RstModule();
			RstState = false;
			//Serial.println("Rst");
		}
	}

	for(byte band = 0;band<Maxband;band++)
	{
		delayMicroseconds(10);
		value[band] = analogRead(_DCPin);
		delayMicroseconds(50);
		digitalWrite(_StrobePin,HIGH);
		delayMicroseconds(18);
		digitalWrite(_StrobePin,LOW);
	}  
}