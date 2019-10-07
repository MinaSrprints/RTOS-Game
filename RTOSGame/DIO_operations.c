/*
 * req_4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Faster
 */

#include "DIO_operations.h"
#include "Memory_map.h"
void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
if(PinValue==1)
{
	if(PinNum>=PinA0&&PinNum<=PinA7)
	{
		Set_Bit(PORTA,PinNum);
	}
	else if(PinNum>=PinB0&&PinNum<=PinB7)
	{
		Set_Bit(PORTB,(PinNum-8));
	}
	else if(PinNum>=PinC0&&PinNum<=PinC7)
	{
		Set_Bit(PORTC,(PinNum-16));
	}
	else if(PinNum>=PinD0&&PinNum<=PinD7)
	{
		Set_Bit(PORTD,(PinNum-24));
	}
}
else if(PinValue==0)
{
	if(PinNum>=PinA0&&PinNum<=PinA7)
	{
		Clear_Bit(PORTA,PinNum);
	}
	else if(PinNum>=PinB0&&PinNum<=PinB7)
	{
		Clear_Bit(PORTB,(PinNum-8));
	}
	else if(PinNum>=PinC0&&PinNum<=PinC7)
	{
		Clear_Bit(PORTC,(PinNum-16));
	}
	else if(PinNum>=PinD0&&PinNum<=PinD7)
	{
		Clear_Bit(PORTD,(PinNum-24));
	}
}
}
uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 Pin_Value;
	if(PinNum>=PinA0&&PinNum<=PinA7)
	{
		Pin_Value=Get_Bit(PINA,PinNum);
	}
	else if(PinNum>=PinB0&&PinNum<=PinB7)
	{
		Pin_Value=Get_Bit(PINB,(PinNum-8));
	}
	else if(PinNum>=PinC0&&PinNum<=PinC7)
	{
		Pin_Value=Get_Bit(PINC,(PinNum-16));
	}
	else if(PinNum>=PinD0&&PinNum<=PinD7)
	{
		Pin_Value=Get_Bit(PIND,(PinNum-24));
	}
	return Pin_Value;
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinDirection==1)
	{
		if(PinNum>=PinA0&&PinNum<=PinA7)
		{
			Set_Bit(DDRA,PinNum);
		}
		else if(PinNum>=PinB0&&PinNum<=PinB7)
		{
			Set_Bit(DDRB,(PinNum-8));
		}
		else if(PinNum>=PinC0&&PinNum<=PinC7)
		{
			Set_Bit(DDRC,(PinNum-16));
		}
		else if(PinNum>=PinD0&&PinNum<=PinD7)
		{
			Set_Bit(DDRC,(PinNum-24));
		}
	}
	else if(PinDirection==0)
	{
		if(PinNum>=PinA0&&PinNum<=PinA7)
		{
			Clear_Bit(PORTA,PinNum);
		}
		else if(PinNum>=PinB0&&PinNum<=PinB7)
		{
			Clear_Bit(DDRB,(PinNum-8));
		}
		else if(PinNum>=PinC0&&PinNum<=PinC7)
		{
			Clear_Bit(DDRC,(PinNum-16));
		}
		else if(PinNum>=PinD0&&PinNum<=PinD7)
		{
			Clear_Bit(DDRD,(PinNum-24));
		}
	}
}
