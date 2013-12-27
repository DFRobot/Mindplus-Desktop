/*Voice.cpp——语音识别库文件。

  成都极趣科技有限公司 版权所有
  http://www.dfrobot.com.cn
  http://dfrobot.taobao.com/
*/
#ifndef Voice_H
#define Voice_H
#include <utility/PinMap.h>
#include <Arduino.h>

#define VoiceRecognitionV1 1   //VoiceRecognitionV1.0 Arduino shield
#define VoiceRecognitionV2 0   //VoiceRecognitionV2.0 Gadgeteer Compatible module

#define MIC 88
#define MONO 99

#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long
#define LD_MODE_IDLE		0x00
#define LD_MODE_ASR_RUN		0x08
#define LD_ASR_NONE	    	0x00	//表示没有在作ASR识别
#define LD_ASR_RUNING		0x01	//表示LD3320正在作ASR识别中
#define LD_ASR_FOUNDOK		0x10	//表示一次识别流程结束后，有一个识别结果
#define LD_ASR_FOUNDZERO 	0x11	//表示一次识别流程结束后，没有识别结果
#define LD_ASR_ERROR	 	0x31	//表示一次识别流程中LD3320芯片内部出现不正确的状态
#define CLK_IN   	     	24
#define LD_PLL_11			(uint8)((CLK_IN/2.0)-1)
#define LD_PLL_MP3_19		0x0f
#define LD_PLL_MP3_1B		0x10
#define LD_PLL_MP3_1D   	(uint8)(((90.0*((LD_PLL_11)+1))/(CLK_IN))-1)
#define LD_PLL_ASR_19 		(uint8)(CLK_IN*32.0/(LD_PLL_11+1) - 0.51)
#define LD_PLL_ASR_1B 		0x48
#define LD_PLL_ASR_1D 		0x1f
#define RESUM_OF_MUSIC          0x01
#define MASK_INT_SYNC	        0x10
#define MASK_INT_FIFO	        0x04
#define MASK_AFIFO_INT		0x01
#define MASK_FIFO_STATUS_AFULL	0x08 	 
#define MIC_VOL                 0x55	
#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
extern uint8  nAsrStatus;

#if MEGA_SOFT_SPI && (defined(__AVR_ATmega1280__)||defined(__AVR_ATmega2560__))
#define SOFTWARE_SPI
#endif  // MEGA_SOFT_SPI
//------------------------------------------------------------------------------
// SPI pin definitions
//
#ifndef SOFTWARE_SPI
// hardware pin defs

/** The default chip select pin for the VOICE is SS. */
uint8_t const  LD_CHIP_SELECT_PIN = SS_PIN;
// The following three pins must not be redefined for hardware SPI.
/** SPI Master Out Slave In pin */
uint8_t const  SPI_MOSI_PIN = MOSI_PIN;
/** SPI Master In Slave Out pin */
uint8_t const  SPI_MISO_PIN = MISO_PIN;
/** SPI Clock pin */
uint8_t const  SPI_SCK_PIN = SCK_PIN;

/** optimize loops for hardware SPI */
#define OPTIMIZE_HARDWARE_SPI

#else  // SOFTWARE_SPI
// define software SPI pins 
/** SPI chip select pin */
uint8_t const LD_CHIP_SELECT_PIN = 10;
/** SPI Master Out Slave In pin */
uint8_t const SPI_MOSI_PIN = 11;
/** SPI Master In Slave Out pin */
uint8_t const SPI_MISO_PIN = 12;
/** SPI Clock pin */
uint8_t const SPI_SCK_PIN = 13;

#endif  // SOFTWARE_SPI


class VoiceClass {

public:
  void Initialise(uint8 mode,uint8 board);
  void MI();
  void MO();
  void Input();
  inline static byte transfer(byte _data);
  inline static void attachInterrupt();
  inline static void detachInterrupt(); 
  uint8_t begin(uint8_t chipSelectPin); 
  static void end();
  static void setBitOrder(uint8_t);
  static void setDataMode(uint8_t);
  static void setClockDivider(uint8_t);
  uint8_t RSTB(uint8_t RSTB);
  void LD_WriteReg(unsigned char address,unsigned char value);
  unsigned char LD_ReadReg(unsigned char address);
  void LD_reset();
  void LD_Init_Common();
  void LD_Init_ASR();
  void ProcessInt0();
  unsigned char LD_Check_ASRBusyFlag_b2();
  void LD_AsrStart();
  unsigned char LD_AsrRun();
  unsigned char RunASR(int x,int y,char  (*p)[80]);
  unsigned char LD_AsrAddFixed( int x,int y,char  (*p)[80]);
  unsigned char LD_GetResult();

 private:

  uint8_t chipSelectPin_;
  void chipSelectHigh(void);
  void chipSelectLow(void);
  unsigned char address_;
  unsigned char value_;
  int RSTB_;
  uint8  nLD_Mode;
  unsigned char I;
  uint8  ucRegVal;
  unsigned char result;
};


extern VoiceClass Voice;


byte VoiceClass::transfer(byte _data) {
  SPDR = _data;
  while (!(SPSR & _BV(SPIF)));
  return SPDR;
}

void VoiceClass::attachInterrupt() {
  SPCR |= _BV(SPIE);
}

void VoiceClass::detachInterrupt() {
  SPCR &= ~_BV(SPIE);
}

#endif
