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
    	m_status.fan_Battery =(uint8_t)((adc * 3.3 /4095) * 12/3.3) ;

    	if(m_status.fan_Battery<=10) Lora_Send_Msg("fan Battery Low",m_status.fan_Battery);
    	else if(m_status.fan_Battery>14) Lora_Send_Msg("fan Battery High",m_status.fan_Battery);
    }

    HAL_ADC_Start(&hadc2);  //ADC 시작
  	if (HAL_ADC_PollForConversion(&hadc2, 1000000) == HAL_OK)  //ADC가 이상없으면
    {
    	adc = HAL_ADC_GetValue(&hadc2);                    //ADC값을 저장
    	m_status.pump_Battery =(uint8_t)((adc * 3.3 /4095) * 12/3.3) ;

    	if(m_status.pump_Battery<=10) Lora_Send_Msg("pump Battery Low",m_status.pump_Battery);
    	else if(m_status.pump_Battery>14) Lora_Send_Msg("pump Battery High",m_status.pump_Battery);
    }

  
}

void Menholl_Open_Config()
{
	if(IS_MENHOLL_OPEN ==0)
	{
		m_status.Menholl_open_flag = 1;
		Lora_Send_Msg("Menholl Open",m_status.Menholl_open_flag);
	}
	else
	{
		m_status.Menholl_open_flag = 0;
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
			Lora_Send_Msg("PUMP ERR",0);	
		break;

		case ON_ON:
			Active_flag = 1;
			sensor_past = WATER_FULL;
		break;
	}

	if(Active_flag == 1) 
	{
		m_status.PumpActive_flag = 1;
		Lora_Send_Msg("PUMP ACTIVE",m_status.PumpActive_flag);
	}
	else
	{
		m_status.PumpActive_flag = 0;
	}
	
}

void Sw_Config()
{
	SW_E sw_status = SW_MODE_0;
	if(SW1_STATUS)m_status.sw_flag[0] =1;
	else m_status.sw_flag[0] =0;

	if(SW2_STATUS)m_status.sw_flag[1] =1;
	else m_status.sw_flag[1] =0;

	if(SW3_STATUS)m_status.sw_flag[2] =1;
	else m_status.sw_flag[2] =0;

	if(SW4_STATUS)m_status.sw_flag[3] =1;
	else m_status.sw_flag[3] =0;

	sw_status = (m_status.sw_flag[3]<<3)|(m_status.sw_flag[2]<<2)|(m_status.sw_flag[1]<<1)|(m_status.sw_flag[0]<<0);
	switch (sw_status)
	{
		case SW_MODE_0:
		break;

		case SW_MODE_1:
		break;
	}

}

void Error_Config()
{
	static uint8_t onFlag = 0;
	uint8_t errStatus = 0;
	static uint8_t cnt = 0;
	uint32_t timeSave = 0;

	Set_Error(ERR0R_1);
	Set_Error(ERR0R_3);
	Set_Error(ERR0R_5);

	if(HAL_GetTick() > timeSave +1000)
	{
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

		timeSave = HAL_GetTick();
	}
}
void Set_Error(ERROR_E error)
{
	m_status.err_status[error] = 1;
}
