#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "INT.h"
#include "INTHandlers.h"
#include "Temp.h"
volatile  uint_8 bug_inth = 0;

void RBO_INT_Cooler(void)
{
    Temp_TurnOnCooler();

}
void PORTBINTCON_INT_Temp(void)
{   
  

}
void TIMER0_ReadAdc100ms(void)
{
    static uint_8 overflow_count = 0;
    if (overflow_count == TIMER0_OverFlowCounts+1)
    {
        overflow_count = 0;
        Toggle_Bit(PORTD,1);
        TMR0 = TIMER0_Preload+1;
    }
    overflow_count++;
    
}
void TIMER1_1s(void)
{
    static uint_8 overflow_count = 0;
    if (overflow_count == 10)
    {
        overflow_count = 0;
        Toggle_Bit(PORTD,2);
        TMR1H = TIMER1_Preload >> 8;
        TMR1L = TIMER1_Preload << 8;
    }
    overflow_count ++;
}

void TIMER2_100ms(void)
{
    static uint_8 overflow_count = 0;
    if (overflow_count == TIMER2_OverFlowCounts+1)
    {
        overflow_count = 0;
        Toggle_Bit(PORTD,3);
        TMR2 = TIMER2_Preload+1;
    }
    overflow_count++;
}