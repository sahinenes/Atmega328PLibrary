/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_twi.h"


int main(void)
{
	
	
	I2C_init();
	I2C_start(0x04<<1);
	I2C_write(0x55);
	I2C_stop();
	
    /* Replace with your application code */
    while (1) 
    {
		 
		 

	
	
    }
}

