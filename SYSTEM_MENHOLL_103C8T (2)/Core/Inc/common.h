//common.h
#ifndef COMMON_H
#define COMMON_H
//
/*  			include start  			*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h> 
#include <time.h> 


#include"main.h"
#include"device_status.h"
#include"eco_sensor.h"
#include "sx1276.h"
#include"gps.h"
#include "usart.h"
#include "lte_module.h"
/*  			include end  			*/



/*  			define start  			*/
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


#define MASTER_DEVICE	 1

#define MSG_END		44
/*  			define end  			*/



/*  			enum start  			*/
typedef enum
{
	STEP1,
	STEP2,
	STEP3,
	STEP4,
	STEP5,
	STEP6,
	STEP7,
	STEP8,
	STEP9,
	STEP10,
	STEP11,
	STEP12,
	STEP13,
	STEP14,
	STEP15,
	
} STEP_E;



typedef enum
{
	ERR =0,
	OK = 1,
} OK_E;


typedef enum
{
	UNCOMPLETE =0,
	COMPLETE = 1,
} COMPLETE_E;
typedef enum
{
	SEC_5 =  5000,
	SEC_10 = 10000,
	SEC_20 = 20000,
	SEC_30 = 30000,
	SEC_40 = 40000,
	SEC_50 = 50000,
	SEC_60 = 60000,
	SEC_70 = 70000,
	SEC_80 = 80000,
	SEC_90 = 90000,
	SEC_100 = 100000,
	SEC_110 = 110000,
	SEC_120 = 1200000,
} SEC_E;
/*  			enum end  				*/



/*  			stuct start  			*/

/*  			stuct end  				*/



/*  			function start  		*/
void Main_config();
uint8_t Event_Config(uint16_t* buffCh, uint8_t chAdd);
/*  			function end  			*/

extern SPI_HandleTypeDef hspi2;
extern I2C_HandleTypeDef hi2c1;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern UART_HandleTypeDef huart2;
extern STATUS_T m_status;
extern ECO_T m_eco;
extern UART_T m_uart1;
extern UART_T m_uart2;
extern uint8_t rxBuff1[1300];
extern int rxCnt1;

#endif
