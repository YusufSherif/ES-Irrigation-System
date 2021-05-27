#ifndef __TASKMOISTURE_H
#define __TASKMOISTURE_H
#include "common.h"
#include "Header.h"


void ADC_Select_MoistureSensor (unsigned long channel)
{
	HAL_Delay(10);
	ADC_ChannelConfTypeDef sConfig = {0};
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	sConfig.Channel = channel;
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

void TaskMoistureSensor(Plant* p){
	ADC_Select_MoistureSensor(p->moistureInputChannel);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	volatile uint32_t result = HAL_ADC_GetValue(&hadc1);
	char outbuf[17] = {0};
	sprintf(outbuf,"Moist %d: %d\r\n",p->index, result);
	#ifdef DEBUG
	HAL_UART_Transmit(&huart1,outbuf, strlen(outbuf)*sizeof(uint8_t), HAL_MAX_DELAY);
	#endif
	if (result > moisture_threshold_upper)
	{
		needs_water = 1;
	} else if (result < moisture_threshold_lower){
		needs_water = 0;
	}
	HAL_ADC_Stop(&hadc1);
}

void TaskSetValve(Plant* p){
  static uint8_t valve_on = 0;
	if(needs_water){
		HAL_GPIO_WritePin(p->valveOutputPort,p->valveOutputPin,1);
	} else {
		HAL_GPIO_WritePin(p->valveOutputPort,p->valveOutputPin,0);
	}
}

void TMS0(){
	TaskMoistureSensor(&plants[0]);
	ReRunMe(&TMS0, 10, 0);
}
void TMS1(){
	TaskMoistureSensor(&plants[1]);
	ReRunMe(&TMS1, 10, 0);
}
void TMS2(){
	TaskMoistureSensor(&plants[2]);
	ReRunMe(&TMS2, 10, 0);
}
void TMS3(){
	TaskMoistureSensor(&plants[3]);
	ReRunMe(&TMS3, 10, 0);
}
void TMS4(){
	TaskMoistureSensor(&plants[4]);
	ReRunMe(&TMS4, 10, 0);
}
void TMS5(){
	TaskMoistureSensor(&plants[5]);
	ReRunMe(&TMS5, 10, 0);
}

void TSV0(){
	TaskSetValve(&plants[0]);
	ReRunMe(&TSV0, 10, 0);
}

void TSV1(){
	TaskSetValve(&plants[1]);
	ReRunMe(&TSV1, 10, 0);
}
void TSV2(){
	TaskSetValve(&plants[2]);
	ReRunMe(&TSV2, 10, 0);
}
void TSV3(){
	TaskSetValve(&plants[3]);
	ReRunMe(&TSV3, 10, 0);
}
void TSV4(){
	TaskSetValve(&plants[4]);
	ReRunMe(&TSV4, 10, 0);
}
void TSV5(){
	TaskSetValve(&plants[5]);
	ReRunMe(&TSV5, 10, 0);
}

#endif