/*
 * GPIO Driver.h
 *
 * Created: 2018-09-19 
 * Author : Mohammed
 */ 
#ifndef LCD_CONF_H_
#define LCD_CONF_H_


#include "standard_types.h"
#include <util/delay.h>
#include "DIO_operations.h"

#define CONTROL_PORT 	PORTA
#define CONTROL_DDR 	DDRA
#define DATA_PORT 		PORTA
#define DATA_DDR 		DDRA


#define RS		PinA1
#define RW		PinA2
#define E 		PinA3

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE
//#define LOWER_BITS
#define HIGHER_BITS




#endif
