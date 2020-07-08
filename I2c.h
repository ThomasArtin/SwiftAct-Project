/* 
 * File:   I2c.h
 * Author: thomas
 *
 * Created on July 2, 2020, 3:28 PM
 */

#ifndef I2C_H
#define	I2C_H

#include "Typdefs.h"


#define _XTAL_FREQ 20000000 

/*define SDA and SCK pins*/
#define I2c_SDA C4
#define I2c_SCK C3

void I2C_init           (uint_32 clock);
void I2C_wait           (void);
void I2C_start          (void);
void I2C_repeated_start (void);
void I2C_stop           (void);
void I2C_write          (uint_8 data);
uint_8 I2C_read         (uint_8 ack);


#endif	/* I2C_H */

