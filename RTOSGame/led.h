/*
 * led.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef LED_H_
#define LED_H_
#include "DIO_operations.h"
#include "Memory_map.h"
#define LEDPIN  PinA2
extern void LED_Toggle(void);
extern void LED_Init(void);
extern void LED_Write(uint8 led_num,uint8 state);
#endif /* LED_H_ */
