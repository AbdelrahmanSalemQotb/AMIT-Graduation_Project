/*
 * Push_Buttons_Interface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */

#ifndef PUSH_BUTTONS_INTERFACE_H_
#define PUSH_BUTTONS_INTERFACE_H_

void PushButtons_voidInit (void);
void PushButtons_u8IsIncrease_Button_Pressed (void);
void PushButtons_u8IsDecrease_Button_Pressed (void);
void PushButtons_voidEnable_Disable (void);
extern u8 EnableDisableFlag;

#endif /* PUSH_BUTTONS_INTERFACE_H_ */
