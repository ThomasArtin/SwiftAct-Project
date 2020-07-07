/* 
 * File:   EEPROM_I2c.h
 * Author: thomas
 *
 * Created on July 2, 2020, 11:32 PM
 */

#ifndef EEPROM_I2C_H
#define	EEPROM_I2C_H

#define EEPROM_Add      0xA0
#define EEPROM_WriteBit 0x00
#define EEPROM_ReadBit  0x01
#define _XTAL_FREQ 20000000 

extern void EEPROM_WB   (uint_8 byte_address, uint_8 byte);
extern uint_8 EEPROM_RB (uint_8 byte_address);

#endif	/* EEPROM_I2C_H */

