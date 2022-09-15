/*
 * LED.h
 *
 * Created: 9/11/2022 3:08:49 PM
 *  Author: Mostafa Ayyad
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"

void LED_init(uint8_t portname, uint8_t pinnum);
void LED_on(uint8_t portname, uint8_t pinnum);
void LED_off(uint8_t portname, uint8_t pinnum);
void LED_toggle(uint8_t portname, uint8_t pinnum);




#endif /* LED_H_ */