/*********************************************************************
 *
 *                Microchip USB C18 Firmware Version 1.0
 *
 *********************************************************************
 * FileName:        user.c
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
 * JWB					16/04/2008  Changed for my USB Board
 * JWB                  15/06/2008  Modified for Velleman P8055-1 USB board
 ********************************************************************/

/** I N C L U D E S **********************************************************/


#include <p18cxxx.h>
#include <pwm.h>	
#include <timers.h>
#include <string.h>
#include <adc.h>
#include <usart.h>	   /* Serial UART stuff */

#include <spi.h>
#include <adc.h> 


#include "system\typedefs.h"
#include "system\usb\usb.h"
#include "io_cfg.h"             // I/O pin mapping
#include "user\user.h"
#include "CartBike.h"


extern const rom char verstring[20]; // version string located in main.c

#pragma udata
byte count;
//DATA_PACKET dataPacket;

void BlinkUSBStatus(void);
void ServiceRequests(void);
void PollHardware(void);

#pragma code
void UserInit(void)
{


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


 OpenADC( ADC_FOSC_8 & // A/D clock source set to 32Tosc
   ADC_RIGHT_JUST& // write the Digital result(10bits) from right, into ADRESH:ADRESL(16bits).
   ADC_20_TAD, // A/D acquisition time: 20TAD (for 10bit conversion at least12TAD)
   ADC_CH0 & //choose input channel (11), AN11
   ADC_INT_OFF& //ADC interrupt off
   ADC_VREFPLUS_VDD& // choose the supply voltage VDD as reference voltage, V+
   ADC_VREFMINUS_VSS, // choose the supply voltage VSS as reference voltage, V-
    0b00001100 // an0 input, all others digital
);


            OpenSPI(SPI_FOSC_4, MODE_00, SMPEND); //initialize SPI
            
            
}


/******************************************************************************
 * Function:        void ProcessIO(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is a place holder for other user routines.
 *                  It is a mixture of both USB and non-USB tasks.
 *
 * Note:            None
 *****************************************************************************/
void ProcessIO(void)
{   
//	#if defined(USE_BLINK_USB_STATUS)
//		BlinkUSBStatus();
//	#endif

    // User Application USB tasks
    if( (usb_device_state < CONFIGURED_STATE) || (UCONbits.SUSPND == 1) ) 
		return;
    
    ServiceRequests();

}

/*******************************************************************************
*
* PollHardware
*
********************************************************************************/
void PollHardware(void)
{
}

void ServiceRequests(void)
{
	static unsigned char D1,D2,D3,stringlength;
	
	unsigned char USBdata[USBGEN_EP_SIZE]; 
	unsigned char i,pplace=0,charindex;
    word dacvalue, adcvalue;
    if ( USBGenRead( (byte*)&USBdata, sizeof(USBdata)) )
    {
	    
	    /*
	    msg[6] = (PatternNumber/10)%10
	msg[7] = PatternNumber%10
	*/
	
	    SetPatternMode(USBdata[6]*10 + USBdata[7]); 
	     
	    // SetNumbers(USBdata);
	     
	     //don't change the message if the song number hasn't changed
	     if(!(USBdata[0] == D1 && USBdata[1] == D2/* && USBdata[2] == D3*/)){

	     	D1 = USBdata[0];
	     	D2 = USBdata[1];
	     	//D3 = USBdata[2];
	     	 
	    
	    
	   	ClearPanel();
  		ClearScrollMessage();
  
    
    
       	for(i=16; i< 64; i++){
	    	if(USBdata[i] == 0){
		    	stringlength = i-16; //not the actual length of the string. 16 bytes longer.
		    	break;
		    }	
	    }
	    
    // #pragma udata gpr4 //linker script sets for 512 bytes


    		for(i=0;i<stringlength;i++){
		    	
		    	charindex = fromAscii(USBdata[(stringlength-i)+15]);
		    	if(charindex == ' '){
			    		pplace+=7;
			    } else {
		    		printchar(charindex,pplace);
		    	
		    		pplace+= GetAlphaPixelLength(charindex) +2;//2 pixels between characters
		    	}
    		}	
 
   //  #pragma udata
 
  			SetScrollLength(pplace);	
		    	
		  } 
		    	
//	  	 	PrintString(messageStart);
	   	
	   	
    	//we got data. do our thing
    }
}

/******************************************************************************
 * Function:        void BlinkUSBStatus(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        BlinkUSBStatus turns on and off LEDs corresponding to
 *                  the USB device state.
 *
 * Note:            mLED macros can be found in io_cfg.h
 *                  usb_device_state is declared in usbmmap.c and is modified
 *                  in usbdrv.c, usbctrltrf.c, and usb9.c
 *****************************************************************************/
//void BlinkUSBStatus(void)
//{
//    static word led_count = 0;
//    
//    if (led_count == 0)
//		led_count = 10000U;
 //   led_count--;
//
//    #define mLED_Both_Off()         {mLED_1_Off();mLED_2_Off();}
//    #define mLED_Both_On()          {mLED_1_On();mLED_2_On();}
//    #define mLED_Only_1_On()        {mLED_1_On();mLED_2_Off();}
//    #define mLED_Only_2_On()        {mLED_1_Off();mLED_2_On();}
//
//    if (UCONbits.SUSPND == 1)
//    {
 //       if (led_count == 0)
  //      {
 //           mLED_1_Toggle();
 //           mLED_2 = mLED_1;        // Both blink at the same time
 //       }
 //   }
 //   else
  //  {
 //       if(usb_device_state == DETACHED_STATE)
 //       {
 //           mLED_Both_Off();
 //       }
 //       else if(usb_device_state == ATTACHED_STATE)
 //       {
 //           mLED_Both_On();
   //     }
  //      else if(usb_device_state == POWERED_STATE)
  //      {
  //          mLED_Only_1_On();
  //      }
  //      else if(usb_device_state == DEFAULT_STATE)
  //      {
  //          mLED_Only_2_On();
  //      }
  //      else if(usb_device_state == ADDRESS_STATE)
  //      {
  //          if(led_count == 0)
  //          {
  //              mLED_1_Toggle();
  //              mLED_2_Off();
  //          }
  //      }
  //      else if (usb_device_state == CONFIGURED_STATE)
  //      {
  //          if (led_count == 0)
  //          {
  //              mLED_1_Toggle();
  //              mLED_2 = !mLED_1;       // Alternate blink                
  //          }
  //      }
  //  }

//}

