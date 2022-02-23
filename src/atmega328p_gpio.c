/*
 * atmega328p_gpio->c
 *
 * Created: 21->02->2022 12:40:04
 *  Author: Enes
 */ 

#include "atmega328p_gpio.h"

void GPIO_init(GPIO_t* init)
{
	if (init->MODE==GPIO_MODE_INPUT || init->MODE==GPIO_MODE_INPUT_PULL_UP)
	{
		*init->DDRx&=~(1<<init->PIN); // input
		*init->PORTx|=(init->MODE<<init->PIN); // pull-up
	}
	else if (init->MODE==GPIO_MODE_OUTPUT)
	{
		*init->DDRx|=(1<<init->PIN); // output		
	}
	else
	{
		*init->DDRx&=~(1<<init->PIN); // input
		*init->PORTx|=(1<<init->MODE); // pull-up		
	}
		
}
uint8_t GPIO_read(GPIO_t* init)
{
	uint8_t state;
	
	state=(*init->PINx & (1<<init->PIN));
	
	return state;
}
void GPIO_write(GPIO_t* init,uint8_t state)
{
	if (state==0)
	{
		*init->PORTx&=~(1<<init->PIN);
	}
	else
	{
		*init->PORTx|=(1<<init->PIN);
	}

	

}