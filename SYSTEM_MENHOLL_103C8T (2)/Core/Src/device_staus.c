//device_staus.c
#include"common.h"

STATUS_T m_status;
void Battery_Config()
{
	float Volt_mcu;
	uint16_t adc = 0;
  	HAL_ADC_Start(&hadc1);  //ADC 시작
  	if (HAL_ADC_PollForConversion(&hadc1, 1000000) == HAL_OK)  //ADC가 이상없으면
    {
    	adc = HAL_ADC_GetValue(&hadc1);                    //ADC값을 저장
    	m_status.fan_Battery =(uint8_t)((adc * 3.3 /4095) * 12/3.3) ;

    	if(m_status.fan_Battery<=10) Lora_Send_Msg("Battery Low",m_status.fan_Battery);
    	else if(m_status.fan_Battery>14) Lora_Send_Msg("Battery High",m_status.fan_Battery);
    }

  
}

void Menholl_Open_Config()
{
	static uint8_t open_flag = 0;
	if(IS_MENHOLL_OPEN ==0)
	{
		m_status.Menholl_open_flag = 1;
		Lora_Send_Msg("Menholl Open",m_status.Menholl_open_flag);
		//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
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
