/*
 * led.c
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#include "led.h"

void LED_Init(void)
{
	DIO_SetPinDirection(PinA2,OUTPUT);
	DIO_WritePin(PinA2,LOW);
	DIO_SetPinDirection(PinA3,OUTPUT);
	DIO_WritePin(PinA3,LOW);
}

void LED_Toggle(void)
{
	PORTA^=(1<<2);
}
void LED_Write(uint8 led_num,uint8 state)
{
	switch (led_num)
	{
	case 1:
		if(state==1)
		{
		DIO_WritePin(PinA2,HIGH);
		}
		else
		{
			DIO_WritePin(PinA2,LOW);
		}
		break;
	case 2:
		if(state==1)
		{
			DIO_WritePin(PinA3,HIGH);
		}
		else
		{
			DIO_WritePin(PinA3,HIGH);
		}
		break;
	}
}
