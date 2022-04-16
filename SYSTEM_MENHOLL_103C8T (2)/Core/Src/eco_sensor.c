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
				                 //slop    y_inter	
float MQ2_LPG_gp[2] =         		  {MQ2_LPG_A,  				MQ2_LPG_B};
float MQ2_PROPANE_gp[2] =     		  {MQ2_PROPANE_A,  			MQ2_PROPANE_B};
float MQ2_H2_gp[2] =    	  		  {MQ2_H2_A,  				MQ2_H2_B};
float MQ2_CO_gp[2] =    	  		  {MQ2_CO_A,  				MQ2_CO_B};
float MQ2_METHANE_gp[2] =     		  {MQ2_METHANE_A,  			MQ2_METHANE_B};
float MQ2_CARBON_MONOXIDE_gp[2] =   {MQ2_CARBON_MONOXIDE_A,  	MQ2_CARBON_MONOXIDE_B};
float MQ2_ALCOHOL_gp[2] =    	      {MQ2_ALCOHOL_A,  			 MQ2_ALCOHOL_B};
float MQ2_SMOKE_gp[2] =    	          {MQ2_SMOKE_A,  			 MQ2_SMOKE_B};


float MQ135_ALCOHOL_gp[2] =    			 {MQ135_ALCOHOL_A,  	MQ135_ALCOHOL_B};
float MQ135_CO2_gp[2]    =     			 {MQ135_CO2_A,  	 	MQ135_CO2_B};
float MQ135_AMMONIA_gp[2] =    			 {MQ135_AMMONIA_A,   	MQ135_AMMONIA_B};
float MQ135_CARBON_DIOXIDE_gp[2]    =    {MQ135_CARBON_DIOXIDE_A,  	 MQ135_CARBON_DIOXIDE_B};
float MQ135_CARBON_MONOXIDE_gp[2]    =   {MQ135_CARBON_MONOXIDE_A,   MQ135_CARBON_MONOXIDE_B};
float MQ135_TOLUENE_gp[2]    =     		 {MQ135_TOLUENE_A,  	 	MQ135_TOLUENE_B};
float MQ135_ACETONE_gp[2]    =           {MQ135_ACETONE_A,  	 	MQ135_ACETONE_B};




void Eco_Config()// 실제값 : 디버깅값 + 0.0103(전압값) - 0.0717
{
//	float MQ2_ratio = 0.0;
//	MQ2_ratio = Get_MQ_Sensor(AIN1_GND, m_eco.MQ2.R0);
//	
//	m_eco.MQ2.LPG       =  			Set_MQ_PPM(MQ2_LPG_gp,        MQ2_ratio);
//	if(m_eco.MQ2.LPG>20) Lora_Send_Msg("LPG",(uint8_t)m_eco.MQ2.LPG);
//	
//	m_eco.MQ2.Propane   =  			Set_MQ_PPM(MQ2_PROPANE_gp,    MQ2_ratio);
//	if(m_eco.MQ2.Propane>20) Lora_Send_Msg("Propane",(uint8_t)m_eco.MQ2.Propane);
//	
//	m_eco.MQ2.H2 =   	   			Set_MQ_PPM(MQ2_H2_gp, 		MQ2_ratio);
//	if(m_eco.MQ2.H2>20) Lora_Send_Msg("H2",(uint8_t)m_eco.MQ2.H2);
//	
//	m_eco.MQ2.CO =   	   			Set_MQ_PPM(MQ2_CO_gp, 		MQ2_ratio);
//	if(m_eco.MQ2.CO>20) Lora_Send_Msg("CO",(uint8_t)m_eco.MQ2.CO);
//	
//	m_eco.MQ2.METHANE =    		    Set_MQ_PPM(MQ2_METHANE_gp, 		MQ2_ratio);
//	if(m_eco.MQ2.METHANE>20) Lora_Send_Msg("METHANE",(uint8_t)m_eco.MQ2.METHANE);
//	
//	m_eco.MQ2.CARBON_MONOXIDE =   	Set_MQ_PPM(MQ2_CARBON_MONOXIDE_gp, 		MQ2_ratio);
//	if(m_eco.MQ2.CARBON_MONOXIDE>20) 	Lora_Send_Msg("CARBON_MONOXIDE",(uint8_t)m_eco.MQ2.CARBON_MONOXIDE);
//	
//	m_eco.MQ2.ALCOHOL =   	   		Set_MQ_PPM(MQ2_ALCOHOL_gp, 		MQ2_ratio);
//	if(m_eco.MQ2.ALCOHOL>20) Lora_Send_Msg("ALCOHOL",(uint8_t)m_eco.MQ2.ALCOHOL);
//	
//	m_eco.MQ2.SMOKE =   	   		Set_MQ_PPM(MQ2_SMOKE_gp, 		MQ2_ratio);
//	if(m_eco.MQ2.SMOKE>20) 	Lora_Send_Msg("SMOKE",(uint8_t)m_eco.MQ2.SMOKE);
//
//	
//
//    float MQ135_ratio = 0.0;
//	MQ135_ratio = Get_MQ_Sensor(AIN2_GND, m_eco.MQ135.R0);
//	m_eco.MQ135.Alcohol   = 		  Set_MQ_PPM(MQ135_ALCOHOL_gp,      MQ135_ratio);
//	if(m_eco.MQ135.Alcohol >20) Lora_Send_Msg("Alcohol",(uint8_t)m_eco.MQ135.Alcohol);
//	
//	m_eco.MQ135.Co2       = 		  Set_MQ_PPM(MQ135_CO2_gp,          MQ135_ratio);
//	if(m_eco.MQ135.Co2 >20) Lora_Send_Msg("Co2",(uint8_t)m_eco.MQ135.Co2);
//	
//	m_eco.MQ135.Ammonia = 			  Set_MQ_PPM(MQ135_AMMONIA_gp,        MQ135_ratio);
//	if(m_eco.MQ135.Ammonia >20) Lora_Send_Msg("Ammonia",(uint8_t)m_eco.MQ135.Ammonia);
//	
//	m_eco.MQ135.CARBON_DIOXIDE =      Set_MQ_PPM(MQ135_CARBON_DIOXIDE_gp,     MQ135_ratio);
//	if(m_eco.MQ135.CARBON_DIOXIDE >20) 	Lora_Send_Msg("CARBON_DIOXIDE",(uint8_t)m_eco.MQ135.CARBON_DIOXIDE);
//	
//	m_eco.MQ135.CARBON_MONOXIDE = Set_MQ_PPM(MQ135_CARBON_MONOXIDE_gp,        MQ135_ratio);
//	if(m_eco.MQ135.CARBON_MONOXIDE >20) Lora_Send_Msg("CARBON_MONOXIDE",(uint8_t)m_eco.MQ135.CARBON_MONOXIDE);
//	
//	m_eco.MQ135.TOLUENE = 			  Set_MQ_PPM(MQ135_TOLUENE_gp,        MQ135_ratio);
//	if(m_eco.MQ135.TOLUENE >20) Lora_Send_Msg("TOLUENE",(uint8_t)m_eco.MQ135.TOLUENE);
//
//	m_eco.MQ135.ACETONE =             Set_MQ_PPM(MQ135_ACETONE_gp,        MQ135_ratio);
//	if(m_eco.MQ135.ACETONE >20) Lora_Send_Msg("ACETONE",(uint8_t)m_eco.MQ135.ACETONE);

	
	ADC_to_Volt(AIN0_GND);
//	ADC_to_Volt(AIN1_GND);
//	ADC_to_Volt(AIN2_GND);
//	MCU_ADC_to_Volt();
}
void ADS1115_Init()
{
	ADS1115_Write(m_eco.config_reg.mux, AIN1_GND);
	ADS1115_Write(m_eco.config_reg.pga, FS_6_114V);

	m_eco.MQ2.R0 = Get_MQ_Sensor(AIN1_GND, R0_MQ2);
	m_eco.MQ135.R0 = Get_MQ_Sensor(AIN2_GND, R0_MQ135);

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
		if(HAL_GetTick()-pastTime >2000)
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
	Lora_Send_Msg("LPG",(uint8_t)m_eco.MQ2.LPG);
	Lora_Send_Msg("PP",(uint8_t)m_eco.MQ2.Propane);
	Lora_Send_Msg("H2",(uint8_t)m_eco.MQ2.H2);
	Lora_Send_Msg("CO",(uint8_t)m_eco.MQ2.CO);
	Lora_Send_Msg("MT",(uint8_t)m_eco.MQ2.METHANE);
	Lora_Send_Msg("CM",(uint8_t)m_eco.MQ2.CARBON_MONOXIDE);
	Lora_Send_Msg("AC",(uint8_t)m_eco.MQ2.ALCOHOL);
	Lora_Send_Msg("SM",(uint8_t)m_eco.MQ2.SMOKE);

	Lora_Send_Msg("AC",(uint8_t)m_eco.MQ135.Alcohol);
	Lora_Send_Msg("CO2",(uint8_t)m_eco.MQ135.Co2);
	Lora_Send_Msg("AM",(uint8_t)m_eco.MQ135.Ammonia);
	Lora_Send_Msg("CD",(uint8_t)m_eco.MQ135.CARBON_DIOXIDE);
	Lora_Send_Msg("CM",(uint8_t)m_eco.MQ135.CARBON_MONOXIDE);
	Lora_Send_Msg("TL",(uint8_t)m_eco.MQ135.TOLUENE);	
	Lora_Send_Msg("AT",(uint8_t)m_eco.MQ135.ACETONE);

	Lora_Send_Msg("Battery ",m_status.fan_Battery);
	Lora_Send_Msg("Menholl Open",m_status.Menholl_open_flag);
	Lora_Send_Msg("PUMP ACTIVE",m_status.PumpActive_flag);
}
