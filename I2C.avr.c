/*
 * I2C.c
 *
 * Created: 3/22/2019 6:20:45 PM
 *  Author: lovish
 */ 

#include "I2C.avr.h"
#include <stdbool.h>



void I2C_Init()
{
	
	TWBR = BITRATE(TWSR=0x00);
	
}

void I2C_Start()
{
	TWCR = ((1<<TWINT)|(1<<TWEN)|(TWSTA));
	while (!(TWCR&(1<<TWINT)));
	
}

void I2C_Write(uint8_t i2c_data_u8)
{
	TWDR = i2c_data_u8;
	TWCR = ((1<<TWINT)|(1<<TWEN));
	while (!(TWCR&(1<<TWINT)));
    
	
}


uint8_t I2c_read_Ack(char i2c_data_ack)
{
	TWCR = ((1<<TWINT)|(TWEN)|(i2c_data_ack<<TWEA));
	while (!(TWCR & (1<<TWINT)));
	return (TWDR);
	
}

void I2c_Stop()
{
	TWCR = ((1<<TWINT)|(1<<TWSTO)|(TWEN));
	while(TWCR &(1<<TWINT));
}