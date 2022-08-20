//eco_sensor.c


#include"common.h"

ECO_T m_eco;


extern uint32_t pre_mytime;
extern uint32_t my_termtime;

void Eco_Config()// 실제값 : 디버깅값 + 0.0103(전압값) - 0.0717
{
	static uint32_t startTime = 0;

	float MQ2_ratio = 0.0;
	float MQ135_ratio = 0.0;
	
	MQ2_ratio = Get_MQ_Sensor(AIN0_GND, m_eco.MQ2.R0);
	MQ135_ratio = Get_MQ_Sensor(AIN1_GND, m_eco.MQ135.R0);
	
	MQ_Config(&m_eco.MQ2.H2,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.LPG,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.CO,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.PROPANE,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.METHANE,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.ALCOHOL,MQ2_ratio);
	MQ_Config(&m_eco.MQ2.SMOKE,MQ2_ratio);

	MQ_Config(&m_eco.MQ135.ALCOHOL,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.CO2,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.AMMONIA,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.CARBON_DIOXIDE,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.CARBON_MONOXIDE,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.TOLUENE,MQ135_ratio);
	MQ_Config(&m_eco.MQ135.ACETONE,MQ135_ratio);	

	uint8_t evntFlag = 0; 
	
	for(int i =0 ;i < 8;i++)
	{
		if(m_sx1276.buffCh1[i] != 0)
		{
			Node_event(i, m_sx1276.buffCh1[i]);
			evntFlag = 1;
			HAL_Delay(2000);
		}

		if(m_sx1276.buffCh2[i] != 0)
		{
			Node_event2(i+8, m_sx1276.buffCh2);
			evntFlag = 2;
			HAL_Delay(2000);
		}	
	}

	memset(m_sx1276.buffCh1, 0, 8*4);
	memset(m_sx1276.buffCh2, 0, 8*4);

	
//	for(int i =0 ;i < 8;i++)
//	{
//		if(m_sx1276.buffCh2[i] != 0)
//		{
//			Node_event2(2, m_sx1276.buffCh2);
//			memset(m_sx1276.buffCh2, 0, 8*4);			
//		}
//	}

	

	
//	ADC_to_Volt(AIN0_GND);
//	ADC_to_Volt(AIN1_GND);
//	ADC_to_Volt(AIN2_GND);
//	MCU_ADC_to_Volt();
}
void Eco_Init()
{
	ADS1115_RegInit(m_eco.config_reg.os, BEING_SINGELE_CONV,  ADS_REG_CONFIG,		MASK_1,  MOVE_BIT_15);
	ADS1115_RegInit(m_eco.config_reg.mux,AIN0_AIN1,			ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_12);
	ADS1115_RegInit(m_eco.config_reg.pga,FS_2_048V,			ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_9 );
	ADS1115_RegInit(m_eco.config_reg.mode,SINGLE_SHOT_MODE,	ADS_REG_CONFIG,		MASK_1,  MOVE_BIT_8);
	ADS1115_RegInit(m_eco.config_reg.data_rate,SPS128,		ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_5);
	
	MQ_Init(&m_eco.MQ2.H2, MQ2_H2_A,MQ2_H2_B, EVENT_H2);
	MQ_Init(&m_eco.MQ2.LPG, MQ2_LPG_A,MQ2_LPG_B, EVENT_LPG);
	MQ_Init(&m_eco.MQ2.CO, MQ2_CO_A,MQ2_CO_B, EVENT_CO);
	MQ_Init(&m_eco.MQ2.PROPANE, MQ2_PROPANE_A,MQ2_PROPANE_B, EVENT_PROPANE);
	MQ_Init(&m_eco.MQ2.METHANE, MQ2_METHANE_A,MQ2_METHANE_B, EVENT_METHANE);
	MQ_Init(&m_eco.MQ2.ALCOHOL, MQ2_ALCOHOL_A,MQ2_ALCOHOL_B, EVENT_ALCOHOL1);
	MQ_Init(&m_eco.MQ2.SMOKE, MQ2_SMOKE_A,MQ2_SMOKE_B, EVENT_SMOKE);

	MQ_Init(&m_eco.MQ135.ALCOHOL, MQ135_ALCOHOL_A,MQ135_ALCOHOL_B, EVENT_ALCOHOL2);
	MQ_Init(&m_eco.MQ135.CO2, MQ135_CO2_A,MQ135_CO2_B, EVENT_CO2);
	MQ_Init(&m_eco.MQ135.AMMONIA, MQ135_AMMONIA_A,MQ135_AMMONIA_B, EVENT_AMMONIA);
	MQ_Init(&m_eco.MQ135.CARBON_DIOXIDE, MQ135_CARBON_DIOXIDE_A,MQ135_CARBON_DIOXIDE_B, EVENT_CARBON_DIOXIDE);
	MQ_Init(&m_eco.MQ135.CARBON_MONOXIDE, MQ135_CARBON_MONOXIDE_A,MQ135_CARBON_MONOXIDE_B, EVENT_CARBON_MONOXIDE);
	MQ_Init(&m_eco.MQ135.TOLUENE, MQ135_TOLUENE_A,MQ135_TOLUENE_B, EVENT_TOLUENE);
	MQ_Init(&m_eco.MQ135.ACETONE, MQ135_ACETONE_A,MQ135_ACETONE_B, EVENT_ACETONE);


	
	ADS1115_Write(m_eco.config_reg.mux, AIN1_GND);
	ADS1115_Write(m_eco.config_reg.pga, FS_6_114V);

	m_eco.MQ2.R0 = Get_MQ_Sensor(AIN0_GND, R0_MQ2);
	m_eco.MQ135.R0 = Get_MQ_Sensor(AIN1_GND, R0_MQ135);

}

void ADS1115_RegInit(uint8_t *reg, uint8_t default_value, uint8_t adderess, uint8_t mask, uint8_t bit)
{
	reg[VALUE] = default_value;
	reg[REG] =  adderess;
	reg[MASK] = mask;
	reg[MOVE] = bit;
}
void MQ_Init(MQ_VALUE_T* MQ, float a, float b, char eventNum)
{
	MQ->graph[0]= a;
	MQ->graph[1]= b;
	MQ->eventNum = eventNum;
	MQ->pre = 99999;
}
void MQ_Config(MQ_VALUE_T* MQ, float MQ135_ratio )
{
	MQ->value =  Set_MQ_PPM(MQ->graph, MQ135_ratio);

	if(MQ->value > MQ->max) MQ->max = MQ->value;
	
	if(MQ->value > MQ->pre+2) 
	{
		//Node_event(MQ->eventNum,(uint16_t)MQ->value);
		if(MQ->eventNum < 7)
			m_sx1276.buffCh1[MQ->eventNum]= (uint16_t)MQ->value;
		else if(MQ->eventNum > 7)
			m_sx1276.buffCh2[MQ->eventNum%8]= (uint16_t)MQ->value;
		
	}
	MQ->pre = MQ->value;
	
	HAL_Delay(50);

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
			Error_Watchdog(ERR0R_1);
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
//
float Set_MQ_PPM(float* sensor, float MQ_ratio)
{
	float PPM_log,PPM,percentage = 0;

	if(sensor[MQ_A]==0 && sensor[MQ_B]==0) return 12345;

#if MQ_SOURCE == 1
	PPM_log = (log10(MQ_ratio) - sensor[MQ_B])/sensor[MQ_A];
	PPM = pow(10, PPM_log);	
#elif MQ_SOURCE == 2
	PPM = sensor[MQ_A] * pow(MQ_ratio, sensor[MQ_B]);
#elif MQ_SOURCE == 3
	PPM = pow(10,((sensor[MQ_A]*(log10(MQ_ratio))) +sensor[MQ_B]));
#endif
	//percentage = PPM/10000;
	percentage = PPM;
	if(percentage<0)percentage = 0;

	return percentage;
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

uint16_t mq_vu = 0;
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

	mq_vu = MQ_adc_avg;

	MQ_volt = MQ_adc_avg * ADS_FS_VALUE/ADS_MAX_ADC_VALUE;

	MQ_volt = MQ_volt + MQ_volt*0.0103 - 0.0717;
	
	MQ_rs = (( ADS_VCC * ADS_RL ) / MQ_volt) - ADS_RL;

	MQ_ratio = MQ_rs / R0_MQ;
	return MQ_ratio;
}

