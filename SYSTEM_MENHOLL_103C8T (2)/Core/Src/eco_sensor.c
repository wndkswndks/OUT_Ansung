//eco_sensor.c


#include"common.h"

ECO_T m_eco = 
{
	{
		{BEING_SINGELE_CONV,	ADS_REG_CONFIG,		MASK_1,  MOVE_BIT_15},
		{AIN0_AIN1,				ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_12},
		{FS_2_048V,				ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_9 },
		{SINGLE_SHOT_MODE,		ADS_REG_CONFIG,		MASK_1,  MOVE_BIT_8 },
		{SPS128,				ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_5 }
	},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};





void Eco_Config()// 실제값 : 디버깅값 + 0.0103(전압값) - 0.0717
{
	float MQ2_ratio = 0.0;
	MQ2_ratio = Get_MQ_Sensor(AIN1_GND, m_eco.MQ2.R0);
		
	MQ_Config(&m_eco.MQ2.H2,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.LPG,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.CO,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.Propane,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.METHANE,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.CARBON_MONOXIDE,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.ALCOHOL,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.SMOKE,MQ2_ratio);
		

    float MQ135_ratio = 0.0;
	MQ135_ratio = Get_MQ_Sensor(AIN2_GND, m_eco.MQ135.R0);

	MQ_Config(&m_eco.MQ135.Alcohol,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.Co2,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.Ammonia,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.CARBON_DIOXIDE,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.CARBON_MONOXIDE,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.TOLUENE,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.ACETONE,MQ135_ratio);	
	
//	ADC_to_Volt(AIN0_GND);
//	ADC_to_Volt(AIN1_GND);
//	ADC_to_Volt(AIN2_GND);
//	MCU_ADC_to_Volt();
}
void ADS1115_Init()
{
	MQ_Init(&m_eco.MQ2.H2, MQ2_H2_A,MQ2_H2_B, "H2");
	MQ_Init(&m_eco.MQ2.LPG, MQ2_LPG_A,MQ2_LPG_B, "LPG");
	MQ_Init(&m_eco.MQ2.CO, MQ2_CO_A,MQ2_CO_B, "CO");
	MQ_Init(&m_eco.MQ2.Propane, MQ2_PROPANE_A,MQ2_PROPANE_B, "Propane");
	MQ_Init(&m_eco.MQ2.METHANE, MQ2_METHANE_A,MQ2_METHANE_B, "METHANE");
	MQ_Init(&m_eco.MQ2.CARBON_MONOXIDE, MQ2_CARBON_MONOXIDE_A,MQ2_CARBON_MONOXIDE_B, "CARBON_MONOXIDE");
	MQ_Init(&m_eco.MQ2.ALCOHOL, MQ2_ALCOHOL_A,MQ2_ALCOHOL_B, "ALCOHOL");
	MQ_Init(&m_eco.MQ2.SMOKE, MQ2_SMOKE_A,MQ2_SMOKE_B, "SMOKE");

	MQ_Init(&m_eco.MQ135.Alcohol, MQ135_ALCOHOL_A,MQ135_ALCOHOL_B, "ALCOHOL");
	MQ_Init(&m_eco.MQ135.Co2, MQ135_CO2_A,MQ135_CO2_B, "CO2");
	MQ_Init(&m_eco.MQ135.Ammonia, MQ135_AMMONIA_A,MQ135_AMMONIA_B, "AMMONIA");
	MQ_Init(&m_eco.MQ135.CARBON_DIOXIDE, MQ135_CARBON_DIOXIDE_A,MQ135_CARBON_DIOXIDE_B, "CARBON_DIOXIDE");
	MQ_Init(&m_eco.MQ135.CARBON_MONOXIDE, MQ135_CARBON_MONOXIDE_A,MQ135_CARBON_MONOXIDE_B, "CARBON_MONOXIDE");
	MQ_Init(&m_eco.MQ135.TOLUENE, MQ135_TOLUENE_A,MQ135_TOLUENE_B, "TOLUENE");
	MQ_Init(&m_eco.MQ135.ACETONE, MQ135_ACETONE_A,MQ135_ACETONE_B, "ACETONE");


	
	ADS1115_Write(m_eco.config_reg.mux, AIN1_GND);
	ADS1115_Write(m_eco.config_reg.pga, FS_6_114V);

	m_eco.MQ2.R0 = Get_MQ_Sensor(AIN1_GND, R0_MQ2);
	m_eco.MQ135.R0 = Get_MQ_Sensor(AIN2_GND, R0_MQ135);

}
void MQ_Init(MQ_VALUE_T* MQ, float a, float b, char*nameStr)
{
	MQ->graph[0]= a;
	MQ->graph[1]= b;
	memcpy(MQ->name, nameStr, strlen(nameStr));
}
void MQ_Config(MQ_VALUE_T* MQ, float MQ135_ratio )
{
	MQ->value =  Set_MQ_PPM(MQ->graph, MQ135_ratio);
	if(MQ->value > 20) Lora_Send_Msg(MQ->name,(uint8_t)MQ->value);

}


float Volt_value[3] = {0,};
void ADC_to_Volt(uint8_t AIN_num)
{
	uint16_t adc = 0;
	adc = MQ_ADC_Read(AIN_num);

	Volt_value[AIN_num-4] = adc * ADS_FS_VALUE/ADS_MAX_ADC_VALUE;
}


uint16_t MQ_ADC_Read(uint8_t AIN_num)
{
	uint8_t os = 0;
	uint16_t get_adc = 0;
	uint32_t pastTime = 0;
	
	ADS1115_Write(m_eco.config_reg.mux, AIN_num);
	pastTime = HAL_GetTick();
	while(os==0)
	{
		os = ADS1115_Part_Read(m_eco.config_reg.os);
		if(HAL_GetTick()-pastTime >200)
		{
			LED1_ON;
			os = 1;
		}
	}
	
	ADS1115_Write(m_eco.config_reg.os, BEING_SINGELE_CONV);

	get_adc = ADS1115_ADC_Read();

	return get_adc;	

	
}
void ADS1115_Write(uint8_t* ads1115,uint8_t cmd)
{
	uint16_t rxWord = 0x00;
	uint16_t txWord = 0x00;
	uint8_t reg = ads1115[REG];
	uint8_t mask = ads1115[MASK];
	uint8_t move = ads1115[MOVE];
	
	rxWord = I2c_read(reg);
	rxWord &=~(mask<<move);
	txWord = rxWord|(cmd<<move);
	
	I2c_write(reg,txWord);
	ads1115[VALUE] = cmd;	
}
uint8_t ADS1115_Part_Read(uint8_t* ads1115)
{
	uint16_t rxWord = 0x00;
	uint8_t rxValue = 0;
	uint8_t reg = ads1115[REG];
	uint8_t mask = ads1115[MASK];
	uint8_t move = ads1115[MOVE];
	
	rxWord = I2c_read(reg);
	rxWord &=(mask<<move);
	rxValue = rxWord >>move;

	ads1115[VALUE] = rxValue;
	return rxValue;

}


uint16_t ADS1115_ADC_Read()
{
	uint16_t rxWord = 0x00;	
	rxWord = I2c_read(ADS_REG_CONVERSION);

	return rxWord;
}
uint16_t I2c_read(uint8_t reg)
{	
	uint8_t rxBuff[2] = {0,};
	uint16_t rxWord = 0;
	HAL_I2C_Mem_Read(&hi2c1, ADS_ADDRESS, reg, 1, rxBuff, 2, 100 );
	HAL_Delay(10);
	rxWord = rxBuff[0]<<8 | rxBuff[1];
	return rxWord;
}

void I2c_write(uint8_t reg, uint16_t txWord)
{
	uint8_t txBuff[2] = {0,};

	txBuff[0] = (txWord >>8)&0xff;
	txBuff[1] = (txWord)&0xff;
	
	HAL_I2C_Mem_Write(&hi2c1, ADS_ADDRESS, reg, 1, txBuff, 2, 100 );
	HAL_Delay(10);
}

float Set_MQ_PPM(float* sensor, float MQ_ratio)
{
	float PPM_log,PPM,percentage = 0;

	if(sensor[MQ_A]==0 && sensor[MQ_B]==0) return 0xFF;

#if MQ_SOURCE == 1
	PPM_log = (log10(MQ_ratio) - sensor[MQ_B])/sensor[MQ_A];
	PPM = pow(10, PPM_log);	
#elif MQ_SOURCE == 2
	PPM = sensor[MQ_A] * pow(MQ_ratio, sensor[MQ_B]);
#elif MQ_SOURCE == 3
	PPM = pow(10,((sensor[MQ_A]*(log10(MQ_ratio))) +sensor[MQ_B]));
#endif
	percentage = PPM/10000;
	
	if(percentage<0)percentage = 0;

	return PPM;
}


int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    uint16_t num1 = *(uint16_t *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    uint16_t num2 = *(uint16_t *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}


float Get_MQ_Sensor(uint8_t AIN_num, float R0_MQ)
{

	uint8_t num = 20;
	uint8_t half_except = 2;
	uint16_t MQ_adc, MQ_adc_avg = 0;
	uint32_t MQ_adc_sum = 0;
	uint16_t MQ_adc_Buff[20] = {0,};
	float MQ_volt,MQ_rs,MQ_ratio = 0;

	for(int i =0 ;i < num;i++)
	{
		MQ_adc = MQ_ADC_Read(AIN_num);
		MQ_adc_Buff[i] = MQ_adc;
		HAL_Delay(20);
	}
	
	qsort(MQ_adc_Buff, sizeof(MQ_adc_Buff) / sizeof(uint16_t), sizeof(uint16_t), compare); // 내림차순 정렬

	for(int i =half_except ;i < num-half_except;i++) // 앞뒤로 half_except 만큼 빼고 더함
	{
		MQ_adc_sum += MQ_adc_Buff[i];
	}
	
	MQ_adc_avg = MQ_adc_sum/(num-half_except*2); // 가운데 16개로만 평균냄

	MQ_volt = MQ_adc_avg * ADS_FS_VALUE/ADS_MAX_ADC_VALUE;

	MQ_volt = MQ_volt + MQ_volt*0.0103 - 0.0717;
	
	MQ_rs = (( ADS_VCC * ADS_RL ) / MQ_volt) - ADS_RL;

	MQ_ratio = MQ_rs / R0_MQ;
	return MQ_ratio;
}

void All_Send()
{
	Lora_Send_Msg("LPG",(uint8_t)m_eco.MQ2.LPG.value);
	Lora_Send_Msg("PP",(uint8_t)m_eco.MQ2.Propane.value);
	Lora_Send_Msg("H2",(uint8_t)m_eco.MQ2.H2.value);
	Lora_Send_Msg("CO",(uint8_t)m_eco.MQ2.CO.value);
	Lora_Send_Msg("MT",(uint8_t)m_eco.MQ2.METHANE.value);
	Lora_Send_Msg("CM",(uint8_t)m_eco.MQ2.CARBON_MONOXIDE.value);
	Lora_Send_Msg("AC",(uint8_t)m_eco.MQ2.ALCOHOL.value);
	Lora_Send_Msg("SM",(uint8_t)m_eco.MQ2.SMOKE.value);

	Lora_Send_Msg("AC",(uint8_t)m_eco.MQ135.Alcohol.value);
	Lora_Send_Msg("CO2",(uint8_t)m_eco.MQ135.Co2.value);
	Lora_Send_Msg("AM",(uint8_t)m_eco.MQ135.Ammonia.value);
	Lora_Send_Msg("CD",(uint8_t)m_eco.MQ135.CARBON_DIOXIDE.value);
	Lora_Send_Msg("CM",(uint8_t)m_eco.MQ135.CARBON_MONOXIDE.value);
	Lora_Send_Msg("TL",(uint8_t)m_eco.MQ135.TOLUENE.value);	
	Lora_Send_Msg("AT",(uint8_t)m_eco.MQ135.ACETONE.value);

	Lora_Send_Msg("Battery ",m_status.fan_Battery);
	Lora_Send_Msg("Battery ",m_status.pump_Battery);
	Lora_Send_Msg("Menholl Open",m_status.Menholl_open_flag);
	Lora_Send_Msg("PUMP ACTIVE",m_status.PumpActive_flag);
}
