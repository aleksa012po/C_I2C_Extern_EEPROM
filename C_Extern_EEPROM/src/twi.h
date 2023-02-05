/*
 * twi.h
 *
 * Created: 17.1.2023. 01:40:36
 *  Author: Aleksandar Bogdanovic
 */ 


#ifndef TWI_H_
#define TWI_H_

void TWI_Init (void);
void TWI_Start (void);
void TWI_Stop (void);
void TWI_Write (char data);
void TWI_Read_Nack (char* ptr);

#endif /* TWI_H_ */