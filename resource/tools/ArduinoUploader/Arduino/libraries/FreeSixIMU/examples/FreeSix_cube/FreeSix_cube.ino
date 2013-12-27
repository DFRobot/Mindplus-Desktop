////////////////////////////////////////////////////////////
// Arduino firmware for use with FreeSixCube processing example
////////////////////////////////////////////////////////////

#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#define DEBUG
#ifdef DEBUG
#include "DebugUtils.h"
#endif

#include "CommunicationUtils.h"
#include "FreeSixIMU.h"
#include <Wire.h>


float q[4]; //hold q values

// Set the FreeIMU object
FreeSixIMU my3IMU = FreeSixIMU();

void setup() {
  Serial.begin(115200);
  Wire.begin();

  delay(5);
  my3IMU.init();
  delay(5);
}


void loop() { 
  my3IMU.getQ(q);
  serialPrintFloatArr(q, 4);
  Serial.println(""); //line break
 
  delay(60);
}
