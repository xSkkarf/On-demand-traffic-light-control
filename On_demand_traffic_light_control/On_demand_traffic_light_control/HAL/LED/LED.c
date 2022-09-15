/*
 * LED.c
 *
 * Created: 9/11/2022 3:09:02 PM
 *  Author: Mostafa Ayyad
 */ 

#include "LED.h"

void LED_init(uint8_t portname, uint8_t pinnum){
	DIO_init(portname, pinnum, OUT);
}


void LED_on(uint8_t portname, uint8_t pinnum){
	DIO_write(portname, pinnum, HIGH);	
}


void LED_off(uint8_t portname, uint8_t pinnum){
	DIO_write(portname, pinnum, LOW);	
}

void LED_toggle(uint8_t portname, uint8_t pinnum){
	DIO_toggle(portname, pinnum);
}