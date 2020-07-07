#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "INT.h"
#include "INTHandlers.h"

/*Global Variables*/
#if (INT_RB0 == ON)
callback RBO_INTHANDLER = NULL;
#endif
#if (INT_PORTBINTCON == ON)
callback PORTBINTCON_INTHANDLER = NULL;
#endif
#if (INT_TIMER0 == ON)
callback TIMER0_INTHANDLER = NULL;
#endif
#if (INT_TIMER1 == ON)
callback TIMER1_INTHANDLER  = NULL;
#endif
#if (INT_TIMER2 == ON)
callback TIMER2_INTHANDLER  = NULL;
#endif
/*Initializes interrupt registers
 *you can configure what gets initialized
 in INT.h                               */
void INT_int (void)
{   
#if ((INT_RB0 == ON) || (INT_PORTBINTCON == ON))
    INT_PullUpPORTB();
#endif
#if (INT_RB0 == ON)
    /*RB0 int enable*/
    INTCONbits.INTE = 1;
    /*int edge select*/
    OPTION_REGbits.INTEDG = INT_RB0_Edge;
#endif
#if (INT_PORTBINTCON == ON)
    /*PORTBINTCON int enbale*/
    INTCONbits.RBIE = 1;
#endif
#if (INT_TIMER0 == ON)
    /*timer0 int enable*/
    INTCONbits.TMR0IE = 1;
    /*Set prescalar to 256*/
    OPTION_REG |= 0b0000111;
    /*timer internal clock source*/
    OPTION_REGbits.T0CS = 0;
    /*timer preload value*/
    TMR0 = TIMER0_Preload;
#endif
#if (INT_TIMER1 == ON)
    /*set prescalar to 8*/
    T1CON |= 0b00110000;
    /*enable timer1 interrupt*/
    PIE1bits.TMR1IE = 1;
    /*turn off oscillator */
    T1CONbits.T1OSCEN = 0;
    /*turn off ext clock synchro*/
    T1CONbits.T1SYNC = 0;
    /*select clock input to be internal*/
    T1CONbits.TMR1CS = 0;
    /*turn timer on*/
    T1CONbits.TMR1ON = 1;
    /*enter preload values*/
    TMR1H = TIMER1_Preload >> 8;
    TMR1L = TIMER1_Preload << 8;
#endif
#if (INT_TIMER2 == ON)
    /*timer2 int enable*/
    PIE1bits.TMR2IE = 1;
    /*set prescalar and postscalar both to 16*/
    T2CON |= 0b01111011;
    /*turn timer 2 on*/
    T2CONbits.TMR2ON = 1;
    TMR2 = TIMER2_Preload;
#endif
    /*enable global int*/
    INTCONbits.GIE = 1;
    /*enables peripheral int*/
    INTCONbits.PEIE = 1;
}

/*Set ISR handlers*/
#if (INT_RB0 == ON)
void INT_RB0_IntCallBack (callback RB0_INTHandlerPtr)
{
    RBO_INTHANDLER = RB0_INTHandlerPtr;
}
#endif
#if (INT_PORTBINTCON == ON)
void INT_PORTBINTCON_IntCallBack (callback PORTBINTCON_INTHandlerPtr)
{
    PORTBINTCON_INTHANDLER = PORTBINTCON_INTHandlerPtr;
}
#endif
#if (INT_TIMER0 == ON)
    void INT_TIMER0_IntCallBack (callback TIMER0_INTHandlerPtr)
    {
        TIMER0_INTHANDLER = TIMER0_INTHandlerPtr;
    }
#endif
#if (INT_TIMER1 == ON)
    void INT_TIMER1_IntCallBack (callback TIMER1_INTHandlerPtr)
    {
        TIMER1_INTHANDLER = TIMER1_INTHandlerPtr;
    }
#endif
#if (INT_TIMER2 == ON)
    void INT_TIMER2_IntCallBack (callback TIMER2_INTHandlerPtr)
    {
        TIMER2_INTHANDLER = TIMER2_INTHandlerPtr;
    }
#endif
/*Sets PORTB to be output and pull all the pins to a weak pull-up*/
void INT_PullUpPORTB(void)
{
    DIO_SetPortDirection(DIOPORTB,0xFF);
    OPTION_REGbits.nRBPU = 0;
}

void __interrupt() ISR(void)
{   
   /*RB0 INT*/
#if (INT_RB0 == ON)
    if(INTCONbits.INTF == 1)
    {   
        (*RBO_INTHANDLER)();
        INTCONbits.INTF = 0;
    }
#endif
#if (INT_PORTBINTCON == ON)
    if(INTCONbits.RBIF == 1)
    {
        (*PORTBINTCON_INTHANDLER)();
        INTCONbits.RBIF = 0;
    }
#endif
#if (INT_TIMER0 == ON)
    if (INTCONbits.T0IF == 1)
    {
        (*TIMER0_INTHANDLER)();
        INTCONbits.T0IF = 0;
    }
#endif
#if (INT_TIMER1 == ON)
    if (PIR1bits.TMR1IF == 1)
    {
        (*TIMER1_INTHANDLER)();
        PIR1bits.TMR1IF = 0;
    }
#endif
#if (INT_TIMER2 == ON)
    if (PIR1bits.TMR2IF == 1)
    {
        (*TIMER2_INTHANDLER)();
        PIR1bits.TMR2IF = 0;
    }
#endif
}
