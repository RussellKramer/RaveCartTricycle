//bitmap displayed on LED Matrix

#ifndef _CARTBIKE
#define _CARTBIKE


#include <p18f4550.h>



                                   
 //moves every pixel in scroll message to the right one
 //loops around   
 
 void SetPatternMode(unsigned char input);
            
 unsigned int loadADCchannel(unsigned char channel);
 unsigned int SafeSub(unsigned int a, unsigned int b);
 void LoadVolume();
 void SetChannel(unsigned char input);
 void giveHSB(unsigned char X);
 void giveRGB(unsigned char red, unsigned char green, unsigned char blue);
 void ShiftMessage();
 unsigned char GetBit(unsigned char x, unsigned char y);
  void giveRGB_secondary(unsigned char red, unsigned char green, unsigned char blue);
  
  void TransverseSecondary(unsigned char divisor, unsigned char R1,unsigned char G1,unsigned char B1,unsigned char R2,unsigned char G2,unsigned char B2);


   void FullTransversalEX( char barmodX, char barmodY, char barmodDiv, char levelmodY1, char levelmodX1,  float amplifier, char UseText);

void FullTransversal();

void CartBike();

unsigned char fromAscii(unsigned char input);

void printchar(unsigned char letter, unsigned char start);

void SetBit(unsigned char x, unsigned char y);

void ClearScrollMessage();
 
 void SetScrollLength(unsigned char input);
 
  unsigned char GetAlphaPixelLength(unsigned char index);
 
 
 void ClearPanel();
 

 