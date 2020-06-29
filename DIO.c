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
//void DIO_SetPinDirection()
/*Sets PORTB to be output and pull all the pins to a weak pull-up*/
void DIO_PullUpPORTB(void)
{
    DIO_SetPortDirection(DIOPORTB,0xFF);
    OPTION_REGbits.nRBPU = 0;
}