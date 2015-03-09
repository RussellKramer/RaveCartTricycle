/*********************************************************************
 *
 *                Microchip USB C18 Firmware Version 1.0
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 2.30.01+
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Rawin Rojvanit       11/19/04    Original.
 * JWB				    16/04/2008  Version for my USB Board
 * JWB                  15/06/2008  Version for velleman P8055-1 board
 ********************************************************************/

/** I N C L U D E S **********************************************************/


#include <p18cxxx.h>
#include "system\typedefs.h"                        // Required
#include "system\usb\usb.h"                         // Required
#include "io_cfg.h"                                 // Required

#include "system\usb\usb_compile_time_validation.h" // Optional
#include "user\user.h"                              // Modifiable
#include "CartBike.h"




/** C O N F I G U R A T I O N  S E T T I N G S *******************************/
#pragma config PLLDIV = 5	// Divide by 5 (20 MHz oscillator input)
#pragma config CPUDIV = OSC1_PLL2	// [OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
#pragma config USBDIV = 2	//U SB clock source comes from the 96 MHz PLL divided by 2
#pragma config FOSC = HSPLL_HS	// HS oscillator, PLL enabled, HS used by USB
#pragma config FCMEN = OFF	//F ail-Safe Clock Monitor disabled
#pragma config IESO = OFF	// Oscillator Switchover mode disabled
#pragma config PWRT = OFF	// PWRT disabled //power up timer
#pragma config BOR = ON	// Brown-out Reset enabled in hardware only (SBOREN is disabled)
#pragma config BORV = 3	// Minimum setting
#pragma config VREGEN = ON	// USB voltage regulator enabled
#pragma config WDT = OFF	// HW Disabled - SW Controlled
#pragma config WDTPS = 32768	// 1:32768
#pragma config MCLRE = ON	// MCLR pin enabled; RE3 input pin disabled
#pragma config LPT1OSC = OFF	// Timer1 configured for higher power operation
#pragma config PBADEN = OFF	// PORTB<4:0> pins are configured as digital I/O on Reset
#pragma config CCP2MX = ON	// CCP2 input/output is multiplexed with RC1
#pragma config STVREN = OFF	// Stack full/underflow will cause Reset
#pragma config LVP = OFF	// Single-Supply ICSP disabled
//#pragma config ICPRT = OFF	// ICPORT disabled
#pragma config XINST = OFF	// Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
#pragma config DEBUG = OFF	// Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
#pragma config CP0 = OFF	//Block 0 (000800-001FFFh) not code-protected
#pragma config CP1 = OFF	//Block 1 (002000-003FFFh) not code-protected
#pragma config CP2 = OFF	//Block 2 (004000-005FFFh) not code-protected
#pragma config CP3 = OFF	//Block 3 (006000-007FFFh) not code-protected
#pragma config CPB = OFF	//Boot block (000000-0007FFh) not code-protected
#pragma config CPD = OFF	//Data EEPROM not code-protected
#pragma config WRT0 = OFF	//Block 0 (000800-001FFFh) not write-protected
#pragma config WRT1 = OFF	//Block 1 (002000-003FFFh) not write-protected
#pragma config WRT2 = OFF	//Block 2 (004000-005FFFh) not write-protected
#pragma config WRT3 = OFF	//Block 3 (006000-007FFFh) not write-protected
#pragma config WRTB = OFF	//Configuration registers (300000-3000FFh) not write-protected
#pragma config WRTC = OFF	//Boot block (000000-0007FFh) not write-protected
#pragma config WRTD = OFF	//Data EEPROM not write-protected
#pragma config EBTR0 = OFF	//Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF	//Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF	//Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
#pragma config EBTR3 = OFF	//Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
#pragma config EBTRB = OFF	//Boot block (000000-0007FFh) not protected from table reads executed in other blocks



 /* Config from cartbike standalone
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

#pragma udata

int encoder_count; 
char mybits;
char icount;

const rom char verstring[] = "PIC-VELLEMAN V1.00\0";

void InterruptHandlerHigh (void); // prototype for int handler

// High priority interrupt vector
#pragma code InterruptVectorHigh = 0x08
void
InterruptVectorHigh (void)
{ 
  _asm
    goto InterruptHandlerHigh //jump to interrupt routine
  _endasm
}

void InterruptHandlerLow (void); // prototype for int handler

#pragma code InterruptVector = 0x18
// low priority interrupt vector
void
InterruptVectorLow (void)
{ 
  _asm
    goto InterruptHandlerLow //jump to interrupt routine
  _endasm
}



static void InitializeSystem(void);
void USBTasks(void);

#pragma code


/******************************************************************************
 * Function:        void main(void)
 *****************************************************************************/
void main(void)
{
	unsigned int longcount;
	unsigned char i, pplace=0,charindex,stringlength=0;
//	unsigned char DefaultMessage[] = {'S','T','A','R','T','I','N','G','-','U','P',' ',' ',0};
//	unsigned char bcd[] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};

	unsigned char USBdata[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,'B','I','K','E',' ','R','A','V','E',0}; 
	
    InitializeSystem();
	//PrintString(DefaultMessage);
   // SetNumbers(bcd);


    ClearScrollMessage();
    
       	for(i=16; i< 64; i++){
	    	if(USBdata[i] == 0){
		    	stringlength = i-16; //not the actual length of the string. 16 bytes longer.
		    	break;
		    }	
	    }
	    
    
    		for(i=0;i<stringlength;i++){
		    	
		    	charindex = fromAscii(USBdata[(stringlength-i)+15]);
		    	if(charindex == ' '){
			    		pplace+=7;
			    } else {
		    		printchar(charindex,pplace);
		    	
		    		pplace+= GetAlphaPixelLength(charindex) +2;//2 pixels between characters
		    	}
    		}	
 
    
  			SetScrollLength(pplace);	
    
  				
  			
/*
    printchar(fromAscii('h'),150-47);
    printchar(fromAscii('e'),140-47);
    printchar(fromAscii('l'),130-47);
    printchar(fromAscii('l'),120-47);
    printchar(fromAscii('o'),110-47);
    
    printchar(fromAscii('w'),88-47);
    printchar(fromAscii('o'),77-47);
    printchar(fromAscii('r'),67-47);
    printchar(fromAscii('l'),57-47);
    printchar(fromAscii('d'),47-47);
    
      SetScrollLength(150-47);
*/

    
    while(1)
    {
	    
	
            
	  LoadVolume();
      FullTransversal();
		  

      	
	   //called from fulltransversal
       // USBTasks(); 
       // ProcessIO();        // Calls ServiceRequests() - See user\user.c & .h
      
    }
}

/******************************************************************************
 * Function:        static void InitializeSystem(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        InitializeSystem is a centralize initialization routine.
 *                  All required USB initialization routines are called from
 *                  here.
 *
 *                  User application initialization routine should also be
 *                  called from here.                  
 *
 * Note:            None
 *****************************************************************************/
static void InitializeSystem(void)
{

//	#if defined(USE_BLINK_USB_STATUS)
//	mInitLED_1_2();
//	#endif

  //  #if defined(USE_USB_BUS_SENSE_IO)
  //  tris_usb_bus_sense = INPUT_PIN; // See io_cfg.h
  //  #endif
    
  //  #if defined(USE_SELF_POWER_SENSE_IO)
  //  tris_self_power = INPUT_PIN;
  //  #endif

    mInitializeUSBDriver();         // See usbdrv.h
    USBCheckBusStatus(); //JWB
    UserInit();                     // See user.c & .h


}

/******************************************************************************
 * Function:        void USBTasks(void)
 *
 *****************************************************************************/
void USBTasks(void)
{
    /*
     * Servicing Hardware
     */
    USBCheckBusStatus();                    // Must use polling method  -->  usbdrv.c
    if(UCFGbits.UTEYE!=1)
        USBDriverService();                 // Interrupt or polling method

}


#pragma interrupt InterruptHandlerHigh

void InterruptHandlerHigh (void)
{
/* No encoder on Velleman card
	if (INTCONbits.INT0IF == 1)		// test for encoder interrupt
	{
		icount++;
		// 1st clear INT0 interrupt flag
		INTCONbits.INT0IF = 0;
		mybits = PORTB & 0b00010000; // read phase 2 level
		if ( (mybits != 0) && (encoder_count < 32000) )
		{
			encoder_count--; // turned anti-clockwise
		}
		else if ( (mybits == 0) && (encoder_count > -32000) )
		{	
			encoder_count++; // turned clockwise
		}
	}
*/

}

#pragma interrupt InterruptHandlerLow

void InterruptHandlerLow(void)
{
}
	

