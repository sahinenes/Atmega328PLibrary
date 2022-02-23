/*
 * atmega328p_adc.h
 *
 * Created: 21.02.2022 16:47:30
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_ADC_H_
#define ATMEGA328P_ADC_H_

#include "atmega328p.h"


/*Voltage Reference Selections for ADC*/
#define ADC_REFERENCE_AREF 0
#define ADC_REFERENCE_AVCC 1
#define ADC_REFERENCE_RESERVED 2
#define ADC_REFERENCE_INTERNAL 3

/*Input Channel Selections*/
#define ADC_INPUT_ADC0 0
#define ADC_INPUT_ADC1 1
#define ADC_INPUT_ADC2 2
#define ADC_INPUT_ADC3 3
#define ADC_INPUT_ADC4 4
#define ADC_INPUT_ADC5 5
#define ADC_INPUT_ADC6 6
#define ADC_INPUT_ADC7 7
#define ADC_INPUT_ADC8 8
#define ADC_INPUT_1V1 14
#define ADC_INPUT_0V 15

/*ADC Prescaler Selections*/
#define ADC_PRESCALER_2 0
#define ADC_PRESCALER_4 2
#define ADC_PRESCALER_8 3
#define ADC_PRESCALER_16 4
#define ADC_PRESCALER_32 5
#define ADC_PRESCALER_64 6
#define ADC_PRESCALER_128 7


typedef struct ADC_t
{
	uint8_t REFERENCE;
	uint8_t PRESCALER;
	uint8_t INPUT;
	uint8_t INTERRUPT;
	
}ADC_t;

void ADC_init(ADC_t init);
uint16_t ADC_read(uint8_t input);

#endif /* ATMEGA328P_ADC_H_ */