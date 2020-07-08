/* 
 * File:   EEPROM_I2c.h
 * Author: thomas
 *
 * Created on July 2, 2020, 11:32 PM
 */

#ifndef EEPROM_I2C_H
#define	EEPROM_I2C_H

#define EEPROM_Add          0xA0
#define EEPROM_WriteBit     0x00
#define EEPROM_ReadBit      0x01
#define _XTAL_FREQ          20000000 
#define EEPROM_TempAndCRCLoc       0x00
#define EEPROM_TempAndCRCLocRed    0x02
extern void EEPROM_Write    (uint_8 byte_address, uint_8* buffer);
extern void EEPROM_Read     (uint_8 byte_address, uint_8* buffer);
extern uint_8 EEPROM_GenCRC (uint_8 data);
#endif	/* EEPROM_I2C_H */

