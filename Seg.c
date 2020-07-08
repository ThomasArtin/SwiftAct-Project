
#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "Seg.h"

/*Initializes the seven segment displays*/
void Seg_Init(void)
{
    DIO_SetPinDirection(Seg_Disp2,OUTPUT);
    DIO_SetPinDirection(Seg_Disp3,OUTPUT);
    DIO_SetPinDirection(Seg_Disp4,OUTPUT);
    DIO_SetPortDirection(Seg_Port,AllOUTPUT);
}
/*Turn on a certain display, turn off the others and write a number to that display*/
void Seg_DispNumber (uint_8 Display,uint_8 Number, uint_8 Dot)
{
    switch (Display)
    {
        case Seg_Disp2:
            DIO_SetPinValue(Seg_Disp2,HIGH);
            DIO_SetPinValue(Seg_Disp3,LOW);
            DIO_SetPinValue(Seg_Disp4,LOW);
            break;
        case Seg_Disp3:
            DIO_SetPinValue(Seg_Disp3,HIGH);
            DIO_SetPinValue(Seg_Disp2,LOW);
            DIO_SetPinValue(Seg_Disp4,LOW);
            break;
        case Seg_Disp4:
            DIO_SetPinValue(Seg_Disp4,HIGH);
            DIO_SetPinValue(Seg_Disp2,LOW);
            DIO_SetPinValue(Seg_Disp3,LOW);
            break;
    }
    switch (Number)
    {
        case 0:
            DIO_SetPortData(Seg_Port,Seg_zero|Dot);
            break;
        case 1:
            DIO_SetPortData(Seg_Port,Seg_one|Dot);
            break;
        case 2:
            DIO_SetPortData(Seg_Port,Seg_two|Dot);
            break;
        case 3:
            DIO_SetPortData(Seg_Port,Seg_three|Dot);
            break;
        case 4:
            DIO_SetPortData(Seg_Port,Seg_four|Dot);
            break;
        case 5:
            DIO_SetPortData(Seg_Port,Seg_five|Dot);
            break;
        case 6:
            DIO_SetPortData(Seg_Port,Seg_six|Dot);
            break;
        case 7:
            DIO_SetPortData(Seg_Port,Seg_seven|Dot);
            break;
        case 8:
            DIO_SetPortData(Seg_Port,Seg_eight|Dot);
            break;
        case 9:
            DIO_SetPortData(Seg_Port,Seg_nine|Dot);
            break;
    }
    
}

extern void Seg_Disp2Dig (uint_16 DispValue)
{
   
    Seg_DispNumber(Seg_Disp3,(DispValue%100)/10,Seg_NoDot);
    __delay_ms(1);
    Seg_DispNumber(Seg_Disp4,(DispValue%100)%10,Seg_NoDot);
    __delay_ms(1);
}

extern void Seg_DispOff(void)
{
    DIO_SetPinValue(Seg_Disp2,LOW);
    DIO_SetPinValue(Seg_Disp3,LOW);
    DIO_SetPinValue(Seg_Disp4,LOW);
}