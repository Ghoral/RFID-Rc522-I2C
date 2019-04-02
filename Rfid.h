/*
 * RTC.h
 *
 * Created: 3/31/2019 11:50:00 PM
 *  Author: lovish
 */ 


#include <avr/io.h>

typedef struct {
	
	unsigned int data;
	
}Rc522;
   
#define Write_Address 0x50
#define Read_Address 0x51

void Rfid_Start();
void Rfid_get_data();