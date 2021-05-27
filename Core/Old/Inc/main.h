/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LEDLightOutput_Pin GPIO_PIN_0
#define LEDLightOutput_GPIO_Port GPIOA
#define ValveOutput_Pin GPIO_PIN_1
#define ValveOutput_GPIO_Port GPIOA
#define FanOutput_Pin GPIO_PIN_2
#define FanOutput_GPIO_Port GPIOA
#define InputPlant1_Pin GPIO_PIN_3
#define InputPlant1_GPIO_Port GPIOA
#define OutputPlant1_Pin GPIO_PIN_4
#define OutputPlant1_GPIO_Port GPIOA
#define InputPlant2_Pin GPIO_PIN_5
#define InputPlant2_GPIO_Port GPIOA
#define OutputPlant2_Pin GPIO_PIN_6
#define OutputPlant2_GPIO_Port GPIOA
#define LightSensorInput_Pin GPIO_PIN_7
#define LightSensorInput_GPIO_Port GPIOA
#define InputPlant3_Pin GPIO_PIN_0
#define InputPlant3_GPIO_Port GPIOB
#define MoistureSensorInput_Pin GPIO_PIN_1
#define MoistureSensorInput_GPIO_Port GPIOB
#define OutputPlant3_Pin GPIO_PIN_8
#define OutputPlant3_GPIO_Port GPIOA
#define InputPlant4_Pin GPIO_PIN_11
#define InputPlant4_GPIO_Port GPIOA
#define OutputPlant4_Pin GPIO_PIN_12
#define OutputPlant4_GPIO_Port GPIOA
#define InputPlant5_Pin GPIO_PIN_15
#define InputPlant5_GPIO_Port GPIOA
#define OutputPlant5_Pin GPIO_PIN_3
#define OutputPlant5_GPIO_Port GPIOB
#define InputPlant6_Pin GPIO_PIN_4
#define InputPlant6_GPIO_Port GPIOB
#define OutputPlant6_Pin GPIO_PIN_5
#define OutputPlant6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
