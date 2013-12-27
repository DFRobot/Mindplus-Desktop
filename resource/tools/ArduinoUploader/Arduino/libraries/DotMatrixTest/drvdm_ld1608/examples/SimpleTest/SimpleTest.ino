#include "dot-matrix.h"
#include "drvdm_ld1608.h"
#include "dot-font.h"
#include "dot-string.h"

#include "vfont_7x3.h"

DrvDmLd1608 dmd;
DotMatrix dm = dmd.getDotMatrix();

void setup()
{
	dm.clear();
	DotFont df(dm);
	df.setPattern(VFONT_7X3, VFONT_7X3_STATE);
	DotString ds(df, 8, true);
	ds.printf("boxz");
	ds.postAt(0,1);
}

void loop()
{
	dmd.display();
}
