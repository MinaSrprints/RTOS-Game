/*
 * button.c
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */
#include "FreeRTOS.h"
#include "task.h"
#include "button.h"
void BUTTON_Init(uint8 button_num)
{
	if(button_num==1)
	{
	DIO_SetPinDirection(PinA0,INPUT);
	DIO_WritePin(PinA0,HIGH);
	}
	else if(button_num==2)
	{
	DIO_SetPinDirection(PinA1,INPUT);
	DIO_WritePin(PinA1,HIGH);
	}
}
uint8 BUTTON_GitButtonState(uint8 button_num)
{
	if(button_num==1)
	{
	return DIO_ReadPin(PinA0);
	}
	else if(button_num==2)
	{
	return DIO_ReadPin(PinA1);
	}
}
