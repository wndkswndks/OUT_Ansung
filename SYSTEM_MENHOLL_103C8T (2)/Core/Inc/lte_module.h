//lte_module.h
#ifndef LTE_MODULE_H
#define LTE_MODULE_H

/*  			include start  			*/
#include"common.h"
/*  			include end  			*/



/*  			define start  			*/
#define RESET_HIGH 	HAL_GPIO_WritePin(LTE_RESET_GPIO_Port, LTE_RESET_Pin, GPIO_PIN_SET) 
#define RESET_LOW   HAL_GPIO_WritePin(LTE_RESET_GPIO_Port, LTE_RESET_Pin, GPIO_PIN_RESET)

#define WAKE_HIGH 	 HAL_GPIO_WritePin(LTE_WAKE_GPIO_Port, LTE_WAKE_Pin, GPIO_PIN_SET)
#define PWR_EN_HIGH  HAL_GPIO_WritePin(LTE_PWR_EN_GPIO_Port, LTE_PWR_EN_Pin, GPIO_PIN_SET)
/*  			define end  			*/



/*  			enum start  			*/

/*  			enum end  				*/



/*  			stuct start  			*/

/*  			stuct end  				*/



/*  			function start  		*/
void LTE_Init();

void AT_CMD(char * buff);
void AT_CMD_College(char * buff, ...);



void Basic_Config();
void TCP_Config();
uint8_t HTTP_Config(uint8_t channel, int* txBuff);
void MQTT_Config();

uint8_t CMD_Init();
uint8_t CMD_Reset();


void APN_Config(uint8_t num);
uint8_t CMD_Set_CFUN();
uint8_t CMD_Set_APN(uint8_t num);
uint8_t CMD_Get_APN();


uint8_t CMD_CanConnect();
uint8_t CMD_GetCIMI();
uint8_t CMD_GetIMEI();
uint8_t CMD_GetCGMR();
uint8_t CMD_GetCCLK();
uint32_t GetWateTime();

uint8_t CMD_GetRSSI();
uint8_t CMD_GetRSRP();
uint8_t CMD_GetRSRQ();
uint8_t CMD_GetSINR();
uint8_t CMD_GetServingCell();
uint8_t CMD_GetTxPower();

uint8_t CMD_GetIPAddr(char* scrAdd, char* dstAdd);
uint8_t CMD_SoketCreate(char* ipAdd,uint8_t port);
uint8_t CMD_SoketActivate();
uint8_t CMD_SoketInfo();
uint8_t CMD_SoketSend(char* str);
uint8_t CMD_SoketRecv();
uint8_t CMD_SoketDeActivate();
uint8_t CMD_SoketClose();

void String_to_hexString(char* inputStr, char*outputStr);
void HexString_to_String();

void API_Read();
void API_Write(char* str, uint8_t add, char* buff);


void Rx_Buff1Clear();
uint8_t OK_Check();
void Passing_field(uint8_t num, int data, char* str);
/*  			function end  			*/

#endif
