/*
 * Register.h
 *
 * Created: 9/11/2022 2:04:25 AM
 *  Author: Mostafa Ayyad
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

	
	// STATUS REGISTER //
	//*************************************************//
	#define SREG *((volatile uint8_t*)0x5F)
	
	
	
	// DIO REGISTERS //
	//*************************************************//
	
	// PORTA //
	#define PORTA *((volatile uint8_t*)0x3B)
	#define DDRA *((volatile uint8_t*)0x3A)
	#define PINA *((volatile uint8_t*)0x39)

	// PORTB //
	#define PORTB *((volatile uint8_t*)0x38)
	#define DDRB *((volatile uint8_t*)0x37)
	#define PINB *((volatile uint8_t*)0x36)

	// PORTC //
	#define PORTC *((volatile uint8_t*)0x35)
	#define DDRC *((volatile uint8_t*)0x34)
	#define PINC *((volatile uint8_t*)0x33)

	// PORTD //
	#define PORTD *((volatile uint8_t*)0x32)
	#define DDRD *((volatile uint8_t*)0x31)
	#define PIND *((volatile uint8_t*)0x30)



	// TIMER REGISTERS //
	//*************************************************//
	
	// TCCR0 //
	#define TCCR0 *((volatile uint8_t*)0x53)
	
	// TCNT0 //
	#define TCNT0 *((volatile uint8_t*)0x52)
	
	// OCRR0 //
	#define OCR0 *((volatile uint8_t*)0x5C)
	
	// TIMSK //
	#define TIMSK *((volatile uint8_t*)0x59)
	
	// TIFR //
	#define TIFR *((volatile uint8_t*)0x58)
	
	
	
	// INTERRUPT REGISTERS //
	//*************************************************//

	// MCUCR //
	#define MCUCR *((volatile uint8_t*)0x55)
	
	// GICR //
	#define GICR *((volatile uint8_t*)0x5B)
	
	// GIFR //
	#define GIFR *((volatile uint8_t*)0x5A)


	

#endif /* REGISTER_H_ */