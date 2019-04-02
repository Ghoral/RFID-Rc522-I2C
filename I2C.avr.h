/*
 * I2C.h
 *
 * Created: 3/22/2019 6:20:56 PM
 *  Author: lovish
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <math.h>




#define SCL_CLk 1000000L

#define BITRATE(TWSR) ((F_CPU/SCL_CLk)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

void I2C_Init();
void I2C_Start();
void I2C_Write(uint8_t i2c_data_u8);
uint8_t I2c_read_Ack(char i2c_data_ack);
void I2c_Stop();