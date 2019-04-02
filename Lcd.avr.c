/*
 * LCD.c
 *
 * Created: 1/13/2019 8:57:55 PM
 * Author : lovish
 */ 

#include "Lcd.avr.h"

void lcd_init() // fuction for intialize
{
	_delay_ms(1);
    dis_cmd(0x01);
	dis_cmd(0x02); // to initialize LCD in 4-bit mode.
	dis_cmd(0x28); //to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	dis_cmd(0x0e); //enable cursor
//	dis_cmd(0x06); cursor increment 
	dis_cmd(0x80); //cursor set to start position
}

void dis_cmd(char cmd_value)
{
	char cmd_value1;
	
	cmd_value1 = cmd_value & 0xF0; //mask lower nibble because PA4-PA7 pins are used.
	lcdcmd(cmd_value1); // send to LCD
	
	cmd_value1 = ((cmd_value<<4) & 0xF0); //shift 4-bit and mask
	lcdcmd(cmd_value1); // send to LCD
}

void dis_data(char data_value)
{
	char data_value1;
	
	data_value1=data_value&0xF0;
	lcddata(data_value1);
	
	data_value1=((data_value<<4)&0xF0);
	lcddata(data_value1);
}

void lcdcmd(char cmdout)
{
	PORTB=cmdout;
	PORTB&=~(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(1);
	PORTB&=~(1<<en);
	_delay_ms(1);
}

void lcddata(char dataout)
{
	PORTB=dataout;
	PORTB|=(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(1);
	PORTB&=~(1<<en);
	_delay_ms(1);
}

void lcdprint( char* str)
{
	
	while (*str !=0)
	{
		dis_data(*str);
		_delay_ms(100);
		str++;
	
	}
	
}

void LCD_String_xy(int row,int column)
{
	 unsigned int position[]={0x80,0xc0};
		dis_cmd(position[column]+row);
}




