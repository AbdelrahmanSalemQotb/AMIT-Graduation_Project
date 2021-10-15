/*
 * ADC_Interface.h
 *
 *  Created on: Sep 19, 2021
 *      Author: msqotb
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(Reference_voltage_ADC Copy_u8VREF  ,ADC_Prescaler Copy_u8ADCPrescaler ,BOOL Copy_BOOL_ADCInterrupt );
void ADC_voidStartConversion(Input_Channel_ADC Copy_u8Channel , MODES_ADC Copy_u8ADCMode);
u16 ADC_u16DigitalRead(void);
void ADC_voidSet_CallbackFunction (void (*Copy_ADC_Callback_Function)(void));

#endif /* ADC_INTERFACE_H_ */
