/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_spi.h"


int main(void)
{
	
	sei();
	SPI_init_master();
	SPI_master_transmit("DENEME",sizeof("deneme"));
	
	
    /* Replace with your application code */
    while (1) 
    {
		 
		 

	
	
    }
}

