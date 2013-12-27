/*
 * hpattern.h
 *
 *  Created on: 2012-7-1
 *      Author: Agu
 */

#ifndef H_PATTERN_H_
#define H_PATTERN_H_

#include <avr/pgmspace.h>

#ifdef PROGMEM
  #undef PROGMEM
  #define PROGMEM __attribute__((section(".progmem.data")))
#endif

extern const uint8_t PROGMEM H_PATTERN[] ;

#endif /* H_PATTERN_H_ */
