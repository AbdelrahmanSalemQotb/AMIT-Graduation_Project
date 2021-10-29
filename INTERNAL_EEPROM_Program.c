/*
 * INTERNAL_EEPROM_Program.c
 *
 *  Created on: Oct 21, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "BIT_MATH.h"
#include "INTERNAL_EEPROM_Private.h"
#include "INTERNAL_EEPROM_Config.h"
void(*INTERNAL_EEPROM_CallbackFunction)(void);
void INTERNAL_EEPROM_voidWriteByte (u16 Copy_u8Address , u8 Copy_u8DataByte)
{
	Copy_u8Address&=0x03FF;
	/* Wait until pervious write operation complete */
	while (GET_BIT(EECR,1)==1);
	/* Wait until SPMEN in SPMCR becomes zero */
	while (GET_BIT(SPMCR,0)==1);
	EEAR=Copy_u8Address;
	EEDR=Copy_u8DataByte;
	/*write logical one to EEMWE*/
	SET_BIT(EECR,2);
	/*start EEPROM write by setting EEWE*/
	SET_BIT(EECR,1);

}
u8 INTERNAL_EEPROM_voidReadByte (u16 Copy_u8Address)
{
	Copy_u8Address&=0x03FF;
	/* Wait until pervious write operation complete */
	while (GET_BIT(EECR,1)==1);
	EEAR=Copy_u8Address;
	/* Enable Read operation */
	SET_BIT(EECR,0);

	return EEDR;
}
void INTERNAL_EEPROM_SET_CallbackFunction(void(*Copy_P_Fun_CallbackFunction)(void))
{
	INTERNAL_EEPROM_CallbackFunction=Copy_P_Fun_CallbackFunction;
}
void __vector_18 (void) __attribute__((signal));
void __vector_18 (void)
{
	INTERNAL_EEPROM_CallbackFunction();
}
