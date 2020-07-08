/* 
 * File:   INT.h
 * Author: thomas
 *
 * Created on July 4, 2020, 10:48 AM
 */

#ifndef INT_H
#define	INT_H

#include "Typdefs.h"


/*typedefs and defines for interrupt driver*/
#define ON                  1
#define OFF                 0
#define RB0_RisingEdge      1
#define RB0_FallingEdge     0
#define TIMER1_OneShoot     1
#define TIMER1_Continious   0
typedef void(*callback)(void);

/*******************************************
**************Configurations****************
********************************************/
/*******************************************/
#define INT_RB0                 ON
#define INT_RB0_Edge            RB0_FallingEdge
/*******************************************/
#define INT_PORTBINTCON         OFF
/*******************************************/
#define INT_TIMER0              ON
#define INT_TIMER0_Prescaler    256
#define INT_TIMER0_Freq         100 //in ms
/*******************************************/
#define INT_TIMER1              ON
#define INT_TIMER1_Prescaler    8
#define INT_TIMER1_Freq         5000 // in ms
/*******************************************/
#define INT_TIMER2              ON
#define INT_TIMER2_Prescaler    16
#define INT_TIMER2_Postscaler   16
#define INT_TIMER2_Freq         100 // in ms
/*******************************************/
#if (INT_TIMER0 == ON)
#define TIMER0_OverFlowCounts       (((INT_TIMER0_Freq*2)/(26)))
#define TIMER0_Preload              (256 * (((INT_TIMER0_Freq*200)/(26))%100)/100)
#endif
#if (INT_TIMER1 == ON)
#define TIMER1_OverFlowCounts       (((INT_TIMER2_Freq*2)/(209)))
#define TIMER1_Preload              (65536 * (((INT_TIMER2_Freq*2)/(209))%100)/100)
#endif
#if (INT_TIMER2 == ON)
#define TIMER2_OverFlowCounts       (((INT_TIMER2_Freq*2)/(26)))
#define TIMER2_Preload              (256 * (((INT_TIMER2_Freq*200)/(26))%100)/100)
#endif
/*******************************************/
extern void INT_int                         (void);
extern void INT_PullUpPORTB                 (void);
extern void INT_RB0_IntCallBack             (callback RB0_INTHandlerPtr);
extern void INT_PORTBINTCON_IntCallBack     (callback PORTBINTCON_INTHandlerPtr);
extern void INT_TIMER0_IntCallBack          (callback TIMER0_INTHandlerPtr);
extern void INT_TIMER1_IntCallBack          (callback TIMER1_INTHandlerPtr);
extern void INT_TIMER2_IntCallBack          (callback TIMER2_INTHandlerPtr);
extern void INT_TIMER0_ON                   (void);
extern void INT_TIMER0_OFF                  (void);
extern void INT_TIMER1_ON                   (void);
extern void INT_TIMER1_OFF                  (void);
extern void INT_TIMER2_ON                   (void);
extern void INT_TIMER2_OFF                  (void);

#endif	/* INT_H */

