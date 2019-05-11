/*
 * macrofortimer.h
 *
 * Created: 5/6/2019 11:15:17 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef MACROFORTIMER_H_
#define MACROFORTIMER_H_



#include <avr\sfr_defs.h>

#define FILL_BITS(x)  ((1 << x) - 1)

#define AR_SIZE(array)    (sizeof(array)/sizeof(array[0]))

#define bit_set(sfr, bit) (sfr |= (1 << bit))
#define bit_clr(sfr, bit) (sfr &= ~(1 << bit))

typedef struct
{
  unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} bitv_t;

#define _paste(a,b)     a##b

/*
 *  #define DEBUG_DDR   bitof(DDRD,PD3)
 *  #define DEBUG       bitof(PORTD,PD3)
 *
 *  {
 *  	DEBUG_DDR = 1;
 *  	DEBUG = 0;
 *  }
 */
#define bitof(var,num) (((volatile bitv_t *)(&var))->_paste(b,num))


#endif /* MACROFORTIMER_H_ */