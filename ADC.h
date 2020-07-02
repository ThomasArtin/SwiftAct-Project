/* 
 * File:   ADC.h
 * Author: thomas
 *
 * Created on June 29, 2020, 10:39 PM
 */

#ifndef ADC_H
#define	ADC_H

#define _XTAL_FREQ 20000000 

extern void ADC_Init        (void);
extern uint_16 ADC_READ     (uint_8 ADCChannel);


#endif	/* ADC_H */

