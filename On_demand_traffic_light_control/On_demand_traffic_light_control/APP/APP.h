/*
 * APP.h
 *
 * Created: 9/12/2022 3:25:33 PM
 *  Author: Mostafa Ayyad
 */ 


#ifndef APP_H_
#define APP_H_

//All the includes of the lower levels
#define F_CPU 1000000U
#include "../HAL/BUTTON/BUTTON.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/INTERRUPT/INTERRUPT.h"
#include "../MCAL/TIMER/TIMER.h"


//** Application function prototypes **//
void APP_init();
void APP_start();




#endif /* APP_H_ */