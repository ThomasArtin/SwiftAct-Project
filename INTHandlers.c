#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "Seg.h"
#include "INT.h"
#include "INTHandlers.h"
#include "Temp.h"
#include "heater.h"

volatile Flag_16 Flags;
/*wake up MCU from Sleep*/
void RBO_INT_WakeUp(void)
{   
    __delay_ms(20);
    if (Flags.State == OFF_mode) 
    {
        Flags.State = ON_mode;
        INT_TIMER0_ON();
        INT_TIMER1_ON();
        INT_TIMER2_ON();
    }

}
void PORTBINTCON_INT_Temp(void)
{   
  

}
void TIMER0_Buttons(void)
{
    if (DIO_GetPinValue(Power_Button) == LOW)
    {
        Flags.PowerPressed = 1;
    }
    else if (DIO_GetPinValue(UP_Button) == LOW)
    {
        Flags.UpPressed = 1;
    }
    else if (DIO_GetPinValue(Down_Button) == LOW)
    {
        Flags.DownPressed = 1;
    }
   
}
void TIMER1_1s(void)
{
 
}

void TIMER2_ADC(void)
{
    Flags.Timer2Adc = 1; 
}
