
#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "ADC.h"
#include "Temp.h"

/*Set Appropriate pins values*/
void Temp_Init(void)
{
    DIO_SetPinDirection(C2,OUTPUT);
    DIO_SetPinDirection(C5,OUTPUT);
}
/*Read temp sensor from the ADC channel*/
uint_16 Temp_ReadTemp(void)
{
    return ADC_READ(TempSensorChannel)*0.488;
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