/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_gpio.h"
#include "atmega328p_adc.h"


int main(void)
{
	GPIO_t led;
	led.DDRx=DDRB;
	led.PORTx=PORTB;
	led.PIN=PORTB5;
	led.MODE=GPIO_MODE_OUTPUT;
	GPIO_init(&led);
	
	ADC_t adc;
	adc.REFERENCE=ADC_REFERENCE_AVCC;
	adc.PRESCALER=ADC_PRESCALER_64;
	adc.INPUT=ADC_INPUT_ADC0;
	adc.INTERRUPT=DISABLE;
	ADC_init(adc);

	
    /* Replace with your application code */
    while (1) 
    {
		 uint16_t adc_value= ADC_read(ADC_INPUT_ADC0);
		 
		
		if (adc_value>=600)
		{
			GPIO_write(&led,HIGH);
		}
		else
		{
			GPIO_write(&led,LOW);
		}
    }
}

