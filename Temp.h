/* 
 * File:   Temp.h
 * Author: thomas
 *
 * Created on July 1, 2020, 1:32 PM
 */

#ifndef TEMP_H
#define	TEMP_H

#define TempSensorChannel 2
extern sint_16 Temp_ReadTemp    (void);
extern void Temp_TurnOnCooler   (void);
extern void Temp_TurnOffCooler  (void);
extern void Temp_TurnOnHeater   (void);
extern void Temp_TurnOffHeater  (void);

#endif	/* TEMP_H */

