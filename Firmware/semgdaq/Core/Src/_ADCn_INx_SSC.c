/*
 * _ADCn_INx_SSC.c
 *
 *  Created on: Oct 3, 2024
 *  Author: Mwangi Alex. W
 *
 *  Defines the functions that are responsible for calculating the slope sign change for the sEMG data in the moving average output buffer.
 *  The slope sign change is a feature of the sEMG signals that allows us to evaluate muscle activation and frequency characteristics without
 *  converting it to the frequency domain
 */

//INCLUDES
#include "_ADCn_INx_SSC.h"

//FUNCTION DEFINITIONS
float32_t ADC1_IN1_SSC(ADC1_IN1_MA *ADC1_IN1_SSC_ptr, float32_t Threshold_1)
{
  float32_t SSC_Count_1 = 0.0f;

  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
  {
	float32_t SSC_Diff_1 = ADC1_IN1_SSC_ptr->MA_ADC1_IN1_OutBfr[n] - ADC1_IN1_SSC_ptr->MA_ADC1_IN1_OutBfr[n-1];
	float32_t SSC_Diff_2 = ADC1_IN1_SSC_ptr->MA_ADC1_IN1_OutBfr[n+1] - ADC1_IN1_SSC_ptr->MA_ADC1_IN1_OutBfr[n];

	if ( SSC_Diff_1 * SSC_Diff_2 > 0 && (fabs (SSC_Diff_1) > Threshold_1 || fabs (SSC_Diff_2) > Threshold_1) )
	{
       SSC_Count_1++;
	}
  }

  return SSC_Count_1;
}


float32_t ADC1_IN2_SSC(ADC1_IN2_MA *ADC1_IN2_SSC_ptr, float32_t Threshold_2)
{
  float32_t SSC_Count_2 = 0.0f;

  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
  {
	float32_t SSC_Diff_3 = ADC1_IN2_SSC_ptr->MA_ADC1_IN2_OutBfr[n] - ADC1_IN2_SSC_ptr->MA_ADC1_IN2_OutBfr[n-1];
	float32_t SSC_Diff_4 = ADC1_IN2_SSC_ptr->MA_ADC1_IN2_OutBfr[n+1] - ADC1_IN2_SSC_ptr->MA_ADC1_IN2_OutBfr[n];

	if ( SSC_Diff_3 * SSC_Diff_4 > 0 && (fabs (SSC_Diff_3) > Threshold_2 || fabs (SSC_Diff_4) > Threshold_2) )
	{
       SSC_Count_2++;
	}
  }

  return SSC_Count_2;
}


float32_t ADC2_IN3_SSC(ADC2_IN3_MA *ADC2_IN3_SSC_ptr, float32_t Threshold_3)
{
  float32_t SSC_Count_3 = 0.0f;

  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
  {
	float32_t SSC_Diff_5 = ADC2_IN3_SSC_ptr->MA_ADC2_IN3_OutBfr[n] - ADC2_IN3_SSC_ptr->MA_ADC2_IN3_OutBfr[n-1];
	float32_t SSC_Diff_6 = ADC2_IN3_SSC_ptr->MA_ADC2_IN3_OutBfr[n+1] - ADC2_IN3_SSC_ptr->MA_ADC2_IN3_OutBfr[n];

	if ( SSC_Diff_5 * SSC_Diff_6 > 0 && (fabs (SSC_Diff_5) > Threshold_3 || fabs (SSC_Diff_6) > Threshold_3) )
	{
       SSC_Count_3++;
	}
  }

  return SSC_Count_3;
}


float32_t ADC2_IN4_SSC(ADC2_IN4_MA *ADC2_IN4_SSC_ptr, float32_t Threshold_4)
{
  float32_t SSC_Count_4 = 0.0f;

  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
  {
	float32_t SSC_Diff_7 = ADC2_IN4_SSC_ptr->MA_ADC2_IN4_OutBfr[n] - ADC2_IN4_SSC_ptr->MA_ADC2_IN4_OutBfr[n-1];
	float32_t SSC_Diff_8 = ADC2_IN4_SSC_ptr->MA_ADC2_IN4_OutBfr[n+1] - ADC2_IN4_SSC_ptr->MA_ADC2_IN4_OutBfr[n];

	if ( SSC_Diff_7 * SSC_Diff_8 > 0 && (fabs (SSC_Diff_7) > Threshold_4 || fabs (SSC_Diff_8) > Threshold_4) )
	{
       SSC_Count_4++;
	}
  }

  return SSC_Count_4;
}


float32_t ADC3_IN1_SSC(ADC3_IN1_MA *ADC3_IN1_SSC_ptr, float32_t Threshold_5)
{
  float32_t SSC_Count_5 = 0.0f;

  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
  {
	float32_t SSC_Diff_9 = ADC3_IN1_SSC_ptr->MA_ADC3_IN1_OutBfr[n] - ADC3_IN1_SSC_ptr->MA_ADC3_IN1_OutBfr[n-1];
	float32_t SSC_Diff_10 = ADC3_IN1_SSC_ptr->MA_ADC3_IN1_OutBfr[n+1] - ADC3_IN1_SSC_ptr->MA_ADC3_IN1_OutBfr[n];

	if ( SSC_Diff_9 * SSC_Diff_10 > 0 && (fabs (SSC_Diff_9) > Threshold_5 || fabs (SSC_Diff_10) > Threshold_5) )
	{
       SSC_Count_5++;
	}
  }

  return SSC_Count_5;
}


float32_t ADC3_IN2_SSC(ADC3_IN2_MA *ADC3_IN2_SSC_ptr, float32_t Threshold_6)
{
  float32_t SSC_Count_6 = 0.0f;

  for(uint32_t n=1; n<ADC_DMA_SIXTEENTHBUFFERSIZE; n++)
  {
	float32_t SSC_Diff_11 = ADC3_IN2_SSC_ptr->MA_ADC3_IN2_OutBfr[n] - ADC3_IN2_SSC_ptr->MA_ADC3_IN2_OutBfr[n-1];
	float32_t SSC_Diff_12 = ADC3_IN2_SSC_ptr->MA_ADC3_IN2_OutBfr[n+1] - ADC3_IN2_SSC_ptr->MA_ADC3_IN2_OutBfr[n];

	if ( SSC_Diff_11 * SSC_Diff_12 > 0 && (fabs (SSC_Diff_11) > Threshold_6 || fabs (SSC_Diff_12) > Threshold_6) )
	{
       SSC_Count_6++;
	}
  }

  return SSC_Count_6;
}


