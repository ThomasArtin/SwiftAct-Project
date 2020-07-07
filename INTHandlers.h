/* 
 * File:   INTHandlers.h
 * Author: thomas
 *
 * Created on July 4, 2020, 1:37 PM
 */

#ifndef INTHANDLERS_H
#define	INTHANDLERS_H

#include "INT.h"
#include "Typdefs.h"


#if (INT_TIMER0 == ON)
#define TIMER0_OverFlowCounts       (((INT_TIMER0_Freq*2)/(26)))
#define TIMER0_Preload              (256 * (((INT_TIMER0_Freq*200)/(26))%100)/100)
#endif

extern void RBO_INT_Cooler              (void);
extern void PORTBINTCON_INT_Temp        (void);
extern void TIMER0_INT                  (void);
#endif	/* INTHANDLERS_H */

