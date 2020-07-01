
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
    DIO_SetPinValue(TempCoolingElement,HIGH);
}
/*Tun off the cooling element*/
void Temp_TurnOffCooler(void)
{
    DIO_SetPinValue(TempCoolingElement,LOW);
}
/*Tun on the heating element*/
void Temp_TurnOnHeater (void)
{
    DIO_SetPinValue(TempHeatingElement,HIGH);

}
/*Turn off the heating element*/
void Temp_TurnOffHeater  (void)
{
    DIO_SetPinValue(TempHeatingElement,LOW);
}