/*
 * EXTI_Config.h
 *
 *  Created on: Sep 21, 2021
 *      Author: msqotb
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

typedef enum
{
	EXTI01_LOW_LEVEL,
	EXTI01_ANY_LOGICAL_CHANGE,
	EXTI01_FALLING_EDGE,
	EXTI01_RISING_EDGE

}EXTI01_Sense;

typedef enum
{
	EXTI2_FALLING_EDGE,
	EXTI2_RISING_EDGE

}EXTI_2_Sense;

#define EXTI0_Sense	EXTI01_FALLING_EDGE
#define EXTI1_Sense	EXTI01_FALLING_EDGE
#define EXTI2_Sense	EXTI2_FALLING_EDGE




#endif /* EXTI_CONFIG_H_ */
