#include "DotMatrixTest.h"

#include "Driver_HD44780.h"
#include "DotMatrix.h"
#include "Font0603.h"
#include "DotFont.h"
#include "DotString.h"

HD44780 lcd(8, 9, 10, 11, 12, 13, 4);
DotMatrix dm = lcd.getDotMatrix();
DotFont df(dm);

void setup()
{
	lcd.init();
	df.setPattern(FONT_0603, FONT_0603_STATE);

	dm.clear();

}

void loop()
{
	static int i = 0;

	dm.clear();

	DotString ds(df, 8);
	ds.printf("%4d", i);
	ds.postAt(0, 3);
	lcd.convertDotMatrixToCache();
	lcd.putCache();
	i++;

	delay(100);
}
