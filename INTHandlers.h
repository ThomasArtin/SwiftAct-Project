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



extern void RBO_INT_WakeUp              (void);
extern void PORTBINTCON_INT_Temp        (void);
extern void TIMER0_Buttons              (void);
extern void TIMER1_1s                   (void);
extern void TIMER2_ADC                  (void);
 
#endif	/* INTHANDLERS_H */

