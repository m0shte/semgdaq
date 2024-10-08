/*
 * _ADCn_INx_MA.c
 *
 * Created on: Sep 25, 2024
 * Author: Mwangi Alex. W
 *
 * Defines the functions that conduct moving average filtering on the output of the notch filters to eradicate baseline drift
 * that arises from motion artifacts and also smoothen data
 *
 */

//INCLUSIONS
#include "_ADCn_INx_MA.h"

//VARIABLES
static float32_t  MA_IMPULSERESPONSE[MA_FILTER_LENGTH] = {0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f}; // Impulse response coefficients

//FUNCTION DEFINITIONS
void MA_ADC1_IN1_Init (ADC1_IN1_MA *ADC1_IN1_MA_ptr)
{

	for(uint8_t j=0; j< MA_FILTER_LENGTH; j++)
	{
        ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr[j]=0.0f; // Clear the moving average buffer
    }


	ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr_indx=0; // Initialize the buffer index


	for (uint32_t i=0; i <ADC_DMA_SIXTEENTHBUFFERSIZE; i++)
	{
	    ADC1_IN1_MA_ptr->MA_ADC1_IN1_OutBfr[i] = 0.0f; // Clear the output buffer
	}
}

void MA_ADC1_IN1_Update(ADC1_IN1_MA *ADC1_IN1_MA_ptr)
{
    for (uint32_t u = 0; u < ADC_DMA_HALFBUFFERSIZE; u++)
    {

        ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr[ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr_indx] = ADC1_IN1_NF_arg._NF_ADC1_IN1_bfr[u]; // Store the current input sample in the circular buffer


        /* Increment the buffer index and wrap around if necessary */
        ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr_indx++;

        if (ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr_indx == MA_FILTER_LENGTH)
        {
            ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr_indx = 0;
        }


        ADC1_IN1_MA_ptr->MA_ADC1_IN1_OutBfr[u] = 0.0f; // Initialize the current output sample inside the struct's output buffer


        uint32_t SumIndex_1 = ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr_indx; // Set SumIndex_1 to the current buffer index

        /* Perform convolution (dot product) with the impulse response */
        for (uint32_t r = 0; r < MA_FILTER_LENGTH; r++)
        {
            /* Decrement index and wrap if necessary (moving backwards in the circular buffer) */
            if (SumIndex_1 > 0)
            {
                SumIndex_1--;
            }

            else
            {
                SumIndex_1 = MA_FILTER_LENGTH - 1;
            }

            /* Multiply impulse response with buffer sample and accumulate into output */
            ADC1_IN1_MA_ptr->MA_ADC1_IN1_OutBfr[u] += MA_IMPULSERESPONSE[r] * ADC1_IN1_MA_ptr->MA_ADC1_IN1_bfr[SumIndex_1];
        }

    }
}



void MA_ADC1_IN2_Init (ADC1_IN2_MA *ADC1_IN2_MA_ptr)
{

	for(uint8_t j=0; j< MA_FILTER_LENGTH; j++)
	{
        ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr[j]=0.0f;
    }


	ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr_indx=0;


	for (uint32_t i=0; i <ADC_DMA_SIXTEENTHBUFFERSIZE; i++)
	{
	    ADC1_IN2_MA_ptr->MA_ADC1_IN2_OutBfr[i] = 0.0f;
	}
}

void MA_ADC1_IN2_Update (ADC1_IN2_MA *ADC1_IN2_MA_ptr)
{
    for (uint32_t u = 0; u < ADC_DMA_HALFBUFFERSIZE; u++)
    {

        ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr[ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr_indx] = ADC1_IN2_NF_arg._NF_ADC1_IN2_bfr[u];



        ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr_indx++;

        if (ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr_indx == MA_FILTER_LENGTH)
        {
            ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr_indx = 0;
        }


        ADC1_IN2_MA_ptr->MA_ADC1_IN2_OutBfr[u] = 0.0f;


        uint32_t SumIndex_2 = ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr_indx;


        for (uint32_t r = 0; r < MA_FILTER_LENGTH; r++)
        {

            if (SumIndex_2 > 0)
            {
                SumIndex_2--;
            }

            else
            {
                SumIndex_2 = MA_FILTER_LENGTH - 1;
            }


            ADC1_IN2_MA_ptr->MA_ADC1_IN2_OutBfr[u] += MA_IMPULSERESPONSE[r] * ADC1_IN2_MA_ptr->MA_ADC1_IN2_bfr[SumIndex_2];
        }

    }
}



void MA_ADC2_IN3_Init (ADC2_IN3_MA *ADC2_IN3_MA_ptr)
{

	for(uint8_t j=0; j< MA_FILTER_LENGTH; j++)
	{
        ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr[j]=0.0f;
    }


	ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr_indx=0;


	for (uint32_t i=0; i <ADC_DMA_SIXTEENTHBUFFERSIZE; i++)
	{
	    ADC2_IN3_MA_ptr->MA_ADC2_IN3_OutBfr[i] = 0.0f;
	}
}

void MA_ADC2_IN3_Update (ADC2_IN3_MA *ADC2_IN3_MA_ptr)
{
    for (uint32_t u = 0; u < ADC_DMA_HALFBUFFERSIZE; u++)
    {

        ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr[ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr_indx] = ADC2_IN3_NF_arg._NF_ADC2_IN3_bfr[u]; // Store the current input sample in the circular buffer



        ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr_indx++;

        if (ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr_indx == MA_FILTER_LENGTH)
        {
            ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr_indx = 0;
        }


        ADC2_IN3_MA_ptr->MA_ADC2_IN3_OutBfr[u] = 0.0f;


        uint32_t SumIndex_3 = ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr_indx;


        for (uint32_t r = 0; r < MA_FILTER_LENGTH; r++)
        {

            if (SumIndex_3 > 0)
            {
                SumIndex_3--;
            }

            else
            {
                SumIndex_3 = MA_FILTER_LENGTH - 1;
            }


            ADC2_IN3_MA_ptr->MA_ADC2_IN3_OutBfr[u] += MA_IMPULSERESPONSE[r] * ADC2_IN3_MA_ptr->MA_ADC2_IN3_bfr[SumIndex_3];
        }

    }

}



void MA_ADC2_IN4_Init (ADC2_IN4_MA *ADC2_IN4_MA_ptr)
{

	for(uint8_t j=0; j< MA_FILTER_LENGTH; j++)
	{
        ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr[j]=0.0f; // Clear the moving average buffer
    }


	ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr_indx=0; // Initialize the buffer index


	for (uint32_t i=0; i <ADC_DMA_SIXTEENTHBUFFERSIZE; i++)
	{
	    ADC2_IN4_MA_ptr->MA_ADC2_IN4_OutBfr[i] = 0.0f; // Clear the output buffer
	}
}

void MA_ADC2_IN4_Update (ADC2_IN4_MA *ADC2_IN4_MA_ptr)
{
    for (uint32_t u = 0; u < ADC_DMA_HALFBUFFERSIZE; u++)
    {

        ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr[ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr_indx] = ADC2_IN4_NF_arg._NF_ADC2_IN4_bfr[u]; // Store the current input sample in the circular buffer


        /* Increment the buffer index and wrap around if necessary */
        ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr_indx++;

        if (ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr_indx == MA_FILTER_LENGTH)
        {
            ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr_indx = 0;
        }


        ADC2_IN4_MA_ptr->MA_ADC2_IN4_OutBfr[u] = 0.0f; // Initialize the current output sample inside the struct's output buffer


        uint32_t SumIndex_4 = ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr_indx; // Set SumIndex_4 to the current buffer index

        /* Perform convolution (dot product) with the impulse response */
        for (uint32_t r = 0; r < MA_FILTER_LENGTH; r++)
        {
            /* Decrement index and wrap if necessary (moving backwards in the circular buffer) */
            if (SumIndex_4 > 0)
            {
                SumIndex_4--;
            }

            else
            {
                SumIndex_4 = MA_FILTER_LENGTH - 1;
            }

            /* Multiply impulse response with buffer sample and accumulate into output */
            ADC2_IN4_MA_ptr->MA_ADC2_IN4_OutBfr[u] += MA_IMPULSERESPONSE[r] * ADC2_IN4_MA_ptr->MA_ADC2_IN4_bfr[SumIndex_4];
        }

    }
}




void MA_ADC3_IN1_Init (ADC3_IN1_MA *ADC3_IN1_MA_ptr)
{

	for(uint8_t j=0; j< MA_FILTER_LENGTH; j++)
	{
        ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr[j]=0.0f;
    }


	ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr_indx=0;


	for (uint32_t i=0; i <ADC_DMA_SIXTEENTHBUFFERSIZE; i++)
	{
	    ADC3_IN1_MA_ptr->MA_ADC3_IN1_OutBfr[i] = 0.0f;
	}
}

void MA_ADC3_IN1_Update (ADC3_IN1_MA *ADC3_IN1_MA_ptr)
{
    for (uint32_t u = 0; u < ADC_DMA_HALFBUFFERSIZE; u++)
    {

        ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr[ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr_indx] = ADC3_IN1_NF_arg._NF_ADC3_IN1_bfr[u];



        ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr_indx++;

        if (ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr_indx == MA_FILTER_LENGTH)
        {
            ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr_indx = 0;
        }


        ADC3_IN1_MA_ptr->MA_ADC3_IN1_OutBfr[u] = 0.0f;


        uint32_t SumIndex_5 = ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr_indx;


        for (uint32_t r = 0; r < MA_FILTER_LENGTH; r++)
        {

            if (SumIndex_5 > 0)
            {
                SumIndex_5--;
            }

            else
            {
                SumIndex_5 = MA_FILTER_LENGTH - 1;
            }


            ADC3_IN1_MA_ptr->MA_ADC3_IN1_OutBfr[u] += MA_IMPULSERESPONSE[r] * ADC3_IN1_MA_ptr->MA_ADC3_IN1_bfr[SumIndex_5];
        }
    }
}




void MA_ADC3_IN2_Init (ADC3_IN2_MA *ADC3_IN2_MA_ptr)
{

	for(uint8_t j=0; j< MA_FILTER_LENGTH; j++)
	{
        ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr[j]=0.0f;
    }


	ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr_indx=0;


	for (uint32_t i=0; i <ADC_DMA_SIXTEENTHBUFFERSIZE; i++)
	{
	    ADC3_IN2_MA_ptr->MA_ADC3_IN2_OutBfr[i] = 0.0f;
	}
}

void MA_ADC3_IN2_Update (ADC3_IN2_MA *ADC3_IN2_MA_ptr)
{
    for (uint32_t u = 0; u < ADC_DMA_HALFBUFFERSIZE; u++)
    {

        ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr[ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr_indx] = ADC3_IN2_NF_arg._NF_ADC3_IN2_bfr[u];



        ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr_indx++;

        if (ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr_indx == MA_FILTER_LENGTH)
        {
            ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr_indx = 0;
        }


        ADC3_IN2_MA_ptr->MA_ADC3_IN2_OutBfr[u] = 0.0f;


        uint32_t SumIndex_6 = ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr_indx;


        for (uint32_t r = 0; r < MA_FILTER_LENGTH; r++)
        {

            if (SumIndex_6 > 0)
            {
                SumIndex_6--;
            }

            else
            {
                SumIndex_6 = MA_FILTER_LENGTH - 1;
            }


            ADC3_IN2_MA_ptr->MA_ADC3_IN2_OutBfr[u] += MA_IMPULSERESPONSE[r] * ADC3_IN2_MA_ptr->MA_ADC3_IN2_bfr[SumIndex_6];
        }

    }

}
