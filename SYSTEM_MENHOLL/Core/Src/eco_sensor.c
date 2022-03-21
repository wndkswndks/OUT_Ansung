//eco_sensor.c

#include <math.h>
#include"eco_sensor.h"

ECO_T m_eco = 
{
	{
		{BEING_SINGELE_CONV,	ADS_REG_CONFIG,		MASK_1,  MOVE_BIT_15},
		{AIN0_AIN1,				ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_12},
		{FS_2_048V,				ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_9 },
		{SINGLE_SHOT_MODE,		ADS_REG_CONFIG,		MASK_1,  MOVE_BIT_8 },
		{SPS128,				ADS_REG_CONFIG,		MASK_3,  MOVE_BIT_5 }
	},
	0,	//volt
	0
};
				                 //slop    y_inter	
float MQ2_LPG_graph[2] =         {-0.476,  3.083};
float MQ2_Propane_graph[2] =     {-0.461,  2.690};
float MQ2_Hydrogen_graph[2] =    {-0.465,  3.251};

float MQ135_Alcohol_graph[2] =    {-0.245,  0.771};
float MQ135_Co2_graph[2]    =     {-0.380,  1.752};
float MQ135_Ammonia_graph[2] =    {-0.418,  2.021};

void Eco_Config()
{
	float MQ2_ratio = 0.0;
	MQ2_ratio = Get_MQ_Sensor(AIN0_GND, R0_MQ2);
	m_eco.MQ2.LPG       =  Set_MQ_PPM(MQ2_LPG_graph,         MQ2_ratio);
	m_eco.MQ2.Propane   =  Set_MQ_PPM(MQ2_Propane_graph,     MQ2_ratio);
	m_eco.MQ2.Hydrogen =   Set_MQ_PPM(MQ2_Hydrogen_graph, MQ2_ratio);

    float MQ135_ratio = 0.0;
	MQ135_ratio = Get_MQ_Sensor(AIN1_GND, R0_MQ135);
	m_eco.MQ135.Alcohol   = Set_MQ_PPM(MQ135_Alcohol_graph,      MQ135_ratio);
	m_eco.MQ135.Co2       = Set_MQ_PPM(MQ135_Co2_graph,          MQ135_ratio);
	m_eco.MQ135.Ammonia = Set_MQ_PPM(MQ135_Ammonia_graph,        MQ135_ratio);
	
}
void ADS1115_Init()
{
	ADS1115_Write(m_eco.config_reg.mux, AIN1_GND);
	ADS1115_Write(m_eco.config_reg.pga, FS_4_096V);

}


uint16_t MQ_ADC_Read(uint8_t AIN_num)
{
	uint8_t os = 0;
	uint16_t get_adc = 0;
	ADS1115_Write(m_eco.config_reg.mux, AIN_num);

	while(os==0)
	{
		os = ADS1115_Part_Read(m_eco.config_reg.os);
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

	ads1115[VALUE_E] = rxValue;
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
	HAL_I2C_Mem_Read(&hi2c1, ADS_ADDRESS, reg, 1, rxBuff, 2, 1000 );
	HAL_Delay(10);
	rxWord = rxBuff[0]<<8 | rxBuff[1];
	return rxWord;
}

void I2c_write(uint8_t reg, uint16_t txWord)
{
	uint8_t txBuff[2] = {0,};

	txBuff[0] = (txWord >>8)&0xff;
	txBuff[1] = (txWord)&0xff;
	
	HAL_I2C_Mem_Write(&hi2c1, ADS_ADDRESS, reg, 1, txBuff, 2, 1000 );
	HAL_Delay(10);
}

float Set_MQ_PPM(float* sensor, float MQ_ratio)
{
	float PPM_log,PPM,percentage = 0;

	PPM_log = (log10(MQ_ratio) - sensor[Y_INTERCEPT])/sensor[SLOPE];
	PPM = pow(10, PPM_log);
	percentage = PPM/10000;
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
		HAL_Delay(100);
	}
	
	qsort(MQ_adc_Buff, sizeof(MQ_adc_Buff) / sizeof(uint16_t), sizeof(uint16_t), compare); // 내림차순 정렬

	for(int i =half_except ;i < num-half_except;i++) // 앞뒤로 half_except 만큼 빼고 더함
	{
		MQ_adc_sum += MQ_adc_Buff[i];
	}
	
	MQ_adc_avg = MQ_adc_sum/(num-half_except*2); // 가운데 16개로만 평균냄

	MQ_volt = MQ_adc_avg * ADS_FS_VALUE/ADS_MAX_ADC_VALUE;

	MQ_rs = (( ADS_VCC * ADS_RL ) / MQ_volt) - ADS_RL;

	MQ_ratio = MQ_rs / R0_MQ;
	return MQ_ratio;
}
