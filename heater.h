/* 
 * File:   heater.h
 * Author: thomas
 *
 * Created on July 8, 2020, 4:21 AM
 */

#ifndef HEATER_H
#define	HEATER_H

#include "Typdefs.h"

/************flags register**********/

typedef union
{
    struct
    {
        unsigned PowerPressed     :1;
        unsigned UpPressed        :1;
        unsigned DownPressed      :1;
        unsigned Timer2Adc        :1;
        unsigned b5     :1;
        unsigned b6     :1;
        unsigned b7     :1;
        unsigned b8     :1;
        unsigned b9     :1;
        unsigned b10    :1;
        unsigned b11    :1;
        unsigned b12    :1;
        unsigned b13    :1;
        unsigned State  :3;
    };
    uint_16 Flag;
}Flag_16;
extern volatile  Flag_16 Flags;
/***********************************/
/**************States**************/
#define OFF_mode             0
#define ON_mode              1
#define Temp_setting_mode    2
/***********************************/
/***********mapping*****************/
#define UP_Button          B2
#define Down_Button        B1
#define Power_Button       B0

/*************defines***************/
#define Max_SetTemp         75
#define Min_SetTemp         35
#define Button_Inecrement   5
#define Num_ADC_Samples     10
#define Temp_MaxError       5

extern void Heater_Main(void);
extern void Heater_FSM(void);
#endif	/* HEATER_H */

