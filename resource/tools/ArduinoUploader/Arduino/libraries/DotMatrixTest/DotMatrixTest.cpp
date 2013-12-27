/*
 * A3D8_Master_SPI.cpp
 *
 *  Created on: 2012-7-27
 *      Author: Agu
 */

#include "DotMatrixTest.h"
#include "dot-matrix-3d8.h"
#include "drvdm_3d8_spi.h"
#include "byte-reverse.h"

#define BYTE_LENGTH 64

DotMatrix3d8 dm;
DrvDm3d8Spi cube(dm, SPI, A3, 8, 9, 5, 4, 3);
byte * cache;

uint8_t led_top = 6;
uint8_t led_bottom = 7;

const uint8_t PROGMEM PATTERN_LOVE[] =
{ 0x00, 0x81, 0x81, 0xFF, // I
		0x38, 0xFC, 0xFE, 0x3F, //heart
		0x00, 0xFF, 0xFF, 0x01, // U
		};

const uint8_t PROGMEM PATTERN_ARROW[] =
{ 0x08, 0x14, 0x22, 0x77, 0x14, 0x14, 0x14, 0x14, 0x14, 0x1c, };


void setup()
{
	pinMode(led_top, OUTPUT);
	pinMode(led_bottom, OUTPUT);

	digitalWrite(led_top, HIGH);
	digitalWrite(led_bottom, HIGH);

	TCCR1B = (TCCR1B & 0xf8) | 0x02;
	cache = (byte *)malloc(sizeof(byte) * BYTE_LENGTH);
	dm.clear(0x00);
	cube.setBrightness(0xff);
}

void animationFlash(word k)
{
	byte value = k & 0x01 ? 0xff : 0x00;
	dm.clear(value);
}

void animationBreathe(word k)
{
	k = k % 0x80;
	byte brightness = k < 0x40 ? 0xff - (k << 2) : (k << 2) - 0xff;
	cube.setBrightness(brightness);
}

void animationFacetScan(word k)
{
	byte value = _BV(k%8);
	dm.clear(value);
}

void animationBlockScan(word k)
{
	k = k % 8;
	byte value = _BV(k+1) - 1;
	dm.clear(value);
}

void animationFlowZPosi(word k)
{
	dm.setMoveDirection(DotMatrix3d8::Z_POSI);
	dm.move(false);
	for (byte i = 0; i < random(4); i++)
	{
		byte x = random(8);
		byte y = random(8);
		dm.setDot(x, y, 0);
	}
}

void animationMoveSide(word k)
{
	if (k == 0)
		dm.clear(0x01);

	byte index;

	for (word i = dm.countBytes(); i;)
	{
		i--;
		byte temp = dm.getByte(i) & 0x81;
		dm.setByte(i, ((dm.getByte(i) & 0x7e) << 1) | temp);
	}

	if (bitRead(dm.orValue(),0) == true)
	{
		do
		{
			index = random(64);
		} while (dm.getByte(index) != 0x01);
		dm.setByte(index, 0x02);
	}
}

void animationMoveSideQuick(word k)
{
	k %= 16;

	if (k % 8 == 0)
	{
		for (byte i = 0; i < BYTE_LENGTH; i++)
		{
			cache[i] = _BV(random(8));
		}
	}

	if (k < 8)
		for (byte i = 0; i < BYTE_LENGTH; i++)
		{
			byte temp = dm.getByte(i);
			if (dm.getByte(i) < cache[i])
				dm.setByte(i, temp << 1);
		}
	else
	{
		for (byte i = 0; i < BYTE_LENGTH; i++)
		{
			byte temp = dm.getByte(i);
			if (dm.getByte(i) < 0x80)
				dm.setByte(i, temp << 1);
		}
	}
}

void animationWave2D(word k)
{
	k %= 16;
	byte value = k < 8 ? k : 15 - k;

	dm.setMoveDirection(DotMatrix3d8::Y_POSI);
	dm.move(false);

	dm.setByte(value, 0xff);
}

void animationWave3D(word k)
{
	k %= 16;
	byte value = k < 8 ? k : 15 - k;

	for (byte i = 0; i < 8; i++)
		cache[i] = dm.getByte(i);

	dm.setMoveDirection(DotMatrix3d8::Y_POSI);
	dm.move(false);

	for (byte i = 0; i < 8; i++)
		dm.setByte(i, cache[i]);

	for (byte i = 7; i; i--)
		dm.setByte(i, dm.getByte(i - 1));

	dm.setByte(0x00, _BV(value));
}

void animationWaveShake(word k)
{
	k %= 16;
	byte value = k < 8 ? k : 15 - k;

	dm.setMoveDirection(DotMatrix3d8::X_POSI);
	dm.move(false);
	dm.setLine(0, value, 7, 7 - value);
}

void animationWaveRotate(word k)
{
	k %= 28;
	dm.setMoveDirection(DotMatrix3d8::X_POSI);
	dm.move(false);

	byte temp = k % 7;
	cache[0] = 0;
	cache[1] = temp;
	cache[2] = 7;
	cache[3] = 7 - temp;

	byte i = k / 7;

	dm.setLine(cache[i % 4], cache[(i + 1) % 4], cache[(i + 2) % 4],
			cache[(i + 3) % 4]);

}

void animationDance(word k)
{
	if (k == 0)
	{
		cache[0] = 0;
		cache[1] = 0;
	}

	char x = cache[0];
	char y = cache[1];

	dm.setMoveDirection(DotMatrix3d8::Z_POSI);
	dm.move();

	char vx = random(3) - 1;
	char vy = random(3) - 1;

	x += vx;
	y += vy;

	if (x >= 8 || x < 0)
	{
		x -= vx + vx;
	}

	if (y >= 8 || y < 0)
	{
		y -= vy + vy;
	}

	cache[0] = x;
	cache[1] = y;

	dm.setDot(x, y, 0);
}

void animationRotateArrow(word k)
{
	k %= 28;
	dm.rotate(0, false, false);
	if (k < 10)
		dm.setByte(0, pgm_read_byte_near(PATTERN_ARROW+k));
}

void animationRotateLove(word k)
{
	k %= 28 * 6;

	if (k % 56 == 0)
	{
		for (byte i = 0; i < 4; i++)
		{
			byte value = reverseByte(
					pgm_read_byte_near(PATTERN_LOVE+(k/56)*4+i));
			dm.setByte(0x20 + i, value);
			dm.setByte(0x27 - i, value);
			dm.setByte(0x18 + i, value);
			dm.setByte(0x1f - i, value);
		}
	}

	dm.rotateSync(true, true);
}

void callAnimation(void (*p)(word), word span, word times, byte init_value,
		DrvDm3d8Spi::ScanMode mode)
{
	static word frame_id = 0;

	cube.setMode(mode);
	dm.clear(init_value);

	while (times--)
	{
		(*p)(frame_id++);
		cube.display(span);
	}
	frame_id = 0;
}

void callAnimationInModes(void (*p)(word), word span, word times,
		byte init_value)
{
	for (byte i = 0; i < 3; i++)
		callAnimation(p, span, times, init_value, (DrvDm3d8Spi::ScanMode) i);
}

void loop()
{

	callAnimation(animationFlash, 0x10, 0x08, 0x00, DrvDm3d8Spi::XYZ);
	callAnimation(animationBreathe, 0x01, 0xff * 2, 0xff, DrvDm3d8Spi::XYZ);
	callAnimationInModes(animationFacetScan, 0x08, 0x08, 0x00);
	callAnimationInModes(animationBlockScan, 0x08, 0x08, 0x00);
	callAnimationInModes(animationFlowZPosi, 0x04, 0x40, 0x00);

	callAnimationInModes(animationMoveSide, 0x04, 72, 0x00);
	callAnimationInModes(animationMoveSideQuick, 0x04, 0x10, 0x01);

	callAnimationInModes(animationWave2D, 0x04, 14 * 4, 0x00);

	callAnimation(animationWave3D, 0x02, 14 * 16, 0x00, DrvDm3d8Spi::ZXY);
	callAnimation(animationWaveShake, 0x02, 14 * 16, 0x00, DrvDm3d8Spi::XYZ);

	callAnimation(animationWaveRotate, 0x02, 14 * 8, 0x00, DrvDm3d8Spi::XYZ);
	callAnimation(animationWaveRotate, 0x02, 14 * 8, 0x00, DrvDm3d8Spi::YZX);

	callAnimation(animationDance, 0x02, 0x80, 0x00, DrvDm3d8Spi::ZXY);

	callAnimation(animationRotateArrow, 0x04, 28 * 3, 0x00, DrvDm3d8Spi::YZX);
	callAnimation(animationRotateArrow, 0x04, 28 * 3, 0x00, DrvDm3d8Spi::ZXY);

	callAnimation(animationRotateLove, 0x04, 28 * 6, 0x00, DrvDm3d8Spi::ZXY);

}

