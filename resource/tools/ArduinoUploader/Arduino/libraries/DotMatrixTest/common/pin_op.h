/*
 * PinWrite.h
 *
 *  Created on: 2012-7-9
 *      Author: Agu
 */

#ifndef PIN_OP

#define pinSet(pin)	*portOutputRegister(digitalPinToPort(pin)) |= digitalPinToBitMask(pin)
#define pinClear(pin)	*portOutputRegister(digitalPinToPort(pin)) &= ~digitalPinToBitMask(pin)
#define pinWrite(pin, val) ( (val) ? pinSet(pin) : pinClear(pin))
#define pinReverse(pin)	*portOutputRegister(digitalPinToPort(pin)) ^= digitalPinToBitMask(pin)

#endif
