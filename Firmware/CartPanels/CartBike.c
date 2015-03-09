#include "CartBike.h"
#include "PhysicalLoc.h"
#include "HSB.h"
#include <math.h>
//#pragma config WDT=OFF, LVP=OFF, DEBUG=OFF, MCLRE = ON
 
 /*
//Internal oscillator, port function on RA6, EC used by USB 
#pragma config FOSC = HSPLL_HS // Using 20 MHz crystal with PLL
#pragma config PLLDIV = 3		// Divide by 5 to provide the 96 MHz PLL with 4 MHz input
#pragma config CPUDIV = OSC1_PLL2 // Divide 96 MHz PLL output by 2 to get 48 MHz system clock
#pragma config USBDIV = 2 		// USB clock comes from 96 MHz PLL output / 2
#pragma config FCMEN = OFF //   Fail-Safe Clock Monitor
#pragma config IESO = ON //   Oscillator Switchover mode
#pragma config PWRT = OFF  //   Power-up timer
#pragma config BOR = OFF //  Brown-out reset
#pragma config VREGEN = ON //  internal USB 3.3V voltage regulator
#pragma config WDT = OFF //  Watchdog timer
#pragma config MCLRE = ON //  MCLR Enable
#pragma config LVP = OFF //  low voltage ICSP
#pragma config ICPRT = OFF //  dedicated programming port (44-pin devices)
#pragma config CP0 = OFF //  code protection
*/


#include <spi.h>
#include <adc.h>

//#pragma code1

#define INDICATOR PORTDbits.RD1
//#define INDICATOR PORTCbits.RC1 //TESTBOARD1


	 
 #define  GIVEBYTE(data)               \
	        WriteSPI(data);

	


unsigned char channel[7];
unsigned char Fchannel[7];
unsigned char SFchannel[7];

unsigned char MaxIndex;
unsigned char MaxValue;
#define  RIGHT_ADC ADC_CH0
#define  LEFT_ADC  ADC_CH1

#define RESET PORTCbits.RC0

#define STROBE PORTCbits.RC2


unsigned char PatternMode=20;

void SetPatternMode(unsigned char input){
	PatternMode = input;
}
	
unsigned int loadADCchannel(unsigned char channel){
	   SetChanADC (channel);
   	   Delay10TCYx(30);
       ConvertADC ();	// Start an A/D conversion				
       while(BusyADC()){	// Wait for the conversion to complete
       //maybe some code for while were waiting (could turn an led on maybe)
        }
        Delay10TCYx(30);
        return  ReadADC();
}
	
	
unsigned int SafeSub(unsigned int a, unsigned int b){
	if(b>a)
	   return 0;
else if(a-b>255)
   return 255;
 else
     return a-b;
}	
	
float ScaleFactor[7] = {0.01,0.01,0.01,0.01, 0.01,0.01,0.01};

//float ScaleFactor[7] = {1,1,1,1, 1,1,1};

unsigned char HasNotHitEleven[7];
#define MAXWANT 16
// use 11 for vertical bar patterns

void LoadVolume(){
   unsigned char i;
   static unsigned char longcount;
   longcount++;
   RESET = 1;
    Delay10TCYx(5);
   STROBE=1;
   Delay10TCYx(5);
   STROBE=0;
   Delay10TCYx(5); 
   
   RESET = 0;

 //STROBE=1;
  // Delay10TCYx(100); 
   
  
  MaxValue=0;
   for(i=0; i< 7; i++){
	  	STROBE=1;
   		Delay10TCYx(5);
        STROBE=0;
        Delay10TCYx(5); 
	    

        
     
	        
	        channel[i] = (float)((float)sqrt((float)loadADCchannel(RIGHT_ADC))) * ScaleFactor[i];
	        
	   
        Fchannel[i] = (SafeSub(channel[i],5) + Fchannel[i]*3)/4;





		if( Fchannel[i] < 2)
			if(ScaleFactor[i] < 1.5)
        		ScaleFactor[i] +=0.01;
       
	     if( Fchannel[i] > MAXWANT){
		    if(ScaleFactor[i] -0.01 > 0)
        		ScaleFactor[i] -=0.01;
        	HasNotHitEleven[i]=0;
        }	else {
        	if (HasNotHitEleven [i] < 255 )
        		HasNotHitEleven[i] ++;
        	else
        	if(ScaleFactor[i] < 1.5)
        	   ScaleFactor[i] +=0.01;
        } 	
       
        
        if(Fchannel[i] > MaxValue){
	       MaxIndex = i;
	       MaxValue =  Fchannel[i];
	       }
	        
       // channel[1][i] = loadADCchannel(LEFT_ADC)>>2;

             
    
   }
}



	/* mux is controlled by RD7, RD6, RD5*/
	
	
	/*
	000 = 0
	001 = 1
	010 = 2
	011 = 3  *
	100 = 4
	101 = 5  *
	110 = 6
	
	
	
	*/
	

 unsigned char position;
 
	void SetChannel(unsigned char input){
		PORTD = PORTD&0b00011111;
		PORTD = PORTD | (input << 5);
		position = 0;
		// Delay1KTCYx(1);
	}//RD5,RD6,RD7
		


  void giveHSB(unsigned char X){
	X%=255;
	 position ++;
	    if(position == 3){
		    
		     GIVEBYTE(HSB_ar[X][1]);//6 green3
	         GIVEBYTE(HSB_ar[X][2]);//7 //blue3
	         GIVEBYTE(HSB_ar[X][0]);//8 //red3
	           
		} else {
		   
		    GIVEBYTE(HSB_ar[X][0]);//0 //red1
	        GIVEBYTE(HSB_ar[X][2]);//1 //blue1
	        GIVEBYTE(HSB_ar[X][1]);//2 //green1
	            
		   if(position==6)
		      position = 0;
		}

	 }
	 
	 
	 

  void giveRGB(unsigned char red, unsigned char green, unsigned char blue){


	 position ++;
	    if(position == 3){
		    
		     GIVEBYTE(green);//6 green3
	         GIVEBYTE(blue);//7 //blue3
	         GIVEBYTE(red);//8 //red3
	           
		} else {
		   
		    GIVEBYTE(red);//0 //red1
	        GIVEBYTE(blue);//1 //blue1
	        GIVEBYTE(green);//2 //green1
	            
		   if(position==6)
		      position = 0;
		}

	 }
	 
	//DAFT PUNK. BRAINWASHER - 11
	//TELEVISION RULES THE NATION - 27
	//ROBOT ROCK - 10
	//VIDEO KILLED THE RADIO STAR
	//AROUND THE WORLD
	
#define M_L 60//22 letters max BYTES LONG
#define M_H	10//10 PIXELS HIGH
unsigned char ScrollLength; //bytes in scroll message

void SetScrollLength(unsigned char input){ //takes in number of pixels
	ScrollLength = (input>>3)+4;
	if(ScrollLength > M_L)
		ScrollLength = M_L;
}
	
	


 #pragma udata gpr4 //linker script sets for 512 bytes
 unsigned char ScrollMessage[M_H][M_L];
 #pragma udata
 
 /*=
//    B           I         K           E                                                   R           A          V        E                                               
{{0b11111100 , 0b01101000 , 0b10001111 , 0b11000000 , 0b00000000 , 0b00000000 ,0b00111111 , 0b00001111 , 0b00001100 , 0b00110111 , 0b11100000 , 0b00000000 , 0b00000000}, 
 {0b11111110 , 0b01101101 , 0b11001111 , 0b11000000 , 0b00000000 , 0b00000000 ,0b00111111 , 0b10011111 , 0b10001100 , 0b00110100 , 0b00000000 , 0b00000000 , 0b00000000},
 {0b11000011 , 0b01101111 , 0b10001100 , 0b00000000 , 0b00000000 , 0b00000000 ,0b00110000 , 0b11011000 , 0b11001100 , 0b00110100 , 0b00000000 , 0b00000000 , 0b00000000},
 {0b11000111 , 0b01101111 , 0b00001100 , 0b00000000 , 0b00000000 , 0b00000000 ,0b00110001 , 0b11011000 , 0b01101100 , 0b00110100 , 0b00000000 , 0b00000000 , 0b00000000},
 {0b11000111 , 0b01101111 , 0b00001111 , 0b10000000 , 0b00000000 , 0b00000000 ,0b00110011 , 0b11011000 , 0b01101100 , 0b00110100 , 0b00000000 , 0b00000000 , 0b00000000},
 {0b11111110 , 0b01101110 , 0b00001111 , 0b10000000 , 0b00000000 , 0b00000000 ,0b00111111 , 0b10011111 , 0b11101100 , 0b00110111 , 0b11000000 , 0b00000000 , 0b00000000},
 {0b11111111 , 0b01101101 , 0b10001100 , 0b00000000 , 0b00000000 , 0b00000000 ,0b00111111 , 0b00011111 , 0b11100110 , 0b01110100 , 0b00000000 , 0b00000000 , 0b00000000},
 {0b11000011 , 0b01101100 , 0b11001100 , 0b00000000 , 0b00000000 , 0b00000000 ,0b00110001 , 0b10011000 , 0b01100011 , 0b11100100 , 0b00000000 , 0b00000000 , 0b00000000},
 {0b11111111 , 0b01101100 , 0b01101111 , 0b11000000 , 0b00000000 , 0b00000000 ,0b00110000 , 0b11011000 , 0b01100001 , 0b11000100 , 0b00000000 , 0b00000000 , 0b00000000},
 {011111110 , 0b01101100 , 0b00111111 , 0b11000000 , 0b00000000 , 0b00000000 ,0b00110000 , 0b11011000 , 0b01100000 , 0b10000111 , 0b11100000 , 0b00000000 , 0b00000000}};
*/

 
 
 void ClearScrollMessage(){
		unsigned char i,j;
		for(i=0; i< M_L; i++)
			for(j=0; j< M_H; j++)
				ScrollMessage[j][i] = 0;	 
 }
 
 //only sets a bit. Does not clear old ones
 void SetBit(unsigned char x, unsigned char y){
	 unsigned char byteoffset;

	if(y>=M_H)
   		return 0;
	y = M_H-1 - y;
	byteoffset = x>>3;
	if(byteoffset >= M_L)
  		return 0;
  //	if(byteoffset > ScrollLength)
  	//	ScrollLength = byteoffset;
  		
	 (ScrollMessage[y][ M_L-1-byteoffset] |= (1<<(x - (byteoffset<<3))));
}

//letter = 0 = 'A';
//start is point in bitmap to enter the letter

/* this function could be a lot faster if I didn't do everything one bit at a time*/

 
 rom unsigned short Alphabet[40][10] = { //26, letters. 10 numbers, one dash,  10 pixels high. up to 16 pixels wide
 {0b0111100000000000, //A
  0b1111110000000000, // 8 pixels
  0b1100011000000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b1111111100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000},
  
 {0b1111110000000000, //B
  0b1111111000000000, // 8 pixels
  0b1100001100000000,
  0b1100011100000000,
  0b1100011100000000,
  0b1111111000000000,
  0b1111111100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b1111111000000000},

	 
 {0b0011111000000000, //C
  0b0111111100000000, // 9-PIXELS
  0b1110000110000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b0110000010000000,
  0b0011111110000000,
  0b0001111100000000},//C
	 
 {0b1111100000000000, //D
  0b1111110000000000, // 8 pixels
  0b1100011000000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100011100000000,
  0b1111111000000000,
  0b1111110000000000},
	 
 {0b1111111100000000, //E
  0b1111111100000000, //8-PIXELS
  0b1100000000000000,
  0b1100000000000000,
  0b1111111000000000,
  0b1111111000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1111111100000000,
  0b1111111100000000},//E
	 
	 
 {0b1111111100000000, //F
  0b1111111100000000, //8-PIXELS
  0b1100000000000000,
  0b1100000000000000,
  0b1111111000000000,
  0b1111111000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000},//
	 
	 
 {0b0001111100000000, //G
  0b0011111110000000, // 9-PIXELS
  0b0111000011000000,
  0b1110000011000000,
  0b1100000000000000,
  0b1100011111000000,
  0b1100011111000000,
  0b1100000011000000,
  0b0111111111000000,
  0b0011111011000000},
	 
	 
 {0b1100001100000000, //H
  0b1100001100000000, //8-PIXELS
  0b1100001100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b1111111100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000},//
	 
	 
 {0b1100000000000000, //I
  0b1100000000000000, //2 PIXELS
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000},//I
	 
	 
 {0b1111111100000000, //J
  0b1111111100000000, //8
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b1100110000000000,
  0b1100110000000000,
  0b1111110000000000,
  0b0111100000000000},//J
	 
	 
 {0b1100001100000000, //K 8
  0b1100011000000000,
  0b1100110000000000,
  0b1101100000000000,
  0b1111000000000000,
  0b1110000000000000,
  0b1111000000000000,
  0b1101100000000000,
  0b1100110000000000,
  0b1100011000000000},//K
	 
 {0b1100000000000000, //L 8
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1111111100000000,
  0b1111111100000000},//L
	 
	 
 {0b1100000000110000,//M
  0b1110000001110000,//12
  0b1111000011110000,
  0b1101100110110000,
  0b1100111100110000,
  0b1100011000110000,
  0b1100001000110000,
  0b1100000000110000,
  0b1100000000110000,
  0b1100000000110000},//M
	 
	 
 {0b1100000110000000,// N 9
  0b1100000110000000,
  0b1110000110000000,
  0b1111000110000000,
  0b1101100110000000,
  0b1101100110000000,
  0b1100110110000000,
  0b1100011110000000,
  0b1100001110000000,
  0b1100000110000000},//N
	 
	 
 {0b0111100000000000,// O 8
  0b0111110000000000,
  0b1110011000000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1110011100000000,
  0b0111111000000000,
  0b0011110000000000},//O
	 
	 
 {0b1111110000000000, //P 8
  0b1111111000000000,
  0b1100011100000000,
  0b1100001100000000,
  0b1100011100000000,
  0b1111111100000000,
  0b1111111000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000},//P
	 
	 
 {0b0011111000000000,
  0b0111111100000000,
  0b1100000110000000,
  0b1100000110000000,
  0b1100000110000000,
  0b1100110110000000,
  0b1100011110000000,
  0b1100001110000000,
  0b0111111111000000,
  0b0011111001100000},//Q 11
	 
	 
 {0b1111110000000000,//R 8
  0b1111111000000000,
  0b1100001100000000,
  0b1100011100000000,
  0b1100111100000000,
  0b1111111000000000,
  0b1111110000000000,
  0b1100011000000000,
  0b1100001100000000,
  0b1100001100000000},
	 
	 
 {0b0011110000000000,
  0b0111111000000000,
  0b1100001100000000,
  0b1100000000000000,
  0b0111100000000000,
  0b0001111000000000,
  0b0000001100000000,
  0b1100001100000000,
  0b0111111100000000,
  0b0011111000000000},//S 8
	 
	 
 {0b1111111110000000,
  0b1111111110000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000},//T 9
	 
	 
 {0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100011100000000,
  0b1111111000000000,
  0b0111110000000000},//U 8
	 
	 
 {0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100011100000000,
  0b0110111000000000,
  0b0011110000000000,
  0b0001100000000000},//V 8
	 

 {0b1100000000110000,
  0b1100000000110000,
  0b1100000000110000,
  0b1100000000110000,
  0b1100011000110000,
  0b1100111100110000, 
  0b1101110110110000,
  0b1111100011110000, 
  0b1111000001110000,//12 
  0b1110000000110000},//W
	  
	   
 {0b1100001100000000,
  0b1100001100000000,
  0b0110011000000000,
  0b0011110000000000,
  0b0001100000000000,
  0b0011110000000000,
  0b0110011000000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000},//X 8
  
 {0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b0110011000000000,
  0b0011110000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000},//Y
  
 {0b1111111100000000,
  0b1111111100000000,
  0b0000011000000000,
  0b0000110000000000,
  0b0001100000000000,
  0b0011000000000000,
  0b0110000000000000,
  0b1100000000000000,
  0b1111111100000000,
  0b1111111100000000},//Z 8
  
  
  
 {0b0111111000000000,
  0b1111111100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1111111100000000, //8-pixels
  0b0111111000000000},//0
  
  
 {0b0110000000000000,
  0b1110000000000000,
  0b1110000000000000,
  0b0110000000000000,
  0b0110000000000000,
  0b0110000000000000,
  0b0110000000000000,
  0b0110000000000000,
  0b1111000000000000,
  0b1111000000000000},//1 4 pixels
  
  
 {0b0111100000000000,
  0b1111110000000000,
  0b1100111000000000,
  0b1100011000000000,
  0b0000111000000000,
  0b0001110000000000,
  0b0011000000000000,
  0b0110000000000000,
  0b1111111100000000,
  0b1111111100000000},//2
  
  
 {0b1111110000000000,
  0b1111111000000000,
  0b0000011100000000,
  0b0000011100000000,
  0b0011111100000000,
  0b0011111000000000,
  0b0000011100000000,
  0b0000001100000000,
  0b1111111100000000,
  0b1111111000000000},//3
  
  
 {0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1111111110000000,
  0b1111111110000000,
  0b0000001100000000,
  0b0000001100000000,
  0b0000001100000000,
  0b0000001100000000},//4
  
  
 {0b1111111100000000,
  0b1111111100000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1111111100000000,
  0b1111111100000000,
  0b0000001100000000,
  0b1000001100000000,
  0b1111111100000000,
  0b1111111000000000},//5
  
 {0b0011111000000000,
  0b0111111100000000,
  0b1100001100000000,
  0b1100000000000000,
  0b1111111000000000,
  0b1111111100000000,
  0b1100001110000000,
  0b1100011110000000,
  0b0111111100000000,
  0b0011111000000000},//6
  
 {0b1111111110000000,
  0b1111111110000000,
  0b0000001110000000,
  0b0000001110000000,
  0b0000011100000000,
  0b0000111000000000,
  0b0001110000000000,
  0b0011100000000000,
  0b0011000000000000,
  0b0011000000000000},//7
  
 {0b0111111000000000,
  0b1111111100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b0111111000000000,
  0b1110001100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b0111111000000000},//8
  
  
 {0b0111111000000000,
  0b1111111100000000,
  0b1100001100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b0111111100000000,
  0b0000001100000000,
  0b1100001100000000,
  0b1111111100000000,
  0b0111111000000000},//9

 {0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b1111111000000000,
  0b1111111000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000},//DASH
  
  {0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b000000000000000,
  0b000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b1100000000000000,
  0b1100000000000000},//DOT
  
 {0b0000000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b0000000000000000,
  0b000000000000000,
  0b000000000000000,
  0b0000000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b0000000000000000},//COLON
  
  
 {0b0000000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b1100000000000000,
  0b110000000000000,
  0b110000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b1100000000000000,
  0b1100000000000000}//!
  
  
	}; //end of character bitmap array
	
	
	//special char array indexes
	#define DASH 36
	#define DOT 37
	#define COLON 38
	#define EXCLAMATION 39
	
	rom unsigned char Alphabet_bitmap_length[40] = { //width in pixels of each alpha bitmap
	 8,//A
8,//B
9,//C
8,//D
8,//E
8,//F
10,//G
8,//H
2,//I
8,//J
8,//K
8,//L
12,//M
9,//N
8,//O
8,//P
11,//Q
8,//R
8,//S
9,//T
8,//U
8,//V
12,//W
8,//X
8,//Y
8,//Z

8,//0
4,//1
8,//2
8,//3
9,//4
8,//5
9,//6
9,//7
8,//8
8,//9
7,//-
2,//.
2,//,
2//!
};

unsigned char GetAlphaPixelLength(unsigned char index){
	return	Alphabet_bitmap_length[index];
}	

  
	 
void printchar(unsigned char letter, unsigned char start){
	unsigned char x,y;
	unsigned short tempro;
	

	
	for(x=0; x< Alphabet_bitmap_length[letter];x++){
		tempro = 0b1000000000000000 >> x;
		for(y=0; y< M_H; y++){
			if((Alphabet[letter][y] & tempro) != 0)	
				SetBit(start +  Alphabet_bitmap_length[letter] - x ,M_H-y-1);
		} //end of y loop
	}//end of x loop	
	
}
	

	 
	 
unsigned char fromAscii(unsigned char input){
	if(input == ' ')
		return ' ';
		
	if(input >= 'a' && input <= 'z')
		return input - 'a';
	if(input >= 'A' && input <= 'Z')
		return input - 	'A';
	if(input >= '0' && input <= '9')
		return input - '0' + 26;
	
	if(input == '-')
		return DASH;
		
	if(input == '.' || input == ',')
		return DOT;
		
	if(input == ':' || input == ';')
		return COLON;
		
	if(input == '!' )
		return EXCLAMATION;
	
	return DASH; //DEFAULT
	
}	
	 
 
 //ScrollLength
 void ShiftMessage(){
  unsigned char j,i,special=0;

  
  for(i=0; i< M_H; i++){//rows
	  special = 0;
  for(j=M_L-ScrollLength; j<M_L; j++){
    if((ScrollMessage[i][j] & 0b10000000)!=0){
        if(j!=M_L-ScrollLength)
           ScrollMessage[i][j-1]|= 0b00000001;
         else
             special = 1;
    }
    ScrollMessage[i][j] = ScrollMessage[i][j]<<1;
  }  
  if(special)
      ScrollMessage[i][M_L-1]|= 0b00000001;
  }  
}



unsigned char GetBit(unsigned char x, unsigned char y){
unsigned char byteoffset;

if(y>=M_H)
   return 0;
y = M_H-1 - y;
byteoffset = x>>3;
if(byteoffset >= M_L)
  return 0;
  

return (ScrollMessage[y][ M_L-1-byteoffset] & (1<<(x - (byteoffset<<3)))) != 0;
}



	void giveRGB_secondary(unsigned char red, unsigned char green, unsigned char blue){


	 position ++; 
	    if(position < 3){ //top
		    
		     GIVEBYTE(blue);//6 green3
	         GIVEBYTE(red);//7 //blue3
	         GIVEBYTE(green);//8 //red3
	           
		} else {
		   GIVEBYTE(blue);
		   GIVEBYTE(red);
		   GIVEBYTE(green);
		   // GIVEBYTE(blue);//0 //red1
	       // GIVEBYTE(red);//1 //blue1
	       // GIVEBYTE(green);//2 //green1
	 }         
	  
	 
     if(position==5)
		  position = 0;
		

	 }
	 
	 void TransverseSecondary(unsigned char divisor, unsigned char R1,unsigned char G1,unsigned char B1,unsigned char R2,unsigned char G2,unsigned char B2){
		  unsigned char i,x,y,rlower,glower,blower;
		  unsigned char Total1,Total2;
		  
		  Total1 = ((Fchannel[0]+ Fchannel[1]+ Fchannel[2]))>>1;
		  Total2 = ((Fchannel[3]+ Fchannel[4]+ Fchannel[5]))>>1;
		  
		  
		 #if SIDE == FRONT
		 	Total1 = Total1/1.5;
		 	Total2 = Total2/1.5;
		 
		 	 if(Total1>19)
		    Total1=19;
		    
		 if(Total2 > 19)
		    Total2 = 19;
		    
	
		 #else
		 
		 	 if(Total1>25)
		    Total1=25;
		    
		 if(Total2 > 25)
		    Total2 = 25;
		 
		 #endif
		    
		  rlower = R2>>5;
		  glower = G2>>5;
		  blower = B2>>5;
		    
		     
		  for(i=0; i< 54;i++){
			  y = i%6<3;
			  if(y==1){
			  x =  26-((i/6)*3 + (i%3));
			  }else{
			   x =  26-(2+(i/6)*3 - (i%3));
			  }
			  
			  if(y==1){
			     if( x - Total1 < 2)
			        giveRGB_secondary(R1,G1,B1);
			     else if (x < Total1)
			       giveRGB_secondary(rlower,glower,blower);
			     else
			        giveRGB_secondary(0,0,0);
			  }else{
			      
			        if( x - Total2 < 2)
			        giveRGB_secondary(R1,G1,B1);
			        
			           else if (x <Total2)
			           giveRGB_secondary(rlower,glower,blower);
			     else
			        giveRGB_secondary(0,0,0);
			        
			  }     
		  } 
		 
		  
	 }
	
	




//horizontal bars with hsb
	 void FullTransversalEX( char barmodX, char barmodY, char barmodDiv, char levelmodY1, char levelmodX1,  float amplifier, char ColorMode){
	 unsigned char i,j,x,y,len,ymod,ymodplus,R2,G2,B2,temp;
	 unsigned char R1[7],G1[7],B1[7];
	 static unsigned char longcount,shiftcount;

	unsigned char Fchannel_amp[7];
	
	
	for(j=0; j< 7; j++){
		Fchannel_amp[j] = Fchannel[j] * amplifier;
	}	
	 
		 
	// 0 = display text
  	if(ColorMode == 0){
  	 longcount+=(Fchannel[3]+Fchannel[5])/3;
  	 
  	 	shiftcount++;
  	 	if(shiftcount  %2){
           	ShiftMessage();
        }
  	 
  			R1[0] = HSB_ar[(longcount)%255][0]>>1;
	     	G1[0] = HSB_ar[(longcount)%255][1]>>1;
	     	B1[0] = HSB_ar[(longcount)%255][2]>>1;
	     	
	     	R2 = HSB_ar[(longcount+128)%255][0];
	     	G2 = HSB_ar[(longcount+128)%255][1];
	     	B2 = HSB_ar[(longcount+128)%255][2];
	     	
	        for(i=1; i< 7; i++){
	    		R1[i] = R1[0];
	     		G1[i] = G1[0];
	     		B1[i] = B1[0];
	     	}
  	} else if (ColorMode == 1){//1 = separate bars
  	
  		longcount+=(Fchannel[3]+Fchannel[5])/10;
		  
		  
    	 for(i=1; i< 7; i++){
	    	R1[i] = HSB_ar[(longcount+i*36)%255][0];
	     	G1[i] = HSB_ar[(longcount+i*36)%255][1];
	     	B1[i] = HSB_ar[(longcount+i*36)%255][2];
	     
	 	} 
  	} else if (ColorMode == 2){ //2= all bars same color
  	
  	 	longcount+=(Fchannel[3]+Fchannel[5])/3;
  		R1[0] = HSB_ar[(longcount)%255][0];
	    G1[0] = HSB_ar[(longcount)%255][1];
	    B1[0] = HSB_ar[(longcount)%255][2];
	    	
	    R2 = HSB_ar[(longcount+128)%255][0];
	    G2 = HSB_ar[(longcount+128)%255][1];
	    B2 = HSB_ar[(longcount+128)%255][2];
	     	
	    for(i=1; i< 7; i++){
	    	R1[i] = R1[0];
	     	G1[i] = G1[0];
	     	B1[i] = B1[0];
	     }
  	}  else if (ColorMode == 3){ //3 =. Separate bars based on audio channel intensity
  	
  	 	 for(i=1; i< 7; i++){
	    	R1[i] = HSB_ar[(Fchannel[i]*14)%255][0];
	     	G1[i] = HSB_ar[(Fchannel[i]*14)%255][1];
	     	B1[i] = HSB_ar[(Fchannel[i]*14)%255][2];
	 	} 
  	}
  	
  	
    
     	
     
	 for(j=0; j< 8; j++){
		   if (ChanLength[j] != 0){
		 
	        SetChannel(j);
	        
	        len = ChanLength[j];
	        for(i=0; i< len; i++){
		        x = PhysLoc[j][len-1-i][0];
		        if(x== EMPTY)
		           giveRGB(0,0,0);
		        else {
			        
			        USBTasks();          //need to do them here because too much delay breaks usb connection.
        			ProcessIO();        // Calls ServiceRequests() - See user\user.c & .h
        
		           y = PhysLoc[j][len-1-i][1];
		           #if SIDE == RIGHT
		           	y--;
		           	
		           #endif
		      
	              
	               #if SIDE == LEFT
		           if(ColorMode==0 && GetBit(x,y-2)){ //FOR TEXT SCROLLING
		           #elif SIDE == RIGHT
		            if(ColorMode==0 && GetBit(30-x,y-2)){//FOR TEXT SCROLLING
			       #elif SIDE == FRONT
			        if(0){ //NO TEXT ON FRONT PANEL
			       #endif
		           
		             
		             
	                  giveRGB(R2,G2,B2); //COLOR OF TEXT
	                  
	                 
	           //    #if SIDE == LEFT
		       //  }    else if(UseText && GetBit(x+1,y-1)){ //FOR TEXT SCROLLING
		       //    #elif SIDE == RIGHT
		       //  }   else if(UseText && GetBit(30-x-1,y-1)){//FOR TEXT SCROLLING
			   //    #elif SIDE == FRONT
			   //     }else if(UseText && GetBit(x+1,y+1)){ //FOR TEXT SCROLLING
			   //    #endif
	              //
	            //       giveRGB(R2,G2,B2); //COLOR OF drop TEXT
	                  
	          } else {    
	              
	              
		          
		              
		          	ymod = ((y*barmodY+x*barmodX)>>barmodDiv)%6+1;
		     	
	              
	                  if(Fchannel_amp[ymod] > y * levelmodY1 + x* levelmodX1){
		                  
		                  
	                        giveRGB(R1[ymod],G1[ymod],B1[ymod]);
	                          } else {
	                   		giveRGB(0,0,0);
	                   }
	               #endif //side = left
	               
	             
	               
	               
	         } //pixel is empty
	         } //pixel is text
	        } //channel is not empty
	    }//channel loop
	    
	 }   
	 
	 
	             #if SIDE == LEFT
                                 
                     SetChannel(3);  
              #elif SIDE == RIGHT
                   SetChannel(6);              
              #elif SIDE == FRONT
                  SetChannel(3);      
              #endif
              TransverseSecondary(3,R1[0],G1[0],B1[0],R1[3],G1[3],B1[3]);
              
	 }//function
	 
	 


//SIMPLE TEST rgb
/*
	 void FullTransversalEX( char barmodX, char barmodY, char barmodDiv, char levelmodY1, char levelmodX1,  char amplifier, char ColorMode){
	 unsigned char i,j,x,y,len,ymod,ymodplus,R2,G2,B2,temp;
	 unsigned char R1[7],G1[7],B1[7];
	 static unsigned int longcount,shiftcount;

	longcount +=2;
	if(longcount < 200){
		R2 = 255;
		G2 = 0;
		B2 = 0;
	}else if (longcount < 400){
		R2 = 0;
		G2 = 255;
		B2 = 0;
	} else{
		R2 = 0;
		G2 = 0;
		B2 = 255;
		if(longcount > 800)
			longcount = 0;
	
	}

	
	 
	
  	
    
     	
     
	 for(j=0; j< 8; j++){
		   if (ChanLength[j] != 0){
		 
	        SetChannel(j);
	        
	        len = ChanLength[j];
	        for(i=0; i< len; i++){
	                  giveRGB(R2,G2,B2); //COLOR OF TEXT
	        }          
	                 
	        
	        } //channel is not empty
	    }//channel loop
	 }//function
	 
	 */
	 

 void ClearPanel(){
	 unsigned char i,j,len;
	 for(j=0; j< 8; j++){
		   if (ChanLength[j] != 0){
		 
	        SetChannel(j);
	        
	        len = ChanLength[j];
	        for(i=0; i< len; i++){
	              giveRGB(0,0,0); //COLOR OF TEXT
	         }
	        } //channel is not empty
	    }//channel loop
	 }
	 
	 
void FullTransversal(){
	
	//  two lowest bits set color mode
	// 0 = display text
	// next 3 option give different color patterns;
	
	//six higher bits set pattern structure
	
	unsigned char colormode = PatternMode&0b00000011;
	unsigned char functionmode = PatternMode >> 2;
	
		switch(functionmode){
			case 0: //0-3
				FullTransversalEX(1,1, 2, 1,0,0.7,colormode); //up right diagonal bars
			break;
			case 1: //4-7
				FullTransversalEX(1,1, 2, 1,0,0.7,colormode); //up right diagonal bars
			break;
			case 2: //8-11
				FullTransversalEX(1,2,3, 1,4,3.3,colormode);
			break;
			case 3: //12-15
				 FullTransversalEX(1,0,2, 1,0,0.7,colormode); // bars pusshing diagonal back slightly
			break;
			case 4: //16-19
				FullTransversalEX(-10,0,10, 1,0,0.7,colormode); // bars pusshing diagonal back slightly //solid bad
			break;
			case 5://20 - 23
				 FullTransversalEX(0,1,1, 0,1,1.3,colormode); // completely horizontal
			break;
			case 6: //24-27
				FullTransversalEX(0,2,3, 1,4,3.5,colormode); // wide bars pusshing forward
			break;
			case 7: //28 - 31
				FullTransversalEX(1,0,5, 0,1,0.7,colormode); // single wide bar right bad
			break;
			case 8: //32 - 35
				FullTransversalEX(1,0,2, 0,1,0.7,colormode); // wide vertical bars that push left
			break;
			case 9: //36 - 39
				FullTransversalEX(1,0,8, 2,2,3.5,colormode); // big diagonal solid slicer
			break;
			case 10: //40 - 43
				FullTransversalEX(1,0,3, 1,1,1.6,colormode); // big diagonal solid slicer //wider slicers
			break;
			case 11: //44 - 47
				 FullTransversalEX(0,1,2, 0,1,0.7,colormode); // completely horizontal and wider
			break;
			case 12: //48 - 51
				FullTransversalEX(0,1,2, 1,0,0.7,colormode); // completely horizontal and pushing up
			break;
			default: //51-54
				FullTransversalEX(1,1,3,  1,0,   0.7,colormode); //  //flat top diagonal bars
			break;
			
		}
			
	
	
		 
		  
}

	

	/*
void  CartBike(void){
    unsigned char  i,j,longcount=0,blinkcount=0;

    TRISE = 0;
   	TRISD = 0;
	TRISC = 0;
	TRISB = 0b00000000;
    TRISA = 0b00000011;
    PORTD = 0;
	PORTC = 0;
	PORTB = 0b00000000;
	PORTA = 0b00000011;
	PORTE = 0;


 OpenADC( ADC_FOSC_64 & // A/D clock source set to 32Tosc
   ADC_RIGHT_JUST& // write the Digital result(10bits) from right, into ADRESH:ADRESL(16bits).
   ADC_20_TAD, // A/D acquisition time: 20TAD (for 10bit conversion at least12TAD)
   ADC_CH0 & //choose input channel (11), AN11
   ADC_INT_OFF& //ADC interrupt off
   ADC_VREFPLUS_VDD& // choose the supply voltage VDD as reference voltage, V+
   ADC_VREFMINUS_VSS, // choose the supply voltage VSS as reference voltage, V-
    0b00001100 // an0 input, all others digital
);
  
 
 
	 
	  
  
	while(1){
		
		
	       
            longcount++;
            if(longcount  %2){
            	ShiftMessage();
            }
            
            LoadVolume();
            	
            OpenSPI(SPI_FOSC_16, MODE_00, SMPEND); //initialize SPI
            
            
            FullTransversal();
            
  
        
        
      blinkcount++;
      if(blinkcount<10){
        INDICATOR=1;
      }else {
	       INDICATOR=0;
	       if(blinkcount > 20)
	         blinkcount=0;
	     }
	      
        
             Delay1KTCYx(1);
      }



   }
*/