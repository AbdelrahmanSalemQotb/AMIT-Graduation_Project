/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 12, 2021
 *      Author: msqotb
 */


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_voidINT0_Init(void);
void EXTI_voidINT1_Init(void);
void EXTI_voidINT2_Init(void);
void EXTI0_voidSet_SenseControl (EXTI01_Sense Copy_EXTI01_Sense_SenseControl);
void EXTI1_voidSet_SenseControl (EXTI01_Sense Copy_EXTI01_Sense_SenseControl);
void EXTI2_voidSet_SenseControl (EXTI_2_Sense Copy_EXTI2_Sense_SenseControl);
void EXTI0_voidSet_CallbackFunction (void (*Copy_EXTI0Callback_Function)(void));
void EXTI1_voidSet_CallbackFunction (void (*Copy_EXTI1Callback_Function)(void));
void EXTI2_voidSet_CallbackFunction (void (*Copy_EXTI2Callback_Function)(void));

void EXTI_voidINT0_Disable(void);
void EXTI_voidINT1_Disable(void);
void EXTI_voidINT2_Disable(void);


#endif /* EXTI_INTERFACE_H_ */
