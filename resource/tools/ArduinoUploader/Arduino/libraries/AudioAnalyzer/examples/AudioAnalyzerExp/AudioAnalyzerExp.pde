#include <AudioAnalyzer.h>
//Version 1.3 for Spectrum analyzer
//Please download the latest library from the Product page!

Analyzer Audio = Analyzer(4,5,0);//Strobe pin ->4  RST pin ->5 Analog Pin ->0
//Analyzer Audio = Analyzer();//Strobe->4 RST->5 Analog->0

int FreqVal[7];//

void setup()
{
  Serial.begin(57600);	//Init the baudrate
  Audio.Init();//Init module 
}

void loop()
{
  Audio.ReadFreq(FreqVal);//return 7 value of 7 bands pass filiter 
                          //Frequency(Hz):63  160  400  1K  2.5K  6.25K  16K
                          //FreqVal[]:      0    1    2    3    4    5    6  
  for(int i=0;i<7;i++)            
  {
    Serial.print(max((FreqVal[i]-100),0));//Transimit the DC value of the seven bands
    if(i<6)  Serial.print(",");
    else Serial.println();
  }
  delay(20);
}
