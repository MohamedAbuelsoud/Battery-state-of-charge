/*
 * millies.h
 *
 * Created: 5/6/2019 10:23:28 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef MILLIES_H_
#define MILLIES_H_

#include "timer32.h"

#define CTC_MATCH_OVERFLOW ((F_CPU / 1000) / 8)


void millis_int();

extern uint32 millis ();

#endif /* MILLIES_H_ */