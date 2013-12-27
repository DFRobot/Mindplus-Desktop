/*
 *  Created on: 2012-7-24
 *	Author: Weihong Guan
 *	Blog: http://aguegu.net
 *	E-mail: weihong.guan@gmail.com
 *
 *	Code license: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 *	http://creativecommons.org/licenses/by-nc-sa/3.0/
 *	source host: https://github.com/aguegu/dot-matrix
 *
 */

#include "drv_74hc595_spi.h"

Drv74hc595Spi chip(SPI, 8, 9);

#define SECTION_COUNT 8
#define LED_PER_SECTION 8
#define BW_SPAN	0x1f

const byte led_count = SECTION_COUNT * LED_PER_SECTION;

byte *pCache;

void setup()
{
	chip.setOE(false);

	pCache = (byte *) malloc(sizeof(byte) * SECTION_COUNT);

}

void display(byte* pBW, byte times = 1, byte length = led_count)
{
	while (times--)
	{
		for (byte bw = 1; bw < BW_SPAN; bw++)
		{
			memset(pCache, 0, SECTION_COUNT);
			for (byte i = 0; i < length; i++)
			{
				if (bw <= pBW[i])
				{
					//	pCache[i >> 3] |= _BV(i&0x07);
					byte k = i >> 4;
					byte j = i & 0x0f;
					if (j < 8)
					{
						pCache[k << 1] |= _BV(7-j);
					}
					else if (j < 11)
						pCache[(k << 1) + 1] |= _BV(10-j);
					else
						pCache[(k << 1) + 1] |= _BV(j-8);
				}
			}

			chip.shiftSend(pCache, SECTION_COUNT);
			chip.shiftLatch();
		}
	}
}

void animationBreatheWhole(byte times = 0x10)
{
	byte *pBW;
	pBW = (byte *) malloc(sizeof(byte) * led_count);

	while (times--)
	{
		byte i = 1;
		while (i < BW_SPAN)
		{
			memset(pBW, i, led_count);
			display(pBW, 0x8);
			i++;
		}
		while (--i)
		{
			memset(pBW, i, led_count);
			display(pBW, 0x8);
		}
	}
	free(pBW);
}

void roll(byte * p, byte length, bool up, bool recycle, byte new_value = 0x00)
{
	if (up)
	{
		byte temp = recycle ? *(p + length - 1) : new_value;
		memmove(p + 1, p, length - 1);
		*p = temp;

	}
	else
	{
		byte tmp = recycle ? *p : new_value;
		memcpy(p, p + 1, length - 1);
		*(p + length - 1) = tmp;
	}

}

void animationMeteor(byte times = 0x10)
{
	byte *pBW = (byte *) malloc(sizeof(byte) * led_count);
	memset(pBW, 0, led_count);

	pBW[0] = 0x1f;
	pBW[1] = 0x08;
	for (byte i = 2; i < 0x0a; i++)
		pBW[i] = 1;

	while (times--)
	{
		roll(pBW, led_count, false, true);

		display(pBW, 0x10);
	}
	free(pBW);
}

void animationRiderBreathe(byte times = 0x10)
{
	byte *pBW = (byte *) malloc(sizeof(byte) * led_count);
	memset(pBW, 0, led_count);
	byte half_length = led_count >> 1;

	while (times--)
	{
		byte j = 0;
		while (j < half_length)
		{
			for (byte i = 0; i < half_length; i++)
			{
				pBW[half_length - 1 - i] = j > i ? (j - i) : 0;
				pBW[half_length + i] = j > i ? (j - i) : 0;
			}
			display(pBW, 0x10);
			j++;
		}
		while (j)
		{
			for (byte i = 0; i < half_length; i++)
			{
				pBW[half_length - 1 - i] = j > i ? (j - i) : 0;
				pBW[half_length + i] = j > i ? (j - i) : 0;
			}
			display(pBW, 0x10);
			j--;
		}
	}

	free(pBW);
}

void funDemoRider(byte times = 0x10)
{
	byte *pBW = (byte *) malloc(sizeof(byte) * led_count);
	memset(pBW, 0x01, led_count);
	pBW[0] = 0x1f;

	byte tmp[7] =
	{ 0x1a, 0x1a, 0x1a, 0x10, 0x08, 0x04, 0x02 };

	while (times--)
	{
		while (*(pBW) - 0x1f)
		{
			display(pBW, 0x08);
			roll(pBW, led_count, false, false, 0x01);
		}

		for (byte i = 0; i < 7; i++)
		{
			display(pBW, 0x08);
			roll(pBW, led_count, true, false, tmp[i]);
		}

		while (*(pBW + led_count - 1) - 0x1f)
		{
			display(pBW, 0x08);
			roll(pBW, led_count, true, false, 0x01);
		}

		for (byte i = 0; i < 7; i++)
		{
			display(pBW, 0x08);
			roll(pBW, led_count, false, false, tmp[i]);
		}

	}

	free(pBW);
}

void loop()
{
	animationBreatheWhole(0x04);
	animationMeteor(0xe0);
	animationRiderBreathe(0x08);
	funDemoRider(0x10);
}
