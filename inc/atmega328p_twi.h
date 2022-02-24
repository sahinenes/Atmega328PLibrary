/*
 * atmega328p_twi.h
 *
 * Created: 11.02.2022 19:39:43
 *  Author: Enes
 */ 


#ifndef ATMEGA328P_TWI_H_
#define ATMEGA328P_TWI_H_

#include "atmega328p.h"
#include <math.h>


#define SCL_CLK 100000L
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

void I2C_init(void);
uint8_t I2C_start(uint8_t slave_adress);
uint8_t I2C_start_wait(uint8_t slave_adress);
uint8_t I2C_repeated_start(uint8_t slave_adress);
uint8_t I2C_write(uint8_t data);
void I2C_stop(void);
char I2C_read_ack();
char I2C_read_nack();

#endif /* ATMEGA328P_TWI_H_ */