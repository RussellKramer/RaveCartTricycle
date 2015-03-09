/******************************************************************************
* PIC USB
* interrupt.h
******************************************************************************/

#ifndef INTERRUPT_H
#define INTERRUPT_H


#include "system\typedefs.h"


#define mEnableInterrupt()          INTCONbits.GIE = 1;


void low_isr(void);
void high_isr(void);

#endif //INTERRUPT_H




