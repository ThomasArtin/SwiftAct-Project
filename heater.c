
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
volatile uint_16 ReadTemp = NULL;
void Heater_Main(void)
{   
    static uint_8 ADC_Count = 0;
    static uint_32 ADC_Average = 0;
    
    /*If in OFF mode and power is pressed go to ON if anything than OFF go to OFF*/
    if (Flags.PowerPressed == 1)
    {
        Flags.PowerPressed = 0;
        if (Flags.State == OFF_mode) 
        {
            Flags.State = ON_mode;
        }
        /*turn off timers ,display,heater,cooler ,clear ADC count and averages and enter sleep mode*/
        else
        {   
            Temp_TurnOffHeater();
            Temp_TurnOffCooler();
            ADC_Count = 0;
            ADC_Average = 0;
            Flags.State = OFF_mode;
            Seg_DispOff();
            INT_TIMER0_OFF();
            INT_TIMER1_OFF();
            INT_TIMER2_OFF();
            Flags.Timer0Reset = 1;
            Flags.Timer1Reset = 1;
            Flags.Timer2Reset = 1;
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
            if (SetTemp < Max_SetTemp) SetTemp += Button_Inecrement;
            INT_TIMER1_OFF();
            INT_TIMER1_ON();
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
            if (SetTemp > Min_SetTemp) SetTemp -= Button_Inecrement;
            INT_TIMER1_OFF();
            INT_TIMER1_ON();
        }
        
    }
    /*when timer2 has reached 100ms read current ADC value and keep doing that
     for 10 times and get their average, if the MCU is powered OFF that count and
     average will be reset*/
    if (Flags.Timer2Adc == 1)
    {        
        Flags.Timer2Adc = 0;
        ADC_Count ++;
        ADC_Average += Temp_ReadTemp();
        if(ADC_Count == Num_ADC_Samples)
        {
            ReadTemp = ADC_Average/Num_ADC_Samples;
            ADC_Count = 0;
            ADC_Average = 0;
        }
    }
    /*timer2 software timer has overflowed, that timer is set for 1 sec 
     and is used for blinking LEDS and the display*/
    if (Flags.Timer2SoftTimer == 1)
    {
        Flags.Timer2SoftTimer = 0;
        Flags.toggle  = ~Flags.toggle;
       // if (Flags.HeaterOn == 1) DIO_SetPinValue(HeatingElementLed,Flags.toggle);
    }
    //if (Flags.CoolerOn == 1) DIO_SetPinValue(HeatingElementLed,HIGH);
    
    Heater_FSM();
}

void Heater_FSM(void)
{
    switch (Flags.State)
    {
        case (ON_mode):
            Seg_Disp2Dig(ReadTemp);
            /*water temp is colder than set*/
            if (SetTemp >= ReadTemp + Temp_MaxError)
            {
                Temp_TurnOnHeater();
                Temp_TurnOffCooler();
                Flags.HeaterOn = 1;
                Flags.CoolerOn = 0;
            }
            /*water temp is hotter than set*/
            if (ReadTemp >= SetTemp + Temp_MaxError)
            {
                Temp_TurnOnCooler();
                Temp_TurnOffHeater();
                Flags.HeaterOn = 0;
                Flags.CoolerOn = 1;
            }
            break;
        case (OFF_mode):
            
            break;
        case (Temp_setting_mode):
            /*If timer2 software toggles the display toggles with it*/
            if (Flags.toggle == 1) Seg_Disp2Dig(SetTemp);
            else                   Seg_DispOff();
            break;
        
    }
}