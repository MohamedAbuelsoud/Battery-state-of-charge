/*
 * millies.c
 *
 * Created: 5/6/2019 10:23:06 PM
 *  Author: Mohamed Alaa
 */ 


#include "millies.h"


 
 volatile uint32 timer1_millis;
 uint32 milliseconds_since;                        
 ISR (TIMER1_COMPA_vect)
 {
	 timer1_millis++;

 }

void millis_int(){
    set_timer1_clock_source(T1S_DIV8);
	set_timer1_wg_mode(CTC_OCR1A);
	
	
	// Load the high byte, then the low byte
	// into the output compare
	OCR1AH = (CTC_MATCH_OVERFLOW >> 8);
	OCR1AL = CTC_MATCH_OVERFLOW;
	
    
	// Enable the compare match interrupt
	timer1_int_ena(TIMER1_OUTPUT_COMPARE_A_MATCH_INTERRUPT);
	
	// Enable global interrupt.
	sei();
}


 uint32 millis ()
 {
	 
	 uint32 millis_return;

	 // Ensure this cannot be disrupted
	 ATOMIC_BLOCK(ATOMIC_FORCEON) {
		 millis_return = timer1_millis;
	 }
	 
	 return millis_return;
 }