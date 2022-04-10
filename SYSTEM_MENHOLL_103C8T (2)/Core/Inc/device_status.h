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
/*  			define end  			*/



/*  			enum start  			*/

typedef enum
{
	WATER_FULL = 1,
	WATER_EMPTY,
} WATER_E;
/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	uint8_t fan_Battery;
	uint8_t pump_Battery;
	uint8_t Menholl_open_flag;
	uint8_t PumpActive_flag;
	
	
} STATUS_T;
/*  			stuct end  				*/



/*  			function start  		*/
void Battery_Config();
void Menholl_Open_Config();
void Pump_Active_Config();
/*  			function end  			*/

#endif
