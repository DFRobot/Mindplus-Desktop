// This example sends a Serial message every 250 milliseconds

#include <Metro.h> // Include the Metro library

Metro serialMetro = Metro(250);  // Instantiate an instance

void setup() {
  Serial.begin(115200); // Start the Serial communication
}

void loop() {

  if (serialMetro.check() == 1) { // check if the metro has passed it's interval .
  // Output all the analog readings seperated by a space character
    for (int i = 0; i < 6; i++ ) {
      Serial.print (analogRead( i) );
      Serial.print(32,BYTE);
    }
    // Terminate message with a linefeed and a carriage return
    Serial.print(13,BYTE);
    Serial.print(10,BYTE);
  }
}

