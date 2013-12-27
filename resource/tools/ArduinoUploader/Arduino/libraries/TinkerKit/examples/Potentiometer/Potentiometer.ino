/*
 Analog input, analog output, serial output

 Reads an analog input pin, and T000140 Rotary Potetiometer Analog Sensor connected to I0, 
 and uses the result to set the brightness on a T010111 LED Module connected on O0.
 Also prints the results to the serial monitor.

 created 29 Dec. 2008
 Modified 4 Sep 2010
 by Tom Igoe
 modified 7 dec 2010
 by Davide Gomba
 modified on Ded 2011
 by Federico Vanzati

 This example code is in the public domain.

 */

#include <TinkerKit.h>

TKPotentiometer pot(I0);// creating the object 'button' that belongs to the 'TKButton' class 
                        // and giving the value to the desired input pin

TKLed led(O0);		// creating the object 'led' that belongs to the 'TKLed' class 
                        // and giving the value to the desired output pin

int brightnessValue = 0;        // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  brightnessValue = pot.get();            

  // set the led brightness
  led.brightness(brightnessValue);       

  // print the results to the serial monitor:
  Serial.print("brightness = " );                      
  Serial.println(brightnessValue);      


  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);                    
}
