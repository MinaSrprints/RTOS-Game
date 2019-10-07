/*
 * GPIO Driver.h
 *
 * Created: 2018-09-19 
 * Author : Mohammed
 */ 
#ifndef LCD_H_
#define LCD_H_

#include "DIO_operations.h"
#include "LCD_CONF.h"


#include "FreeRTOS.h"
#include "task.h"






#define LCD_4_BIT_MODE				0x02
#define LCD_8_BIT_2_LINES_COMMAND	0x38
#define LCD_4_BIT_2_LINES_COMMAND	0x28
#define LCD_CLEAR					0x01
#define CURSOR_OFF					0x0C
#define CURSOR_ON					0x0E
#define CURSOR_BLINKING				0x0F
#define CURSOR_RIGHT				0x14
#define CURSOR_LEFT					0x10
#define SET_CURSOR_LOCATION         0x80



void LCD_sendCommand(const uint8 Command);
void LCD_INIT(void);
void LCD_sendChar(const char Char);
void LCD_sendString(const char *str);
void LCD_Clear(void);
void LCD_IntToStr(const uint16 data);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *Str);








#endif
