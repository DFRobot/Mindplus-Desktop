#include "drv_hd44780_i2c.h"

DrvHd44780I2c lcd(0x20 + 7);

void setup()
{
	lcd.init();
}

void loop()
{
	static word val = 0;
	lcd.printf("Hello, world.");
	lcd.printf(0x18, "%8d", val);
	lcd.putCache();

	val++;
	delay(200);
}