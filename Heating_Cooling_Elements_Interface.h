/*
 * Heating_Cooling_Elements_Interface.h
 *
 *  Created on: Oct 29, 2021
 *      Author: msqotb
 */

#ifndef HEATING_COOLING_ELEMENTS_INTERFACE_H_
#define HEATING_COOLING_ELEMENTS_INTERFACE_H_

void HEATING_voidInit (void);
void HEATING_voidEnable (void);
void HEATING_voidDisable (void);

void COOLING_voidInit (void);
void COOLING_voidEnable (void);
void COOLING_voidDisable (void);

extern u8 Heating_LED_Count;
void HEATING_COOLING_voidLED_Disable(void);


#endif /* HEATING_COOLING_ELEMENTS_INTERFACE_H_ */
