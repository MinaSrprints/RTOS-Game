#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "LCD.h"
#include "lcd_4bit.h"
#include "keypad.h"
#include "button.h"
#include "semphr.h"
TaskHandle_t  init_handel = NULL;
TaskHandle_t A_handel = NULL;
TaskHandle_t B_handel = NULL;
TaskHandle_t C_handel = NULL;
//TaskHandle_t D_handel = NULL;
SemaphoreHandle_t xSemaphore2;
SemaphoreHandle_t xSemaphore1;
SemaphoreHandle_t xSemaphoreCount_2;
SemaphoreHandle_t xSemaphoreCount_1;

void InitTask(void);
void B(void);
void A(void);
void C(void);
//void D(void);

int main(void)
{
	xTaskCreate((TaskFunction_t)InitTask,"init",200,NULL,5,&init_handel);
	xTaskCreate((TaskFunction_t)B,"A",100,NULL,5,&B_handel);
	xTaskCreate((TaskFunction_t)A,"B",100,NULL,5,&A_handel);
	xTaskCreate((TaskFunction_t)C,"C",100,NULL,2,&C_handel);
	//	xTaskCreate((TaskFunction_t)D,"D",100,NULL,4,&D_handel);
	//	LED_Write(1,HIGH);
	/* Start Scheduler */
	vTaskStartScheduler();

	while(1)
	{

	}
	return 0;
}
void InitTask(void)
{
	for(;;)
	{
		LED_Init();
		BUTTON_Init(2);
		vTaskDelay(10);
		BUTTON_Init(1);
		vTaskDelay(10);
		lcd_init();
		vTaskDelay(10);
		/* Attempt to create a semaphore. */
		xSemaphore2 = xSemaphoreCreateBinary();
		xSemaphore1 = xSemaphoreCreateBinary();
		xSemaphoreCount_1 = xSemaphoreCreateCounting((UBaseType_t)10,(UBaseType_t)0);
		xSemaphoreCount_2 = xSemaphoreCreateCounting((UBaseType_t)10,(UBaseType_t)0);
		vTaskDelay(10);
		vTaskSuspend(init_handel);
	}
}
void A(void)
{
	vTaskDelay(50);
	for(;;)
	{
		if(!BUTTON_GitButtonState(1))
		{
			vTaskDelay(10);
			if(!BUTTON_GitButtonState(1))
			{
				xSemaphoreGive(xSemaphoreCount_2);
				if (xSemaphoreTake(xSemaphoreCount_1,0) == pdTRUE)
				{

				}
				while(!BUTTON_GitButtonState(1));
			}
		}
		vTaskDelay(5);
	}
}
void B(void)
{
	vTaskDelay(50);
	for(;;)
	{
		if(!BUTTON_GitButtonState(2))
		{
			vTaskDelay(10);
			if(!BUTTON_GitButtonState(2))
			{
				xSemaphoreGive(xSemaphoreCount_1);
				if (xSemaphoreTake(xSemaphoreCount_2,0) == pdTRUE)
				{

				}
				while(!BUTTON_GitButtonState(2));
			}
		}
		vTaskDelay(5);
	}
}
void C(void)
{
	static UBaseType_t playerOneCount=0;
	static UBaseType_t playerTwoCount=0;
	static uint32 taskCount=0;
	vTaskDelay(50);
	for(;;)
	{

		playerOneCount=uxSemaphoreGetCount(xSemaphoreCount_1);
		playerTwoCount=uxSemaphoreGetCount(xSemaphoreCount_2);

		if(playerOneCount==10)
		{
			lcd_disp_string_xy("player one win",0,0);
			taskCount++;
			if(taskCount==10)
			{
				vTaskSuspend(C_handel);
			}
			lcd_disp_string_xy("                  ",1,0);
			vTaskDelay(200);
			lcd_disp_string_xy("congratulations",1,0);
			vTaskDelay(200);

		}
		else if(playerTwoCount==10)
		{
			taskCount++;
			lcd_disp_string_xy("player Two win",0,0);
			if(taskCount==10)
			{
				vTaskSuspend(C_handel);
			}
			lcd_disp_string_xy("                  ",1,0);
			vTaskDelay(200);
			lcd_disp_string_xy("congratulations",1,0);
			vTaskDelay(200);
		}
		else
		{
			lcd_gotoxy(0,0);
			lcd_displayChar(playerOneCount + '0');
			lcd_gotoxy(1,0);
			lcd_displayChar(playerTwoCount + '0');
		}
		vTaskDelay(10);
	}
}
//void D(void)
//{
//	vTaskDelay(50);
//	for(;;)
//	{
//
//	}
//}
