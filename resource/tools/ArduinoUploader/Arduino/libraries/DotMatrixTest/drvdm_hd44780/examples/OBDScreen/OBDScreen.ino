#include "drvdm_hd44780.h"
#include "dot-matrix.h"
#include "vfont_6x3.h"
#include "dot-font.h"
#include "dot-string.h"

DrvDmHd44780 lcd(7, 6, 5, 4, 3, 2, 4, 0x14);

DotMatrix dm = lcd.getDotMatrix();
DotFont df(dm);

void setup()
{
	lcd.init();
	df.setPattern(VFONT_6X3, VFONT_6X3_STATE);

	dm.clear();

	DotString ds(df, 8);
	ds.printf("%4d", 2360);
	ds.postAt(0x05, 0);
	lcd.convertDotMatrixToCache();

	lcd.printf(0x28, "THR.%d%% SPD.%3d km/h", 47, 107);
	lcd.printf(0x3c, "CLD.%d%% TMP.%2d/%2d %cC", 62, 90, 58, 0xdf);
	lcd.printf(0x00, "RPM.");
	lcd.putCache();
}

void loop()
{

}