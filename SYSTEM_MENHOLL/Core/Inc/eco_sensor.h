//eco_sensor.h
#ifndef ECO_SENSOR_H
#define ECO_SENSOR_H

/*  			include start  			*/
#include "main.h"
#include <string.h>
#include <stdlib.h>

/*  			include end  			*/



/*  			define start  			*/
#define ADS_ADDRESS  		0x48<<1
#define ADS_REG_CONVERSION  0x00
#define ADS_REG_CONFIG		0x01
#define ADS_REG_LO_THRESH   0x02
#define ADS_REG_HI_THRESH   0x03

#define ADS_FS_VALUE		 4.096
#define ADS_MAX_ADC_VALUE	 0X7FFF
#define ADS_VCC				 3.3  //3.3V
#define ADS_RL				 10.0 // 10K옴

#define R0_MQ2				 6.865
#define R0_MQ135			 13.465


/*  			define end  			*/



/*  			enum start  			*/
typedef enum
{
	SLOPE,
	Y_INTERCEPT,
} MQ_BUFF_E;
typedef enum
{
	NOT_EFFECT,
	BEING_SINGELE_CONV,
} OS_E;
typedef enum
{ // AINp_AINn
	AIN0_AIN1,
	AIN0_AIN3,
	AIN1_AIN3,
	AIN2_AIN3,
	AIN0_GND,
	AIN1_GND,
	AIN2_GND,
	AIN3_GND,
} ADS_MUX_E;

typedef enum
{
	FS_6_114V,
	FS_4_096V,
	FS_2_048V,
	FS_1_024V,
	FS_0_512V,
	FS_0_256V,
} ADS_FS_E;

typedef enum
{
	CONTINUOUS_CONV_MODE,
	SINGLE_SHOT_MODE,
} ADS_MODE;

typedef enum
{
	SPS8,
	SPS16,
	SPS32,
	SPS64,
	SPS128,
	SPS250,
	SPS475,
	SPS860,
} ADS_DR;

typedef enum
{
	VALUE,
	REG,
	MASK,
	MOVE,
} BUFF_ADS1115_E;
/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	uint8_t os[4];
	uint8_t mux[4];
	uint8_t pga[4];
	uint8_t mode[4];
	uint8_t data_rate[4];
	
	
} ADS_CONFIG_REG_T;

typedef struct
{
	float LPG;
    float Propane;
    float Hydrogen;
} MQ2_T;

typedef struct
{
	float Alcohol;
	float Co2;
	float Ammonia;

} MQ135_T;

typedef struct
{
	
	ADS_CONFIG_REG_T config_reg; // ADS_REG_CONFIG
	MQ2_T MQ2;
	MQ135_T MQ135;
	 
	
} ECO_T;
/*  			stuct end  				*/



/*  			function start  		*/

void Eco_Config();

void ADS1115_Init();
uint16_t MQ_ADC_Read(uint8_t AIN_num);


void ADS1115_Write(uint8_t* ads1115,uint8_t cmd);
uint8_t ADS1115_Part_Read(uint8_t* ads1115);
uint16_t ADS1115_ADC_Read();

uint16_t I2c_read(uint8_t reg);
void I2c_write(uint8_t reg, uint16_t txWord);
int compare(const void *a, const void *b); 
float Get_MQ_Sensor(uint8_t AIN_num, float R0_MQ);
float Set_MQ_PPM(float* sensor, float MQ_ratio);




/*  			function end  			*/

#endif
