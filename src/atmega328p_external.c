/*
 * atmega328p_external.c
 *
 * Created: 22.02.2022 11:57:45
 *  Author: Enes
 */ 
#include "atmega328p_external.h"

void EXTI_init(uint8_t intx,uint8_t sense)
 {
	 if (intx==INT0)
	 {
		 EICRA|=(sense<<ISC00);
	 }
	 else
	 {
		 EICRA|=(sense<<ISC10);
	 }
	 EIMSK|=(1<<intx);
 }
 
