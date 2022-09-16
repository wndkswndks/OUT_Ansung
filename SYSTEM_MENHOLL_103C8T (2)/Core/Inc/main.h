/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define LED1_Pin GPIO_PIN_14
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_15
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_1
#define LED3_GPIO_Port GPIOA
#define DOOR1_Pin GPIO_PIN_5
#define DOOR1_GPIO_Port GPIOA
#define DOOR2_Pin GPIO_PIN_6
#define DOOR2_GPIO_Port GPIOA
#define DOOR3_Pin GPIO_PIN_7
#define DOOR3_GPIO_Port GPIOA
#define WATER_L_Pin GPIO_PIN_1
#define WATER_L_GPIO_Port GPIOB
#define WATER_H_Pin GPIO_PIN_10
#define WATER_H_GPIO_Port GPIOB
#define NSS_Pin GPIO_PIN_12
#define NSS_GPIO_Port GPIOB
#define RESET_Pin GPIO_PIN_8
#define RESET_GPIO_Port GPIOA
#define IO0_Pin GPIO_PIN_9
#define IO0_GPIO_Port GPIOA
#define IO0_EXTI_IRQn EXTI9_5_IRQn
#define LTE_WAKE_Pin GPIO_PIN_10
#define LTE_WAKE_GPIO_Port GPIOA
#define LTE_RESET_Pin GPIO_PIN_11
#define LTE_RESET_GPIO_Port GPIOA
#define LTE_PWR_EN_Pin GPIO_PIN_12
#define LTE_PWR_EN_GPIO_Port GPIOA
#define SW1_Pin GPIO_PIN_15
#define SW1_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_3
#define SW2_GPIO_Port GPIOB
#define SW3_Pin GPIO_PIN_4
#define SW3_GPIO_Port GPIOB
#define SW4_Pin GPIO_PIN_5
#define SW4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */




/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
