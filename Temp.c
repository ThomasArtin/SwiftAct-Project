
#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "ADC.h"
#include "Temp.h"

/*Read temp sensor from the ADC channel*/
sint_16 Temp_ReadTemp(void)
{
    return ADC_READ(TempSensorChannel);
}
/*Turn on the cooling element*/
void Temp_TurnOnCooler(void)
{
    PORTCbits.RC2 = HIGH;
}
/*Tun off the cooling element*/
void Temp_TurnOffCooler(void)
{
    PORTCbits.RC2 = LOW;
}
/*Tun on the heating element*/
void Temp_TurnOnHeater (void)
{
    PORTCbits.RC5 = HIGH;

}
/*Turn off the heating element*/
void Temp_TurnOffHeater  (void)
{
    PORTCbits.RC5 = LOW;
}