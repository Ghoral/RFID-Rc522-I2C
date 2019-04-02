/*
 * RTC.c
 *
 * Created: 3/31/2019 11:49:51 PM
 *  Author: lovish
 */ 

#include "Rfid.h"
#include "I2C.avr.h"

void Rfid_Start()
{
	I2C_Init();
	I2C_Start();
	I2C_Write(Write_Address);
	I2c_Stop();
}

void Rfid_get_data(Rc522 *rfid)
{
	I2C_Start();
	I2C_Write(Write_Address);
	I2c_Stop();
	
	I2C_Start();
	I2C_Write(Read_Address); 
	rfid->data=I2c_read_Ack(0);
	I2c_Stop();
    
}