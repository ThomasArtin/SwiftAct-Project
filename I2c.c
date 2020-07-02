#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "I2c.h"

/*Initializes SDA and SCK pins direction and sets the appropriate bits in the
 *in the control registers as master                                                */
void I2c_Init (uint_32 freq)
{
    DIO_SetPinDirection(I2c_SDA,INPUT);
    DIO_SetPinDirection(I2c_SCK,INPUT);
    SSPCON2 = 0b00000000;
    SSPCON  = 0b00101000;
    SSPADD = (_XTAL_FREQ/(4*freq*100))-1;
    SSPSTAT = 0b00000000; 
}
/*Stretch the I2c until operation is complete*/
void I2c_wait(void)
{
    while ((SSPSTAT&0x04)||(SSPCON2&0x1F)) ;
}
/*Begin I2c protocol*/
void I2c_Begin(void)
{
    I2c_wait();
    /*Start Condition Enabled/Stretch Enabled bit*/
    SSPCON2bits.SEN = 1;
}
/*End I2c protocol*/
void I2c_End(void)
{
    I2c_wait();
    /*Stop Condition Enable bit*/
    SSPCON2bits.PEN = 1;
}
/*Writes a byte*/
void I2c_WB(uint_8 data)
{
    I2c_wait();
    SSPBUF = data;
}
/*Reads a byte*/
uint_8 I2c_RB(void)
{   
    I2c_wait();
    /*Receive Enable bit*/
    SSPCON2bits.RSEN = 1;
    /*Return read data from the buffer*/
    I2c_wait();
    return SSPBUF;
}