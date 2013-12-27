/*
NewSoftSerial.cpp - Multi-instance software serial library
Copyright (c) 2006 David A. Mellis.  All rights reserved.
Interrupt-driven receive and other improvements by ladyada
Tuning, circular buffer, derivation from class Print,
multi-instance support, porting to 8MHz processors by
Mikal Hart

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

The latest version of this library can always be found at
http://arduiniana.org.
*/

// When set, _DEBUG co-opts pins 11 and 13 for debugging with an
// oscilloscope or logic analyzer.  Beware: it also slightly modifies
// the bit times, so don't rely on it too much at high baud rates
#define _DEBUG 0

//
// Includes
//
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "WConstants.h"
#include "NewSoftSerial.h"

//
// Lookup table
//
typedef struct _DELAY_TABLE
{
  long baud;
  unsigned short rx_delay_centering;
  unsigned short rx_delay_intrabit;
  unsigned short rx_delay_stopbit;
  unsigned short tx_delay;
} DELAY_TABLE;

#if F_CPU == 16000000

static const DELAY_TABLE PROGMEM table[] =
{
//  baud    rxcntr   rxintra    rxstop    tx
  { 115200, 0,       0,         0,        8,    },
  { 57600,  /*7*/2,       /*25,*/24,        /*31,28*/25,       28,   },
  { 38400,  /*17*/8,      45,        /*51*/38,       48,   },
  { 31250,  23,      56,        62,       62,   },
  { 28800,  27,      64,        /*70*/66,       66,   },
  { 19200,  46,      102,       108,      108,  },
  { 14400,  68,      146,       152,      152,  },
  { 9600,   105,     220,       226,      226,  },
  { 4800,   224,     458,       464,      464,  },
  { 2400,   462,     934,       940,      940,  },
  { 1200,   926,     1862,      1868,     1868, },
  { 300,    3710,    7430,      7436,     7436, },
};

#elif F_CPU == 8000000

static const DELAY_TABLE table[] PROGMEM =
{
//  baud    rxcntr   rxintra    rxstop    tx
  { 57600,  0,      /*5*/5,       /*8*/3,      /*6*/8, },
  { 38400,  /*5*/1,      /*15*/16,      /*18*/16,     /*16*/18, },
  { 31250,  /*8*//*2*/3,      /*21*/23,      /*24, 23*/23,     24, },
  { 28800,  /*10*//*3*/4,     /*25*/26,      /*28*/24,     /*26*/28, },
  { 19200,  /*19*//*3,5*/5,     /*44,45*/45,      43,     47, },
  { 14400,  /*30*/8,     66,      /*69*/66,     69, },
  { 9600,   49,     103,     106,    106, },
  { 4800,   108,    222,     225,    225, },
  { 2400,   227,    460,     463,    463, },
  { 1200,   459,    924,     927,    927, },
  { 300,    1851,   3708,    3711,   3711, },
};

#else

#error This version of NewSoftSerial supports only 16 and 8MHz processors

#endif

//
// Statics
//
NewSoftSerial *NewSoftSerial::active_object = 0;
char NewSoftSerial::_receive_buffer[_NewSS_MAX_RX_BUFF];
volatile uint8_t NewSoftSerial::_receive_buffer_tail = 0;
volatile uint8_t NewSoftSerial::_receive_buffer_head = 0;

//
// Private methods
//

/* static */
void NewSoftSerial::tunedDelay(uint16_t delay) {
  uint8_t tmp=0;

  asm volatile("sbiw    %0, 0x01 \n\t"
    "ldi %1, 0xFF \n\t"
    "cpi %A0, 0xFF \n\t"
    "cpc %B0, %1 \n\t"
    "brne .-10 \n\t"
    : "+r" (delay), "+a" (tmp)
    : "0" (delay)
    );
}

// This function sets the current object as the "active"
// one and returns true if it replaces another
bool NewSoftSerial::activate(void)
{
  if (active_object != this)
  {
    _buffer_overflow = false;
    uint8_t oldSREG = SREG;
    cli();
    _receive_buffer_head = _receive_buffer_tail = 0;
    active_object = this;
    SREG = oldSREG;
    return true;
  }

  return false;
}

//
// The receive routine called by the interrupt handler
//
void NewSoftSerial::recv()
{

#if GCC_VERSION < 40302
// Work-around for avr-gcc 4.3.0 OSX version bug
// Preserve the registers that the compiler misses
// (courtesy of Arduino forum user *etracer*)
  asm volatile(
    "push r18 \n\t"
    "push r19 \n\t"
    "push r20 \n\t"
    "push r21 \n\t"
    "push r22 \n\t"
    "push r23 \n\t"
    "push r26 \n\t"
    "push r27 \n\t"
    ::);
#endif

  char i, d = 0;

  // If RX line is high, then we don't see any start bit
  // so interrupt is probably not for us
  if (!digitalRead(_receivePin))
  {
    // Wait approximately 1/2 of a bit width to "center" the sample
    tunedDelay(_rx_delay_centering);

    // Read each of the 8 bits
    for (i=0; i<8; i++)
    {
#if _DEBUG // for scope: bring pin 13 high
      PORTB |= _BV(5);
#endif
      tunedDelay(_rx_delay_intrabit);  // digitalread takes some time
#if _DEBUG // for scope: bring pin 13 low
      PORTB &= ~_BV(5);
#endif
      if (digitalRead(_receivePin))
        d |= (1 << i);
      else // else clause added to ensure function timing is ~balanced
        d &= ~(1 << i);
    }

    // skip the stop bit
    tunedDelay(_rx_delay_stopbit);

    // if buffer full, set the overflow flag and return
    if ((_receive_buffer_tail + 1) % _NewSS_MAX_RX_BUFF != _receive_buffer_head)
    {
      // save new data in buffer: tail points to where byte goes
      _receive_buffer[_receive_buffer_tail] = d; // save new byte
      _receive_buffer_tail = (_receive_buffer_tail + 1) % _NewSS_MAX_RX_BUFF;
    }
    else
    {
#if _DEBUG // for scope: bring pin 11 high: overflow indicator
      PORTB |= _BV(3);
#endif
      _buffer_overflow = true;
    }
  }

#if GCC_VERSION < 40302
// Work-around for avr-gcc 4.3.0 OSX version bug
// Restore the registers that the compiler misses
  asm volatile(
    "pop r27 \n\t"
    "pop r26 \n\t"
    "pop r23 \n\t"
    "pop r22 \n\t"
    "pop r21 \n\t"
    "pop r20 \n\t"
    "pop r19 \n\t"
    "pop r18 \n\t"
    ::);
#endif
}

//
// Interrupt handling
//

/* static */
inline void NewSoftSerial::handle_interrupts(int lopin, int hipin)
{
  if (active_object &&
    active_object->_receivePin >= lopin &&
    active_object->_receivePin <= hipin)
  {
    active_object->recv();
  }
}

ISR(PCINT0_vect)
{
  NewSoftSerial::handle_interrupts(8, 13);
}

ISR(PCINT1_vect)
{
  NewSoftSerial::handle_interrupts(14, 21);
}

ISR(PCINT2_vect)
{
  NewSoftSerial::handle_interrupts(0, 7);
}

//
// Constructor
//
NewSoftSerial::NewSoftSerial(uint8_t receivePin, uint8_t transmitPin) :
  _rx_delay_centering(0),
  _rx_delay_intrabit(0),
  _rx_delay_stopbit(0),
  _tx_delay(0),
  _buffer_overflow(false)
{
  setTX(transmitPin);
  setRX(receivePin);
}

//
// Public methods
//
void NewSoftSerial::setTX(uint8_t tx)
{
  _transmitPin = tx;
  pinMode(_transmitPin, OUTPUT);
  digitalWrite(_transmitPin, HIGH);
}

void NewSoftSerial::setRX(uint8_t rx)
{
  _receivePin = rx;
  pinMode(_receivePin, INPUT);
  digitalWrite(_receivePin, HIGH);  // pullup!
}

void NewSoftSerial::begin(long speed)
{
  _rx_delay_centering = _rx_delay_intrabit = _rx_delay_stopbit = _tx_delay = 0;

  for (unsigned i=0; i<sizeof(table)/sizeof(table[0]); ++i)
  {
    long baud = pgm_read_dword(&table[i].baud);
    if (baud == speed)
    {
      _rx_delay_centering = pgm_read_word(&table[i].rx_delay_centering);
      _rx_delay_intrabit = pgm_read_word(&table[i].rx_delay_intrabit);
      _rx_delay_stopbit = pgm_read_word(&table[i].rx_delay_stopbit);
      _tx_delay = pgm_read_word(&table[i].tx_delay);
      break;
    }
  }

  // Set up RX interrupts, but only if we have a valid RX baud rate
  if (_rx_delay_stopbit)
  {
    if (_receivePin < 8)
    {
      // a PIND pin, PCINT16-23
      PCICR |= _BV(2);
      PCMSK2 |= _BV(_receivePin);
    }
    else if (_receivePin <= 13)
    {
      // a PINB pin, PCINT0-7
      PCICR |= _BV(0);
      PCMSK0 |= _BV(_receivePin-8);
    }
    else if (_receivePin <= 21)
    {
      // a PINC pin, PCINT8-14/15
      PCICR |= _BV(1);
      PCMSK1 |= _BV(_receivePin-14);
    }

    tunedDelay(_tx_delay); // if we were low this establishes the end
  }

#if _DEBUG
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
#endif
  activate();
}

// Read data from buffer
int NewSoftSerial::read(void)
{
  uint8_t d;

  // A newly activated object never has any rx data
  if (activate())
    return -1;

  // Empty buffer?
  if (_receive_buffer_head == _receive_buffer_tail)
    return -1;

  // Read from "head"
  d = _receive_buffer[_receive_buffer_head]; // grab next byte
  _receive_buffer_head = (_receive_buffer_head + 1) % _NewSS_MAX_RX_BUFF;
  return d;
}

uint8_t NewSoftSerial::available(void)
{
  // A newly activated object never has any rx data
  if (activate())
    return 0;

  return (_receive_buffer_tail + _NewSS_MAX_RX_BUFF - _receive_buffer_head) % _NewSS_MAX_RX_BUFF;
}

void NewSoftSerial::write(uint8_t b)
{
  if (_tx_delay == 0)
    return;

  activate();

  uint8_t oldSREG = SREG;
  cli();  // turn off interrupts for a clean txmit

  // Write the start bit
  digitalWrite(_transmitPin, LOW);
  tunedDelay(_tx_delay);

  // Write each of the 8 bits
  for (byte mask = 0x01; mask; mask <<= 1) {
    if (b & mask){ // choose bit
      digitalWrite(_transmitPin, HIGH); // send 1
    }
    else{
      digitalWrite(_transmitPin, LOW); // send 0
    }
    tunedDelay(_tx_delay);
  }

  digitalWrite(_transmitPin, HIGH);
  SREG = oldSREG; // turn interrupts back on. hooray!
  tunedDelay(_tx_delay);
}

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
void NewSoftSerial::enable_timer0(bool enable)
{
  if (enable)
#if defined(__AVR_ATmega8__)
  	sbi(TIMSK, TOIE0);
#else
	  sbi(TIMSK0, TOIE0);
#endif
  else
#if defined(__AVR_ATmega8__)
  	cbi(TIMSK, TOIE0);
#else
	  cbi(TIMSK0, TOIE0);
#endif
}

void NewSoftSerial::flush()
{
  if (active_object == this)
  {
    uint8_t oldSREG = SREG;
    cli();
    _receive_buffer_head = _receive_buffer_tail = 0;
    SREG = oldSREG;
  }
}

// MnetCS - Allocates memory for NewSoftSerial. Allows us to instance a new object
void* NewSoftSerial::operator new(unsigned int size) // Implicit NSS obj size
{
  void * p; // void pointer
  p = malloc(size); // Allocate memory
  memset((NewSoftSerial*)p,0,size); // Initalise memory

  //!!! CANT EXPLICITLY CALL CONSTRUCTOR - workaround by using an init() method
  return (NewSoftSerial*) p; // Cast blank region to NSS pointer
}

// MnetCS 2009 -  Unallocates the memory used by this instance
void NewSoftSerial::operator delete(void* p)
{
  NewSoftSerial* pNss =  (NewSoftSerial*) p; // Cast to NSS pointer
  pNss->~NewSoftSerial(); // Destruct the object

  free(p); // Free the memory
}
