/*
 Toggle Button

 Turns on and off a LED Module [T010111] connected to O0,
 when pressing a TinkerKit Push Button Module [T000180] attached to I0.
 With the toggle() method you can use the push button as a switch. 
 To each button press correspond a status change of the LED

 Created 1 Dec 2011
 by Federico Vanzati
 
 This example code is in the public domain.
 */

// include the TinkerKit library
#include <TinkerKit.h>


TKButton button(I0);              // creating the object 'tilt' that bleongs to the 'TKTiltSensor' class
                                  // and giving the value to the desired input pin

TKLed led(O0);                    // creating the object 'led' that belongs to the 'TKLed' class
                                  // and giving the value to the desired output pin

// variables will change as they take the current value of the sensor.
int toggleState = 0;              // variable for reading the pushbutton toggle status


void setup() {
// The 'objects' created above, eleminates the need for pinMode().
}

void loop(){
  
  // the toggle method trigger the istant when you press the button
  toggleState = button.toggle();  // for each pressure the toggleState variable change its state
                                  // and tkeep the value when you release the button

  if (toggleState == HIGH) {      // hold on the led if the toggleState is HIGH
    led.on();                     // turn LED on: 
  } else {                        // otherwise
    led.off();                    // turn LED off:
  }
}