//bettery_cheak.c
#include"bettery_cheak.h"

void Bettery_cheak_Config()
{
	uint32_t ADCValue = 0;
	HAL_ADC_Start(&hadc1);  //ADC 시작
	if (HAL_ADC_PollForConversion(&hadc1, 1000000) == HAL_OK)  //ADC가 이상없으면
	{
	    ADCValue = HAL_ADC_GetValue(&hadc1);                    //ADC값을 저장
	}
 
}