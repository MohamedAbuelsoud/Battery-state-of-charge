/*
 * timer32.c
 *
 * Created: 5/6/2019 10:55:46 PM
 *  Author: Mohamed Alaa
 */ 


#include"timer32.h"    



void set_timer0_wg_mode(timer0_wg_mode_enum wgm)
{
	register uint8_t tccr0 = TCCR0;
	
	tccr0 &=~ (_BV(WGM01) | _BV(WGM00));
	
	switch (wgm)
	{
		case T0_WG_NORMAL:
		break;

		case T0_WG_PWM_PHASE_CORRECT:
		bit_set(tccr0, WGM00);
		break;

		case T0_WG_CTC:
		bit_set(tccr0, WGM01);
		break;

		case T0_WG_FAST_PWM:
		tccr0 |= (_BV(WGM01) | _BV(WGM00));
		break;
		
		default:
		break;
	}
	
	TCCR0 = tccr0;
}

void set_timer0_clock_source(timer0_clock_select_enum clock_select)
{
	unsigned char tmp;
	tmp = TCCR0 & ~(_BV(CS02) | _BV(CS01) | _BV(CS00));
	TCCR0 = tmp | (clock_select << CS00);
}

void set_timer0_OC0_mode(timer0_compare_output_mode_enum mode)
{
	unsigned char tmp;
	tmp = TCCR0 & ~(_BV(COM01) | _BV(COM00));//0xe7;
	TCCR0 = tmp | (mode << COM00);
}

void timer0_int_ena(timer0_int_enum timer0_int)
{
	register uint8_t tifr = 0;
	register uint8_t timsk = TIMSK;
	
	switch (timer0_int)
	{
		case TIMER0_OVERFLOW_INTERRUPT:
		bit_set(tifr, TOV0);
		bit_set(timsk, TOIE0);
		break;

		case TIMER0_OUTPUT_COMPARE_A_MATCH_INTERRUPT:
		bit_set(tifr, OCF0);
		bit_set(timsk, OCIE0);
		break;

		case TIMER0_ALL_INTERRUPTS:
		tifr = (_BV(TOV0) | _BV(OCF0));
		timsk |= (_BV(TOIE0) | _BV(OCIE0));
		break;

		default:
		break;
	}
	
	TIFR = tifr;
	TIMSK = timsk;
}

void timer0_int_dis(timer0_int_enum timer0_int)
{
	register uint8_t timsk = TIMSK;
	
	switch (timer0_int)
	{
		case TIMER0_OVERFLOW_INTERRUPT:
		bit_clr(timsk, TOIE0);
		break;

		case TIMER0_OUTPUT_COMPARE_A_MATCH_INTERRUPT:
		bit_clr(timsk, OCF0);
		break;

		case TIMER0_ALL_INTERRUPTS:
		timsk &=~ (_BV(TOIE0) | _BV(OCIE0));
		break;
		default:
		break;
	}
	
	TIMSK = timsk;
}

void set_timer1_clock_source(timer1_clock_select_enum clock_select)
{
	uint8_t tmp = TCCR1B;
	tmp &= ~0x07;
	tmp |= (clock_select & 0x07);
	TCCR1B = tmp;
}

void set_timer1_wg_mode(timer1_wg_mode_enum wgm)
{
	#if 1

	register uint8_t tccr1a = TCCR1A;
	register uint8_t tccr1b = TCCR1B;
	
	tccr1a &= ~(_BV(WGM11) | _BV(WGM10));
	tccr1b &= ~(_BV(WGM13) | _BV(WGM12));
	
	tccr1a |= ((wgm & 0x03) << WGM10);
	tccr1b |= (((wgm & 0x0c) >> 2) << WGM10);
	
	TCCR1A = tccr1a;
	TCCR1B = tccr1b;
	
	#else
	TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
	TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
	
	switch (wgm)
	{
		case NORMAL:
		break;
		
		case PWM_PHASE_CORRECT_8_BIT:
		TCCR1A |= _BV(WGM10);
		break;
		case PWM_PHASE_CORRECT_9_BIT:
		TCCR1A |= _BV(WGM11);
		break;
		case PWM_PHASE_CORRECT_10_BIT:
		TCCR1A |= (_BV(WGM11) | _BV(WGM10));
		break;
		case CTC_OCR1A:
		TCCR1B |= _BV(WGM12);
		break;
		case FAST_PWM_8_BIT:
		TCCR1A |= _BV(WGM10);
		TCCR1B |= _BV(WGM12);
		break;
		case FAST_PWM_9_BIT:
		TCCR1A |= _BV(WGM11);
		TCCR1B |= _BV(WGM12);
		break;
		case FAST_PWM_10_BIT:
		TCCR1A |= (_BV(WGM11) | _BV(WGM10));
		TCCR1B |= _BV(WGM12);
		break;
		case PWM_PHASE_AND_FREQ_CORRECT_ICR1:
		TCCR1B |= _BV(WGM13);
		break;
		case PWM_PHASE_AND_FREQ_CORRECT_OCR1A:
		TCCR1A |= _BV(WGM10);
		TCCR1B |= _BV(WGM13);
		break;
		case PWM_PHASE_CORRECT_ICR1:
		TCCR1A |= _BV(WGM11);
		TCCR1B |= _BV(WGM13);
		break;
		case PWM_PHASE_CORRECT_OCR1A:
		TCCR1A |= (_BV(WGM11) | _BV(WGM10));
		TCCR1B |= _BV(WGM13);
		break;
		case CTC_ICR1:
		TCCR1B |= (_BV(WGM13) | _BV(WGM12));
		break;
		case RESERVED:
		TCCR1A |= _BV(WGM10);
		TCCR1B |= (_BV(WGM13) | _BV(WGM12));
		break;
		case FAST_PWM_ICR1:
		TCCR1A |= _BV(WGM11);
		TCCR1B |= (_BV(WGM13) | _BV(WGM12));
		break;
		case FAST_PWM_OCR1A:
		TCCR1A |= (_BV(WGM11) | _BV(WGM10));
		TCCR1B |= (_BV(WGM13) | _BV(WGM12));
		break;
		default:
		break;
	}
	#endif
}

void set_timer1_OC1A_mode(timer1_compare_output_mode_enum mode)
{
	TCCR1A &= ~(_BV(COM1A1) | _BV(COM1A0));

	switch (mode)
	{
		case T1_NORMAL_PORT_OPERATION:
		break;
		
		case T1_TOGGLE:
		TCCR1A |= _BV(COM1A0);
		break;
		
		case T1_CLEAR:
		TCCR1A |= _BV(COM1A1);
		break;
		
		case T1_SET:
		TCCR1A |= (_BV(COM1A1) | _BV(COM1A0));
		break;
		
		default:
		break;
	}
}

void set_timer1_OC1B_mode(timer1_compare_output_mode_enum mode)
{
	TCCR1A &= ~(_BV(COM1B1) | _BV(COM1B0));

	switch (mode)
	{
		case T1_NORMAL_PORT_OPERATION:
		break;

		case T1_TOGGLE:
		TCCR1A |= _BV(COM1B0);
		break;
		
		case T1_CLEAR:
		TCCR1A |= _BV(COM1B1);
		break;
		
		case T1_SET:
		TCCR1A |= (_BV(COM1B1) | _BV(COM1B0));
		break;
		
		default:
		break;
	}
}

void timer1_int_ena(timer1_int_enum timer1_int)
{
	register uint8_t tifr = 0;
	register uint8_t timsk = TIMSK;
	
	if (timer1_int & TIMER1_OVERFLOW_INTERRUPT) {
		bit_set(tifr, TOV1);
		bit_set(timsk, TOIE1);
	}
	
	if (timer1_int & TIMER1_OUTPUT_COMPARE_A_MATCH_INTERRUPT) {
		bit_set(tifr, OCF1A);
		bit_set(timsk, OCIE1A);
	}
	
	if (timer1_int & TIMER1_OUTPUT_COMPARE_B_MATCH_INTERRUPT) {
		bit_set(tifr, OCF1B);
		bit_set(timsk, OCIE1B);
	}
	
	if (timer1_int & TIMER1_INPUT_CAPTURE_INTERRUPT) {
		bit_set(tifr, ICF1);
		bit_set(timsk, TICIE1);
	}
	
	TIFR = tifr;
	TIMSK = timsk;
}

void timer1_int_dis(timer1_int_enum timer1_int)
{
	register uint8_t timsk = TIMSK;
	
	if (timer1_int & TIMER1_OVERFLOW_INTERRUPT) {
		bit_clr(timsk, TOIE1);
	}
	
	if (timer1_int & TIMER1_OUTPUT_COMPARE_A_MATCH_INTERRUPT) {
		bit_clr(timsk, OCIE1A);
	}
	
	if (timer1_int & TIMER1_OUTPUT_COMPARE_B_MATCH_INTERRUPT) {
		bit_clr(timsk, OCIE1B);
	}
	
	if (timer1_int & TIMER1_INPUT_CAPTURE_INTERRUPT) {
		bit_clr(timsk, TICIE1);
	}
	
	TIMSK = timsk;
}

void set_timer2_clock_source(timer2_clock_select_enum clock_select)
{
	uint8_t tmp = TCCR2;
	tmp &= ~0x07;
	tmp |= (clock_select & 0x07);
	TCCR2 = tmp;
}

void set_timer2_wg_mode(timer2_wg_mode_enum wgm)
{
	register uint8_t tmp = TCCR2;

	tmp &= ~(_BV(WGM20) | _BV(WGM21));

	switch (wgm)
	{
		case T2_WG_NORMAL:
		break;
		
		case T2_WG_PWM_PHASE_CORRECT:
		tmp |= _BV(WGM20);
		break;
		
		case T2_WG_CTC:
		tmp |= _BV(WGM21);
		break;
		
		case T2_WG_FAST_PWM:
		tmp |= (_BV(WGM20) | _BV(WGM21));
		break;
	}

	TCCR2 = tmp;
}

void set_timer2_OC_mode(timer2_compare_output_mode_enum mode)
{
	TCCR2 &= ~(_BV(COM21) | _BV(COM20));

	switch (mode)
	{
		case T2_NORMAL_PORT_OPERATION:
		break;
		
		case T2_TOGGLE:
		TCCR2 |= _BV(COM20);
		break;
		
		case T2_CLEAR:
		TCCR2 |= _BV(COM21);
		break;
		
		case T2_SET:
		TCCR2 |= (_BV(COM21) | _BV(COM20));
		break;
		
		default:
		break;
	}
}

void timer2_int_ena(timer2_int_enum timer2_int)
{
	register uint8_t tifr = 0;
	register uint8_t timsk = TIMSK;
	
	if (timer2_int & TIMER2_OVERFLOW_INTERRUPT) {
		bit_set(tifr, TOV2);
		bit_set(timsk, TOIE2);
	}
	
	if (timer2_int & TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT) {
		bit_set(tifr, OCF2);
		bit_set(timsk, OCIE2);
	}
	
	TIFR = tifr;
	TIMSK = timsk;
}

void timer2_int_dis(timer2_int_enum timer2_int)
{
	register uint8_t timsk = TIMSK;
	
	if (timer2_int & TIMER2_OVERFLOW_INTERRUPT) {
		bit_clr(timsk, TOIE2);
	}
	
	if (timer2_int & TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT) {
		bit_clr(timsk, OCIE2);
	}
	
	TIMSK = timsk;
} 
