/*
 * RFID_I2C_1.c
 *
 * Created: 3/31/2019 11:48:15 PM
 * Author : lovish
 */ 

#define F_CPU 16000000UL
#include <avr/io.h> 
#include <string.h>
 
#include "Rfid.h"
#include "Lcd.avr.h"
#include "I2C.avr.h"
int main()
{
	
	int i;
	char buffer[20];
	Rc522 rfid;
	DDRB = 0xFF;
	DDRC = 0xFF;
	lcd_init();
	_delay_ms(100);
	lcdprint("Show your card:");
    Rfid_Start();
	 
    while(1) 
    {
			sprintf(buffer,"%d",rfid.data);
			LCD_String_xy(0,1);
			lcdprint(buffer);
    }


}