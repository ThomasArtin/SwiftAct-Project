#include <xc.h>
#include "BIT_CALC.h"
#include "Typdefs.h"
#include "DIO.h"
#include "I2c.h"
#include "EEPROM_I2c.h"

/*writes a byte to a specific address in the eeprom*/
volatile uint_8 bug = 0;
void EEPROM_WB(uint_8 byte_address, uint_8 byte)
{
    I2c_Begin();
    I2c_WB(0b10100000);
    I2c_WB(byte_address);
    I2c_WB(byte);
    I2c_End();

}
/*Reads a byte from a specific address in the eeprom*/
uint_8 EEPROM_RB(uint_8 byte_address)
{   
    uint_8 read_byte ;
    I2c_Begin();
    I2c_WB(0b10100000);
    I2c_WB(byte_address);
    I2c_RepeatedStart();
    bug = 1;
    I2c_WB(0b10100001);
    bug = 2;
    read_byte = I2c_RB();
    bug = 3;
    bug = read_byte;
    I2c_NAck();
    bug = 4;
    I2c_End();
    bug = 5;
    return read_byte;
}