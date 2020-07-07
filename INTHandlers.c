#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "INT.h"
#include "INTHandlers.h"
#include "Temp.h"
volatile uint_8 overflow_count = 0;
volatile  uint_8 bug_inth = 1;
void RBO_INT_Cooler(void)
{
    Temp_TurnOnCooler();

}
void PORTBINTCON_INT_Temp(void)
{   
    static uint_8 toggle = 0;
    toggle ++;
    if (toggle%2 == 0)
    {
     Temp_TurnOnCooler();
     Temp_TurnOffHeater();
    }
    else
    {
     Temp_TurnOnHeater();
     Temp_TurnOffCooler();
    }

}
void TIMER0_INT(void)
{
    
    bug_inth = TIMER0_OverFlowCounts;
    if (overflow_count == TIMER0_OverFlowCounts+1)
    {
        overflow_count = 0;
        Toggle_Bit(PORTD,1);
        TMR0 = TIMER0_Preload+1;
    }
    overflow_count++;
    
}