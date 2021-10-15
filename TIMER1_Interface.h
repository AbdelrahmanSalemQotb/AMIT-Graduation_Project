/*
 * TIMER1_Interface.h
 *
 *  Created on: Sep 25, 2021
 *      Author: msqotb
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInit(PIN_OC1 Copy_OC1_PINUnitSelect);
void TIMER1_voidSetCTCValue(PIN_OC1 Copy_OC1_PINUnitSelect,u16 Copy_u8CTC_Value);
void TIMER1_voidSet_ICRValue(u16 Copy_u8CTC_Value);
u16 TIMER1_u16Read_Timer_Register (void);
void TIMER1_voidICU_Init (void);
u32 TIMER1_voidICU_Event_TimeValue (void);
void TIMER1_voidSetCTCA_CallBackFunction	(void (*Copy_void_CTCA_CallBackFunction)(void));
void TIMER1_voidSetCTCB_CallBackFunction	(void (*Copy_void_CTCB_CallBackFunction)(void));



#endif /* TIMER1_INTERFACE_H_ */
