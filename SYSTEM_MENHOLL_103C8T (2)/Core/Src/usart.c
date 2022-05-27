/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include <stdarg.h>
#include"common.h"

extern uint8_t rxData1[1];
extern uint8_t rxData2[1];

extern uint8_t rxMsg1[30];
extern uint8_t rxMsg2[30];

/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PB6     ------> USART1_TX
    PB7     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_AFIO_REMAP_USART1_ENABLE();

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PB6     ------> USART1_TX
    PB7     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6|GPIO_PIN_7);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	static uint8_t start1 = 0;
	static uint8_t rxCnt1 = 0;
	static uint8_t rxBuff1[30] = {0,};

	static uint8_t start2 = 0;
	static uint8_t rxCnt2 = 0;
	static uint8_t rxBuff2[30] = {0,};
	
	if(huart == &huart2) //GPS_UART_CallBack();
	{
		HAL_UART_Receive_IT(&huart2, rxData2, 1);

		if(rxData2[0] == '[')
		{
			rxCnt2 =  0;
			start2 = 1;
		}
		else if(rxData2[0] == ']')
		{
			memcpy(rxMsg2, rxBuff2, 30);
			memset(rxBuff2, 0 , 30);
			rxCnt2 = 0;
			start2 = 0;
		}
		else if(start2)
		{
			rxBuff2[rxCnt2] = rxData2[0];
			rxCnt2++;
		}
			
	}

	
	else if(huart == &huart1)
	{
		HAL_UART_Receive_IT(&huart1, rxData1, 1);

		if(rxData1[0] == '[')
		{
			rxCnt1 =  0;
			start1 = 1;
		}
		else if(rxData1[0] == ']')
		{
			memcpy(rxMsg1, rxBuff1, 30);
			memset(rxBuff1, 0 , 30);
			rxCnt1 = 0;
			start1 = 0;
		}
		else if(start1)
		{
			rxBuff1[rxCnt1] = rxData1[0];
			rxCnt1++;
		}
	}
}




void Pc_Command_Response()
{
	uint16_t num = 0;
	int rxLen = 0;
	rxLen = strlen(rxMsg1);

	if(rxLen != NULL)
	{
		if(rxMsg1[DIVISION_POS] !='_') return;
		
		if(atoi(rxMsg1+VALUE_POS) != 0)
		{
			num = atoi(rxMsg1+VALUE_POS);
		}
		
		if(Is_Include_ThisStr( rxMsg1, "SF"))
		{
			if(SF_07<= num && num<= SF_12 )
			{
				Lora_Send_Msg("SF",num);
				HAL_Delay(100);
				SX1276_Control_SF((uint8_t)num);	
				PCPrintf("SF = %u \r\n",num);
			}										
		}
		
		else if(Is_Include_ThisStr( rxMsg1, "WT"))
		{
			m_status.txWateTime = num;
			PCPrintf("txWateTime = %u \r\n",m_status.txWateTime );
		}	

		else if(Is_Include_ThisStr( rxMsg1, "TO"))
		{
			m_status.txTimeOut = num;	
			PCPrintf("txTimeOut = %u \r\n",m_status.txTimeOut );
		}

		else if(Is_Include_ThisStr( rxMsg1, "RU"))
		{				
			Lora_Send_Msg(rxMsg1,NONE_VALUE);
			HAL_Delay(100);
			if(rxMsg1[DIVISION_POS] =='_')
				memcpy(m_status.toNodeRute, rxMsg1+VALUE_POS, strlen(rxMsg1)-CMD_LEN);

		}
		memset(rxMsg1, 0, 30);
	}
}

void PCPrintf(char *format, ...)
{
	va_list	ap;
	char str[256];

	va_start(ap, format);
	vsprintf(str, format, ap);
	
	HAL_UART_Transmit_IT(&huart1, str, strlen(str));

	va_end(ap);
	
	return;
}

void PCPuts(char *msg)
{
	char str[256] = {0,};
	memcpy(str, msg, strlen(msg));
	
	HAL_UART_Transmit_IT(&huart1, str, strlen(str));
}

uint32_t String_To_Hex(char* str)
{
	uint32_t hex = 0;
	int len = strlen(str);
	for(int i =0 ;i < len;i++)
	{
		hex |= (str[(len-1)-i]<<i*8);
	}
	return hex;
}

uint8_t Is_Include_ThisStr(uint8_t* buff, char* str)
{
	if(strncmp(str,buff ,strlen(str))==0)
	{
		return 1;
	}

	return 0;
}


uint8_t E22HeadMsg[6] = {0x11, 0x01, 0x03,0xAA,0xBB,0xCC};
uint8_t E22ReadStatus[3] = {0xC1, 0x00, 0x09}; 
uint8_t dddata[] = "[AABBCC]";
int wwee = 0;
void E22_Send()
{
	//HAL_UART_Transmit_IT(&huart2, E22ReadStatus, 3);
	HAL_UART_Transmit_IT(&huart2, dddata, strlen(dddata));
}
/* USER CODE END 1 */
