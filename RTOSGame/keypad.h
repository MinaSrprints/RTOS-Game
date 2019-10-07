 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mohamed AbdElkader
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "standard_types.h"
#include "function_macros.h"
#include "DIO_operations.h"
#include "keypad_cfg.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
enum
{
	PRESSED,
	RELEASD,
	KeyPad_IDEAL
}EnmButton_State;
/*
 * Function responsible for getting the pressed keypad key
 */
uint8 KeyPad_getPressedKey(void);
extern uint8 press_flag;
extern void KeyPad_init(void);


#endif /* KEYPAD_H_ */
