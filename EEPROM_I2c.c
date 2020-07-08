#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "I2c.h"
#include "EEPROM_I2c.h"
/*writes a buffer to a specific address in the eeprom*/
void EEPROM_Write(uint_8 byte_address, uint_8* buffer)
{
    I2C_start();
    I2C_write(EEPROM_Add|EEPROM_WriteBit);
    I2C_write(byte_address);
    I2C_write(*(buffer));
    I2C_write(*(buffer+1));
    I2C_stop();

}
/*Reads a buffer from a specific address in the eeprom*/
void EEPROM_Read(uint_8 byte_address, uint_8* buffer)
{   
    I2C_start();
    I2C_write(EEPROM_Add|EEPROM_WriteBit);
    I2C_write(byte_address);
    I2C_repeated_start();
    I2C_write(EEPROM_Add|EEPROM_ReadBit);
    *(buffer) = I2C_read(0);
    *(buffer+1) = I2C_read(1);
    I2C_stop();
}

/*generate 8-bit CRC*/
uint_8 EEPROM_GenCRC (uint_8 data)
{
    uint_8 crc = 0xff;
    uint_8  j;
    crc ^= data;
    for (j = 0; j < 8; j++) {
        if ((crc & 0x80) != 0)
            crc = (uint_8)((crc << 1) ^ 0x31);
        else
            crc <<= 1;
        }
    return crc;
}

