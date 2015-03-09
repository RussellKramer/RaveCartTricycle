//bitmap displayed on LED Matrix

#ifndef DISPLAYBOARD
#define DISPLAYBOARD


#include <p18f2550.h>



                                   
 //moves every pixel in scroll message to the right one
 //loops around              
 void ShiftScrollMessage();
 void DisplayBoard();//call to put data on the screen. Try to call every ~40ms 
 
 void SetNumbers(unsigned char bcd[]);

 
 #define DECIMAL 10
 #define DASH 11
 
 
 /*       7-segment character encodings */
 