/*
 * BUTTON.h
 *
 * Created: 9/11/2022 3:51:00 AM
 *  Author: Mostafa Ayyad
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../LED/LED.h"
#include "../../MCAL/TIMER/TIMER.h"

// Function prototypes
void BUTTON_init(uint8_t portname, uint8_t pinnum);
void BUTTON_read(uint8_t portname, uint8_t pinnum, uint8_t* result);



#endif /* BUTTON_H_ */