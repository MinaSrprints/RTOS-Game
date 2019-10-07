/******************************************************************************
 *
 * Module: LCD 16x2
 *
 * File Name: LCD.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mohamed AbdElkader
 *
 *******************************************************************************/

#include "LCD.h"



void LCD_INIT(void)
{
#ifdef EIGHT_BIT_MODE

	DATA_DDR = 0xFF;
	Set_Bit(CONTROL_DDR,RS);
	Set_Bit(CONTROL_DDR,RW);
	Set_Bit(CONTROL_DDR,E);
	LCD_sendCommand(LCD_8_BIT_2_LINES_COMMAND);
	LCD_sendCommand(CURSOR_OFF);
	LCD_Clear();

#elif defined FOUR_BIT_MODE

#ifdef LOWER_BITS
	DATA_DDR = 0x0F;
	Set_Bit(CONTROL_DDR,RS);
	Set_Bit(CONTROL_DDR,RW);
	Set_Bit(CONTROL_DDR,E);
	LCD_sendCommand(LCD_4_BIT_MODE);
	LCD_sendCommand(LCD_4_BIT_2_LINES_COMMAND);
	LCD_sendCommand(CURSOR_OFF);
	LCD_Clear();

#elif defined HIGHER_BITS
	DATA_DDR = 0xF0;
	Set_Bit(CONTROL_DDR,RS);
	Set_Bit(CONTROL_DDR,RW);
	Set_Bit(CONTROL_DDR,E);
	LCD_sendCommand(LCD_4_BIT_MODE);
	LCD_sendCommand(LCD_4_BIT_2_LINES_COMMAND);
	LCD_sendCommand(CURSOR_OFF);
	LCD_Clear();

#endif

#endif
}


void LCD_sendCommand(const uint8 Command)
{
#ifdef EIGHT_BIT_MODE
	Clear_Bit(CONTROL_PORT,RS);
	Clear_Bit(CONTROL_PORT,RW);
	vTaskDelay(1);;
	Set_Bit(CONTROL_PORT,E);
	vTaskDelay(1);;
	DATA_PORT = Command;
	vTaskDelay(1);;
	Clear_Bit(CONTROL_PORT,E);
	vTaskDelay(1);;


#elif defined FOUR_BIT_MODE
	Clear_Bit(CONTROL_PORT,RS);
	Clear_Bit(CONTROL_PORT,RW);
	vTaskDelay(2);
	Set_Bit(CONTROL_PORT,E);
	vTaskDelay(2);
#ifdef LOWER_BITS
	DATA_PORT = (DATA_PORT & 0xF0) | ((0xF0 & Command)>>4);
#elif defined HIGHER_BITS
	DATA_PORT = (DATA_PORT & 0x0F) | (0xF0 & Command);
#endif
	vTaskDelay(2);
	Clear_Bit(CONTROL_PORT,E);
	vTaskDelay(2);
	Set_Bit(CONTROL_PORT,E);
	vTaskDelay(2);
#ifdef LOWER_BITS
	DATA_PORT = (DATA_PORT & 0xF0) | (0x0F & Command);
#elif defined HIGHER_BITS
	DATA_PORT = (DATA_PORT & 0x0F) | ((0x0F & Command)<<4);
#endif
	Clear_Bit(CONTROL_PORT,E);
	vTaskDelay(2);

#endif
}


void LCD_sendChar(const char Char)
{
#ifdef EIGHT_BIT_MODE
	Set_Bit(CONTROL_PORT,RS);
	Clear_Bit(CONTROL_PORT,RW);
	vTaskDelay(1);;
	Set_Bit(CONTROL_PORT,E);
	vTaskDelay(1);;
	DATA_PORT = Char;
	vTaskDelay(1);;
	Clear_Bit(CONTROL_PORT,E);
	vTaskDelay(1);;


#elif defined FOUR_BIT_MODE
	Set_Bit(CONTROL_PORT,RS);
	Clear_Bit(CONTROL_PORT,RW);
	vTaskDelay(2);
	Set_Bit(CONTROL_PORT,E);
	vTaskDelay(2);
#ifdef LOWER_BITS
	DATA_PORT = (DATA_PORT & 0xF0) | ((0xF0 & Char) >> 4);
#elif defined HIGHER_BITS
	DATA_PORT = (DATA_PORT & 0x0F) | (0xF0 & Char);
#endif
	vTaskDelay(2);
	Clear_Bit(CONTROL_PORT,E);
	vTaskDelay(2);
	Set_Bit(CONTROL_PORT,E);
	vTaskDelay(2);
#ifdef LOWER_BITS
	DATA_PORT = (DATA_PORT & 0xF0) | (0x0F & Char);
#elif defined HIGHER_BITS
	DATA_PORT = (DATA_PORT & 0x0F) | ((0x0F & Char) << 4);
#endif
	Clear_Bit(CONTROL_PORT,E);
	vTaskDelay(2);

#endif

}


void LCD_sendString(const char *str)
{
	uint8 i =0;
	while(str[i]!= '\0')
	{
		LCD_sendChar(str[i]);
		i++;
	}
}


void LCD_Clear(void)
{
	LCD_sendCommand(LCD_CLEAR); 
}


void LCD_IntToStr(const uint16 data)
{
	uint8 buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* 10 for decimal */
	LCD_sendString(buff);
}


void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;

	/* first of all calculate the required address */
	switch(row)
	{
	case 0:
		Address=col;
		break;
	case 1:
		Address=col+0x40;
		break;
	case 2:
		Address=col+0x10;
		break;
	case 3:
		Address=col+0x50;
		break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_sendString(Str); /* display the string */
}
