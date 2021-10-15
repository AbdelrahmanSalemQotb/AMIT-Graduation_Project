/*
 * ADC_Config.h
 *
 *  Created on: Sep 19, 2021
 *      Author: msqotb
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/* select Reference voltage Bits */
typedef enum{
	Reference_voltage_ADC_AVCC,
	Reference_voltage_ADC_2_56V
}Reference_voltage_ADC;

/* select Left OR Right adjust */
/*Choose from
 * 1-R_Adjust
 * 2-L_Adjust*/
#define ADC_ADJUST	R_Adjust

/* ADC RESLOUTION
 * 1-ADC_RESLOUTION_8BIT
 * 2-ADC_RESLOUTION_10BIT */
#define ADC_RESLOUTION	ADC_RESLOUTION_10BIT

/* Prescaler select */
typedef enum{
	ADC_PR2=1,
	ADC_PR4,
	ADC_PR8,
	ADC_PR16,
	ADC_PR32,
	ADC_PR64,
	ADC_PR128
}ADC_Prescaler;


/* Input Channel and Gain Selections */
typedef enum{
	Input_Channel_ADC_ADC0=0,
	Input_Channel_ADC_ADC1,
	Input_Channel_ADC_ADC2,
	Input_Channel_ADC_ADC3,
	Input_Channel_ADC_ADC4,
	Input_Channel_ADC_ADC5,
	Input_Channel_ADC_ADC6,
	Input_Channel_ADC_ADC7,
	Input_Channel_ADC_Diff_PADC0_NADC0_G10,
	Input_Channel_ADC_Diff_PADC1_NADC0_G10,
	Input_Channel_ADC_Diff_PADC0_NADC0_G200,
	Input_Channel_ADC_Diff_PADC1_NADC0_G200,
	Input_Channel_ADC_Diff_PADC2_NADC2_G10,
	Input_Channel_ADC_Diff_PADC3_NADC2_G10,
	Input_Channel_ADC_Diff_PADC2_NADC2_G200,
	Input_Channel_ADC_Diff_PADC3_NADC2_G200,

	Input_Channel_ADC_Diff_PADC0_NADC1_G1,
	Input_Channel_ADC_Diff_PADC1_NADC1_G1,
	Input_Channel_ADC_Diff_PADC2_NADC1_G1,
	Input_Channel_ADC_Diff_PADC3_NADC1_G1,
	Input_Channel_ADC_Diff_PADC4_NADC1_G1,
	Input_Channel_ADC_Diff_PADC5_NADC1_G1,
	Input_Channel_ADC_Diff_PADC6_NADC1_G1,
	Input_Channel_ADC_Diff_PADC7_NADC1_G1,

	Input_Channel_ADC_Diff_PADC0_NADC2_G1,
	Input_Channel_ADC_Diff_PADC1_NADC2_G1,
	Input_Channel_ADC_Diff_PADC2_NADC2_G1,
	Input_Channel_ADC_Diff_PADC3_NADC2_G1,
	Input_Channel_ADC_Diff_PADC4_NADC2_G1,
	Input_Channel_ADC_Diff_PADC5_NADC2_G1,
}Input_Channel_ADC;


typedef enum
{
	MODES_ADC_FREE_RUNNING,
	MODES_ADC_ANALOG_COMPARATOR,
	MODES_ADC_EXTI0,
	MODES_ADC_TIMER0_COMPAR_MATCH,
	MODES_ADC_TIMER0_OVERFLOW,
	MODES_ADC_TIMER1_COMPAR_MATCH_B,
	MODES_ADC_TIMER1_OVERFLOW,
	MODES_ADC_TIMER1_CAPTURE_EVENT,
	MODES_ADC_SINGLE_CONVERSION
}MODES_ADC;




#endif /* ADC_CONFIG_H_ */
