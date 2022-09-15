/*
 * APP.c
 *
 * Created: 9/12/2022 3:25:24 PM
 *  Author: Mostafa Ayyad
 */ 

#include "APP.h"

// count variable keeps track of program during execution from phase_1 (0) to phase_4 (3). Initially at phase_1 (0)
uint8_t count = phase_1;

// first_click flag holds the value (0) when in normal mode. Once it is clicked its value turns to (1) indicating pedestrian mode.
uint8_t first_click=0;


/** This is the app initialization in which all the system drivers are set up **/
void APP_init(){
	
	// Initializing button port and pin as input
	BUTTON_init(BUTTON_port, BUTTON_pin);
	
	// Initializing all the system led port and pins as output.
	LED_init(CAR_light, LED_green);
	LED_init(CAR_light, LED_yellow);
	LED_init(CAR_light, LED_red);
	LED_init(PED_light, LED_green);
	LED_init(PED_light, LED_yellow);
	LED_init(PED_light, LED_red);
	
	// Initializing Timer_0 
	TIMER_0_init();
	// Enabling Timer_0 overflow interrupt
	INTERRUPT_T0_ovf_init();
	
	// Enabling INT_0 interrupt
	INTERRUPT_0_init();
	
	// Enabling global interrupt
	INTERRUPT_global_init();
	
	// Passing led toggle function to operate in timer driver (lower level)(MCAL)
	setcallback(LED_toggle);
}


/** This is the app start in which the program starts execution **/
void APP_start(){
	
	//************************************* Phase 1 *************************************//
	
	if(count == phase_1){
		// Initial start of the normal mode cycle
		LED_on(CAR_light, LED_green);
		LED_on(PED_light, LED_red);
		
		// This function start a 5 seconds delay
		TIMER_0_delay();
	
		// count is incremented by one to go to next phase, then modulus 4 to make the range of values (0-3) --> (phase_1 - phase_4)
		count = (count+1)%4;
	}
	
	//***********************************************************************************//
	
	
	
	//************************************* Phase 2 *************************************//
	if(count == phase_2){
		/*	In this phase, timer_0 overflow interrupt blinks cars yellow light in normal mode
			and both cars and pedestrian yellow light in pedestrian mode. */
		TIMER_0_delay();
		
		// Turning both yellow leds off to ensure toggling ends with an off states for the leds after blinking.
		LED_off(CAR_light, LED_yellow);
		LED_off(PED_light, LED_yellow);
		
		count = (count+1)%4;
	}
	
	//***********************************************************************************//
	
	
	
	//************************************* Phase 3 *************************************//
	if(count == phase_3){
		// Program only enters this if condition in pedestrian mode (first_click==1)
		if(first_click){
			// Allowing pedestrians to cross the road by turning on green light and turning off red light in pedestrian mode.
			LED_on(PED_light, LED_green);
			LED_off(PED_light, LED_red);
		}
		
		// Stopping the cars in normal mode by turning on red light and turning off green light.
		LED_off(CAR_light, LED_green);
		LED_on(CAR_light, LED_red);
		
		TIMER_0_delay();
		
		count = (count+1)%4;
	}
	//***********************************************************************************//
	
	
	
	//************************************* Phase 4 *************************************//
	
	/*	In this phase, timer_0 overflow interrupt blinks cars yellow light in normal mode
		and both cars and pedestrian yellow light in pedestrian mode. */
	TIMER_0_delay();
	
	// Turning off pedestrian green light in case of pedestrian mode to exit and enter normal mode phase_1 again.
	LED_off(PED_light, LED_green);
	
	// Turning off cars blinking yellow light in case of normal mode to start again from phase_1.
	LED_off(CAR_light, LED_yellow);
	
	// Turning off pedestrian yellow light in case of pedestrian mode to exit and enter normal mode phase_1 again.
	LED_off(PED_light, LED_yellow);
	
	
	if(count == phase_4){
		count = (count+1)%4;
		
		// Turning off cars blinking red light in case of normal mode to start again from phase_1.
		LED_off(CAR_light, LED_red);
		
		// Setting first_click flag to zero to indicate returning to normal mode.
		first_click=0;
	}
	//***********************************************************************************//
	
}

