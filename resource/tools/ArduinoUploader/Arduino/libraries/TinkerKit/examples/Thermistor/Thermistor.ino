/*
Thermistor

The TinkerKit Thermistor Module [T00020] is hooked up on I0.
Three values are displayed on the Serial Monitor every second:
- the value between 0 and 1023 that represent the Analog Input reading
- the temperature expressed in Celsius degrees
- the temperature expressed in Fahrenheit dedegrees

created 29 Nov 2011
by Federico Vanzati

This example code is in the public domain.
*/

// include the TinkerKit library
#include <TinkerKit.h>

TKThermistor therm(I0);       // creating the object 'therm' that belongs to the 'TKThermistor' class 
                              // and giving the value to the desired output pin

float C, F;		      // temperature readings are returned in float format

void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  C = therm.getCelsius();     	// Reading the temperature in Celsius degrees and store in the C variable
  F = therm.getFahrenheit();  	// Reading the temperature in Fahrenheit degrees and store in the F variable

  // Print the collected data in a row on the Serial Monitor
  Serial.print("Analog reading: \t");	// Reading the analog value from the thermistor
  Serial.print(therm.get());
  Serial.print("\tC: \t");
  Serial.print(C);
  Serial.print("\tF: \t");
  Serial.println(F);

  delay(1000);                // Wait one second before get another temperature reading
}
