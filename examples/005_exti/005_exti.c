/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_external.h"
#include "atmega328p_gpio.h"

GPIO_t led;
uint8_t led_state=LOW;

int main(void)
{
	
	
	led.DDRx=DDRB;
	led.PORTx=PORTB;
	led.PIN=PORTB5;
	led.MODE=GPIO_MODE_OUTPUT;
	GPIO_init(&led);
	
	EXTI_init(INT0,EXTI_SENSE_RISING);

	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		 
		 

	
	
    }
}

ISR (INT0_vect)
{
		
		
	led_state=!led_state;
	GPIO_write(&led,led_state);
	

}