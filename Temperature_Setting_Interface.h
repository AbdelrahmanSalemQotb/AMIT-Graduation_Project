/*
 * Temperature_Setting_Interface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */

#ifndef TEMPERATURE_SETTING_INTERFACE_H_
#define TEMPERATURE_SETTING_INTERFACE_H_

void TemperatureSetting_voidCheck (void);
void TemperatureSetting_voidTempSettingModeRun (void);
extern u8 FirstButtonFlag;
extern u8 CurrentSetTemp;
extern u8 SettingMode_Segment_Counter;



#endif /* TEMPERATURE_SETTING_INTERFACE_H_ */
