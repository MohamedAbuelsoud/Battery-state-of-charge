/*
 * micro.h
 *
 * Created: 10/12/2018 5:34:58 PM
 *  Author: HP
 */


#ifndef MICRO_H_
#define MICRO_H_

#include "config.h"

#define dira DDRA
#define dirb DDRB
#define dirc DDRC
#define dird DDRD

#define vala PORTA
#define valb PORTB
#define valc PORTC
#define vald PORTD

#define inputa PINA
#define inputb PINB
#define inputc PINC
#define inputd PIND

#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7

#define input 0
#define output 1
#define HIGH 1
#define LOW 0


#define ADC_CTRL_A ADCSRA
#define ADC_EN ADEN
#define ADC_MULTIPLEXER ADMUX
#define RefS0 6
#define REFS1 7 

//MACROS

#define pin_write(reg,index,val) reg= (reg&(~(1<<index)))|(val<<index)
#define get_bit(reg,index)  ((reg>>index) & 0x01)
#define Higher_Nibble_Val(reg,val) rg=(reg & 0x0f) | (val<<4)
#define Lower_Nibble_Val(reg,val) rg=(reg & 0xf0) | (val)
#define output_mode 0xff
#define lower_mode 0xf0
#define higher_mode 0x0f
#define higherr_nibble(reg) reg = reg | 0xf0
#define lowerr_nibble(reg) reg = reg | 0x0f

#endif /* MICRO_H_ */
