/*
 * C_Software_EEPROM.c
 *
 * Created: 14.1.2023. 22:50:20
 * Author : Aleksandar Bogdanovic
 */ 

/*  Arduino program koji koristi hardverski TWI/I2C interfejs kako bi
pisao i citao na EEPROM (24LC256 256K I2C CMOS Serial EEPROM). Output
je na PORTD7 na LED diodi koja proverava ispravnost programa. Program 
inkrementuje vrednost bajta i upisuje na EEPROM na adresu 0x02 i zatim
cita vrednost sa iste adrese. Provera na LED diodi vrsi se kada inkrement
bude vrednost 0x10. */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "twi.h"
#include "eeprom.h"

void ee_read_write_func()								// Write and read to EEPROM from 0 to 255
{
	char R;
	
	for (uint8_t byte = 0; byte < 255; byte++)
	{
		
		EEPROM_Write(byte,0x02);						// 0x02 is address to be written to
		_delay_ms(1000);								// You must allow sufficient delay for the EEPROM to complete the its internal write cycle
		EEPROM_Read(0x02,&R);

		if (R == 0x10)
		{
			led_on();
			_delay_ms(400);
		}
		else
		{
			PORTD &= ~(1 << PORTD7);					// Turn off
		}
	}
}

void led_on()
{
	DDRD = 0xFF;
	PORTD |= (1 << PORTD7);
}


int main(void)
{
	TWI_Init();

	while(1)
	{
		ee_read_write_func();
	}
}