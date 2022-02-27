//sx1276.h

#ifndef SX1276_H
#define SX1276_H
#include <stdint.h>
#include"main.h"


/*  			include start  			*/

/*  			include end  			*/



/*  			define start  			*/
//RFM98 Internal registers Address
/********************LoRa mode***************************/
#define RegFifo                               	 0x00
// Common settings
#define RegOpMode                                0x01
#define RegFrMsb                                 0x06
#define RegFrMid                                 0x07
#define RegFrLsb                                 0x08
// Tx settings
#define RegPaConfig                              0x09
#define RegPaRamp                                0x0A
#define RegOcp                                   0x0B
// Rx settings
#define RegLna                                   0x0C
// LoRa registers
#define RegFifoAddrPtr                           0x0D
#define RegFifoTxBaseAddr                        0x0E
#define RegFifoRxBaseAddr                        0x0F
#define RegFifoRxCurrentaddr                     0x10
#define RegIrqFlagsMask                          0x11
#define RegIrqFlags                              0x12
#define RegRxNbBytes                             0x13
#define RegRxHeaderCntValueMsb                   0x14
#define RegRxHeaderCntValueLsb                   0x15
#define RegRxPacketCntValueMsb                   0x16
#define RegRxPacketCntValueLsb                   0x17
#define RegModemStat                             0x18
#define RegPktSnrValue                           0x19
#define RegPktRssiValue                          0x1A
#define RegRssiValue_                             0x1B
#define RegHopChannel                            0x1C
#define RegModemConfig1                          0x1D
#define RegModemConfig2                          0x1E
#define RegSymbTimeoutLsb                        0x1F
#define RegPreambleMsb                           0x20
#define RegPreambleLsb                           0x21
#define RegPayloadLength                         0x22
#define RegMaxPayloadLength                      0x23
#define RegHopPeriod                             0x24
#define RegFifoRxByteAddr                        0x25
#define RegModemConfig3                          0x26
// I/O settings
#define RegDioMapping1                           0x40
#define RegDioMapping2                           0x41
// Version
#define RegVersion                              0x42
// Additional settings
#define RegTcxo                                 0x4B
#define RegPaDac                                0x4D
#define RegFormerTemp                           0x5B
#define RegAgcRef                               0x61
#define RegAgcThresh1                           0x62
#define RegAgcThresh2                           0x63
#define RegAgcThresh3                           0x64


#define MASK_1		0X01
#define MASK_2		0X03
#define MASK_3		0X07
#define MASK_4		0X0F
#define MASK_5		0X1F
#define MASK_6		0X3F
#define MASK_7		0X7F
#define MASK_8		0XFF


#define MOVE_BIT_0	0
#define MOVE_BIT_1	1
#define MOVE_BIT_2	2
#define MOVE_BIT_3	3
#define MOVE_BIT_4	4
#define MOVE_BIT_5	5
#define MOVE_BIT_6	6
#define MOVE_BIT_7	7


#define SPI_NSS_RESET	HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_RESET); 
#define SPI_NSS_SET		HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_SET); 








/*  			define end  			*/



/*  			enum start  			*/

typedef enum
{
	VALUE_E,
	REGISTER_E,
	MASK_E,
	MOVE_E,
} BUFF_SX1276_E;
typedef enum
{
	FSK_OOK_MODE,
	LORA_MODE,	
} LongRangeMode_E;

typedef enum
{
	ACCESS_LORA_PAGE,
	ACCESS_FSK_PAGE,	
} AccessSharedReg_E;

typedef enum
{
	HIGH_FREQ_MODE,
	LOW_FREQ_MODE,	
} LowFrequencyModeOn_E;

typedef enum
{
	MODE_SLEEP,
	MODE_STDBY,
	MODE_FSTX,
	MODE_TX,
	MODE_FSRX,
	MODE_RXCONTINUOUS,
	MODE_RXSINGLE,
	MODE_CAD,
} Mode_E;//

typedef enum
{
	RFO_PIN,
	PA_BOOST,	
} PaSelect_E;

typedef enum
{
	MS3_4,
	MS2_0,
	MS1_0,
	US500,
	US250,
	US125,
	US100,
	US62,
	US50,
	US40,
	US31,
	US25,
	US20,
	US15,
	US12,
	US10,
} PaRamp_E;

typedef enum
{
	OCP_DISABLE,	
	OCP_ENABLE,
} OcpOn_E;

typedef enum
{
	NOT_USE,
	G1,
	G2,
	G3,
	G4,
	G5,
	G6,
} LnaGain_E;

typedef enum
{
	DEFAULT_LNA_CURRENT,
	BOOST_ON_150_LNA_CURRENT,
} LnaBoostHf_E;

typedef enum
{
	PLL_DID_LOCK,
	PLL_DID_NOT_LOCK,
} PllTimeout_E;

typedef enum
{
	HEADER_CRC_OFF,
	HEADER_CRC_ON,
} CrcOnPayload_E;

typedef enum
{
	KHZ_7_8,
	KHZ_10_4,
	KHZ_15_6,
	KHZ_20_8,
	KHZ_31_25,
	KHZ_41_7,
	KHZ_62_5,
	KHZ_125,
	KHZ_250,
	KHZ_500,
} BW_E;

typedef enum
{
	RATE_4_5 = 1,
	RATE_4_6,
	RATE_4_7,
	RATE_4_8,
} CodingRate_E;

typedef enum
{
	EXPLICIT_HEADER_MODE,
	IMPLICIT_HEADER_MODE,
} ImplicitHeaderModeOn_E;

typedef enum
{
	SF_06 = 6,
	SF_07,
	SF_08,
	SF_09,
	SF_10,
	SF_11,
	SF_12,
} SpreadingFactor_E;

typedef enum
{
	NORMAL_MODE,
	CONTIUOUS_MODE,
} TxContinuousMode_E;

typedef enum
{
	CRC_DISABLE,
	CRC_ENABLE,
} RxPayloadCrcOn_E;

typedef enum
{
	OPTIMIZE_DISABLE,
	OPTIMIZE_ENABLE,
} LowDataRateOptimize_E;

typedef enum
{
	LNA_GAIN,
	AGC_GAIN,
} AgcAutoOn_E;

typedef enum
{
	OPTIMIZE_SF7_SF12 = 0x03,
	OPTIMIZE_SF6 = 0x05,
} DetectionOptimize_E;

typedef enum
{
	IQ_NOMAL,
	IQ_INVERTED,
} InvertIQ_E;

typedef enum
{
	THRES_SF7_SF12 = 0x0A,
	THRES_SF7_SF6 = 0x0C,
} DetectionThreshold_E;


typedef enum
{
	CRYSTAL,
	TCXO,
} TcxoInputOn_E;

typedef enum
{
	PA_DAC_DEFAULT = 0x04,
	PA_DAC_BOOST = 0x07,
} PaDac_E;

	
/*  			enum end  				*/



/*  			stuct start  			*/

typedef struct
{
	uint8_t Fifo[4];
} Fifo_t;

typedef struct
{
	uint8_t LongRangeMode[4];
	uint8_t AccessSharedReg[4];
	uint8_t LowFrequencyModeOn[4];
	uint8_t Mode[4];
} OpMode_t;
typedef struct
{
	uint8_t FrfMsb[4];
} FrMsb_t;
typedef struct
{
	uint8_t FrfMid[4];
} FrMid_t;
typedef struct
{
	uint8_t FrfLsb[4];
} FrLsb_t;

typedef struct
{
	uint8_t PaSelect[4];
	uint8_t MaxPower[4];
	uint8_t OutputPower[4];
} PaConfig_t;
typedef struct
{
	uint8_t PaRamp[4];
} PaRamp_t;
typedef struct
{
	uint8_t OcpOn[4];
	uint8_t OcpTrim[4];
} Ocp_t;

typedef struct
{
	uint8_t LnaGain[4];
	uint8_t LnaBoostLf[4];
	uint8_t LnaBoostHf[4];
} Lna_t;


typedef struct
{
	uint8_t FifoAddrPtr[4];
} FifoAddrPtr_t;
typedef struct
{
	uint8_t FifoTxBaseAddr[4];
} FifoTxBaseAddr_t;
typedef struct
{
	uint8_t FifoRxBaseAddr[4];
} FifoRxBaseAddr_t;
typedef struct
{
	uint8_t FifoRxCurrentAddr[4];
} FifoRxCurrentaddr_t;
typedef struct
{
	uint8_t RxTimeoutMask[4];
	uint8_t RxDoneMask[4];
	uint8_t PayloadCrcErrorMask[4];
	uint8_t ValidHeaderMask[4];
	uint8_t TxDoneMask[4];
	uint8_t CadDoneMask[4];
	uint8_t FhssChangeChannelMask[4];
	uint8_t CadDetectedMask[4];
} IrqFlagsMask_t;
typedef struct
{
	uint8_t RxTimeout[4];
	uint8_t RxDone[4];
	uint8_t PayloadCrcError[4];
	uint8_t ValidHeader[4];
	uint8_t TxDone[4];
	uint8_t CadDone[4];
	uint8_t FhssChangeChannel[4];
	uint8_t CadDetected[4];
} IrqFlags_t;
typedef struct
{
	uint8_t FifoRxBytesNb[4];
} RxNbBytes_t;
typedef struct
{
	uint8_t ValidHeaderCntMsb[4];
} RxHeaderCntValueMsb_t;
typedef struct
{
	uint8_t ValidHeaderCntLsb[4];
} RxHeaderCntValueLsb_t;
typedef struct
{
	uint8_t ValidPacketCntMsb[4];
} RxPacketCntValueMsb_t;
typedef struct
{
	uint8_t ValidPacketCntLsb[4];
} RxPacketCntValueLsb_t;
typedef struct
{
	uint8_t RxCodingRate[4];
	uint8_t ModemStatus[4];
} ModemStat_t;
typedef struct
{
	uint8_t PacketSnr[4];
} PktSnrValue_t;
typedef struct
{
	uint8_t PacketRssi[4];
} PktRssiValue_t;
typedef struct
{
	uint8_t Rssi[4];
} RssiValue_t;

typedef struct
{
	uint8_t PllTimeout[4];
	uint8_t CrcOnPayload[4];
	uint8_t FhssPresentChannel[4];
} HopChannel_t;
typedef struct
{
	uint8_t Bw[4];
	uint8_t CodingRate[4];
	uint8_t ImplicitHeaderModeOn[4];
} ModemConfig1_t;
typedef struct
{
	uint8_t SpreadingFactor[4];
	uint8_t TxContinuousMode[4];
	uint8_t RxPayloadCrcOn[4];
	uint8_t SymbTimeoutMsB[4];
} ModemConfig2_t;
typedef struct
{
	uint8_t SymbTimeoutLsb[4];
} SymbTimeoutLsb_t;
typedef struct
{
	uint8_t PreambleLengthMsb[4];
} PreambleMsb_t;
typedef struct
{
	uint8_t PreambleLengthLsb[4];
} PreambleLsb_t;
typedef struct
{
	uint8_t PayloadLength[4];
} PayloadLength_t;
typedef struct
{
	uint8_t PayloadMaxLength[4];
} MaxPayloadLength_t;
typedef struct
{
	uint8_t FreqHoppingPeriod[4];
} HopPeriod_t;
typedef struct
{
	uint8_t FifoRxByteAddrPtr[4];
} FifoRxByteAddr_t;
typedef struct
{
	uint8_t LowDataRateOptimize[4];
	uint8_t AgcAutoOn[4];
} ModemConfig3_t;



typedef struct
{
	uint8_t DioMapping1[4];
} DioMapping1_t;          
typedef struct
{
	uint8_t DioMapping2[4];
} DioMapping2_t;          

typedef struct
{
	uint8_t Version[4];
} Version_t;               
     
typedef struct
{
	uint8_t Tcxo[4];
} Tcxo_t;                 
typedef struct
{
	uint8_t PaDac[4];
} PaDac_t;                
typedef struct
{
	uint8_t FormerTemp[4];
} FormerTemp_t;           
typedef struct
{
	uint8_t AgcRef[4];
} AgcRef_t;               
typedef struct
{
	uint8_t AgcThresh1[4];
} AgcThresh1_t;           
typedef struct
{
	uint8_t AgcThresh2[4];
} AgcThresh2_t;           
typedef struct
{
	uint8_t AgcThresh3[4];
} AgcThresh3_t;  

typedef struct
{
	Fifo_t				  Fifo;	
	OpMode_t			  OpMode;				
	FrMsb_t 			  FrMsb;			   
	FrMid_t 			  FrMid;			   
	FrLsb_t 			  FrLsb;				
						
	PaConfig_t			  PaConfig; 		   
	PaRamp_t			  PaRamp;			   
	Ocp_t				  Ocp;				   
						
	Lna_t				  Lna;				   
						
	FifoAddrPtr_t		  FifoAddrPtr;			 
	FifoTxBaseAddr_t	  FifoTxBaseAddr;		
	FifoRxBaseAddr_t	  FifoRxBaseAddr;		
	FifoRxCurrentaddr_t   FifoRxCurrentaddr;	
	IrqFlagsMask_t		  IrqFlagsMask; 		
	IrqFlags_t			  IrqFlags; 			
	RxNbBytes_t 		  RxNbBytes;		   
	RxHeaderCntValueMsb_t  RxHeaderCntValueMsb; 
	RxHeaderCntValueLsb_t  RxHeaderCntValueLsb; 
	RxPacketCntValueMsb_t  RxPacketCntValueMsb; 
	RxPacketCntValueLsb_t  RxPacketCntValueLsb;	
	ModemStat_t 		  ModemStat;		   
	PktSnrValue_t		  PktSnrValue;			
	PktRssiValue_t		  PktRssiValue;		   
	RssiValue_t 		  RssiValue;			
	HopChannel_t		  HopChannel;		   
	ModemConfig1_t		  ModemConfig1; 	  
	ModemConfig2_t		  ModemConfig2; 	  
	SymbTimeoutLsb_t	  SymbTimeoutLsb;	   
	PreambleMsb_t		  PreambleMsb;		   
	PreambleLsb_t		  PreambleLsb;		   
	PayloadLength_t 	  PayloadLength;	   
	MaxPayloadLength_t	  MaxPayloadLength;    
	HopPeriod_t 		  HopPeriod;		   
	FifoRxByteAddr_t	  FifoRxByteAddr;		
	ModemConfig3_t		  ModemConfig3; 	  
						
	DioMapping1_t		  DioMapping1;		   
	DioMapping2_t		  DioMapping2;		   
						
	Version_t			  Version;				
								   
	Tcxo_t				  Tcxo; 			   
	PaDac_t 			  PaDac;			   
	FormerTemp_t		  FormerTemp;		   
	AgcRef_t			  AgcRef;			   
	AgcThresh1_t		  AgcThresh1;		   
	AgcThresh2_t		  AgcThresh2;		   
	AgcThresh3_t		  AgcThresh3;  

} SX1276_T;

/*  			stuct end  				*/



/*  			function start  		*/
uint8_t SPI_Read(uint8_t reg);
void SPI_Write(uint8_t reg, uint8_t cmd);
void SX1276_Write(uint8_t * sx1276, uint8_t cmd);
uint8_t SX1276_Read(uint8_t * sx1276);

/*  			function end  			*/
extern SX1276_T m_sx1276;

#endif

