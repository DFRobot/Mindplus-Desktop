#include "dot-matrix.h"
#include "drvdm_st7920.h"

DrvDmSt7920 dmd(7, 6, 5, 4, 3, 2);
DotMatrix dm = dmd.getDotMatrix();

volatile bool completed = false;

void setup()
{
	Serial.begin(115200);
	dm.clear();
	dmd.putDM();
}

void loop()
{
	if (completed)
	{
		dmd.putDM();
		completed = false;
	}
}

void serialEvent()
{
	static int index = 0;
	byte data = Serial.read();

	if (index == 0 && data == 0xf3)
	{
		index = 1;
	}
	else if (index)
	{
		if (index >= 1024)
		{
			index = 0;
			completed = true;
		}
		else
		{
			dm.setByte(index++ - 1, data);
		}
	}
}
