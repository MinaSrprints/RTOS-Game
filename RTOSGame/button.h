/*
 * button.h
 *
 *  Created on: ???/???/????
 *      Author: Mina
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "DIO_operations.h"
#include "function_macros.h"
void BUTTON_Init(uint8 button_num);
uint8 BUTTON_GitButtonState(uint8 button_num);

#endif /* BUTTON_H_ */
