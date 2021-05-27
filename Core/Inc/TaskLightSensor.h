#ifndef __TASKLIGHTSENSOR_H
#define __TASKLIGHTSENSOR_H
#include "common.h"

void ADC_Select_LightSensor (void)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_12;
	sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

void TaskLightSensor(){
	ADC_Select_LightSensor();
	static int light_time = 0;
	static int day_count = 0;
	day_count++;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	volatile uint32_t result = HAL_ADC_GetValue(&hadc1);	char outbuf[17] = {0};
	sprintf(outbuf,"Light: %d\r\n",result);
	#ifdef DEBUG
	HAL_UART_Transmit(&huart1,outbuf, strlen(outbuf)*sizeof(uint8_t), HAL_MAX_DELAY);
	#endif
	if ((result > dark_threshold) || (HAL_GPIO_ReadPin(LEDLightOutput_GPIO_Port, LEDLightOutput_Pin)))
	{
		light_time++;
	} 
	if ( (light_time > light_time_threshold)){
		HAL_GPIO_WritePin(LEDLightOutput_GPIO_Port, LEDLightOutput_Pin,0);
	} else if ((result < dark_threshold)) {
		HAL_GPIO_WritePin(LEDLightOutput_GPIO_Port, LEDLightOutput_Pin,1);
	} else {
		HAL_GPIO_WritePin(LEDLightOutput_GPIO_Port, LEDLightOutput_Pin,0);
	}
	if (day_count == 1440){
		 day_count = 0;
		 light_time = 0;
	}
	HAL_ADC_Stop(&hadc1);

}

#endif