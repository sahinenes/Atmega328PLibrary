/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_gpio.h"
#include "atmega328p_ac.h"


int main(void)
{
	GPIO_t led;
	led.DDRx=DDRB;
	led.PORTx=PORTB;
	led.PIN=PORTB5;
	led.MODE=GPIO_MODE_OUTPUT;
	GPIO_init(&led);
	
	AC_init(AC_NEGATIVE_ADC0,DISABLE,DISABLE);

	
    /* Replace with your application code */
    while (1) 
    {
		 
		uint8_t ac_value=AC_value();
		
		
		GPIO_write(&led,ac_value);
	
    }
}

