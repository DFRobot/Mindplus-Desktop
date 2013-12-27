/*
 Touch Sensor

 Turns on and off a T010111 LED Module connected to O0,
 when pressing a T000220 Touch Sensor attached to I0.

 created in Dec 2011
 by Federico Vanzati

 This example code is in the public domain.
 */

// include the TinkerKit library
#include <TinkerKit.h>

TKTouchSensor touch(I0);// creating the object 'touch' that belongs to the 'TKTouchSensor' class 
                        // and giving the value to the desired input pin

TKLed led(O0);		// creating the object 'led' that belongs to the 'TKLed' class 
                        // and giving the value to the desired output pin


void setup() {
// TinkerKit 'object' eliminate the need for pin declaration with pinMode()
}

void loop()
{
  // check if the touch sensor is pressed.
  // if it is, the touch.state() is HIGH:
  if (touch.get() == HIGH) {      
    led.on();     // turn LED on 
  } else {
    led.off();    // turn LED off
  }
}
