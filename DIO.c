#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"

/*Configures Directions for ports*/
void DIO_SetPortDirection (uint_8 Port,uint_8 Direction)
{
    switch(Port)
    {
        case DIOPORTA :
            TRISA = Direction;
            break;
         
        case DIOPORTB :
            TRISB = Direction;
            break;
            
        case DIOPORTC :
            TRISC = Direction;
            break;
            
        case DIOPORTD :
            TRISD = Direction;
            break;
            
        case DIOPORTE :
            TRISE = Direction;
            break;
    }
    
}

/*Sets Data for ports*/
void DIO_SetPortData (uint_8 Port,uint_8 Data)
{
        switch(Port)
    {
        case DIOPORTA :
            PORTA = Data;
            break;
         
        case DIOPORTB :
            PORTB = Data;
            break;
            
        case DIOPORTC :
            PORTC = Data;
            break;
            
        case DIOPORTD :
            PORTD = Data;
            break;
            
        case DIOPORTE :
            PORTE = Data;
            break;
    } 
}
/*Gets the port data*/
uint_8 DIO_GetPortData (uint_8 Port,uint_8 Data)
{
    switch(Port)
    {
        case DIOPORTA :
            return PORTA;
            break;
         
        case DIOPORTB :
            return PORTB;
            break;
            
        case DIOPORTC :
            return PORTC;
            break;
            
        case DIOPORTD :
            return PORTD;
            break;
            
        case DIOPORTE :
            return PORTE;
            break;
    } 
}
/*Set pins direction individually*/
void DIO_SetPinDirection (uint_8 Pin, uint_8 Direction)
{
    if ((Pin >= A0) && (Pin <= A5))
    {
        Pin -= A0;
        Assign_Bit(TRISA,Pin,Direction);
    }
    else if ((Pin >= B0) && (Pin <= B7))
    {
        Pin -= B0;
        Assign_Bit(TRISB,Pin,Direction);
    }
    else if ((Pin >= C0) && (Pin <= C7))
    {
        Pin -= C0;
        Assign_Bit(TRISC,Pin,Direction);
    }
    else if ((Pin >= D0) && (Pin <= D7))
    {
        Pin -= D0;
        Assign_Bit(TRISD,Pin,Direction);
    }
    else if ((Pin >= E0) && (Pin <= E7))
    {
        Pin -= E0;
        Assign_Bit(TRISE,Pin,Direction);
    }
}
/*Set pins value individually*/
void DIO_SetPinValue(uint_8 Pin,uint_8 Value)
{
    if ((Pin >= A0) && (Pin <= A5))
    {
        Pin -= A0;
        Assign_Bit(PORTA,Pin,Value);
    }
    else if ((Pin >= B0) && (Pin <= B7))
    {
        Pin -= B0;
        Assign_Bit(PORTB,Pin,Value);
    }
    else if ((Pin >= C0) && (Pin <= C7))
    {
        Pin -= C0;
        Assign_Bit(PORTC,Pin,Value);
    }
    else if ((Pin >= D0) && (Pin <= D7))
    {
        Pin -= D0;
        Assign_Bit(PORTD,Pin,Value);
    }
    else if ((Pin >= E0) && (Pin <= E7))
    {
        Pin -= E0;
        Assign_Bit(PORTE,Pin,Value);
    }
}

/*Get pins value individually*/
uint_8 DIO_GetPinValue(uint_8 Pin)
{
    if ((Pin >= A0) && (Pin <= A5))
    {
        Pin -= A0;
        return Get_Bit(PORTA,Pin);
    }
    else if ((Pin >= B0) && (Pin <= B7))
    {
        Pin -= B0;
        return Get_Bit(PORTB,Pin);;
    }
    else if ((Pin >= C0) && (Pin <= C7))
    {
        Pin -= C0;
        return Get_Bit(PORTC,Pin);
    }
    else if ((Pin >= D0) && (Pin <= D7))
    {
        Pin -= D0;
        return Get_Bit(PORTD,Pin);
    }
    else if ((Pin >= E0) && (Pin <= E7))
    {
        Pin -= E0;
        return Get_Bit(PORTE,Pin);
    }
}
/*Sets PORTB to be output and pull all the pins to a weak pull-up*/
void DIO_PullUpPORTB(void)
{
    DIO_SetPortDirection(DIOPORTB,0xFF);
    OPTION_REGbits.nRBPU = 0;
}