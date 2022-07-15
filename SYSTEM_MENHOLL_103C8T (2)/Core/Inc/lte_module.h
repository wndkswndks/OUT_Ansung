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
void Terminal_Send(uint8_t* buff);

void AT_CMD(uint8_t * buff);
void AT_CMD_College(uint8_t * buff, ...);



void Basic_Config();
void TCP_Config();
void HTTP_Config(char* txBuff);
void MQTT_Config();

void CMD_Init();
void CMD_Reset();


void APN_Config();
void CMD_Set_CFUN();
void CMD_Set_APN();
void CMD_Get_APN();


void CMD_CanConnect();
void CMD_GetCIMI();
void CMD_GetIMEI();
void CMD_GetCGMR();
void CMD_GetCCLK();
void CMD_GetRSSI();
void CMD_GetRSRP();
void CMD_GetRSRQ();
void CMD_GetSINR();
void CMD_GetServingCell();
void CMD_GetTxPower();

void CMD_GetIPAddr(char* scrAdd, char* dstAdd);
void CMD_SoketCreate(char* ipAdd,uint8_t port);
void CMD_SoketActivate();
void CMD_SoketInfo();
void CMD_SoketSend(char* str);
void CMD_SoketRecv();
void CMD_SoketDeActivate();
void CMD_SoketClose();

void String_to_hexString(char* inputStr, char*outputStr);
void HexString_to_String();

void Rx_Buff1Clear();
void OK_Check();
void Passing_field(uint8_t num, int data, char* str);
/*  			function end  			*/

#endif