//lte_module.c

#include"common.h"

void LTE_Init()
{
  HAL_Delay(100);

  PWR_EN_HIGH;
  WAKE_HIGH;

  RESET_LOW;
  HAL_Delay(100);
  RESET_HIGH;

  HAL_Delay(2000); // 	
}
uint8_t rxBuff1[1300] = {0,};
int rxCnt1 = 0;

void Terminal_Send(uint8_t* buff)
{
	HAL_UART_Transmit(&huart2, buff, strlen(buff),1000);
}
void Rx_Buff1Clear()
{
	memset(rxBuff1,0,strlen(rxBuff1));
	rxCnt1 = 0;
}

uint8_t ATbuff[15] = "AT+CPSMS=0\r\n";
//uint8_t ATbuff[15] = "etegg\r\n";

void AT_CMD(uint8_t * buff)
{
	HAL_UART_Transmit(&huart1, buff, strlen(buff), 100);
	HAL_UART_Transmit(&huart1, "\r\n", 2, 100);
	HAL_Delay(1000);
//	HAL_UART_Transmit(&huart2, rxBuff1, rxCnt1,1000);
//	HAL_Delay(100);
}

void AT_CMD_College(uint8_t * buff, ...)
{
	va_list ap;
	//char str[256];
	char str[500];

	va_start(ap, buff);
	vsprintf(str, buff, ap);
	
	HAL_UART_Transmit_IT(&huart1, str, strlen(str));

	va_end(ap);
	HAL_UART_Transmit(&huart1, "\r\n", 2, 100);
//	HAL_UART_Transmit(&huart2, rxBuff1, rxCnt1,1000);
		
	return;

}
char qqStr[50] = {0,};
char qqStr2[50] = {0,};

char qq1 = 0;
char qq2 = 0;
char qq3 = 0;



void CMD_Init()
{
	AT_CMD("AT");
	OK_Check();
	//AT_CMD("ATE0");	
	AT_CMD("AT+CEREG=2");	
	OK_Check();
	AT_CMD("AT%CMATT=1");
	OK_Check();

}

char ccbuff[20] = "AAA$ABCDEF$";
char ccstr[10] = {0,};

void CMD_Reset()
{
	AT_CMD("AT+CFUN=1,1");	
	OK_Check();
	//sscanf(ccbuff,"AAA$%[^$]",ccstr );
	//sscanf(ccbuff,"AAA$%s$",ccstr );

}
//==============================
void APN_Config()
{
	CMD_Reset();
	HAL_Delay(2000);
	
	CMD_Init();
	
	CMD_Set_CFUN();
	HAL_Delay(3000);
	
	CMD_Set_APN();
	
	CMD_Reset();
	HAL_Delay(2000);
	
	CMD_Init();
	
	CMD_Get_APN();

	HAL_Delay(3000);

	HAL_UART_Transmit(&huart2, rxBuff1, rxCnt1,1000);


	HAL_UART_Transmit(&huart2, "=====", 5,1000);
}
void CMD_Set_CFUN()
{
	AT_CMD("AT+CFUN=0");	
}

void CMD_Set_APN()
{
	AT_CMD("AT%NWOPER=\"DEFAULT\"");	
	AT_CMD("AT%SETSYSCFG=\"sw_cfg.3gpp.plmn_roaming\",\"ENABLE\"");	
	AT_CMD("AT%SETSYSCFG=\"sw_cfg.nb_vendor_scan_plan.plmn_sel_mode\",\"STANDARD\"");	
	AT_CMD("AT%APNN=\"connect.cxn\"");	
}

void CMD_Get_APN()
{
	
	AT_CMD("AT%PDNACT?");	//?뙆?떛 
}



//==============================
// basic
void CMD_CanConnect()
{
	AT_CMD("AT+CEREG?");
	OK_Check();
}

void CMD_GetCIMI()
{
	AT_CMD("AT+CIMI");
}

void CMD_GetIMEI()
{
	AT_CMD("AT+CGSN");
	
}

void CMD_GetCGMR()
{
	AT_CMD("AT+CGMR");	
}

void CMD_GetCCLK()
{
	AT_CMD("AT+CCLK?");	
}

void CMD_GetRSSI()
{
	AT_CMD("AT%MEAS=\"8\"");	//
}

void CMD_GetRSRP()
{
	AT_CMD("AT%MEAS=\"8\"");	//
}

void CMD_GetRSRQ()
{
	AT_CMD("AT%MEAS=\"8\"");	//
}

void CMD_GetSINR()
{
	AT_CMD("AT%MEAS=\"8\"");//
}

void CMD_GetServingCell()
{
	AT_CMD("AT%LBSCMD=\"MLIDS\"");	//
}

void CMD_GetTxPower()
{
	AT_CMD("AT%MEAS=\"4\"");	
}

#define CMD_DELAY	2000

void Basic_Config()
{
	//setup
	CMD_Reset();
	HAL_Delay(CMD_DELAY);
	
	CMD_Init();
	CMD_CanConnect();

	HAL_Delay(CMD_DELAY);


	//loop
	CMD_GetCIMI();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetIMEI();
	HAL_Delay(CMD_DELAY);
		
	CMD_GetCGMR();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetCCLK();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetRSSI();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetRSRP();
	HAL_Delay(CMD_DELAY);

	CMD_GetRSRQ();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetSINR();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetServingCell();
	HAL_Delay(CMD_DELAY);
	
	CMD_GetTxPower();
	HAL_Delay(CMD_DELAY);

	HAL_UART_Transmit(&huart2, rxBuff1, rxCnt1,1000);
}



//==============================
char ipAdd[30] = {0,};
void CMD_GetIPAddr(char* scrAdd, char* dstAdd) // ???씪臾? 
{
	while(1)
	{
		memset(dstAdd,0,30);
		AT_CMD_College("AT%DNSRSLV=0,\"%s\"\r\n",scrAdd);	
		HAL_Delay(2000);
		char* ptr = strstr(rxBuff1,"DNSRSLV:0,");


		sscanf(ptr,"DNSRSLV:0,\"%[^\"]\r\n",dstAdd ); //臾몄옄?뿴 ?뙆?떛 二쇰ぉ

		if(dstAdd[0] != NULL)
		{
			break;
		}
	}
	OK_Check();
}

void CMD_SoketCreate(char* ipAdd, uint8_t port)
{
	char *service[] = {"UDP", "TCP"};
	int service_type = 1;

	AT_CMD_College("AT%SOCKETCMD=\"ALLOCATE\",0,\"%s\",\"OPEN\",\"%s\",%d,1500\r\n",
	service[service_type], ipAdd, port);
	OK_Check();

}
int _nSocket = 1; ////諛쏆?媛믪쑝濡? ?뙆?떛?빐?빞?븿

void CMD_SoketActivate()
{
	AT_CMD("AT%SOCKETCMD=\"ACTIVATE\",1");
	OK_Check();
}
void CMD_SoketInfo()
{
	AT_CMD("AT%SOCKETCMD=\"INFO\",1");
	OK_Check();

	
}

//char str_q1[200] = {0,};
void CMD_SoketSend(char* str)// ?닔?젙?빐?빞?븿 ?뼱?젮??
{
	char outputStr[500] = {0,};
	//char outputStr[232] = {0,};

	//memcpy(str_q1,str,strlen(str));
	
	String_to_hexString(str,outputStr);
	AT_CMD_College("AT%SOCKETDATA=\"SEND\",1,%d,\"%s\"\r\n",strlen(outputStr)/2,outputStr);
	OK_Check();
}


void CMD_SoketRecv()
{
	AT_CMD("AT%SOCKETDATA=\"RECEIVE\",1,1000");

	char* ptr = strstr(rxBuff1,"SOCKETDATA:");

//	sscanf(ptr,"SOCKETDATA:%d,%d,%d,\"%s\"",&qq1,&qq2,&qq3,qqStr );
	
	OK_Check();
}
void CMD_SoketDeActivate()
{
	//AT_CMD_College("AT%SOCKETCMD=\"DEACTIVATE\",%d", _nSocket);
	AT_CMD("AT%SOCKETCMD=\"DEACTIVATE\",1");
	OK_Check();
}
void CMD_SoketClose()
{
	//AT_CMD_College("AT%SOCKETCMD=\"DELETE\",%d", _nSocket);	
	AT_CMD("AT%SOCKETCMD=\"DELETE\",1");
	OK_Check();
}

void TCP_Config()
{
	CMD_Reset();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<1>\r\n");
	
	CMD_Init();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<2>\r\n");
	
	CMD_CanConnect(); //+CEREG: 2,2 +CEREG: 0 +CEREG: 2  +CEREG: 5,"05FB","010C5802",7
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<3>\r\n");
	
	CMD_GetIPAddr("echo.mbedcloudtesting.com",ipAdd); // %DNSRSLV:0, %DNSRSLV:1,
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<4>\r\n");
	
	CMD_SoketCreate(ipAdd,7); // SOCKETCMD:	
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<5>\r\n");
	
	CMD_SoketActivate();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<6>\r\n");
	
	CMD_SoketInfo(); //SOCKETCMD:\" ACTIVATED
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<7>\r\n");
	
	CMD_SoketSend("HELLO KOREA 33"); //SOCKETDATA:
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<8>\r\n");

	CMD_SoketRecv(); //SOCKETDATA:
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<9>\r\n");

	CMD_SoketDeActivate();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<10>\r\n");

	CMD_SoketInfo();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<11>\r\n");

	CMD_SoketClose();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<12>\r\n");

}

//==============================
//mqtt
void CMD_Set_MQTT_EV()
{
	int value = 0;
	AT_CMD_College("AT%%MQTTEV=\"ALL\",%d", value);
	Rx_Buff1Clear();
}

void CMD_Set_MQTT_NODES()
{
	char clientID[128] = {0,};
	char mqttADDR[256] = {0,};

	AT_CMD_College("AT%%MQTTCFG=\"NODES\",1,\"%s\",\"%s\"", clientID, mqttADDR);
	Rx_Buff1Clear();
}

void CMD_Set_MQTT_TIMEOUT()
{
	uint32_t value = 0;
	AT_CMD_College("AT%%MQTTCFG=\"PROTOCOL\",1,0,%u,1", value);
	Rx_Buff1Clear();
	
}
void CMD_Set_MQTT_Connect()
{
	AT_CMD("AT%%MQTTCMD=\"CONNECT\",1");
}

void CMD_MQTT_SUBSCRIBE()
{
	int qos = 0;
	char clientTopic[128];
	
	AT_CMD_College("AT%%MQTTCMD=\"SUBSCRIBE\",1,%d,\"%s\"", qos, clientTopic);
	Rx_Buff1Clear();
}

void CMD_MQTT_Publish()
{
	int qos = 0;
	char clientTopic[128];
	int szData = 0;
	
	AT_CMD_College("AT%%MQTTCMD=\"PUBLISH\",1,%d,0,\"%s\",%d", qos, clientTopic,(szData + 1));
	Rx_Buff1Clear();
}

void MQTT_UnSUBSCRIBE()
{
	char clientTopic[128];
	AT_CMD_College("AT%%MQTTCMD=\"UNSUBSCRIBE\",1,\"%s\"", clientTopic);
	Rx_Buff1Clear();
}

void CMD_Set_MQTT_Disconnect()
{
	AT_CMD("AT%%MQTTCMD=\"DISCONNECT\",1");
}

//==============================




void HTTP_Config()
{
	Terminal_Send("START\r\n");
	CMD_Reset();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<1>\r\n");

	
	CMD_Init();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<2>\r\n");
	
	CMD_CanConnect();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<3>\r\n");
        
	CMD_GetIPAddr("api.thingspeak.com",ipAdd);
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<4>\r\n");
	
	CMD_SoketCreate(ipAdd,80);
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<5>\r\n");
	
	CMD_SoketActivate();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<6>\r\n");
	
	CMD_SoketInfo();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<7>\r\n");
	
	char* WApiKey  = "R23GE8B1UPOM1RR4";//test1
	//char* WApiKey  = "PVAEO8IIU8VVDXJZ"; //test4
	
	char sendMsg[200] = "GET /update";
	int testData[10]={11,22,33,44,55,66};

	strcat(sendMsg,"?api_key=");
	strcat(sendMsg,WApiKey);

	for(int i =1 ;i < 6;i++)
	{
		Passing_field(i,testData[i],sendMsg);
	}

	strcat(sendMsg," HTTP/1.1\r\n");
	strcat(sendMsg,"Host: api.thingspeak.com\r\n");
	strcat(sendMsg,"Connection: close\r\n\r\n");

	CMD_SoketSend(sendMsg);
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<8>\r\n");

	CMD_SoketRecv();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<9>\r\n");

	CMD_SoketDeActivate();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<10>\r\n");

	CMD_SoketInfo();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<11>\r\n");

	CMD_SoketClose();
	HAL_Delay(CMD_DELAY);
	Terminal_Send("<12>\r\n");

}


void String_to_hexString(char* inputStr, char*outputStr)
{
	char sths_let[4] = {0,};
	//memset(outputStr, 0, 230);
	for(int i =0 ;i < strlen(inputStr);i++)
	{
		if(inputStr[i]=='\r')
		{
			sths_let[0] = '0';
			sths_let[1] = 'D';
		}
		else if(inputStr[i]=='\n')
		{
			sths_let[0] = '0';
			sths_let[1] = 'A';
		}
		else
		{
			sprintf(sths_let, "%x", inputStr[i]);
			
			if(('a'<=sths_let[0])&&(sths_let[0]<='f'))
				sths_let[0] = sths_let[0] - 0x20;
				
			if(('a'<=sths_let[1])&&(sths_let[1]<='f'))
				sths_let[1] = sths_let[1] -0x20;
		}
		
			
		strcat(outputStr,sths_let);
		memset(sths_let,0,4);
	}
}

char hsts_str[60] = "5B5C5D647D42434431323334";
char hsts_buff[30] = {0,};

#define HEX_TO_ASKI(data) ('0' <= data && data <= '9')? (data - '0') : (data - 'A' + 10)
void HexString_to_String()
{
	char upper,lower = 0;
	uint8_t hexdata = 0;
	char latter[2] = {0,};

	for(int i =0 ;i < strlen(hsts_str);i=i+2)
	{
		upper = HEX_TO_ASKI(hsts_str[i]);
		lower= HEX_TO_ASKI(hsts_str[i+1]);
		
		hexdata |= (upper<<4)&0xf0;
		hexdata |= lower&0x0f;
		latter[0] = hexdata;
		hexdata = 0;
		strcat(hsts_buff,latter);
	}


	//ddd = HEX_TO_ASKI('C');
}

void OK_Check()
{
	int i;
	uint32_t startTime = HAL_GetTick();
	
	while(1)
	{
		for(i =0 ;i < 20;i++)
		{
			if(rxBuff1[i]==NULL)i++;
			else break;
		}
		char* ptr = strstr(rxBuff1+i,"OK");
		
		if(ptr !=NULL)
		{
			HAL_UART_Transmit(&huart2, rxBuff1, rxCnt1,1000);
			Rx_Buff1Clear();
			break;
		}
		if(HAL_GetTick() - startTime >4000)
		{
			Terminal_Send("FAIL CMD!!\r\n");
			
			HAL_UART_Transmit(&huart2, rxBuff1, rxCnt1,1000);
			Rx_Buff1Clear();
			break;
		}

	}
}

void Passing_field(uint8_t num, int data, char* str)
{
	char numstr[2] = {0,};
	char datastr[10] = {0,};
	
	numstr[0] = num+'0';
	sprintf(datastr,"%d",data);
	
	strcat(str,"&");
	strcat(str,"field");
	strcat(str,numstr);
	strcat(str,"=");
	strcat(str,datastr);
}
void MQTT_Config()
{
	
}


