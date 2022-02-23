/*
 * atmega328p_adc.c
 *
 * Created: 21.02.2022 16:47:47
 *  Author: Enes
 */ 
#include "atmega328p_adc.h"


void ADC_init(ADC_t init)
{
	ADMUX = (init.REFERENCE<<REFS0) | (init.INPUT<<MUX0); // voltage reference and input channel
	ADCSRA = (init.INTERRUPT<<ADIE) | (init.PRESCALER<<ADPS0) | (1<<ADEN); // interrupt and prescaler
}

uint16_t ADC_read(uint8_t input)
{
	 //select ADC channel with safety mask
	 ADMUX = (ADMUX & 0xF0) | (input & 0x0F);
	 //single conversion mode
	 ADCSRA |= (1<<ADSC);
	 // wait until ADC conversion is complete
	 while( ADCSRA & (1<<ADSC) );
	 return ADC;
	
}