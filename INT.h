/* 
 * File:   INT.h
 * Author: thomas
 *
 * Created on July 4, 2020, 10:48 AM
 */

#ifndef INT_H
#define	INT_H

/*typedefs and defines for interrupt driver*/
#define ON                  1
#define OFF                 0
#define RB0_RisingEdge      1
#define RB0_FallingEdge     0
typedef void(*callback)(void);

/*global variables*/
callback RB0_callbackptr = NULL;

/*******************************************
**************Configurations****************
********************************************/
#define INT_RB0                 ON
#define INT_RB0_Edge            RB0_FallingEdge
#define INT_PORTBINTCON         OFF
#define INT_TIMER0              ON
#define INT_TIMER0_Prescaler    256
#define INT_TIMER0_Freq         50 //in ms


extern void INT_int                         (void);
extern void INT_PullUpPORTB                 (void);
extern void INT_RB0_IntCallBack             (callback RB0_INTHandlerPtr);
extern void INT_PORTBINTCON_IntCallBack     (callback PORTBINTCON_INTHandlerPtr);
extern void INT_TIMER0_IntCallBack          (callback TIMER0_INTHandlerPtr);
#endif	/* INT_H */

