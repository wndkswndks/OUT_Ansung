//device_staus.c
#include"common.h"



STATUS_T m_status;
void Battery_Config()
{
	uint16_t adc = 0;
  	HAL_ADC_Start(&hadc1);  //ADC 시작
  	if (HAL_ADC_PollForConversion(&hadc1, 1000000) == HAL_OK)  //ADC가 이상없으면
    {
    	adc = HAL_ADC_GetValue(&hadc1);                    //ADC값을 저장
    	m_status.fan_Battery = ((float)adc * 3.3 /4095) * 12/3.3 ;

    	if(m_status.fan_Battery<=9) m_sx1276.buffCh3[EVENT_FANBETTERY%8]= (uint16_t)m_status.fan_Battery; 
    	else if(m_status.fan_Battery>14) m_sx1276.buffCh3[EVENT_FANBETTERY%8]= (uint16_t)m_status.fan_Battery; 
    }
    
 	HAL_Delay(500);
 	
    HAL_ADC_Start(&hadc2);  //ADC 시작
  	if (HAL_ADC_PollForConversion(&hadc2, 1000000) == HAL_OK)  //ADC가 이상없으면
    {
    	adc = HAL_ADC_GetValue(&hadc2);                    //ADC값을 저장
    	m_status.pump_Battery =(adc * 3.3 /4095) * 12/3.3 ;

    	if(m_status.pump_Battery<=9) m_sx1276.buffCh3[EVENT_PUMPBETTERY%8]= (uint16_t)m_status.pump_Battery; 
    	else if(m_status.pump_Battery>14) m_sx1276.buffCh3[EVENT_PUMPBETTERY%8]= (uint16_t)m_status.pump_Battery; 
    }

  
}

uint16_t Madc = 0;
void Menholl_Open_Config()
{
	if(!IS_MENHOLL_OPEN1 && !IS_MENHOLL_OPEN2 && !IS_MENHOLL_OPEN3)
	{
		m_status.MenhollOpenFlag = 0;
	}
	else
	{
		m_status.MenhollOpenFlag = 1;
		m_sx1276.buffCh3[EVENT_MENHOLL%8]= 1; 
	}


}






void Pump_Active_Config()
{
	uint8_t sensor_stusus = 0;
	uint8_t Active_flag = 0;
	static uint8_t sensor_past = 0;
	sensor_stusus = ((WATER_SENSOR_HIGH<<8)&0xf0) |((WATER_SENSOR_LOW)&0x0f);
	


	switch(sensor_stusus)
	{
		case OFF_OFF:
			Active_flag = 0;
			sensor_past = WATER_EMPTY;
		break;

		case OFF_ON:
			if(sensor_past == WATER_FULL) Active_flag = 1;
			else if(sensor_past == WATER_EMPTY) Active_flag = 0;
			else Active_flag = 0;
		break;

		case ON_OFF:
			//Node_event(EVENT_PUMPACTIVE,1);	
			m_sx1276.buffCh3[EVENT_PUMPACTIVE%8]= 1; 
		break;

		case ON_ON:
			Active_flag = 1;
			sensor_past = WATER_FULL;
		break;
	}

	if(Active_flag == 1) 
	{
		m_status.PumpActiveFlag = 1;
		//Node_event(EVENT_PUMPACTIVE,2);
		m_sx1276.buffCh3[EVENT_PUMPACTIVE%8]= 2; 
	}

	
}

uint32_t MY_1;
uint32_t MY_2;
uint32_t MY_3;


void My_Device()//
{

	
	if(!SW4_STATUS)
	{
		PCPuts("### MASTER ### \r\n");
		m_status.device = MASTER_DEVICE;		

		m_status.nodeNum = (int)m_status.minNodeNum;

		m_status.maxNodeNum = Flash_Read(0);
		PCPrintf("maxNodeNum = %u \r\n",m_status.maxNodeNum );
		
		m_status.minNodeNum = Flash_Read(1);
		PCPrintf("minNodeNum = %u \r\n",m_status.minNodeNum );

		m_status.masterFolingEnable = Flash_Read(2);
		PCPrintf("masterFolingEnable = %u \r\n",m_status.masterFolingEnable );
		API_Read();

	}
	else
	{
		PCPuts("### NODE ### \r\n");
		m_status.myNodeNameInt = Flash_Read(2);
		memcpy(m_status.myNodeName,IntToStr(m_status.myNodeNameInt),strlen(IntToStr(m_status.myNodeNameInt)));
		PCPrintf("myNodeNameInt = %u \r\n",m_status.myNodeNameInt );
		
		m_status.o2Enable = Flash_Read(3);
		PCPrintf("o2Enable = %u \r\n",m_status.o2Enable );
		
		m_status.adcEnable = Flash_Read(4);
		PCPrintf("adcEnable = %u \r\n",m_status.adcEnable );	


		m_status.mqEnable = Flash_Read(5);
		PCPrintf("mqEnable = %u \r\n",m_status.mqEnable );
		
		m_status.menhollEnable = Flash_Read(6);
		PCPrintf("menhollEnable = %u \r\n",m_status.menhollEnable );
		
		m_status.pumpEnable = Flash_Read(7); // 68 is last memory
		PCPrintf("pumpEnable = %u \r\n",m_status.pumpEnable );

		if(!SW1_STATUS) 
		{
			m_status.gpsEnable = 1;
		}
		else
		{
			m_status.gpsEnable = 0;
		}	
		PCPrintf("gpsEnable = %u \r\n",m_status.gpsEnable );
	}
	
	
	m_status.txTimeOut =  1000;
	m_status.txWateTime = 20000;

}

void Error_Config()
{
	static uint8_t onFlag = 0;
	uint8_t errStatus = 0;
	static uint8_t cnt = 0;

	Set_Error(ERR0R_1);
	Set_Error(ERR0R_3);
	Set_Error(ERR0R_5);


	if(onFlag==1)
	{
		onFlag = 0;
		for(int i = cnt ;i < 8;i++)
		{
			if(m_status.err_status[i] ==1)
			{
				errStatus = i;
				cnt = i+1;
				cnt %= 8;
				break;
			}
		}
		
		switch(errStatus)
		{
			case ERR0R_0:	LED1_OFF;	LED2_OFF;	LED3_OFF;	break;//000
			case ERR0R_1:	LED1_ON;	LED2_OFF;	LED3_OFF;	break;//001					
			case ERR0R_2:	LED1_OFF;	LED2_ON;	LED3_OFF;	break;//010
			case ERR0R_3:	LED1_OFF;	LED2_ON;	LED3_ON;	break;//011
			case ERR0R_4:	LED1_ON;	LED2_OFF;	LED3_OFF;	break;//100
			case ERR0R_5:	LED1_ON;	LED2_OFF;	LED3_ON;	break;//101
			case ERR0R_6:	LED1_ON;	LED2_ON;	LED3_OFF;	break;//110					
			case ERR0R_7:	LED1_ON;	LED2_ON;	LED3_ON;	break;//111
		}
	}
	else
	{
		onFlag = 1;
		LED1_OFF;
		LED2_OFF;
		LED3_OFF;
	}

}
void Set_Error(ERROR_E error)
{
	m_status.err_status[error] = 1;
}

void Error_Watchdog(ERROR_E error)
{	
	Lora_Send_Msg("<E>",error);
	MX_IWDG_Init();
}

void Poling_Str_Add(uint16_t data)//
{
	strcat(m_status.polingDataStr,IntToStr(data));
}
void Led_Toggle_Config()
{
	static uint32_t time_stamp = 0;

	if(HAL_GetTick() - time_stamp >500)
	{
		LED3_TOGGLE;
		time_stamp = HAL_GetTick(); 
	}
}
void Flash_Write(uint16_t data, uint16_t add)
{
	
	 uint32_t PAGEError;
	 uint32_t Address = 0x08010000-0x1400;

	  static FLASH_EraseInitTypeDef EraseInitStruct;

	  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;  //0x00
	  EraseInitStruct.PageAddress = Address +0x400*add;  // 지우기 페이지의 시작 어드레스
	  EraseInitStruct.NbPages =1; //지울 페이지 수
	  HAL_FLASH_Unlock();
	  		
	  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK) 
	  {
		  printf("Eraser Error\r\n");
		  while(1);
	  }
	  
	  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Address+0x400*add, ((uint32_t)data)) != HAL_OK)
	  {
		printf("Write Error\r\n");
		while(1);
	  }
	  HAL_FLASH_Lock();
}
uint32_t Flash_Read(uint16_t add)
{
	uint32_t Address = 0x08010000-0x1400;
	uint32_t readData = 0;

	readData = *(__IO uint32_t *)(Address+0x400*add);
	return readData;
}

char tmpStr[30] = {0,};
char* IntToStr(int data)
{
	memset(tmpStr,0,30);
	sprintf(tmpStr,"%d",data);

	return tmpStr;
}

uint8_t Get_Size(uint16_t* buff)
{
	for(int i =0 ;i < 8;i++)
	{
		if(buff[i] != 0)
		{
			return 1;
		}
	}
      return 0;
}

uint32_t timeToMs(uint8_t hour, uint8_t min, uint8_t sec)
{
	return(hour*HOUR_1 + min*MIN_1 + sec*SEC_1);
}



uint32_t CalculateWateTime(uint8_t hour, uint8_t min, uint8_t sec)
{
	uint32_t wateTime,nowTime,targetTime = 0;
	uint32_t timeBuff[5] = {0,};

	nowTime = timeToMs(hour,min,sec);
	timeBuff[0] = timeToMs(0,0,0);
	timeBuff[1] = timeToMs(6,0,0);
	timeBuff[2] = timeToMs(12,0,0);
	timeBuff[3] = timeToMs(18,0,0);
	timeBuff[4] = nowTime;
	
	qsort(timeBuff, sizeof(timeBuff) / sizeof(uint32_t), sizeof(uint32_t), compare_32); 

	for(int i =0 ;i < 5;i++)
	{
		if(timeBuff[i] == nowTime)
		{
			targetTime = timeBuff[(i+1)%5];
		}
	}
	
	if(nowTime<targetTime) wateTime =targetTime - nowTime; 
	else wateTime =HOUR_1*24 + targetTime- nowTime;
		
	PCPrintf("wateTime = %u \r\n",wateTime);

	return wateTime;
}

uint32_t Time_Pass(uint32_t preTime)
{
	uint32_t nowTime = 0;
	
	nowTime = HAL_GetTick();
	return (nowTime- preTime);
}
