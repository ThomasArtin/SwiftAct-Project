/*
 * File:   main.c
 * Author: thomas
 *
 * Created on June 29, 2020, 5:02 PM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "ADC.h"
#include "Temp.h"

void main()
{
    DIO_SetPortDirection(DIOPORTD,0x00);
    DIO_SetPortDirection(DIOPORTC,0x00);
    DIO_PullUpPORTB();
    ADC_Init();
    volatile sint_16 adcvalue;
    uint_1 toggle = 0;
    while(1)
    {   
        
        if (PORTBbits.RB1 == LOW)
        {       
            if(toggle == 1)
            {
                Temp_TurnOnCooler();
                Temp_TurnOffHeater();
                toggle = 0;
            }
            else
            {
                Temp_TurnOffCooler();
                Temp_TurnOnHeater();
                toggle = 1;
            }
                DIO_SetPortData(DIOPORTD,0x0F);
        }
        else
        {
                DIO_SetPortData(DIOPORTD,0xF0);
        }
        adcvalue = Temp_ReadTemp();
    } 
} 