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
#include "cmsis_os.h"
#include "adc.h"
#include "i2c.h"
#include "iwdg.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include"common.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
int cnt = 0;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t rxData1[1] = {0,};
uint8_t rxData2[1] = {0,};

char rxMsg1[30] ={0,};
uint8_t rxMsg2[30] ={0,};

int httpTemp[8]={100,200,333};
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
  MX_SPI2_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_ADC2_Init();
  MX_USART1_UART_Init();
  //MX_IWDG_Init();
  /* USER CODE BEGIN 2 */

	HAL_UART_Receive_IT(&huart1, rxData1, 1);
	HAL_UART_Receive_IT(&huart1, m_uart1.rxByte, 1);
  //GPS_Init();
  Poling_Str_Add(44);
  Poling_Str_Add(215);
  Poling_Str_Add(66);
  My_Device();
  
  if(m_status.device != 1)
  {
  	  Eco_Init();
  }	
  
  SX1276_Init(922000000, SF_VALUE, KHZ_125, RATE_4_5, CRC_ENABLE);
  if(m_sx1276.device == TX_DEVICE)
  {
	  SX1276_TX_Entry(16, 2000);
  }
  else
  {
	  SX1276_RX_Entry(2000);
  }

  LTE_Init();




  //MQTT_Config();
  //HTTP_Config(1,httpTemp );

  //GPS_config();

  Lora_Send_Msg("Device_start",NONE_VALUE);

  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();
  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */



//	  if(m_status.device == 0x01) 
//	  {
//		  	Master_Pass_Many_Station();
//			Pc_Command_Response();
//	  }	
//	  if(m_status.device == 0x02 ||m_status.device == 0x03||m_status.device == 0x04) 
//	  {
//	  		Gateway_Pass();
//	  }
//	  if(m_status.device == 0x05) Node_Pass();
//
//    Led_Toggle_Config();
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
//void Main_config()
//{
//	static uint8_t step = STEP1;
//	static uint32_t standardTime = 0; 
//	static int cnt = 0;
//	switch(step)
//	{
//		case STEP1:
//			if(HAL_GetTick() >standardTime + SEC_30)
//			{
//				Lora_Send_Msg("Nowtime",HAL_GetTick()/1000);
//				HAL_Delay(1000);
//				Lora_Send_Msg("CNT",cnt++);
//				
//				Eco_Config();
//				step = STEP2;
//				standardTime = HAL_GetTick();
//			}
//		break;
//
//		case STEP2:
//			if(HAL_GetTick() >standardTime + SEC_40)
//			{
//				Battery_Config();
//				step = STEP3;
//				standardTime = HAL_GetTick();
//			}
//		break;
//
//		case STEP3:
//			if(HAL_GetTick() >standardTime + SEC_5)
//			{
//				Menholl_Open_Config(); 
//				step = STEP4;
//				standardTime = HAL_GetTick();
//			}
//		break;
//
//		case STEP4:
//			if(HAL_GetTick() >standardTime + SEC_5)
//			{
//				Pump_Active_Config();
//				step = STEP5;
//				standardTime = HAL_GetTick();
//			}
//		break;
//
//		case STEP5:
//			if(HAL_GetTick() >standardTime + SEC_5)
//			{
//				step = STEP1;
//				All_Send();
//				standardTime = HAL_GetTick();
//			}
//		break;
//
//	}
//	LED1_TOGGLE;
//	LED2_TOGGLE;
//	LED3_TOGGLE;
//	HAL_Delay(100);
//	//Error_Config();
//}
extern uint8_t eventFlag;
extern char buffer[512];
void Main_config()
{	
	static uint32_t startTime = 0;
	uint8_t eventFlag = 0;
	uint8_t evntFlag = 0; 
	Eco_Config();
	
	Battery_Config();
	Menholl_Open_Config(); 
	//Pump_Active_Config();
	Event_Config(m_sx1276.buffCh3 ,2);




	if(WATER_SENSOR_HIGH == 0)
	{
		eventFlag = 1;
	}
	if(eventFlag)
	{


		m_sx1276.buffCh1[0] = 111;
		m_sx1276.buffCh1[1] = 222;
		m_sx1276.buffCh1[2] = 0;
		m_sx1276.buffCh1[3] = 444;
		m_sx1276.buffCh1[4] = 555;
		m_sx1276.buffCh1[5] = 0;
		m_sx1276.buffCh1[6] = 666;
		
		m_sx1276.buffCh2[0] = 11;
		m_sx1276.buffCh2[1] = 22;
		m_sx1276.buffCh2[2] = 0;
		m_sx1276.buffCh2[3] = 44;
		m_sx1276.buffCh2[4] = 55;
		m_sx1276.buffCh2[5] = 0;
		m_sx1276.buffCh2[6] = 66;

		Event_Config(m_sx1276.buffCh1,0);

		Event_Config(m_sx1276.buffCh2,1);
		

		eventFlag = 0;
	}


	
//	if(HAL_GetTick()-startTime>120000)
//	{
//		startTime = HAL_GetTick();	
//		m_sx1276.buffCh1[0] = startTime/1000;
//		m_sx1276.buffCh1[1] = startTime/1000+1;
//		m_sx1276.buffCh1[2] = startTime/1000+2;
//		m_sx1276.buffCh1[3] = startTime/1000+3;
//		m_sx1276.buffCh1[4] = startTime/1000+4;
//		m_sx1276.buffCh1[5] = startTime/1000+5;
//		m_sx1276.buffCh1[6] = startTime/1000+6;
//		m_sx1276.buffCh1[7] = startTime/1000+7;
//
//		Event_Config(m_sx1276.buffCh1);
//
//	}
}



void Event_Config(uint16_t* buffCh, uint8_t chAdd)
{
	uint8_t evntFlag = 0; 
	
		for(int i =0 ;i < 8;i++)
		{
			if(buffCh[i] != 0)
			{
				Node_event(i + (chAdd*8), buffCh[i]);
				HAL_Delay(500);
				evntFlag = 1;
			}
			
		}
		
		if(evntFlag==1)
		{
			Node_event(44, 44);
			HAL_Delay(1000);
			memset(buffCh, 0 , 8*2);
		}	
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  Error_Watchdog(ERR0R_2);
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

