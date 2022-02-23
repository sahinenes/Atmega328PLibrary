/*
 * CFile1.c
 *
 * Created: 12.02.2022 00:10:29
 *  Author: Enes
 */ 

/*

  copy main setup
  
	 FILE usart0_str = FDEV_SETUP_STREAM(USART_transmit, NULL, _FDEV_SETUP_WRITE);
	 stdout=&usart0_str;
	 
	 sei();
  
  
  use
  printf("Potentiometer value = %u Ohm\n", (uint16_t)potval);
  
  
*/

#include "atmega328p_uart.h"





volatile static uint8_t rx_buffer[RX_BUFFER_SIZE] = {0};
volatile static uint16_t rx_count = 0;
volatile static uint8_t USART_tx_busy = 1;

void USART_init(USART_t usart_t)
{
	uint8_t speed = 16;
	uint32_t baud;
		
	baud = (F_CPU/(usart_t.baudRate*speed)) - 1;

	UBRR0H = (baud & 0x0F00) >> 8;
	UBRR0L = (baud & 0x00FF);
	
	UCSR0C|=(usart_t.mode<<6)|(usart_t.parity<<4)|(usart_t.stop<<3)|(usart_t.character<<0);
	
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0)|(1<<TXCIE0)|(1<<RXCIE0);
	

}


void usart_transmitChar(uint8_t data)
{
	while(USART_tx_busy == 0);
	USART_tx_busy = 0;
	UDR0 = data;
}


int USART_transmit(uint8_t data, FILE *stream)
{
	if(data == '\n')
	{
		USART_transmit('\r', stream);
	}

	usart_transmitChar((uint8_t)data);
	return 0;
	
}
void USART_receive(uint8_t* data,uint16_t Len)
{
	   while(Len>0)
	   {
		   static uint16_t rx_read_pos = 0;
		   
		   *data = rx_buffer[rx_read_pos];
		   rx_read_pos++;
		   rx_count--;
		   Len--;
		   if(rx_read_pos >= RX_BUFFER_SIZE){
			   rx_read_pos = 0;
		   }
	   }
}

ISR( USART_RX_vect){
	
	volatile static uint16_t rx_write_pos = 0;
	
	rx_buffer[rx_write_pos] = UDR0;
	rx_count++;
	rx_write_pos++;
	if(rx_write_pos >= RX_BUFFER_SIZE){
		rx_write_pos = 0;
	}
	
}


ISR(USART_TX_vect){
	USART_tx_busy = 1;
}
