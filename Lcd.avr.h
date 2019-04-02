/*
 * Lcd.h
 *
 * Created: 3/22/2019 6:27:10 PM
 *  Author: lovish
 */ 




#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define rs PB0
#define rw PB1
#define en PB2

void lcd_init();
void dis_cmd(char);
void dis_data(char);
void lcdcmd(char);
void lcddata(char);
void lcdprint(char* str);
void clear();
void lcd_home();
void LCD_String_xy(int row,int column);


