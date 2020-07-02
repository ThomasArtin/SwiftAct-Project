/* 
 * File:   I2c.h
 * Author: thomas
 *
 * Created on July 2, 2020, 3:28 PM
 */

#ifndef I2C_H
#define	I2C_H

#define _XTAL_FREQ 20000000 

/*define SDA and SCK pins*/
#define I2c_SDA C4
#define I2c_SCK C3

extern void I2c_Init        (uint_32 freq);
extern void I2c_wait        (void);
extern void I2c_Begin       (void);
extern void I2c_End         (void);
extern void I2c_WB          (uint_8 data);
extern uint_8 I2c_RB        (void);


#endif	/* I2C_H */

