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
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
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
#include "Seg.h"
#include "EEPROM_I2c.h"
#include "I2c.h"
#include "INT.h"
#include "INTHandlers.h"
#include "heater.h"
volatile Flag_16 Flags;
void main()
{   
    /*Initialize I2C for 100KHZ*/
    I2C_init (100000);
    /*Initialize Temperature controlling driver*/
    Temp_Init();
    /*Initialize 7 segment displays*/
    Seg_Init();
    /*Initialize ADc peripheral*/
    ADC_Init();
    /*Sets the Interrupt CallBack functions
     * (these functions are found in INTHandlers.c)*/
    INT_RB0_IntCallBack    (RBO_INT_WakeUp);
    INT_TIMER0_IntCallBack (TIMER0_Buttons);
    INT_TIMER1_IntCallBack (TIMER1_TempSettingModeExit);
    INT_TIMER2_IntCallBack (TIMER2_ADC);
    /*Initialize interrupts*/
    INT_int();
    while(1)
    {   /*Main loop */
        Heater_Main();
    } 
} 