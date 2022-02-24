/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_gpio.h"


int main(void)
{
	GPIO_t led;
	led.DDRx=DDRB;
	led.PORTx=PORTB;
	led.PIN=PORTB5;
	led.MODE=GPIO_MODE_OUTPUT;
	GPIO_init(&led);
	
	GPIO_t buton;
	buton.DDRx=DDRD;
	buton.PORTx=PORTD;
	buton.PIN=PORTD2;
	buton.PINx=PIND;
	buton.MODE=GPIO_MODE_INPUT;
	GPIO_init(&buton);
	
    /* Replace with your application code */
    while (1) 
    {
		uint8_t button=GPIO_read(&buton);
		
		if (button==LOW)
		{
			GPIO_write(&led,HIGH);
		}
		else
		{
			GPIO_write(&led,LOW);
		}
    }
}

