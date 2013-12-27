/* Ultrasound Sensor
*------------------
* URM V3.2 ultrasonic sensor TTL connection with Arduino
* Reads values (0-300) from an ultrasound sensor (3m sensor)
* and writes the values to the serialport.
* Pin12 (Arduino)-> Pin 1 VCC (URM V3.2)
* GND (Arduino) -> Pin 2 GND (URM V3.2)
* Pin11 (Arduino) -> Pin 7 (URM V3.2)
* Pin 0 (Arduino) -> Pin 9 (URM V3.2)
* Pin 1 (Arduino) -> Pin 8 (URM V3.2)
* www.yerobot.com
* Last modified 20/04/2009
*/

int UREnable = 11; // Ultrasound enable pin
int URPower = 12; // Ultrasound power pin
int val = 0;
int USValue = 0;
int timecount = 0; // Echo counter
int ledPin = 13; // LED connected to digital pin 13
boolean flag=true;
uint8_t DMcmd[4] = { 0x22, 0x00, 0x00, 0x22}; //distance measure command

void setup() {
  Serial.begin(9600);                  // Sets the baud rate to 9600
  pinMode(ledPin, OUTPUT);            // Sets the digital pin as output
   pinMode(UREnable, OUTPUT);
   digitalWrite(UREnable, HIGH); // Set to High
    pinMode(URPower, OUTPUT);
   digitalWrite(URPower, HIGH); // Set to High

delay(200); //Give sensor some time to start up --Added By crystal  from Singapo, Thanks Crystal.
}

void loop()
{
 
  flag=true;
  //Sending distance measure command :  0x22, 0x00, 0x00, 0x22 ;

  for(int i=0;i<4;i++)
  {
    Serial.print(DMcmd[i],BYTE);
  }
 
  delay(75); //delay for 75 ms
 
while(flag)
{
    if(Serial.available()>0)
    {
        int header=Serial.read(); //0x22
        int highbyte=Serial.read();
        int lowbyte=Serial.read();
        int sum=Serial.read();//sum
       
        if(highbyte==255)
        {
          USValue=65525;  //if highbyte =255 , the reading is invalid.
        }
        else
        {
          USValue = highbyte*255+lowbyte;
        }
   
       Serial.print("Distance=");
       Serial.print(USValue);
       
       flag=false;
     }
}
  delay(50);
}

