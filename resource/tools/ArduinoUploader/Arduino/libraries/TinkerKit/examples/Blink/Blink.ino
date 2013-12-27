/*
  based on Blink, Arduino's "Hello World!"
  Turns on an LED on for one second, then off for one second, repeatedly.
  The Tinkerkit Led Modules (T010110-7) is hooked up on O0

  created in Dec 2011
  by Federico Vanzati

  This example code is in the public domain.
 */
 
// include the TinkerKit library
#include <TinkerKit.h>

TKLed led(O0);	// creating the object 'led' that belongs to the 'TKLed' class 
		// and giving the value to the desired output pin

void setup() {
// TinkerKit 'object' eliminate the need for pin declaration with pinMode()
}

void loop() 
{
  led.on();       // set the LED on
  delay(1000);    // wait for a second
  led.off();      // set the LED off
  delay(1000);    // wait for a second
}
