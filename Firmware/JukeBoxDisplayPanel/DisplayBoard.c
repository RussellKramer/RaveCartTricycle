#include "DisplayBoard.h"

#define INDICATOR PORTAbits.RA5 //repurposed to 7-seg shutdown

rom unsigned char Alpha[38][8] = {
 {0b01110000, //0     A
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b11111000, //4
  0b10001000, //5
  0b10001000, //6
  0b10001000}, //7
  
 {0b11110000, //0     B
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b11110000, //4
  0b10001000, //5
  0b10001000, //6
  0b11110000}, //7
   
 {0b01111000, //0     C
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b10000000, //4
  0b10000000, //5
  0b10000000, //6
  0b01111000}, //7
   
 {0b11110000, //0     D
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b10001000, //4
  0b10001000, //5
  0b10001000, //6
  0b11110000}, //7
   
 {0b11111000, //0     E
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b11111000, //4
  0b10000000, //5
  0b10000000, //6
  0b11111000}, //7
   
 {0b11111000, //0     F
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b11111000, //4
  0b10000000, //5
  0b10000000, //6
  0b10000000}, //7
   
 {0b01111000, //0     G
  0b10001000, //1
  0b10000000, //2
  0b10000000, //3
  0b10011000, //4
  0b10001000, //5
  0b10001000, //6
  0b01110000}, //7
   
 {0b10001000, //0     H
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b11111000, //4
  0b10001000, //5
  0b10001000, //6
  0b10001000}, //7
   
 {0b11111000, //0     I
  0b00100000, //1
  0b00100000, //2
  0b00100000, //3
  0b00100000, //4
  0b00100000, //5
  0b00100000, //6
  0b11111000}, //7
   
 {0b11111000, //0     J
  0b00100000, //1
  0b00100000, //2
  0b00100000, //3
  0b00100000, //4
  0b00100000, //5
  0b00100000, //6
  0b11100000}, //7
   
 {0b10001000, //0     K
  0b10010000, //1
  0b10100000, //2
  0b11000000, //3
  0b10100000, //4
  0b10010000, //5
  0b10001000, //6
  0b10001000}, //7
   
 {0b10000000, //0     L
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b10000000, //4
  0b10000000, //5
  0b10000000, //6
  0b11111000}, //7
   
 {0b11111000, //0     M
  0b10101000, //1
  0b10101000, //2
  0b10101000, //3
  0b10101000, //4
  0b10101000, //5
  0b10101000, //6
  0b10101000}, //7
   
 {0b10001000, //0     N
  0b10001000, //1
  0b11001000, //2
  0b10101000, //3
  0b10101000, //4
  0b10101000, //5
  0b10011000, //6
  0b10001000}, //7
   
 {0b01110000, //0     O
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b10001000, //4
  0b10001000, //5
  0b10001000, //6
  0b01110000}, //7
   

 {0b11110000, //0     P
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b11110000, //4
  0b10000000, //5
  0b10000000, //6
  0b10000000}, //7
  
 {0b01110000, //0     Q
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b10001000, //4
  0b10101000, //5
  0b01111000, //6
  0b00001000}, //7
   
 {0b11110000, //0     R
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b11110000, //4
  0b10100000, //5
  0b10010000, //6
  0b10001000}, //7
   
 {0b01111000, //0     S
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b01110000, //4
  0b00001000, //5
  0b00001000, //6
  0b11110000}, //7
   
 {0b11111000, //0     T
  0b00100000, //1
  0b00100000, //2
  0b00100000, //3
  0b00100000, //4
  0b00100000, //5
  0b00100000, //6
  0b00100000}, //7
   
 {0b10001000, //0     U
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b10001000, //4
  0b10001000, //5
  0b10001000, //6
  0b01110000}, //7
   
 {0b10001000, //0     V
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b10001000, //4
  0b10001000, //5
  0b01010000, //6
  0b00100000}, //7
   
 {0b10101000, //0     W
  0b10101000, //1
  0b10101000, //2
  0b10101000, //3
  0b10101000, //4
  0b10101000, //5
  0b10101000, //6
  0b01010000}, //7
   
 {0b10001000, //0     X
  0b10001000, //1
  0b01010000, //2
  0b01010000, //3
  0b00100000, //4
  0b01010000, //5
  0b10001000, //6
  0b10001000}, //7
   
 {0b10001000, //0     Y
  0b10001000, //1
  0b10001000, //2
  0b01010000, //3
  0b00100000, //4
  0b00100000, //5
  0b00100000, //6
  0b00100000}, //7
   
 {0b11111000, //0     Z
  0b00001000, //1
  0b00010000, //2
  0b00100000, //3
  0b01000000, //4
  0b10000000, //5
  0b10000000, //6
  0b11111000}, //7
   
 {0b01110000, //0     0
  0b10001000, //1
  0b11001000, //2
  0b10101000, //3
  0b10101000, //4
  0b10011000, //5
  0b10001000, //6
  0b01110000},
  
 {0b00100000, //0     1
  0b01100000, //1
  0b10100000, //2
  0b00100000, //3
  0b00100000, //4
  0b00100000, //5
  0b00100000, //6
  0b11111000},
  
  
 {0b11110000, //0     2
  0b00001000, //1
  0b00001000, //2
  0b00001000, //3
  0b01111000, //4
  0b10000000, //5
  0b10000000, //6
  0b11111000},
  
  
 {0b11110000, //0     3
  0b00001000, //1
  0b00001000, //2
  0b00001000, //3
  0b11110000, //4
  0b00001000, //5
  0b00001000, //6
  0b11110000},
  
  
 {0b10001000, //0     4
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b11111000, //4
  0b00001000, //5
  0b00001000, //6
  0b00001000},
  
  
 {0b11111000, //0     5
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b11110000, //4
  0b00001000, //5
  0b10001000, //6
  0b11110000},
  
  
 {0b01111000, //0     6
  0b10000000, //1
  0b10000000, //2
  0b10000000, //3
  0b11110000, //4
  0b10001000, //5
  0b10001000, //6
  0b01110000},
  
  
 {0b11111000, //0     7
  0b00001000, //1
  0b00001000, //2
  0b00001000, //3
  0b00010000, //4
  0b00010000, //5
  0b00010000, //6
  0b00010000},
  
  
 {0b01110000, //0     8
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b01110000, //4
  0b10001000, //5
  0b10001000, //6
  0b01110000},
  
  
 {0b01111000, //0     9
  0b10001000, //1
  0b10001000, //2
  0b10001000, //3
  0b01111000, //4
  0b00001000, //5
  0b10001000, //6
  0b01110000},
  
 {0b00000000, //0     space
  0b00000000, //1
  0b00000000, //2
  0b00000000, //3
  0b00000000, //4
  0b00000000, //5
  0b00000000, //6
  0b00000000},
  
 {0b00000000, //0     dash
  0b00000000, //1
  0b00000000, //2
  0b00000000, //3
  0b11111000, //4
  0b00000000, //5
  0b00000000, //6
  0b00000000}
  };
  
  
 
 
unsigned char GetBitMapIndex(unsigned char input){
	if ( input >= 'A' && input <= 'Z')
		return input - 'A';
	
	if(input >= 'a' && input <= 'z')
		return input - 'a';
		
	if(input >= '0' && input <= '9')
		return input - '0' + 26;// last 10 chars in alpha array are arab numerals
	
	if(input == '-')
	     return 37;
	     
	return 36;	
	
}	

#define MaxMessageLength 25 // can't fit any more into PIC memory.

 unsigned char ScrollMessage[8][MaxMessageLength];/* {{0b00100000,0b10000000}, //0
                                       {0b00010001,0b00000000}, //1
                                       {0b00111111,0b10000000}, //2
                                       {0b01101110,0b11000000}, //3
                                       {0b11111111,0b11100000}, //4
                                       {0b10111111,0b10100000}, //5
                                       {0b10100000,0b10100000}, //6
                                       {0b00011011,0b00000000}}; //7 */
                                     
unsigned char ScrollMessageLength = 0; //legngth of scroll message in bytes (8-pixels)
 
                                    
void ClearScrollMessage(){
	unsigned char i,j;
		for(i=0; i< MaxMessageLength; i++){
			for(j=0;j<8;j++)
				ScrollMessage[j][i] = 0;
		}	
}
	                                     
void CopyInDigit(unsigned char loc, unsigned char ASCIIValue){
	unsigned char i;
	unsigned char BitmapIndex = GetBitMapIndex(ASCIIValue);
	if(BitmapIndex > 37)
		return;
	for(i=0; i< 8; i++){
		ScrollMessage[i][loc] = Alpha[BitmapIndex][i];
	}	
	
}	

//terminated by a '0' char
void PrintString(unsigned char *msg){
	unsigned char i;
	ClearScrollMessage();
	for(i=0; i< MaxMessageLength && msg[i]!=0; i++){
		if(msg[i]!=0)
			CopyInDigit(i , msg[i]);
		
	}	
	ScrollMessageLength = i;

}	


rom unsigned char LeftOddNum[12] =          {0b11101110, //0
                                 		     0b10000010, //1
                                             0b11011100, //2
                                             0b11010110, //3
                                             0b10110010, //4
                                             0b01110110, //5
                                             0b01111110, //6
                                             0b11000010, //7
                                             0b11111110, //8
                                             0b11110110, //9
                                             0b00000001,  //decimal
                                             0b00010000   //dash
                                      } ;
                                      
                                      
  rom unsigned char LeftEvenNum[12] =       {0b01110111, //0
                                 		     0b00010100, //1
                                             0b10110011, //2
                                             0b10110110, //3
                                             0b11010100, //4
                                             0b11100110, //5
                                             0b11100111, //6
                                             0b00110100, //7
                                             0b11110111, //8
                                             0b11110110, //9
                                             0b00001000, //decimal
                                             0b10000000 //dash
                                             
                                      } ;
                                      
                                      
  rom unsigned char RightOddNum[12] =       {0b01110111, //0
                                 		     0b01000001, //1
                                             0b00111011, //2
                                             0b01101011, //3
                                             0b01001101, //4
                                             0b01101110, //5
                                             0b01111110, //6
                                             0b01000011, //7
                                             0b01111111, //8
                                             0b01101111, //9
                                             0b10000000,  //decimal
                                             0b00001000  //dash
                                      } ;
                                      
                                      
 rom unsigned char RightEvenNum[12] =       {0b11101110, //0
                                 		     0b00101000, //1
                                             0b11001101, //2
                                             0b01101101, //3
                                             0b00101011, //4
                                             0b01100111, //5
                                             0b11100111, //6
                                             0b00101100, //7
                                             0b11101111, //8
                                             0b01101111, //9
                                             0b00010000,  //decimal
                                             0b00000001  //dash
                                      } ;
                                                                  
                                                                  




                                     
 //Values displayed on 7-segment grid
 unsigned char NumberGrid[2][8]  = {{1,2,3,4,5,6,7,8},
                                   {0,2,4,6,8,0,2,4}};
 
 void SetNumbers(unsigned char bcd[]){
	 unsigned char i;
	 
	 for(i=0; i < 8; i++){
		 NumberGrid[0][i] = bcd[i];
	}
	
	 for(i=0; i < 8; i++){
		 NumberGrid[1][i] = bcd[i+8];
	} 
	
	 
}
	 

 void SetCountdown(unsigned char bcd[]){

	 

		NumberGrid[1][13] = bcd[3];
		NumberGrid[1][13] = bcd[4];
		NumberGrid[1][13] = bcd[5];
	
	 
}

 
 void ShiftScrollMessage(){
    unsigned char i,j,special;
    for(i=0; i< 8 ; i++){ //vertical
	    for(j=0; j< ScrollMessageLength; j++){
	    
	 		if(j==0){
	 			special = ((ScrollMessage[i][0] & 0b10000000) == 0b10000000);
			}
	    	 // ScrollMessage[8][30];
	 		ScrollMessage[i][j] = (ScrollMessage[i][j] << 1);// | ((ScrollMessage[i][j+1] & 0b10000000) != 0);
			if(j!=ScrollMessageLength-1){
				if( (ScrollMessage[i][j+1] & 0b10000000) != 0)
	     			ScrollMessage[i][j]  = ScrollMessage[i][j] | 1;
			}
	     
		 
	 
	 	if( j == ScrollMessageLength-1 && special){
	    	 ScrollMessage[i][j] |= 0b00000001;
		}
		 }
 	}
 }
	                                     



void DisplayBoard(){
//Push Data into 164s.


	static unsigned char Shiftposion,i;

	unsigned char value[8];
	
	unsigned char digit[4];


		Shiftposion++;
	

	
	if(Shiftposion >= 8){
	   Shiftposion = 0;
	   LATB = LATB | 0b00000100; //data for transistor matrix shift registers
	} else {
		LATB = LATB & 0b11111011; //data for transistor matrix shift registers.
	    
	}
	if(Shiftposion % 4 == 0){
		LATB = LATB | 0b00000010;
	}else{
		LATB = LATB & 0b11111101; //data for transistor 7-seg shift registers.
	}
	


	
		switch (Shiftposion%4){
			case 0:
				digit[0] = RightEvenNum[NumberGrid[1][4]]; //bottom right
				digit[1] = RightEvenNum[NumberGrid[0][4]]; //top right
				digit[2] =  LeftEvenNum[NumberGrid[0][0]]; //top left
				digit[3] =  LeftEvenNum[NumberGrid[1][0]]; //bottom left
			break;
			case 1:
				digit[0] = RightOddNum[NumberGrid[1][5]]; //bottom right
				digit[1] = RightOddNum[NumberGrid[0][5]]; //top right
				digit[2] =  LeftOddNum[NumberGrid[0][1]]; //top left
				digit[3] =  LeftOddNum[NumberGrid[1][1]]; //bottom left
			break;
			case 2:
				digit[0] = RightEvenNum[NumberGrid[1][6]];  //bottom right
				digit[1] = RightEvenNum[NumberGrid[0][6]]; //top right
				digit[2] =  LeftEvenNum[NumberGrid[0][2]];  //top left
				digit[3] =  LeftEvenNum[NumberGrid[1][2]];	//bottom left
			break;
			case 3:
				digit[0] = RightOddNum[NumberGrid[1][7]]; //bottom right
				digit[1] = RightOddNum[NumberGrid[0][7]];  //top right
				digit[2] =  LeftOddNum[NumberGrid[0][3]]; //top left
				digit[3] =  LeftOddNum[NumberGrid[1][3]];//bottom left
			break;
		}	

	
	for(i=0; i< 8; i++){
	//	RC 2,4,5,6 control 7-seg
	

		value[i]=0;
		value[i] |= (((digit[0] & (1 << i)) == 0) ? 0b00000100 : 0);
		value[i] |= (((digit[1] & (1 << i)) == 0) ? 0b10000000 : 0);
	
		value[i] |= (((digit[2] & (1 << i)) == 0) ? 0b01000000 : 0);
		value[i] |= (((digit[3] & (1 << i)) == 0) ? 0b00001000 : 0);
			
		value[i] |=  (((ScrollMessage[7-i][0] >> Shiftposion) & 0b00000001) ==  0) | ((((ScrollMessage[i][1] >> Shiftposion) & 0b00000001) ==  0)?2:0);

	}
	
	LATB = LATB & 0b111011111; //turn off output
    INDICATOR = 0;
		
		
	
	


	for(i=0; i< 8; i++){
		
		LATC = value[i];
		
		PORTB = PORTB & 0b11110111;
		PORTB = PORTB | (value[i] & 0b00001000);
        LATB = LATB & 0b11101111;
		LATB = LATB | 0b00010000; //clock for 164s, 7-seg matrix
		
	}
	
		
		
	
	//Advance transistor shift.

	LATB = LATB & 0b11111110; //clock for transistor shift registers
	LATB = LATB |  0b00000001;
	
	LATB = LATB | 0b00100000; //turn back on output
	INDICATOR = 1;
}
	
	
