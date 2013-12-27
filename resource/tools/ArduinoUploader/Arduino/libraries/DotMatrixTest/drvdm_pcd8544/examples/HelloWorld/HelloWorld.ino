#include "dot-matrix.h"
#include "dot-font.h"
#include "dot-string.h"
#include "drvdm_pcd8544.h"

#include "vfont_7x3.h"

DrvDmPcd8544 lcd(7, 6, 5, 4, 3);
DotMatrix dm = lcd.getDM();

void setup()
{
	pinMode(2, OUTPUT);
	digitalWrite(2, HIGH);	// background led

	lcd.init();

	dm.clear();
	dm.setMoveDirection(DotMatrix::BIT_IN_COL_POSI);

	DotFont df(dm);

	df.setPattern(VFONT_7X3, VFONT_7X3_STATE);
	DotString ds(df, 32, true);

	dm.setDot(0,0);

	ds.printf("Hello, world.");
	ds.postAt(2,0);

	df.setVertical(false);
	ds.printf("Font Display on Nokia");
	ds.postAt(0, 0);

	ds.printf("5110, driven by");
	ds.postAt(0, 9);

	ds.printf("Arduino.");
	ds.postAt(0, 18);

	ds.printf("aGuegu.net");
	ds.postAt(0, 27);

	ds.printf("%2d-%02d, %d", 5, 31, 2012);
	ds.postAt(0, 36);
}

void loop()
{
	lcd.putDM();

	dm.move(true);
	delay(200);
}

