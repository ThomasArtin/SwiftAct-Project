/* 
 * File:   DIO.h
 * Author: thomas
 *
 * Created on June 29, 2020, 1:45 PM
 */

#ifndef DIO_H
#define	DIO_H

#define HIGH 1
#define LOW  0
/*Ports of the MCU*/
enum DIO_PORTS
{
    DIOPORTA,
    DIOPORTB,
    DIOPORTC,
    DIOPORTD,
    DIOPORTE
};

extern void DIO_SetPortDirection (uint_8 Port,uint_8 Direction);
extern void DIO_SetPortData (uint_8 Port,uint_8 Data);
extern uint_8 DIO_GetPortData (uint_8 Port,uint_8 Data);
extern void DIO_PullUpPORTB(void);

#endif	/* DIO_H */

