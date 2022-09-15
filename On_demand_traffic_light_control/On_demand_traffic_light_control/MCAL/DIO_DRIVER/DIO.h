/*
 * DIO.h
 *
 * Created: 9/11/2022 2:20:20 AM
 *  Author: Mostafa Ayyad
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/Macros.h"
#include "../../Utilities/Register.h"

//** FUNCTION prototypes **//
void DIO_init(uint8_t portname, uint8_t pinnum, uint8_t direction);
void DIO_write(uint8_t portname, uint8_t pinnum, uint8_t state);
void DIO_toggle(uint8_t portname, uint8_t pinnum);
void DIO_read(uint8_t portname, uint8_t pinnum, uint8_t* result);


//** PORT names **//
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


//** PORT directions **//
#define IN 0
#define OUT 1

//** PORT states **//
#define LOW 0
#define HIGH 1


#endif /* DIO_H_ */