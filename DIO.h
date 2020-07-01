/* 
 * File:   DIO.h
 * Author: thomas
 *
 * Created on June 29, 2020, 1:45 PM
 */

#ifndef DIO_H
#define	DIO_H

#define HIGH        1
#define LOW         0
#define OUTPUT      0
#define INPUT       1
#define AllOUTPUT   0x00
#define ALLINPUT    0xFF

/*Ports of the MCU*/
enum DIO_PORTS
{
    DIOPORTA,
    DIOPORTB,
    DIOPORTC,
    DIOPORTD,
    DIOPORTE
};
/*Pins of the MCU*/
enum DIO_PINS
{
    A0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	B0,
	B1,
	B2,
	B3,
	B4,
	B5,
	B6,
	B7,
	C0,
	C1,
	C2,
	C3,
	C4,
	C5,
	C6,
	C7,
	D0,
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7,
    E0,
    E1,
    E2,
    E3,
    E4,
    E5,
    E6,
    E7
};
extern void DIO_SetPortDirection    (uint_8 Port,uint_8 Direction);
extern void DIO_SetPortData         (uint_8 Port,uint_8 Data);
extern uint_8 DIO_GetPortData       (uint_8 Port,uint_8 Data);
extern void DIO_PullUpPORTB         (void);
extern void DIO_SetPinDirection     (uint_8 Pin, uint_8 Direction);
extern void DIO_SetPinValue         (uint_8 Pin,uint_8 Value);
extern uint_8 DIO_GetPinValue       (uint_8 Pin);

#endif	/* DIO_H */

