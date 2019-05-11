/*
 * timer32.h
 *
 * Created: 5/6/2019 10:57:05 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef TIMER32_H_
#define TIMER32_H_

#include "macrofortimer.h"
#include "micro_config.h"
#include "std_types.h"

typedef enum
{
	T0_WG_NORMAL,
	T0_WG_PWM_PHASE_CORRECT,
	T0_WG_CTC,
	T0_WG_FAST_PWM
} timer0_wg_mode_enum;

typedef enum
{
	T0_NO_CLOCK,
	T0S_DIV1,
	T0S_DIV8,
	T0S_DIV64,
	T0S_DIV256,
	T0S_DIV1024,
	T0EXT_FALLING_EDGE,
	T0EXT_RISING_EDGE
} timer0_clock_select_enum;

typedef enum
{
	T0_NORMAL_PORT_OPERATION = 0,
	T0_TOGGLE = 1,
	T0_CLEAR = 2,
	T0_SET = 3,
} timer0_compare_output_mode_enum;

typedef enum
{
	TIMER0_OVERFLOW_INTERRUPT = 0x01,
	TIMER0_OUTPUT_COMPARE_A_MATCH_INTERRUPT = 0x02,
	TIMER0_ALL_INTERRUPTS = 0x03
} timer0_int_enum;

typedef enum
{
	NORMAL = 0,
	PWM_PHASE_CORRECT_8_BIT = 1,
	PWM_PHASE_CORRECT_9_BIT = 2,
	PWM_PHASE_CORRECT_10_BIT = 3,
	CTC_OCR1A = 4,
	FAST_PWM_8_BIT = 5,
	FAST_PWM_9_BIT = 6,
	FAST_PWM_10_BIT = 7,
	PWM_PHASE_AND_FREQ_CORRECT_ICR1 = 8,
	PWM_PHASE_AND_FREQ_CORRECT_OCR1A = 9,
	PWM_PHASE_CORRECT_ICR1 = 10,
	PWM_PHASE_CORRECT_OCR1A = 11,
	CTC_ICR1 = 12,
	RESERVED = 13,
	FAST_PWM_ICR1 = 14,
	FAST_PWM_OCR1A = 15
} timer1_wg_mode_enum;

typedef enum
{
	T1_NORMAL_PORT_OPERATION = 0,
	T1_TOGGLE = 1,
	T1_CLEAR = 2,
	T1_SET = 3,
} timer1_compare_output_mode_enum;

typedef enum
{
	T1_NO_CLOCK = 0,
	T1S_DIV1 = 1,
	T1S_DIV8 = 2,
	T1S_DIV64 = 3,
	T1S_DIV256 = 4,
	T1S_DIV1024 = 5,
	T1EXT_FALLING_EDGE = 6,
	T1EXT_RISING_EDGE = 7,
} timer1_clock_select_enum;

typedef enum
{
	TIMER1_INPUT_CAPTURE_INTERRUPT = 0x01,
	TIMER1_OUTPUT_COMPARE_A_MATCH_INTERRUPT = 0x02,
	TIMER1_OUTPUT_COMPARE_B_MATCH_INTERRUPT = 0x04,
	TIMER1_OVERFLOW_INTERRUPT = 0x08,
	TIMER1_ALL_INTERRUPTS = 0x0f
} timer1_int_enum;

typedef enum
{
	T2_WG_NORMAL = 0,
	T2_WG_PWM_PHASE_CORRECT = 1,
	T2_WG_CTC = 2,
	T2_WG_FAST_PWM = 3
} timer2_wg_mode_enum;

typedef enum
{
	T2_NORMAL_PORT_OPERATION,
	T2_TOGGLE,
	T2_CLEAR,
	T2_SET
} timer2_compare_output_mode_enum;

typedef enum
{
	T2_NO_CLOCK = 0,
	T2S_DIV1 = 1,
	T2S_DIV8 = 2,
	T2S_DIV32 = 3,
	T2S_DIV64 = 4,
	T2S_DIV128 = 5,
	T2S_DIV256 = 6,
	T2S_DIV1024 = 7,
} timer2_clock_select_enum;

typedef enum
{
	TIMER2_OVERFLOW_INTERRUPT = 0x01,
	TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT = 0x02,
} timer2_int_enum;

void set_timer0_wg_mode(timer0_wg_mode_enum wgm);
void set_timer0_clock_source(timer0_clock_select_enum clock_select);
void set_timer0_OC0_mode(timer0_compare_output_mode_enum mode);

void timer0_int_ena(timer0_int_enum timer0_int);
void timer0_int_dis(timer0_int_enum timer0_int);
void set_timer0_ctc_freq(uint32_t freq);

void set_timer1_wg_mode(timer1_wg_mode_enum wgm);
void set_timer1_OC1A_mode(timer1_compare_output_mode_enum mode);
void set_timer1_OC1B_mode(timer1_compare_output_mode_enum mode);
void set_timer1_clock_source(timer1_clock_select_enum clock_select);
void timer1_int_ena(timer1_int_enum timer1_int);
void timer1_int_dis(timer1_int_enum timer1_int);

void set_timer2_wg_mode(timer2_wg_mode_enum wgm);
void set_timer2_clock_source(timer2_clock_select_enum clock_select);
void timer2_int_ena(timer2_int_enum timer2_int);
void timer2_int_dis(timer2_int_enum timer2_int);



#endif /* TIMER32_H_ */