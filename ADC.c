#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "ADC.h"

/*initializes the ADC module with a sampling freq = OSfreq/2*/
void ADC_Init(void)
{   
    /*Turn off the ADC module*/
    ADCON0bits.ADON = 0;
    /*Set sampling freq = OSfreq/2*/
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS0 = 0;
    /*ADRESH right is justified*/
    ADCON1bits.ADFM = 1;
}
/*Get a one-shot read of the ADC channel selected*/
sint_16 ADC_READ(uint_8 ADCChannel)
{
    /*Turn on ADC module*/
    ADCON0bits.ADON = 1;
    /*Select correct channel*/
    for (uint_8 i = 0; i < 3; i++)
    {
        if (Get_Bit(ADCChannel,i) == 1) Set_Bit(ADCON0,i+3);
        else                            Clear_Bit(ADCON0,i+3);
    }
    __delay_ms(1);
    /*Start the ADC conversion*/
    ADCON0bits.GO_DONE = 1;
    /*wait for the conversion to end*/
    while (ADCON0bits.GO_DONE == 1);
    /*Turn off ADC module*/
    ADCON0bits.ADON = 1;
    /*return right justified 10-bit result*/
    return((ADRESH<<8) + ADRESL);

}