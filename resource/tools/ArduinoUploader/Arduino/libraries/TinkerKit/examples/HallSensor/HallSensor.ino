/*
 Hall Sensor

 The Hall Sensor [T000070] is connected to I0 and reacts
 to the magnetic field polarity changing its analog output.
 When there is no magnetic field the sensor read a value around 512,
 going to the north pole cause an increasing of the value while going to 
 south cause a decreasing of the value.
 Uses the result to light up a T010111 LED Module connected on O0.
 Also prints the value of the Hall Sensor to the serial monitor.

 created on 7 Dec 2010
 by Davide Gomba 
 modified on Dec 2011
 by Federico Vanzati

 This example code is in the public domain.
 */

// include the TinkerKit library
#include <TinkerKit.h>

TKHallSensor hs(I0);	// creating the object 'hs' that belongs to the 'TKHallSensor' class 
                        // and giving the value to the desired input pin

TKLed led(O0);		// creating the object 'led' that belongs to the 'TKLed' class 
			// and giving the value to the desired output pin

void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  // Read the analog value of the Hall Sensor and print on the serial monitor
  Serial.print("Hall Sensor Value = ");                      
  Serial.println( hs.get() );

  // with polarity() we can know if the magnetic field 
  // is going to NORTH or SOUTH without read the analog value
  if (hs.polarity() == NORTH) {
    led.on();
  }
  if (hs.polarity() == SOUTH) {
    led.off();
  }

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);  
}


