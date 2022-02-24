/*
 * Atmega328PExamples.c
 *
 * Created: 24.02.2022 15:27:02
 * Author : Enes
 */ 

#include "atmega328p_uart.h"


int main(void)
{
	USART_t usart;
	usart.baudRate=9600;
	usart.character=USART_CHARACTER_8;
	usart.mode=USART_OPERATION_ASYNC;
	usart.parity=USART_PARITY_DISABLED;
	usart.stop=USART_STOP_1;
	USART_init(usart);
	
	  
	 FILE usart0_str = FDEV_SETUP_STREAM(USART_transmit, NULL, _FDEV_SETUP_WRITE);
	 stdout=&usart0_str;
	  
	 sei();

	
    /* Replace with your application code */
    while (1) 
    {
		 
		 
		 printf("Hello World!!\n");
		 _delay_ms(100);
	
	
    }
}

