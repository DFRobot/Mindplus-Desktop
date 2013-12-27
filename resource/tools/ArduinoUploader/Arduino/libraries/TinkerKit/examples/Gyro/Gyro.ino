/*
 Gyro

 Reads two analog input pins; a T000064 Gyro Module with the x-axis connected to I0 pin
 the y-axis connected to the I1 pin and prints the results to the serial monitor.

 created on Dec 2011
 by Federico Vanzati

 This example code is in the public domain.

 */

// include the TinkerKit library
#include <TinkerKit.h>

TKGyro gyro(I0, I1, TK_X4);  // creating the object 'gyro' that belongs to the 'TKGyro' class 
                       	     // and giving the values to the desired input pins
                             // using the 4x amplified module, insert the TK_4X costant.


void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  Serial.print("X raw: ");
  Serial.print(gyro.getXAxis());        // print x-axis analog value
  Serial.print("\trate: ");
  Serial.print(gyro.getXAxisRate());    // print the x-axis anguar rate in the range of -/+1500 °/s
  Serial.print("\t|\t Y raw: ");  
  Serial.print(gyro.getYAxis());        // print x-axis analog value
  Serial.print("\trate: ");
  Serial.println(gyro.getYAxisRate());  // print the x-axis anguar rate in the range of -/+1500 °/s
  
  delay(1000);
}


