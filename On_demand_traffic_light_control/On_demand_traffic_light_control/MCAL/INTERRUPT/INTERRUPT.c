/*
 * INTERRUPT.c
 *
 * Created: 9/11/2022 3:50:16 PM
 *  Author: Mostafa Ayyad
 */ 

#include "INTERRUPT.h"

void INTERRUPT_global_init(){
	//enabling global interrupt in status register
	set_pin(SREG, 7);
}

void INTERRUPT_0_init(){
	//setting int_0 mode on rising edge
	set_pin(MCUCR, 0);
	set_pin(MCUCR, 1);
	
	//enabling int_0 interrupt
	set_pin(GICR, 6);
}


void INTERRUPT_T0_ovf_init(){
	//enabling t0_ovf interrupt
	set_pin(TIMSK, 0);
}

