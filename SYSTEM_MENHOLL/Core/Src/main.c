/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "SX1278.h"
#include "sx1276.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//#define ORG_ROLA
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

int putchar(int ch)
{
    while(HAL_OK != HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1,3000))
    {}
    return ch;
    HAL_Delay(100);
}

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
SX1278_hw_t SX1278_hw;
SX1278_t SX1278;

int master;
int ret;

char buffer[512];

int message;
int message_length;
 
uint8_t tmp = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  #ifdef ORG_ROLA
  master = 0;
  if (master == 1) {
	  printf("Mode: Master\r\n");
  } else {
	  printf("Mode: Slave\r\n");
  }
  
  //initialize LoRa module
  SX1278_hw.dio0.port = IO0_GPIO_Port;
  SX1278_hw.dio0.pin = IO0_Pin;
  SX1278_hw.nss.port = NSS_GPIO_Port;
  SX1278_hw.nss.pin = NSS_Pin;
  SX1278_hw.reset.port = RESET_GPIO_Port;
  SX1278_hw.reset.pin = RESET_Pin;
  SX1278_hw.spi = &hspi2;
  
  SX1278.hw = &SX1278_hw;
  
  printf("Configuring LoRa module\r\n");
  SX1278_init(&SX1278, 434000000, SX1278_POWER_17DBM, SX1278_LORA_SF_7,
  SX1278_LORA_BW_125KHZ, SX1278_LORA_CR_4_5, SX1278_LORA_CRC_EN, 10);
  printf("Done configuring LoRaModule\r\n");
  
  if (master == 1) {
	  ret = SX1278_LoRaEntryTx(&SX1278, 16, 2000);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
  } else {
	  ret = SX1278_LoRaEntryRx(&SX1278, 16, 2000);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
  }

  #else

  
  //m_sx1276.device = TX_DEVICE;


  SX1276_Init(434000000, SF_07, KHZ_125, RATE_4_5, CRC_ENABLE);


	if(m_sx1276.device == TX_DEVICE)
	{
		SX1276_TX_Entry(16, 2000);
	}
	else
	{
		SX1276_RX_Entry(2000);
	}
		

  #endif



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    #ifdef ORG_ROLA
		  if (master == 1) {
		  printf("Master ...\r\n");
		  HAL_Delay(1000);
		  printf("Sending package...\r\n");
	  
		  message_length = sprintf(buffer, "Hello %d", message);
		  ret = SX1278_LoRaEntryTx(&SX1278, message_length, 2000);
		  printf("Entry: %d\r\n", ret);
	  
		  printf("Sending %s\r\n", buffer);
		  ret = SX1278_LoRaTxPacket(&SX1278, (uint8_t*) buffer,
				  message_length, 2000);
		  message += 1;
	  
		  printf("Transmission: %d\r\n", ret);
		  printf("Package sent...\r\n");
	  
	  } else {
		  printf("Slave ...\r\n");
		  HAL_Delay(800);
		  printf("Receiving package...\r\n");
	  
		  ret = SX1278_LoRaRxPacket(&SX1278);
		  printf("Received: %d\r\n", ret);
		  if (ret > 0) {
			  SX1278_read(&SX1278, (uint8_t*) buffer, ret);
			  printf("Content (%d): %s\r\n", ret, buffer);
		  }
		  printf("Package received ...\r\n");
	  
	  }

    #else
    
	if(m_sx1276.device == TX_DEVICE)
	{
		HAL_Delay(1000);
		message_length = sprintf(buffer, "Hello %d", message);

		SX1276_TX_Entry(message_length, 2000);
		
		SX1276_TX_Packet(buffer,message_length,2000);

		message += 1;
	}
	else
	{
		HAL_Delay(800);
		SX1276_RX_Packet(buffer);
	}
	
    #endif


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

