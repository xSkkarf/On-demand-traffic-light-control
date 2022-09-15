/*
 * TIMER.h
 *
 * Created: 9/11/2022 6:39:50 AM
 *  Author: Mostafa Ayyad
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/Macros.h"
#include "../../Utilities/Register.h"
#include "../INTERRUPT/INTERRUPT.h"



#define init_value 11

		
	
// TIMER0 function prototypes
void TIMER_0_init();
void TIMER_0_set_init_value(uint8_t val);
void TIMER_0_start();
void TIMER_0_stop();
void TIMER_0_reset();

void TIMER_0_delay();


// Callback function to access LED_toggle function from upper layer (HAL)
void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum));



#endif /* TIMER_H_ */