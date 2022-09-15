/*
 * TIMER.c
 *
 * Created: 9/11/2022 6:40:00 AM
 *  Author: Mostafa Ayyad
 */ 

#include "TIMER.h"

/** After performing timer calculations to make a 5 seconds delay, prescaler 1024 is used, number of overflows is 20, and initial value is 11 **/


// Declaring extern variables to be accessed by timer driver
extern uint8_t count;
extern uint8_t first_click;

// Overflow counter for timer_0
uint8_t ovf;

// Pointer to function to save address of the function passed to callback function
void static (*callbackvar)(uint8_t portname, uint8_t pinnum);

// Callback function that takes the address of toggle function from upper layers and execute it in timer_0 overflow to blink yellow lights
void setcallback(void (*cbvar)(uint8_t portname, uint8_t pinnum)){
	callbackvar = cbvar;
}


void TIMER_0_init(){
	//selecting normal mode
	TCCR0 |= ((0<<3) | (0<<6));
	
	TIMER_0_set_init_value(init_value);
}

void TIMER_0_set_init_value(uint8_t val){
	//assigning initial value after calculation
	TCNT0 = val;
}
	
void TIMER_0_start(){
	// Selecting 1024 prescaler
	TCCR0 |= ((1<<0) | (1<<2));
	
	// Waiting the overflow counter to reach 20
	while(ovf <20);
}


void TIMER_0_stop(){
	// Setting control register to 0 (no prescaler) to stop the timer
	TCCR0 = 0;
	
	// Resetting overflow counter
	ovf = 0;
}

// Delay function that perform the 5 seconds delay
void TIMER_0_delay(){
	TIMER_0_start();
	TIMER_0_stop();
}

// This function resets timer without stopping it
void TIMER_reset(){
	TIMER_0_set_init_value(init_value);
	ovf = 0;
}

// Timer_0 overflow interrupt
ISR(TIMER_0_OVF){
	// Resetting initial value for the next timer cycle
	TIMER_0_set_init_value(init_value);
	
	// Incrementing overflow variable
	ovf++;
	
	// Blinking yellow lights only in phase_2 and phase_4
	if(count== phase_2 || count == phase_4){
		// Only blink cars yellow light in normal mode
		if(!first_click){
			callbackvar(CAR_light, LED_yellow);
		}
		// Blink both yellow lights in pedestrian mode
		else if(first_click){
				callbackvar(CAR_light, LED_yellow);
				callbackvar(PED_light, LED_yellow);
		}
	}
}