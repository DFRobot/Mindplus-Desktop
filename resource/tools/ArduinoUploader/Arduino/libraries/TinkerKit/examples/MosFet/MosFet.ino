/*
 MosFet

 Turns on and off a T010111 LED Module connected to O0,
 when pressing a T010020 MosFet attached to I0.

 This example code is in the public domain.
 
 created in Dec 2011
 by Federico Vanzati
 
 This example code is in the public domain.
 */

// include the TinkerKit library
#include <TinkerKit.h>

TKButton btn(I0);  // creating the object 'led' that belongs to the 'TKLed' class 
		   // and giving the value to the desired output pin

TKMosFet mos(O0);  // creating the object 'mos' that belongs to the 'TKMosFet' class 
                   // and giving the value to the desired output pin

void setup() {
  // TinkerKit 'object' eliminate the need for pin declaration with pinMode()
}

void loop() 
{
  // check if the pushbutton is pressed
  
  if(button.get() == HIGH) {  // if it is, the button.state() is HIGH  
    mos.on();                 // turn MosFet on 
  }
  else{                       // if it is not, the button.state() is LOW
    mos.off();                // turn MosFet off
  }
}

