#include "dot-matrix-3d8.h"
#include "drvdm_3d8.h"

DotMatrix3d8 dm;
DrvDm3d8 cube(dm, 9, 10, 17, 8, 11, 5, 4, 3);

void setup()
{
	dm.clear(0x00);

	cube.setBrightness(0xff);

	for (byte i = 0; i < 8; i++)
		dm.setDot(i, i, 0, true);
}

void animationFacetScan(byte speed = 0x04)
{
	for (byte j = 0; j < 3; j++)
	{
		cube.setMode((DrvDm3d8::ScanMode) j);
		byte i = 0;
		while (i < 8)
		{
			dm.clear(0x00);
			dm.setRect(i * 8, 0, i * 8 + 7, 7);
			cube.display(speed);
			i++;
		}
		while (i)
		{
			i--;
			dm.clear(0x00);
			dm.setRect(i * 8, 0, i * 8 + 7, 7);
			cube.display(speed);
		}
	}
}

void animationFlow(word length = 0x40, byte speed = 0x04)
{
	word counter;
	for (byte j = 0; j < 3; j++)
	{
		cube.setMode((DrvDm3d8::ScanMode) j);
		counter = length;
		while (counter--)
		{
			for (byte i = 0; i < random(4); i++)
				dm.setDot(random(8), random(8), 7, true);
			cube.display(speed);
			dm.setMoveDirection(DotMatrix3d8::Z_NEGA);
			dm.move(false);
		}
	}
}

void loop()
{
	dm.clear(0xff);
	cube.display(0x80);
	dm.clear(0x00);
	cube.display(0x40);

	animationFacetScan();
	animationFlow();

}
