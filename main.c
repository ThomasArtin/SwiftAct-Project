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

volatile uint_8 bug_1 = 0;
void main()
{
    Temp_Init();
    Seg_Init();
    ADC_Init();
    INT_TIMER0_IntCallBack (TIMER0_ReadAdc100ms);
    INT_TIMER1_IntCallBack (TIMER1_1s);
    INT_TIMER2_IntCallBack (TIMER2_100ms);
    INT_RB0_IntCallBack(RBO_INT_Cooler);
    INT_int();
    //I2c_Init(1000000);
    uint_1 toggle = 0;
   /* EEPROM_WB(0x00,0x03);
    uint_8 read_byte;
    __delay_ms(1000);
    read_byte = EEPROM_RB(0x00);*/
    while(1)
    {   
        //Seg_Disp2Dig(Temp_ReadTemp());
        //Seg_Disp2Dig(read_byte);
       /* if (PORTBbits.RB1 == LOW)
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
                
        }
        else
        {
                
        }
        */
    } 
} 