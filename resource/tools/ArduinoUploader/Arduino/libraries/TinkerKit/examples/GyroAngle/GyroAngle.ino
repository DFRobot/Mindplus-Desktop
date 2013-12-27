/* TinkerKit! Gyroscope [T000062-64]
 *
 * This sketch shows how to read this 2-axis gyroscope,
 * turning in a given angular velocity and then converting it
 * in the simplest way in an angular position (/inclination).
 *
 * Connect: the X-axis to the Analog Input Pin 0 (I0)
 *          the Y-axis to the Analog Input Pin 1 (I1)
 * Optional: connect a servo to Analog Output Pin 9 (O2)
 *
 * created by Federico Vanzati / f.vanzati@arduino.cc
 * in Dec 2011
 *
 * inspired from www.arduino.cc/playground/Main/Gyro
 * by eric barch / ericbarch.com
 *
 * This example code is in the public domain.
 */

#include <Servo.h>
#include <TinkerKit.h>

TKGyro gyro(I0, I1, TK_X4);

const int SERVO = O2;  // Pin on which is connected the servo 

Servo myservo;  // create servo object to control a servo

// Timing variables
unsigned long time;
int sampleTime = 10;  // The sampling period of the gyro 

//Gyroscope variables      
int rollRate, pitchRate;  
int prev_rollRate = 0, prev_pitchRate = 0;
long rollAngle = 0, pitchAngle = 0;
int rotationThreshold = 2;   //Minimum deg/sec to keep track of, helps with gyro drifting

int pos = 0;    // variable to store the servo position


void setup()
{
  myservo.attach(SERVO);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);

  Serial.begin(115200);

  Serial.println("Calibration...");
  gyro.calibrate();

  Serial.print("TinkerKit! Gyroscope [T000062-64] Test Example\n\n");

  time = millis();
}


void loop()
{
  // Every 10 ms take a sample from the gyro
  if(millis() - time > sampleTime)
  {
    time = millis();  // update the time to get the next sample

    // get the gyro's angular velocity 
    rollRate  = gyro.getYAxisRate();  // by calling the getXAxisRate() method
    pitchRate = gyro.getXAxisRate();  // and the getYAxisRate() method


    // Integrate the angular veloity to obtain angular position (or inclination)
    // Using the trapeziod method for numerical integration.
    //          (previous_Rate + current_Rate) * sampleTime
    // Angle = ---------------------------------------------- 
    //                        2 * 1000                            
    // because the sampleTime is expressed in millisecndos and rate in degree 
    // per seconds we also need to divide by 1000 ms/s to obtain the correct units. 
    

    // Ignore the gyro if our angular velocity does not meet our threshold
    if(rollRate >= rotationThreshold || rollRate <= -rotationThreshold) 
      rollAngle  += ((long)(prev_rollRate + rollRate) * sampleTime) / 2000;

    // Ignore the gyro if our angular velocity does not meet our threshold
    if(pitchRate >= rotationThreshold || pitchRate <= -rotationThreshold)
      pitchAngle += ((long)(prev_pitchRate + pitchRate) * sampleTime) / 2000;
    
    // remember the current speed for the next loop rate integration.
    prev_rollRate = rollRate;
    prev_pitchRate = pitchRate;

    // Keep our angle between 0-359 degrees
    if (rollAngle < 0)
      rollAngle += 360;
    else if (rollAngle > 359)
      rollAngle -= 360;

    if (pitchAngle < 0)
      pitchAngle += 360;
    else if (pitchAngle > 359)
      pitchAngle -= 360;

    // Now we control the servo: home position is setted in the center at 90 degrees
    if(rollAngle >= 0 && rollAngle <= 90)  // counterclockwise rotation of the gyro...
      pos = 90 + (int)rollAngle;           // ...produces rotation from 90 to 180 deg on servo                    
    if(rollAngle >= 270)                   // clockwise rotation of the gyro...
      pos = (int)rollAngle - 270;          // ...produces rotation from 90 to 0 deg on servo

    myservo.write(pos);  // send the position to servo
    
    // Pint the obtained values on the serial monitor.
    Serial.print("Roll_Rate: ");
    Serial.print(rollRate);
    Serial.print("\tRoll_Angle: ");
    Serial.print(rollAngle);
    Serial.print("\tPitch_Rate: ");
    Serial.print(pitchRate);
    Serial.print("\tPitch_Angle: ");
    Serial.print(pitchAngle);
    Serial.print("\tServo: ");
    Serial.println(pos);
  }
}



