#include <stdint.h>
#include "Typdefs.h"
//#include "I2C.h"
#include "I2c.h"
uint8_t EEPROM_Read(uint8_t address){
    uint8_t data;
    //I2C_Start();
    I2c_Begin();
    //I2C_Write(0b10100000); // Slave I2C Device Address + Write
    I2c_WB(0b10100000);
    //I2C_Write(address); // Slave I2C Device Address + Write
    I2c_WB(address);
    //I2C_Res();
    I2c_RepeatedStart();
   // I2C_Write(0b10100001); // Slave I2C Device Address + Read
    I2c_WB(0b10100001);
    // data = I2C_Read_Byte();
    data = I2c_RB();
    // I2C_Nack();
    I2c_NAck();
    //I2C_Stop();
     I2c_End();
    return data;
}
/*
void EEPROM_Write (uint8_t address , uint8_t data){

    I2C_Start();
    I2C_Write(0b10100000); // Slave I2C Device Address + Write
    I2C_Write(address); // Data To Be Sent
    I2C_Write(data);
    I2C_Stop();

}
 * */