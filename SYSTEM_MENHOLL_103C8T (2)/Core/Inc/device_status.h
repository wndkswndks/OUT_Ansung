//device_status.h

#ifndef DEVICE_STATUS_H
#define DEVICE_STATUS_H

/*  			include start  			*/

#include"common.h"

/*  			include end  			*/



/*  			define start  			*/

#define IS_MENHOLL_OPEN1		HAL_GPIO_ReadPin(DOOR1_GPIO_Port, DOOR1_Pin)
#define IS_MENHOLL_OPEN2		HAL_GPIO_ReadPin(DOOR2_GPIO_Port, DOOR2_Pin)
#define IS_MENHOLL_OPEN3		HAL_GPIO_ReadPin(DOOR3_GPIO_Port, DOOR3_Pin)

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
	DEVICE_0,
	DEVICE_1,
	DEVICE_2,
	DEVICE_3,
	DEVICE_4,
	DEVICE_5,
	DEVICE_6,
	DEVICE_7,
	DEVICE_8,
	DEVICE_9,
	DEVICE_10,
	DEVICE_11,
	DEVICE_12,
	DEVICE_13,
	DEVICE_14,
	DEVICE_15,
} DEVICE_NUM_E;

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

typedef enum
{
	EVENT_H2 = 0,			
	EVENT_LPG,				
	EVENT_CO,				
	EVENT_PROPANE,			
	EVENT_METHANE,			
	EVENT_ALCOHOL1,			
	EVENT_SMOKE,				
	EVENT_ALCOHOL2 = 8,			
	EVENT_CO2,				
	EVENT_AMMONIA,			
	EVENT_CARBON_DIOXIDE,	
	EVENT_CARBON_MONOXIDE	,
	EVENT_TOLUENE,			
	EVENT_ACETONE,			
	EVENT_FANBETTERY = 16,		
	EVENT_PUMPBETTERY,		
	EVENT_MENHOLL,			
	EVENT_PUMPACTIVE,			
	EVENT_O2,
} EVENT_E;
/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	float fan_Battery;
	float pump_Battery;
	uint8_t MenhollOpenFlag;
	uint8_t PumpActiveFlag;
	uint8_t device;
	uint8_t err_status[8];
	uint8_t event_flag;
	
	uint16_t nodeMaxNum;
	char stationName[20];
	char toNodeRute[20];
	char toMasterRute[20];
	char myNodeName[20];
	char polingDataStr[40];
	char nodeNum[40];
	uint16_t txWateTime;
	uint16_t txTimeOut;
	uint32_t maxNodeNum;
	uint32_t minNodeNum;
	int myNodeNameInt;
} STATUS_T;
/*  			stuct end  				*/



/*  			function start  		*/
void Battery_Config();
void Menholl_Open_Config();
void Pump_Active_Config();
void My_Device();
void Error_Config();
void Set_Error(ERROR_E error);
void Error_Watchdog(ERROR_E error);
void Poling_Str_Add(uint16_t data);
void Led_Toggle_Config();
void MX_IWDG_Init(void);
void Flash_Write(uint16_t data, uint16_t add);
uint32_t Flash_Read(uint16_t add);
char* IntToStr(int data);
uint8_t Get_Size(uint16_t* buff);


/*  			function end  			*/

#endif
