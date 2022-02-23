/*
 * atmega328p_spi.h
 *
 * Created: 12.02.2022 17:10:42
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_SPI_H_
#define ATMEGA328P_SPI_H_

#include "atmega328p.h"

void SPI_init_master();
void SPI_master_transmit(char* data,size_t size);
void SPI_init_slave();
void SPI_slave_recive(char* data,size_t size);

#endif /* ATMEGA328P_SPİ_H_ */