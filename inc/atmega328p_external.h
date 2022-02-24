/*
 * atmega328p_external.h
 *
 * Created: 22.02.2022 11:57:28
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_EXTERNAL_H_
#define ATMEGA328P_EXTERNAL_H_


#include "atmega328p.h"
#include "interrupt.h"


/* External Interrupt*/

/*Interrupt Sense Control*/
#define EXTI_SENSE_LOW 0
#define EXTI_SENSE_ANY 1
#define EXTI_SENSE_FALLING 2
#define EXTI_SENSE_RISING 3


void EXTI_init(uint8_t intx,uint8_t sense);







#endif /* ATMEGA328P_EXTERNAL_H_ */