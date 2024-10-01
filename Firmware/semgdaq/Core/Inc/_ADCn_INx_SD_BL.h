/*
 * _ADCn_INx_SD_BL.h
 *
 *  Created on: Oct 1, 2024
 *  Author: Mwangi Alex. W
 */

#ifndef INC__ADCN_INX_SD_BL_H_
#define INC__ADCN_INX_SD_BL_H_

//INCLUDES
#include "_ADCn_INx_Offset.h"

//VARIABLES
ADC1_IN1_MA OffsetCalc_ADC1_IN1; // Declaring an instance of the Offset calculation
ADC1_IN2_MA OffsetCalc_ADC1_IN2;
ADC2_IN3_MA OffsetCalc_ADC2_IN3;
ADC2_IN4_MA OffsetCalc_ADC2_IN4;
ADC3_IN1_MA OffsetCalc_ADC3_IN1;
ADC3_IN2_MA OffsetCalc_ADC3_IN2;


//FUNCTION DECLARATIONS
float32_t  ADC1_IN1_SD_BL(float32_t Buffer_1); // Calculates the offset (mean of the baseline signal) for ADC1 channel 1 to be subtracted from data that follows

float32_t  ADC1_IN2_SD_BL(float32_t Buffer_2);

float32_t  ADC2_IN3_SD_BL(float32_t Buffer_3);

float32_t  ADC2_IN4_SD_BL(float32_t Buffer_4);

float32_t  ADC3_IN1_SD_BL(float32_t Buffer_5);

float32_t  ADC3_IN2_SD_BL(float32_t Buffer_6);




#endif /* INC__ADCN_INX_SD_BL_H_ */
