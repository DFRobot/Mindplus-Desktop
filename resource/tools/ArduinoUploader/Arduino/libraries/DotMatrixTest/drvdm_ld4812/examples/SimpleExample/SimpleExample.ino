#include "drvdm_ld4812.h"
#include "dot-matrix.h"
#include "dot-font.h"
#include "dot-string.h"

#include "vfont_7x3.h"

DrvDmLd4812 dmd(9, 8, 7, 6, 5);
DotMatrix dm = dmd.getDotMatrix();

void setup()
{
	dm.clear(0x00);
	DotFont df(dm);
	df.setPattern(VFONT_7X3, VFONT_7X3_STATE);
	DotString ds(df, 16, true);
	ds.printf("aGuegu.net");
	dm.setRect(0, 0, 47, 11);
	dm.setRect(1, 1, 46, 10, false);

	ds.postAt(4, 3);
}

void loop()
{
	dmd.display();
}
