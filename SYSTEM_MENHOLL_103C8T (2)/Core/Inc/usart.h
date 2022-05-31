/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
#define DIVISION_POS 	2
#define VALUE_POS 		3

#define CMD_LEN		3
typedef struct
{
	char msgBuff[30];
	uint8_t rxByte[1];
	uint8_t rxBuff[30];
	uint8_t rxCnt;
	uint8_t rxStart;
} UART_T;


/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */
void Pc_Command_Response();
void PCPrintf(char *format, ...);
void PCPuts(char *msg);
uint32_t String_To_Hex(char* str);
uint8_t Is_Include_ThisStr(char* buff, uint8_t order ,char* str);

void E22_Send(uint8_t* buff);
void Rute_Cmd(uint8_t* msg);



/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

