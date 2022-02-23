/*
 * atmega328p_spi.c
 *
 * Created: 12.02.2022 17:11:05
 *  Author: Enes
 */ 

#include "atmega328p_spi.h"


volatile static uint8_t SPI_tx_busy = 1;

void SPI_init_master()
{
	/* Set MOSI and SCK output, all others input */
	*DDRB|=(1<<PORTB3)|(1<<PORTB5)|(1<<PORTB2); 
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);
	
	
	
}

void SPI_master_transmit_char(char data)
{
	while(SPI_tx_busy == 0);
	SPI_tx_busy = 0;
	SPDR = data;
}

void SPI_master_transmit(char* data,size_t size)
{
	while(size>0)
	{
		 SPI_master_transmit_char(*data++);
		 size--;
		
	}
}


void SPI_init_slave()
{
	/* Set MISO output, all others input */
	*DDRB = (1<<PORTB4);
	/* Enable SPI */
	SPCR = (1<<SPE);

}

char SPI_slave_recive_char()
{
	// transmit dummy byte
	SPDR = 0xFF;
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return Data Register */
	return SPDR;
}

void SPI_slave_recive(char* data,size_t size)
{
	while(size>1)
	{
		*data=SPI_slave_recive_char();
		data++;
		size--;
	}
}



ISR(SPI_STC_vect)
{
	SPI_tx_busy=1;
}