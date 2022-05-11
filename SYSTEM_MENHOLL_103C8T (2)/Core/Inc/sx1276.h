//sx1276.h

#ifndef SX1276_H
#define SX1276_H
#include"common.h"


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

#define  RegSyncWord_							0x39//사용됨

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



#define SPI_NSS_RESET	HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_RESET); 
#define SPI_NSS_SET		HAL_GPIO_WritePin(NSS_GPIO_Port, NSS_Pin, GPIO_PIN_SET); 

#define RESET_SX1276	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET); 
#define SET_SX1276		HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET); 


#define GET_IO0				HAL_GPIO_ReadPin(IO0_GPIO_Port, IO0_Pin)
#define GET_DEVICE_SELECT	HAL_GPIO_ReadPin(DIP_IN_GPIO_Port, DIP_IN_Pin)

#define RSSI_LF_CONSTANS	164
#define RSSI_HF_CONSTANS	157


#define ALL_IRQ_CLEAR	0xFF
#define OPEN_TXDONE_IRQ	0xF7
#define OPEN_RXDONE_IRQ	0x3F

#define SX1276_MAX_PACKET	256


#define NONE_VALUE		0XAA

#define EXTENSION_NODE1	  "$A01"
#define EXTENSION_NODE2	  "$A02"
#define EXTENSION_NODE3	  "$A03"
#define EXTENSION_NODE4	  "$A04"




#define NODE1	  	"#001"
#define NODE2	  	"#002"
#define NODE3	  	"#003"
#define NODE4	  	"#004"




#define TO_NODE_ROUTE	      "$A01"
#define TO_MASTER_ROUTE 	"$A01&M"


/*  			define end  			*/



/*  			enum start  			*/
typedef enum
{
	RX_DEVICE,
	TX_DEVICE,
} DEVICE_E;
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
	DEFAULT_LNA_CURRENT = 0,
	BOOST_ON_150_LNA_CURRENT = 11,
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
	PA_DAC_DEFAULT = 0x84,
	PA_DAC_BOOST = 0x87,
} PaDac_E;
typedef enum
{
	RX_DONE,
	TX_DONE,
}DioMapping1_E;
	
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
	uint8_t Modem_clear[4];
	uint8_t Header_info_valid[4];
	uint8_t RX_on_going[4];
	uint8_t Signal_synchronized[4];
	uint8_t Signal_detected[4];
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
	uint8_t SyncWord[4];
} SyncWord_t;

typedef struct
{
	//uint8_t DioMapping1[4];
	uint8_t Dio0[4];
	uint8_t Dio1[4];
	uint8_t Dio2[4];
	uint8_t Dio3[4];
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
	int Rssi;
	int rowRssi;
	int pktRssi;
	int SNR;
	int rowSNR;
} OBSERV_t;
typedef struct
{
	Fifo_t				  s_Fifo;//Fifo[4];;	//0x00
	OpMode_t			  s_OpMode;	//0x01			
	FrMsb_t 			  s_FrMsb;	//0x06		   
	FrMid_t 			  s_FrMid;	//0x07		   
	FrLsb_t 			  s_FrLsb;	//0x08			
						
	PaConfig_t			  s_PaConfig; //0x09		   
	PaRamp_t			  s_PaRamp;	//0x0a		   
	Ocp_t				  s_Ocp;	//0x0b			   
						
	Lna_t				  s_Lna;	//0x0c			   
						
	FifoAddrPtr_t		  s_FifoAddrPtr;	//0x0d			 
	FifoTxBaseAddr_t	  s_FifoTxBaseAddr;	//0x0e	
	FifoRxBaseAddr_t	  s_FifoRxBaseAddr;	//0x0f	
	FifoRxCurrentaddr_t   s_FifoRxCurrentaddr;//0x10	
	IrqFlagsMask_t		  s_IrqFlagsMask;   //0x11	
	IrqFlags_t			  s_IrqFlags; 		//0x12	
	RxNbBytes_t 		  s_RxNbBytes;		//0x13   
	RxHeaderCntValueMsb_t  s_RxHeaderCntValueMsb; //0x14
	RxHeaderCntValueLsb_t  s_RxHeaderCntValueLsb; //0x15
	RxPacketCntValueMsb_t  s_RxPacketCntValueMsb; //0x16
	RxPacketCntValueLsb_t  s_RxPacketCntValueLsb; //0x17
	ModemStat_t 		  s_ModemStat;  //0x18	   
	PktSnrValue_t		  s_PktSnrValue; //0x19			
	PktRssiValue_t		  s_PktRssiValue; //0x1a		   
	RssiValue_t 		  s_RssiValue;  //0x1b		
	HopChannel_t		  s_HopChannel;	//0x1c	   
	ModemConfig1_t		  s_ModemConfig1; 	//0x1d 
	ModemConfig2_t		  s_ModemConfig2; 	//0x1e
	SymbTimeoutLsb_t	  s_SymbTimeoutLsb;	//0x1f
	PreambleMsb_t		  s_PreambleMsb;	//0x20 	   
	PreambleLsb_t		  s_PreambleLsb;	//0x21 	   
	PayloadLength_t 	  s_PayloadLength;	//0x22 	   
	MaxPayloadLength_t	  s_MaxPayloadLength; //0x23    
	HopPeriod_t 		  s_HopPeriod;		//0x24 	   
	FifoRxByteAddr_t	  s_FifoRxByteAddr;	//0x25 		
	ModemConfig3_t		  s_ModemConfig3; 	//0x26 
	SyncWord_t 			  s_SyncWord;		//0x39 
	
	DioMapping1_t		  s_DioMapping1;	//0x40 	   
	DioMapping2_t		  s_DioMapping2;	//0x41 		   						
	Version_t			  s_Version;		//0x42 											   
	Tcxo_t				  s_Tcxo; 			//0x4b 	   
	PaDac_t 			  s_PaDac;			//0x4d 	   
	FormerTemp_t		  s_FormerTemp;		//0x5b 	   
	AgcRef_t			  s_AgcRef;			//0x61 	   
	AgcThresh1_t		  s_AgcThresh1;		//0x62 	   
	AgcThresh2_t		  s_AgcThresh2;		//0x63 	   
	AgcThresh3_t		  s_AgcThresh3;  	//0x64 

	DEVICE_E device;
	OBSERV_t observ;
} SX1276_T;

/*  			stuct end  				*/



/*  			function start  		*/
uint8_t SPI_Read(uint8_t reg);
void SPI_Write(uint8_t reg, uint8_t cmd);
void SX1276_Segment_Write(uint8_t * sx1276, uint8_t cmd);
void SX1276_Byte_Write(uint8_t reg, uint8_t txByte);

void SX1276_Gather_segment(uint8_t * sx1276, uint8_t cmd, uint8_t *txByte);

uint8_t SX1276_Read(uint8_t * sx1276);
void SX1276_BurstWrite(uint8_t reg, uint8_t* txBuff, uint8_t length);
void SX1276_BurstRead(uint8_t reg, uint8_t* rxBuff, uint8_t length);
void SX1276_Init(uint64_t frequency,uint8_t SF, uint8_t Bw, uint8_t CR, uint8_t CRC_enable);
void HW_Reset();
uint8_t SX1276_TX_Entry(uint8_t length, uint32_t timeOut);
uint8_t SX1276_RX_Entry(uint32_t timeOut);
uint8_t SX1276_TX_Packet(uint8_t* txBuff, uint8_t lengh, uint32_t timeOut);
void SX1276_RX_Packet(uint8_t* rxBuff);
void SX1276_Calculrate_SNR_Rssi();
void Lora_config();
void Lora_Send_Msg(char* msg, uint16_t data);
void SX1276_Change_rx_tx(uint8_t mode);

void Master_Pass();
void Node_Send();
void Gateway_Pass();
void Node_Pass();


/*  			function end  			*/

/*              extern start            */

/*              extern end	            */

extern SX1276_T m_sx1276;

#endif

