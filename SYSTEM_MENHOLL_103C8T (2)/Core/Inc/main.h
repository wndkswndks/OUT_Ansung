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
#define LED_Pin GPIO_PIN_1
#define LED_GPIO_Port GPIOA
#define DIP_OUT_Pin GPIO_PIN_6
#define DIP_OUT_GPIO_Port GPIOA
#define DIP_IN_Pin GPIO_PIN_7
#define DIP_IN_GPIO_Port GPIOA
#define WATER_H_Pin GPIO_PIN_1
#define WATER_H_GPIO_Port GPIOB
#define WATER_L_Pin GPIO_PIN_2
#define WATER_L_GPIO_Port GPIOB
#define COVER_Pin GPIO_PIN_11
#define COVER_GPIO_Port GPIOB
#define NSS_Pin GPIO_PIN_12
#define NSS_GPIO_Port GPIOB
#define RESET_Pin GPIO_PIN_8
#define RESET_GPIO_Port GPIOA
#define IO0_Pin GPIO_PIN_9
#define IO0_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */
extern SPI_HandleTypeDef hspi2;
extern I2C_HandleTypeDef hi2c1;
extern ADC_HandleTypeDef hadc1;
#define MASK_1		0X01
#define MASK_2		0X03
#define MASK_3		0X07
#define MASK_4		0X0F
#define MASK_5		0X1F
#define MASK_6		0X3F
#define MASK_7		0X7F
#define MASK_8		0XFF


#define MOVE_BIT_0	 0
#define MOVE_BIT_1	 1
#define MOVE_BIT_2	 2
#define MOVE_BIT_3	 3
#define MOVE_BIT_4	 4
#define MOVE_BIT_5	 5
#define MOVE_BIT_6	 6
#define MOVE_BIT_7	 7
#define MOVE_BIT_8	 8
#define MOVE_BIT_9	 9
#define MOVE_BIT_10	 10
#define MOVE_BIT_11	 11
#define MOVE_BIT_12	 12
#define MOVE_BIT_13	 13
#define MOVE_BIT_14	 14
#define MOVE_BIT_15	 15

typedef enum
{
	STEP1,
	STEP2,
	STEP3,
	STEP4,
	STEP5,
	STEP6,
} STEP_E;

#define SEC_1	1000

#define SEC_10	10000

#define SEC_30	30000
#define MINUTE_1	5000//60000
void Main_config();

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
