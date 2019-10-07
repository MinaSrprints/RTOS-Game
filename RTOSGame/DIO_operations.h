/*
 * DIO_operations.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Faster
 */

#ifndef DIO_OPERATIONS_H_
#define DIO_OPERATIONS_H_
#include "Memory_map.h"
#include "standard_types.h"
/*---Prototypes---*/
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif /* DIO_OPERATIONS_H_ */
