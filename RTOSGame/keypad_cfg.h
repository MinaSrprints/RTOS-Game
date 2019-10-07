/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad_cfg.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mohamed AbdElkader
 *
 *******************************************************************************/
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 3
#define N_row 3

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTC
#define KEYPAD_PORT_IN  PINC
#define KEYPAD_PORT_DIR DDRC




#endif /* KEYPAD_CFG_H_ */
