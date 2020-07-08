
#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "ADC.h"
#include "Temp.h"
#include "Seg.h"
#include "EEPROM_I2c.h"
#include "I2c.h"
#include "INT.h"
#include "INTHandlers.h"
#include "heater.h"

volatile Flag_16 Flags;
volatile uint_8  SetTemp = 60;
void Heater_Main(void)
{   
    /*If in OFF mode and power is pressed go to ON if anything than OFF go to OFF*/
    if (Flags.PowerPressed == 1)
    {
        Flags.PowerPressed = 0;
        if (Flags.State == OFF_mode) 
        {
            Flags.State = ON_mode;
        }
        /*turn off timers and display and enter sleep mode*/
        else
        {
            Flags.State = OFF_mode;
            Seg_DispOff();
            INT_TIMER0_OFF();
            INT_TIMER1_OFF();
            INT_TIMER2_OFF();
            SLEEP();
        }
    }
    
    if (Flags.UpPressed == 1)
    {
        Flags.UpPressed = 0;
        /*If UP is pressed and in ON mode go to TempSettingMode*/
        if (Flags.State == ON_mode) Flags.State = Temp_setting_mode;
        /*If UP is pressed and in TempSettingMode increment setTemp by 5*/
        if (Flags.State == Temp_setting_mode)
        {
            if (SetTemp < 75) SetTemp += 5;
        }
    }
    
    if (Flags.DownPressed == 1)
    {
        Flags.DownPressed = 0;
        /*If Down is pressed and in ON mode go to TempSettingMode*/
        if (Flags.State == ON_mode) Flags.State = Temp_setting_mode;
        /*If UP is pressed and in TempSettingMode decrement setTemp by 5*/
        if (Flags.State == Temp_setting_mode)
        {
            if (SetTemp > 35) SetTemp -= 5;
        }
        
    }
    Heater_FSM();
}

void Heater_FSM(void)
{
    switch (Flags.State)
    {
        case (ON_mode):
            Seg_Disp2Dig(SetTemp);
            break;
        case (OFF_mode):
            
            break;
        case (Temp_setting_mode):
            Seg_Disp2Dig(SetTemp);
            break;
        
    }
}