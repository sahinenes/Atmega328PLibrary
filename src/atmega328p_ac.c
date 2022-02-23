/*
 * atmega328p_ac_c.c
 *
 * Created: 21.02.2022 19:24:20
 *  Author: Enes
 */ 


#include "atmega328p_ac.h"

void AC_init(uint8_t negative,uint8_t interrupt,uint8_t interrupt_mode)
{
	ADCSRA &=~(1<<ADEN); // ADC disable
	ADMUX = (negative<<MUX0);
	ADCSRB=(1<<ACME); // analog comparator enable
	ACSR|=(interrupt<<ACIE) | (interrupt_mode<<ACIS0) | (1<<ACBG);
}


uint8_t AC_value()
{
	uint8_t state;
	state= (ACSR & (1<<ACO));
	return state;
	
}