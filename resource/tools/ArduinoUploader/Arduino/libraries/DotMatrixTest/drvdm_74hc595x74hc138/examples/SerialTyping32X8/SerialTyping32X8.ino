#include "drvdm_74hc595x74hc138.h"
#include "dot-matrix.h"
#include "dot-font.h"
#include "dot-string.h"
#include "vfont_7x3.h"

DotMatrix dm(32, 8);
DrvDm74hc595X74hc138 dmd(dm, 8, 9, 13, 12, 7, 6, 5, 4);
DotFont df(dm);
DotString ds(df, dm.countCol(), true);

extern HardwareSerial Serial;
byte index = 0;

void setup()
{
	dmd.setShiftMode(LSBFIRST);

	pinMode(10, OUTPUT);
	digitalWrite(10, HIGH);

	pinMode(9, OUTPUT);
	digitalWrite(9, LOW);

	dm.clear(0x00);
	dm.setDot(0,0);

	df.setPattern(VFONT_7X3, VFONT_7X3_STATE);
	ds.printf("Hi, world.");
	ds.postAt(0,0);

	Serial.begin(9600);
}

void loop()
{
	dmd.display();
	delayMicroseconds(0x200);
}

void serialEvent()
{

	while (Serial.available())
	{
		if (index < dm.countCol())
		{
			byte cData = Serial.read();

			ds.setChar(index, cData);
			index++;

			if (cData == 0x0A)
			{
				dm.clear();
				ds.setChar(index-1, 0);
				ds.postAt(0,0);
				Serial.println(ds.getString());
				index = 0;
			}
		}
	}
}
