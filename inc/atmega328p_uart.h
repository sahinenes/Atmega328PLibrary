/*
 * atmega328p_uart.h
 *
 * Created: 12.02.2022 00:07:22
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_UART_H_
#define ATMEGA328P_UART_H_



#include "atmega328p.h"
#include <stdio.h>
#include <avr/interrupt.h>

#define RX_BUFFER_SIZE 128

/* OPERATION*/
#define USART_OPERATION_ASYNC 0
#define USART_OPERATION_SYNC  1

/* PARITY MODE */
#define USART_PARITY_DISABLED 0
#define USART_PARITY_RESERVED 1
#define USART_PARITY_EVEN     2
#define USART_PARITY_ODD      3

/* STOP BIT */
#define USART_STOP_1          0
#define USART_STOP_2          1

/* CHARACTER SIZE */
#define USART_CHARACTER_5     0
#define USART_CHARACTER_6     1
#define USART_CHARACTER_7     2
#define USART_CHARACTER_8     3
#define USART_CHARACTER_9     7

/* CLOCK POLARITY */
#define USART_CLK_PLRTY_RSNG  0
#define USART_CLK_PLRTY_FLNG  1



typedef struct USART_t
{
	uint8_t mode;
	uint8_t parity;
	uint8_t stop;
	uint8_t character;
	uint32_t baudRate;	
}USART_t;


/* Ýnit */
void USART_init(USART_t usart_t);

/*Transmit and Recive Data */
int USART_transmit(uint8_t data, FILE *stream);
void USART_receive(uint8_t* data,uint16_t Len);

#endif /* ATMEGA328P_UART_H_ */