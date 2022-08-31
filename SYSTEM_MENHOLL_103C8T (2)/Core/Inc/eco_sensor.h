//eco_sensor.h
#ifndef ECO_SENSOR_H
#define ECO_SENSOR_H

/*  			include start  			*/
#include"common.h"


/*  			include end  			*/



/*  			define start  			*/
#define ADS_ADDRESS  		0x48<<1
#define ADS_REG_CONVERSION  0x00
#define ADS_REG_CONFIG		0x01
#define ADS_REG_LO_THRESH   0x02
#define ADS_REG_HI_THRESH   0x03

#define ADS_FS_VALUE		 6.114//4.096
#define ADS_MAX_ADC_VALUE	 0X7FFF
#define ADS_VCC				 5  



#define MQ_SOURCE			3

#if MQ_SOURCE == 1

#define ADS_RL				 10.0 // 10K옴

#define R0_MQ2				 6.865
#define R0_MQ135			 13.465

#define MQ2_LPG_A			-0.476
#define MQ2_LPG_B			3.083
#define MQ2_PROPANE_A		-0.461
#define MQ2_PROPANE_B		2.690
#define MQ2_H2_A			-0.465
#define MQ2_H2_B			3.251
#define MQ2_CO_A			0
#define MQ2_CO_B			0
#define MQ2_METHANE_A		0
#define MQ2_METHANE_B		0
#define MQ2_CARBON_MONOXIDE_A	0
#define MQ2_CARBON_MONOXIDE_B	0
#define MQ2_ALCOHOL_A		0
#define MQ2_ALCOHOL_B		0
#define MQ2_SMOKE_A		0	
#define MQ2_SMOKE_B		0	

#define MQ135_ALCOHOL_A		-0.245	
#define MQ135_ALCOHOL_B		0.771
#define MQ135_CO2_A			-0.380	
#define MQ135_CO2_B			1.752
#define MQ135_AMMONIA_A		-0.418	
#define MQ135_AMMONIA_B		2.021
#define MQ135_CARBON_DIOXIDE_A	0
#define MQ135_CARBON_DIOXIDE_B	0
#define MQ135_CARBON_MONOXIDE_A	0
#define MQ135_CARBON_MONOXIDE_B	0
#define MQ135_TOLUENE_A		0
#define MQ135_TOLUENE_B		0
#define MQ135_ACETONE_A		0
#define MQ135_ACETONE_B		0



#elif MQ_SOURCE == 2
#define ADS_RL				 10.0 // 10K옴


#define R0_MQ2			9.83	
#define R0_MQ135		3.6	

#define MQ2_LPG_A		574.25		
#define MQ2_LPG_B		-2.222	
#define MQ2_PROPANE_A	 658.71	
#define MQ2_PROPANE_B	 -2.168	
#define MQ2_H2_A		 987.99	
#define MQ2_H2_B		 -2.162	
#define MQ2_CO_A		 36974	
#define MQ2_CO_B		 -3.109	
#define MQ2_METHANE_A		0
#define MQ2_METHANE_B		0
#define MQ2_CARBON_MONOXIDE_A	0
#define MQ2_CARBON_MONOXIDE_B	0
#define MQ2_ALCOHOL_A		0
#define MQ2_ALCOHOL_B		0
#define MQ2_SMOKE_A		0	
#define MQ2_SMOKE_B		0	

#define MQ135_ALCOHOL_A		77.255	
#define MQ135_ALCOHOL_B		-3.18 
#define MQ135_CO2_A			110.47	
#define MQ135_CO2_B			-2.862
#define MQ135_AMMONIA_A		102.2
#define MQ135_AMMONIA_B		-2.473
#define MQ135_CARBON_DIOXIDE_A	0
#define MQ135_CARBON_DIOXIDE_B	0
#define MQ135_CARBON_MONOXIDE_A	0
#define MQ135_CARBON_MONOXIDE_B	0
#define MQ135_TOLUENE_A		0
#define MQ135_TOLUENE_B		0
#define MQ135_ACETONE_A		0
#define MQ135_ACETONE_B		0

#elif MQ_SOURCE == 3
#define ADS_RL				 1.0 // 10K옴


#define R0_MQ2		9.577		
#define R0_MQ135	3.59	

#define MQ2_LPG_A		-2.123
#define MQ2_LPG_B		2.758
#define MQ2_PROPANE_A	-2.174
#define MQ2_PROPANE_B	2.799
#define MQ2_H2_A		-2.109	
#define MQ2_H2_B		2.983
#define MQ2_CO_A		0
#define MQ2_CO_B		0
#define MQ2_METHANE_A		-2.622
#define MQ2_METHANE_B		3.635
#define MQ2_CARBON_MONOXIDE_A	-2.955
#define MQ2_CARBON_MONOXIDE_B	4.457
#define MQ2_ALCOHOL_A		-2.692
#define MQ2_ALCOHOL_B		3.545
#define MQ2_SMOKE_A		-2.331	
#define MQ2_SMOKE_B		3.596	


#define MQ135_ALCOHOL_A		-3.181
#define MQ135_ALCOHOL_B		1.895
#define MQ135_CO2_A			0
#define MQ135_CO2_B			0
#define MQ135_AMMONIA_A	   -2.469
#define MQ135_AMMONIA_B	 2.005
#define MQ135_CARBON_DIOXIDE_A	-2.890
#define MQ135_CARBON_DIOXIDE_B	2.055
#define MQ135_CARBON_MONOXIDE_A	-3.891
#define MQ135_CARBON_MONOXIDE_B	2.750
#define MQ135_TOLUENE_A		-3.479
#define MQ135_TOLUENE_B		1.658
#define MQ135_ACETONE_A		-3.452
#define MQ135_ACETONE_B		1.542

#else

#endif

#define MQ_OVER_PERSENT		100












/*  			define end  			*/



/*  			enum start  			*/
typedef enum
{
	MQ_A,
	MQ_B,
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
	float graph[2];
	float value;
	float max;
	float pre;
	char eventNum;
} MQ_VALUE_T;

typedef struct
{
    MQ_VALUE_T H2;
	MQ_VALUE_T LPG;
    MQ_VALUE_T CO;
    MQ_VALUE_T PROPANE;
	MQ_VALUE_T METHANE;
	MQ_VALUE_T ALCOHOL;
	MQ_VALUE_T SMOKE;	
    float R0;
} MQ2_T;

typedef struct
{
	MQ_VALUE_T ALCOHOL;
	MQ_VALUE_T CO2;
	MQ_VALUE_T AMMONIA;
	MQ_VALUE_T CARBON_DIOXIDE;
	MQ_VALUE_T CARBON_MONOXIDE;
	MQ_VALUE_T TOLUENE;
	MQ_VALUE_T ACETONE;
	float R0;

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

void Eco_Init();
void ADC_to_Volt(uint8_t AIN_num);

uint16_t MQ_ADC_Read(uint8_t AIN_num);

void ADS1115_RegInit(uint8_t *reg, uint8_t default_value, uint8_t adderess, uint8_t mask, uint8_t bit);



void ADS1115_Write(uint8_t* ads1115,uint8_t cmd);
uint8_t ADS1115_Part_Read(uint8_t* ads1115);
uint16_t ADS1115_ADC_Read();

uint16_t I2c_read(uint8_t reg);
void I2c_write(uint8_t reg, uint16_t txWord);
int compare(const void *a, const void *b); 
float Get_MQ_Sensor(uint8_t AIN_num, float R0_MQ);
float Set_MQ_PPM(float* sensor, float MQ_ratio);
void MQ_Init(MQ_VALUE_T* MQ, float a, float b, char eventNum);
void MQ_Config(MQ_VALUE_T* MQ, float MQ135_ratio );

void O2_Sensor();





/*  			function end  			*/

#endif
