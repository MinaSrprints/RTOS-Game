/*
 * Req_4.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Faster
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
#include "standard_types.h"
#include "function_macros.h"
/*---Ports---*/
//Port A
#define PORTA (*(volatile uint8*)0x3B)
#define DDRA (*(volatile uint8*)0x3A)
#define PINA (*(volatile uint8*)0x39)

//Port B
#define PORTB (*(volatile uint8*)0x38)
#define DDRB (*(volatile uint8*)0x37)
#define PINB (*(volatile uint8*)0x36)

//Port C
#define PORTC (*(volatile uint8*)0x35)
#define DDRC (*(volatile uint8*)0x34)
#define PINC (*(volatile uint8*)0x33)

//Port D
#define PORTD (*(volatile uint8*)0x32)
#define DDRD (*(volatile uint8*)0x31)
#define PIND (*(volatile uint8*)0x30)
/*---Pins---*/
//Port A
#define PinA0 0
#define PinA1 1
#define PinA2 2
#define PinA3 3
#define PinA4 4
#define PinA5 5
#define PinA6 6
#define PinA7 7
//Port B
#define PinB0 8
#define PinB1 9
#define PinB2 10
#define PinB3 11
#define PinB4 12
#define PinB5 13
#define PinB6 14
#define PinB7 15
//Port C
#define PinC0 16
#define PinC1 17
#define PinC2 18
#define PinC3 19
#define PinC4 20
#define PinC5 21
#define PinC6 22
#define PinC7 23
//Port D
#define PinD0 24
#define PinD1 25
#define PinD2 26
#define PinD3 27
#define PinD4 28
#define PinD5 29
#define PinD6 30
#define PinD7 31
/*---Direction---*/
#define INPUT 0
#define OUTPUT 1
/*---HIGH or LOW---*/
#define LOW 0
#define HIGH 1

#endif /* MEMORY_MAP_H_ */
