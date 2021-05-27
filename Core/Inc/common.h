#ifndef __COMMON_H
#define __COMMON_H

#include "main.h"
#include "stdio.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;

extern uint8_t needs_water;
extern uint8_t is_hot;
extern unsigned int temp_threshold;
extern unsigned int moisture_threshold_upper;
extern unsigned int moisture_threshold_lower;
extern unsigned int dark_threshold;
extern unsigned int light_time_threshold;

extern uint32_t adc_values[];

typedef struct Plant {
	unsigned long moistureInputChannel;
	GPIO_TypeDef * valveOutputPort;
	uint16_t valveOutputPin;
	uint8_t index;
} Plant;

void initPlant(Plant* p, uint8_t p_index, unsigned long p_moisturechannel, GPIO_TypeDef * p_valvePort, uint16_t p_valvePin) {
	p->moistureInputChannel = p_moisturechannel;
	p->valveOutputPin = p_valvePin;
	p->valveOutputPort = p_valvePort;
	p->index = p_index;
}

#define PLANT0_CHANNEL ADC_CHANNEL_16
#define PLANT1_CHANNEL ADC_CHANNEL_9
#define PLANT2_CHANNEL ADC_CHANNEL_10
#define PLANT3_CHANNEL ADC_CHANNEL_15
#define PLANT5_CHANNEL ADC_CHANNEL_11
#define PLANT6_CHANNEL ADC_CHANNEL_8
#define PLANT_COUNT 6


unsigned long PlantsInputChannels[] = {PLANT0_CHANNEL, PLANT1_CHANNEL, PLANT2_CHANNEL, PLANT3_CHANNEL, PLANT5_CHANNEL, PLANT6_CHANNEL};
GPIO_TypeDef * PlantsOutputPorts[] = {ValveOutput_GPIO_Port, OutputPlant1_GPIO_Port, OutputPlant2_GPIO_Port, OutputPlant3_GPIO_Port, OutputPlant5_GPIO_Port, OutputPlant6_GPIO_Port};

uint16_t PlantsOutputPins[] = {ValveOutput_Pin, OutputPlant1_Pin, OutputPlant2_Pin, OutputPlant3_Pin, OutputPlant5_Pin, OutputPlant6_Pin};

/*

unsigned long PlantsInputChannels[] = {PLANT0_CHANNEL, PLANT1_CHANNEL, PLANT2_CHANNEL, PLANT3_CHANNEL};
GPIO_TypeDef * PlantsOutputPorts[] = {ValveOutput_GPIO_Port, OutputPlant1_GPIO_Port,OutputPlant2_GPIO_Port,OutputPlant3_GPIO_Port};

uint16_t PlantsOutputPins[] = {ValveOutput_Pin, OutputPlant1_Pin,OutputPlant2_Pin,OutputPlant3_Pin};

*/

Plant plants[PLANT_COUNT] = {0};

#define DEBUG
#undef DEBUG

#endif