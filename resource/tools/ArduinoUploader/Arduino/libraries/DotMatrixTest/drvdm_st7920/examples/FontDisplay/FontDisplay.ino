
#include "dot-matrix.h"
#include "drvdm_st7920.h"
#include "dot-font.h"
#include "dot-string.h"

#include "vfont_7x3.h"
#include "vfont_7x4.h"
#include "vfont_7x5.h"
#include "vfont_5x3.h"

DrvDmSt7920 dmd(7, 6, 5, 4, 3, 2);
DotMatrix dm = dmd.getDotMatrix();

void setup()
{
	dm.clear();

	DotFont df(dm);
	df.setPattern(VFONT_7X3, VFONT_7X3_STATE);
	df.setVertical(false);

	df.setPattern(VFONT_7X5, VFONT_7X5_STATE);
	for (byte i = 0; i < 10; i++)
	{
		DotString ds(df, 32, true);
		ds.printf("%d", i);
		ds.postAt(i * 6, 0);
	}

	df.setPattern(VFONT_5X3, VFONT_5X3_STATE);
	for (byte i = 0; i < 10; i++)
	{
		DotString ds(df, 32, true);
		ds.printf("%d", i);
		ds.postAt(i * 6, 8);
	}

	df.setPattern(VFONT_7X4, VFONT_7X4_STATE);
	df.setVertical();
	DotString hds(df, 32, true);
	hds.printf("%s", "Lcd12864 driven by dot-matrix");
	hds.postAt(18, 2);

	hds.printf("%s", "library for Arduino.");
	hds.postAt(18, 12);

	hds.printf("%s", "Developed by W.H. Guan");
	hds.postAt(40, 24);

	dm.setRect(32, 40, 108, 56);
	dm.setRect(34, 42, 106, 54, false);

	hds.printf("%s", "aGuegu.net");
	hds.postAt(40, 45);

	dm.setLine(20, 48, 30, 54);
	dm.setLine(16, 54, 30, 54);
	dm.setLine(20, 60, 30, 54);

	dm.setLine(120, 32, 110, 40);
	dm.setLine(126, 40, 110, 40);
	dm.setLine(120, 48, 110, 40);

	dmd.putDM();
}

void loop()
{

}
