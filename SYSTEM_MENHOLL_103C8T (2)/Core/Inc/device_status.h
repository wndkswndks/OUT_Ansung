//device_status.h

#ifndef DEVICE_STATUS_H
#define DEVICE_STATUS_H

/*  			include start  			*/

#include"common.h"

/*  			include end  			*/



/*  			define start  			*/

#define IS_MENHOLL_OPEN			HAL_GPIO_ReadPin(COVER_GPIO_Port, COVER_Pin)

#define WATER_SENSOR_HIGH		HAL_GPIO_ReadPin(WATER_H_GPIO_Port, WATER_H_Pin)
#define WATER_SENSOR_LOW		HAL_GPIO_ReadPin(WATER_L_GPIO_Port, WATER_L_Pin)

#define OFF_OFF	0x00
#define OFF_ON	0x01
#define ON_OFF	0x10
#define ON_ON	0x11


#define SW1_STATUS		HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)
#define SW2_STATUS		HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin)
#define SW3_STATUS		HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin)
#define SW4_STATUS		HAL_GPIO_ReadPin(SW4_GPIO_Port, SW4_Pin)

#define LED1_ON			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED1_OFF		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
#define LED1_TOGGLE		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)
						
#define LED2_ON			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET)
#define LED2_OFF		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET)
#define LED2_TOGGLE		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin)

#define LED3_ON			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET)
#define LED3_OFF		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET)
#define LED3_TOGGLE		HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin)




/*  			define end  			*/



/*  			enum start  			*/

typedef enum
{
	WATER_FULL = 1,
	WATER_EMPTY,
} WATER_E;

typedef enum
{
	SW_MODE_0,
	SW_MODE_1,
	SW_MODE_2,
	SW_MODE_3,
	SW_MODE_4,
	SW_MODE_5,
	SW_MODE_6,
	SW_MODE_7,
	SW_MODE_8,
	SW_MODE_9,
	SW_MODE_10,
	SW_MODE_11,
	SW_MODE_12,
	SW_MODE_13,
	SW_MODE_14,
	SW_MODE_15,
} SW_E;

typedef enum
{
	ERR0R_0,
	ERR0R_1,
	ERR0R_2,
	ERR0R_3,
	ERR0R_4,
	ERR0R_5,
	ERR0R_6,
	ERR0R_7,
} ERROR_E;
/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	float fan_Battery;
	uint8_t pump_Battery;
	uint8_t Menholl_open_flag;
	uint8_t PumpActive_flag;
	uint8_t sw_flag[4];
	uint8_t err_status[8];
	
	
} STATUS_T;
/*  			stuct end  				*/



/*  			function start  		*/
void Battery_Config();
void Menholl_Open_Config();
void Pump_Active_Config();
void Sw_Config();
void Error_Config();
void Set_Error(ERROR_E error);


/*  			function end  			*/

#endif
