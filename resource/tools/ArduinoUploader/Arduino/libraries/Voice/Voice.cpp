/*Voice.cpp——语音识别库文件。

  成都极趣科技有限公司 版权所有
  http://www.dfrobot.com.cn
  http://dfrobot.taobao.com/
*/
#include "utility/PinMap.h"
#include "Voice.h"


VoiceClass Voice;


void VoiceClass::Input(){
  if(I==1) {LD_WriteReg(0x1c, 0x0b);Serial.println("MIC"); }
  if(I==2) {LD_WriteReg(0x1c, 0x23);Serial.println("MONO");}
}

void VoiceClass::MI(){
  I=1;
}

void VoiceClass::MO(){
  I=2;
}

void VoiceClass::Initialise(uint8 mode,uint8 board){
  if(mode==MIC) MI();
  else if(mode==MONO) MO();
  begin(4);        //使用数字口4
  if(board)RSTB(9);//VoiceRecognitionV1.0 Arduino shield 使用数字口9
  else RSTB(6);    //VoiceRecognitionV2.0 Gadgeteer Compatible module 使用数字口6
  setDataMode(0x08);
  LD_reset();
}

uint8_t VoiceClass::begin(uint8_t chipSelectPin){

chipSelectPin_ = chipSelectPin;
  // set pin modes
  pinMode(chipSelectPin_, OUTPUT);
  chipSelectHigh();
  pinMode(SPI_MISO_PIN, INPUT);
  pinMode(SPI_MOSI_PIN, OUTPUT);
  pinMode(SPI_SCK_PIN, OUTPUT);

#ifndef SOFTWARE_SPI
  // SS must be in output mode even it is not chip select
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH); // disable any SPI device using hardware SS pin
  // Enable SPI, Master, clock rate f_osc/128
  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
  // clear double speed
  SPSR &= ~(1 << SPI2X);
#endif  // SOFTWARE_SPI
}

void VoiceClass::chipSelectHigh(void) {
  digitalWrite(chipSelectPin_, HIGH);
}

//------------------------------------------------------------------------------
void VoiceClass::chipSelectLow(void) {
  digitalWrite(chipSelectPin_, LOW);
}

void VoiceClass::setDataMode(uint8_t mode)
{
  SPCR = (SPCR & ~SPI_MODE_MASK) | mode;
}

uint8_t VoiceClass::RSTB(uint8_t RSTB)
{
  RSTB_=RSTB;
  pinMode(RSTB_,OUTPUT);
  
}

void VoiceClass::LD_WriteReg(unsigned char address,unsigned char value)
{
  address_=address;
  value_=value;
	
  chipSelectLow();
  delay(10);
  Voice.transfer(0x04);
  Voice.transfer(address_);
  Voice.transfer(value_);
  chipSelectHigh(); 
 }

unsigned char VoiceClass::LD_ReadReg(unsigned char address)
{ 
  address_=address;

  chipSelectLow();
  delay(10);
  Voice.transfer(0x05);
  Voice.transfer(address_);
  result = Voice.transfer(0x00);  
  chipSelectHigh();
  return(result);
 }

void VoiceClass::LD_reset()
{

  digitalWrite(RSTB_,HIGH);
  delay(1);
  digitalWrite(RSTB_,LOW);
  delay(1);
  digitalWrite(RSTB_,HIGH);
  delay(1);
  chipSelectLow();
  delay(1);
  chipSelectHigh();
  delay(1);
}
void VoiceClass::LD_Init_Common()
{

  LD_ReadReg(0x06);  
  LD_WriteReg(0x17, 0x35); 
  delay(10);
  LD_ReadReg(0x06);  

  LD_WriteReg(0x89, 0x03);  
  delay(5);
  LD_WriteReg(0xcf, 0x43);  
  delay(5);
  LD_WriteReg(0xcb, 0x02);

  LD_WriteReg(0x11, LD_PLL_11);  
  LD_WriteReg(0x1e,0x00);
  LD_WriteReg(0x19, LD_PLL_ASR_19); 
  LD_WriteReg(0x1b, LD_PLL_ASR_1B);	
  LD_WriteReg(0x1d, LD_PLL_ASR_1D);

  delay(10);
  LD_WriteReg(0xcd, 0x04);
  LD_WriteReg(0x17, 0x4c); 
  delay(5);
  LD_WriteReg(0xb9, 0x00);
  LD_WriteReg(0xcf, 0x4f); 
}
void VoiceClass::LD_Init_ASR()
{
  nLD_Mode=LD_MODE_ASR_RUN;
  LD_Init_Common();

  LD_WriteReg(0xbd, 0x00);
  LD_WriteReg(0x17, 0x48);
  delay(10);

  LD_WriteReg(0x3c, 0x80);  
  LD_WriteReg(0x3e, 0x07);
  LD_WriteReg(0x38, 0xff);  
  LD_WriteReg(0x3a, 0x07);
  LD_WriteReg(0x40, 0);   
  LD_WriteReg(0x42, 8);
  LD_WriteReg(0x44, 0); 
  LD_WriteReg(0x46, 8); 
  delay(1);
}
void VoiceClass::ProcessInt0()
{ 
  uint8 nAsrResCount=0;
  //detachInterrupt(0) ;
  ucRegVal = LD_ReadReg(0x2b);
	if(nLD_Mode == LD_MODE_ASR_RUN)
	{
		LD_WriteReg(0x29,0) ;
		LD_WriteReg(0x02,0) ;	
		if((ucRegVal & 0x10) &&
			LD_ReadReg(0xb2)==0x21 && 
			LD_ReadReg(0xbf)==0x35)
		{
            
			nAsrResCount = LD_ReadReg(0xba);
			if(nAsrResCount>0 && nAsrResCount<4) 
			{
                                Serial.print( "ASR_FOUN ONE: ");
				nAsrStatus=LD_ASR_FOUNDOK;
			}
			else
		        {
                                 Serial.println( "ASR_FOUND ZERO");
                                 Serial.println( " ");
				nAsrStatus=LD_ASR_FOUNDZERO;
			}	
		}
		else
		{
                        Serial.println( "ASR_FOUND ZERO");
                        Serial.println( " ");
			nAsrStatus=LD_ASR_FOUNDZERO;
		}
			
		LD_WriteReg(0x2b, 0);
    	        LD_WriteReg(0x1C,0);

		return;
	}
	
  delay(10);
  //detachInterrupt(1); 
}
unsigned char VoiceClass::LD_Check_ASRBusyFlag_b2()
{ 
  uint8 j;
  uint8 flag = 0;
  for (j=0; j<10; j++)
	{
	  if (LD_ReadReg(0xb2) == 0x21)
		{
			flag = 1;
			break;
		}
	  delay(10);		
	}
  return flag;
}

void VoiceClass::LD_AsrStart()
{
  LD_Init_ASR();
}

unsigned char VoiceClass::LD_AsrRun()
{
  LD_WriteReg(0x35, MIC_VOL);

  LD_WriteReg(0x1c, 0x09);

  LD_WriteReg(0xbd, 0x20);
  LD_WriteReg(0x08, 0x01);
  delay( 1);
  LD_WriteReg(0x08, 0x00);
  delay( 1);
  if(LD_Check_ASRBusyFlag_b2() == 0)
	{
		return 0;
	}

  LD_WriteReg(0xb2, 0xff);

  LD_WriteReg(0x37, 0x06);
  delay( 5 );
  //Serial.println( LD_ReadReg(0xbf),BYTE);
  //	LD_WriteReg(0x1c, 0x0b);
  Input();
  LD_WriteReg(0x29, 0x10);
  LD_WriteReg(0xbd, 0x00);
  //detachInterrupt(1) ;
  return 1;
}
unsigned char VoiceClass::RunASR(int x,int y,char (*p)[80])
{
  int i=0;
  int r=0;
  for (i=0; i<5; i++)	//防止由于硬件原因导致LD3320芯片工作不正常，所以一共尝试5次启动ASR识别流程
	{
		LD_AsrStart();

		delay(100);
		if (LD_AsrAddFixed(x,y,p)==0)
		{

			LD_reset();			//	LD3320芯片内部出现不正常，立即重启LD3320芯片
			delay(100);			//	并从初始化开始重新ASR识别流程
		continue;	
		}
		delay(10);
		if (LD_AsrRun() == 0)
		{
			LD_reset();			//	LD3320芯片内部出现不正常，立即重启LD3320芯片
			delay(100);			//	并从初始化开始重新ASR识别流程
                 continue;
		}
		r=1;
		break;					//	ASR流程启动成功，退出当前for循环。开始等待LD3320送出的中断信号
	}
  return r;
}

unsigned char VoiceClass::LD_AsrAddFixed(int x,int y,char (*p)[80])
{
  int k,flag;
  int nAsrAddLength;

	flag = 1;
	for (k=0; k<x; k++)
	{
			
		if(LD_Check_ASRBusyFlag_b2() == 0)
		{
			flag = 0;
			break;
		}
		
		LD_WriteReg(0xc1, k);
		LD_WriteReg(0xc3, 0 );
		LD_WriteReg(0x08, 0x04);
  
		delay(1);
		LD_WriteReg(0x08, 0x00);
		delay(1);

		for (nAsrAddLength=0; nAsrAddLength<y; nAsrAddLength++)
		{
			if (p[k][nAsrAddLength] == 0)
				break;
			LD_WriteReg(0x5, p[k][nAsrAddLength]);
 
		}
		LD_WriteReg(0xb9, nAsrAddLength);
		LD_WriteReg(0xb2, 0xff);
 
		LD_WriteReg(0x37, 0x04);
	}
  //Serial.println( LD_ReadReg(0xbf),BYTE);  
  return flag;
}

unsigned char VoiceClass::LD_GetResult()
{
  return LD_ReadReg(0xc5 );
}




