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


void Eco_Config()
{
	ADS1115_Config(AIN0_GND);
	ADS1115_Config(AIN1_GND);
}
void ADS1115_Init()
{
	ADS1115_Write(m_eco.config_reg.mux, AIN1_GND);
	ADS1115_Write(m_eco.config_reg.pga, FS_4_096V);

}


void ADS1115_Config(uint8_t AIN_num)
{
	uint8_t os = 0;

	ADS1115_Write(m_eco.config_reg.mux, AIN_num);
	
	os = ADS1115_Part_Read(m_eco.config_reg.os);

	if(os == SET)
	{
		ADS1115_Write(m_eco.config_reg.os, BEING_SINGELE_CONV);

		switch(AIN_num)
		{
			case AIN0_GND:  m_eco.MQ1 = ADS1115_ADC_Read();    break;			
			case AIN1_GND:  m_eco.MQ2 = ADS1115_ADC_Read();    break;						
		}
			
	}
	
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


float ADS1115_ADC_Read()
{
	uint16_t rxWord = 0x00;	
	float volt = 0;
	rxWord = I2c_read(ADS_REG_CONVERSION);

	volt = rxWord * ADS_FS_VALUE /ADS_MAX_ADC_VALUE; 

	return volt;
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

void MQ_sensor_read(double* sensor, uint8_t data)
{
	double PPM_log,PPM,percentage = 0;

	PPM_log = (log10(data) - sensor[Y_INTERCEPT])/sensor[SLOPE];
	PPM = pow(10, PPM_log);
	percentage = PPM/10000;
}