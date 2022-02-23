/*
 * atmega328p_ac.h
 *
 * Created: 21.02.2022 19:24:06
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_AC_H_
#define ATMEGA328P_AC_H_



#include "atmega328p.h"


/*Analog Comparator Multiplexed Input*/
#define AC_NEGATIVE_ADC0 0
#define AC_NEGATIVE_ADC1 1
#define AC_NEGATIVE_ADC2 2
#define AC_NEGATIVE_ADC3 3
#define AC_NEGATIVE_ADC4 4
#define AC_NEGATIVE_ADC5 5
#define AC_NEGATIVE_ADC6 6
#define AC_NEGATIVE_ADC7 7

/*ACIS1/ACIS0 Settings*/
#define AC_INTERRUPT_TOGGLE 0
#define AC_INTERRUPT_RESERVED 1
#define AC_INTERRUPT_FALLING 2
#define AC_INTERRUPT_RISING 3

void AC_init(uint8_t negative,uint8_t interrupt,uint8_t interrupt_mode);
uint8_t AC_value();



#endif /* ATMEGA328P_AC_H_ */