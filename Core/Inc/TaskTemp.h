#ifndef __TASKTEMP_H
#define __TASKTEMP_H
#include "common.h"

void TaskTemp(){
	 uint8_t temp[2];
	 HAL_I2C_Mem_Read(&hi2c1, 0xD0, 0x11, 1, temp, 2, 1000);
	 float t = ((temp[0])+(temp[1]>>6)/4.0);
	 char y[20];
	 sprintf(y,"Temp: %.2f\r\n",t);
	//	HAL_UART_Transmit(&huart1,outbuf,7+strlen(outbuf)*sizeof(uint8_t), HAL_MAX_DELAY);
	 HAL_UART_Transmit(&huart1,y, strlen(y)*sizeof(uint8_t), HAL_MAX_DELAY);
	 if(t>temp_threshold)
		 is_hot = 1;
	 else
		 is_hot = 0;
}

void TaskFan(){
  static uint8_t fan_on = 0;
	if(is_hot){
		HAL_GPIO_WritePin(FanOutput_GPIO_Port,FanOutput_Pin,1);
	} else {
		HAL_GPIO_WritePin(FanOutput_GPIO_Port,FanOutput_Pin,0);
	}
}


#endif