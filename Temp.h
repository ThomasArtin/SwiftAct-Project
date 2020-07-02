    /* 
 * File:   Temp.h
 * Author: thomas
 *
 * Created on July 1, 2020, 1:32 PM
 */

#ifndef TEMP_H
#define	TEMP_H

#include "Typdefs.h"

/*Configure the ADC temp sensor channel,
 *And the cooling element pin and heating
 element pin                            */
#define TempSensorChannel   2
#define TempCoolingElement  C2
#define TempHeatingElement  C5
extern void Temp_Init           (void);
extern uint_16 Temp_ReadTemp    (void);
extern void Temp_TurnOnCooler   (void);
extern void Temp_TurnOffCooler  (void);
extern void Temp_TurnOnHeater   (void);
extern void Temp_TurnOffHeater  (void);

#endif	/* TEMP_H */

