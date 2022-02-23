/*
 * atmega328p_gpio.h
 *
 * Created: 21.02.2022 12:40:18
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_GPIO_H_
#define ATMEGA328P_GPIO_H_


#include "atmega328p.h"

#define GPIO_MODE_INPUT 0
#define GPIO_MODE_INPUT_PULL_UP 1
#define GPIO_MODE_OUTPUT 2


typedef struct GPIO_t
{
   volatile uint8_t *PORTx;
   volatile uint8_t *DDRx;
   volatile uint8_t *PINx;
   uint8_t  MODE;
   uint8_t  PIN;
		
}GPIO_t;


void GPIO_init(GPIO_t* init);
uint8_t GPIO_read(GPIO_t* init);
void GPIO_write(GPIO_t* init,uint8_t state);


#endif /* ATMEGA328P_GPIO_H_ */