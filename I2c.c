#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "I2c.h"

/*Initializes SDA and SCK pins direction and sets the appropriate bits in the
 *in the control registers as master                                                */
void I2c_Init (uint_32 freq)
{   
    SSPADD = 49;
    DIO_SetPinDirection(I2c_SDA,INPUT);
    DIO_SetPinDirection(I2c_SCK,INPUT);
    SSPCON  = 0b00101000;
    SSPCON2 = 0x00;   
    SSPSTAT = 0x00;	 
}
/*Stretch the I2c until operation is complete*/
void I2c_wait(void)
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); 
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
   /* uint_8 read_data;
    I2c_wait();
    /*Receive Enable bit*/
   // SSPCON2bits.RCEN = 1;
    /*Return read data from the buffer*/
   /* I2c_wait();
    read_data = SSPBUF;
    I2c_wait();
    I2c_NAck();
    return read_data;*/
     PIR1bits.SSPIF = 0;
     SSPCON2bits.RCEN = 1;
     while(!PIR1bits.SSPIF);
     PIR1bits.SSPIF = 0;
     return SSPBUF;
           
}
/*Send Ack*/
void I2c_Ack(void)
{
    SSPCON2bits.ACKDT = 0;
    I2c_wait();
    SSPCON2bits.ACKEN = 1;
}
/*Send NAck*/
void I2c_NAck(void)
{
    I2c_wait();
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
}
/*Waits for Ack from slave*/
void I2c_WaitAck(void)
{
    while (SSPCON2bits.ACKSTAT);
}
void I2c_RepeatedStart (void)
{
    I2c_wait();
    SSPCON2bits.RSEN = 1;
}