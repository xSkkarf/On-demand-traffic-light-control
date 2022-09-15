/*
 * Macros.h
 *
 * Created: 9/11/2022 2:10:45 AM
 *  Author: Mostafa Ayyad
 */ 


#ifndef MACROS_H_
#define MACROS_H_


	//** Typedefs **//
	typedef unsigned char uint8_t;
	
	
	//** Bit manipulation function-like macros **//
	#define set_pin(x,n) x|= (1<<n)
	#define clr_pin(x,n) x&= ~(1<<n)
	#define tgl_pin(x,n) x^= (1<<n)
	#define get_pin(x,n) ((x&(1<<n))>>n)
	
	
	//** PORT names to pass to functions **//
	#define PORT_A 'A'
	#define PORT_B 'B'
	#define PORT_C 'C'
	#define PORT_D 'D'

	//** LED port names **//
	#define CAR_light PORT_A
	#define PED_light PORT_B

	//** LED pin names **//
	#define LED_green	0
	#define LED_yellow	1
	#define LED_red		2

	//** Button port name **//
	#define BUTTON_port PORT_D
	
	//** Button pin name **//
	#define BUTTON_pin	0
	
	//** Execution phases **//
	#define phase_1 0
	#define phase_2 1
	#define phase_3 2
	#define phase_4 3
	
	
#endif /* MACROS_H_ */