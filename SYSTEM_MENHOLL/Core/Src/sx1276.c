//sx1276.c

#include "sx1276.h"
#include "main.h"
#include <string.h>


SX1276_T m_sx1276 = 
{
//	Fifo_t				  s_Fifo;
{{0x00, 					RegFifo, 				MASK_8, MOVE_BIT_0}},//Fifo[4];

//	OpMode_t			  s_OpMode;				
{{FSK_OOK_MODE, 		   	RegOpMode, 				MASK_1, MOVE_BIT_7},//LongRangeMode[4];
 {ACCESS_LORA_PAGE, 		RegOpMode, 				MASK_1, MOVE_BIT_6},//AccessSharedReg[4];
 {LOW_FREQ_MODE, 			RegOpMode, 				MASK_1, MOVE_BIT_3},//LowFrequencyModeOn[4];
 {MODE_STDBY, 				RegOpMode, 				MASK_3, MOVE_BIT_0}},//Mode[4];

//	FrMsb_t 			  s_FrMsb;	
{{0x6c, 					RegFrMsb, 				MASK_8, MOVE_BIT_0}},//FrfMsb[4];

//	FrMid_t 			  s_FrMid;	
{{0x80, 					RegFrMid, 				MASK_8, MOVE_BIT_0}}, //FrfMid[4];

//	FrLsb_t 			  s_FrLsb;	
{{0x00, 					RegFrLsb, 				MASK_8, MOVE_BIT_0}}, //FrfLsb[4];

//	PaConfig_t			  s_PaConfig; 		   
{{RFO_PIN, 					RegPaConfig, 			MASK_1, MOVE_BIT_7}, //PaSelect[4];
 {0x04, 					RegPaConfig, 			MASK_3, MOVE_BIT_4}, //MaxPower[4];
 {0x0f, 					RegPaConfig, 			MASK_4, MOVE_BIT_0}}, //OutputPower[4];

//	PaRamp_t			  s_PaRamp;	
{{US40, 					RegPaRamp, 				MASK_4, MOVE_BIT_0}}, //PaRamp[4];

//	Ocp_t				  s_Ocp;
{{OCP_ENABLE, 				RegOcp, 				MASK_1, MOVE_BIT_5}, //OcpOn[4];
 {0x0b, 					RegOcp, 				MASK_5, MOVE_BIT_0}}, //OcpTrim[4];

//	Lna_t				  s_Lna;
{{G1, 						RegLna, 				MASK_3, MOVE_BIT_5}, //LnaGain[4];
 {0x00, 					RegLna, 				MASK_2, MOVE_BIT_3}, //LnaBoostLf[4];
 {DEFAULT_LNA_CURRENT, 		RegLna, 				MASK_2, MOVE_BIT_0}}, //LnaBoostHf[4];

//	FifoAddrPtr_t		  s_FifoAddrPtr;
{{0x00, 					RegFifoAddrPtr, 		MASK_8, MOVE_BIT_0}}, //FifoAddrPtr[4];

//	FifoTxBaseAddr_t	  s_FifoTxBaseAddr;	
{{0x80, 					RegFifoTxBaseAddr, 		MASK_8, MOVE_BIT_0}}, //FifoTxBaseAddr[4];

//	FifoRxBaseAddr_t	  s_FifoRxBaseAddr;
{{0x00, 					RegFifoRxBaseAddr, 		MASK_8, MOVE_BIT_0}}, //FifoRxBaseAddr[4];

//	FifoRxCurrentaddr_t   s_FifoRxCurrentaddr;	
{{0x00, 					RegFifoRxCurrentaddr, 	MASK_8, MOVE_BIT_0}}, //FifoRxCurrentAddr[4];

//	IrqFlagsMask_t		  s_IrqFlagsMask; 
{{0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_7}, //RxTimeoutMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_6}, //RxDoneMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_5}, //PayloadCrcErrorMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_4}, //ValidHeaderMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_3}, //TxDoneMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_2}, //CadDoneMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_1}, //FhssChangeChannelMask[4
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_0}}, //CadDetectedMask[4];

//	IrqFlags_t			  s_IrqFlags; 	
{{0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_7}, //RxTimeout[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_6}, //RxDone[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_5}, //PayloadCrcError[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_4}, //ValidHeader[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_3}, //TxDone[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_2}, //CadDone[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_1}, //FhssChangeChannel[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_0}}, //CadDetected[4];

//	RxNbBytes_t 		  s_RxNbBytes;	
{{0x00, 					RegRxNbBytes, 			MASK_8, MOVE_BIT_0}}, //FifoRxBytesNb[4];

//	RxHeaderCntValueMsb_t  s_RxHeaderCntValueMsb; 
{{0x00, 					RegRxHeaderCntValueMsb, MASK_8, MOVE_BIT_0}}, //ValidHeaderCntMsb[4];

//	RxHeaderCntValueLsb_t  s_RxHeaderCntValueLsb; 
{{0x00, 					RegRxHeaderCntValueLsb,  MASK_8, MOVE_BIT_0}}, //ValidHeaderCntLsb[4];

//	RxPacketCntValueMsb_t  s_RxPacketCntValueMsb; 
{{0x00, 					RegRxPacketCntValueMsb,  MASK_8, MOVE_BIT_0}}, //ValidPacketCntMsb[4];

//	RxPacketCntValueLsb_t  s_RxPacketCntValueLsb;	
{{0x00, 					RegRxPacketCntValueLsb,  MASK_8, MOVE_BIT_0}}, //ValidPacketCntLsb[4];

//	ModemStat_t 		  s_ModemStat;	
{{0x00, 					RegModemStat, 			 MASK_3, MOVE_BIT_5}, //RxCodingRate[4];
 {0x01, 				 	RegModemStat,			 MASK_1, MOVE_BIT_4},//
 {0x00, 				 	RegModemStat,			 MASK_1, MOVE_BIT_3},//
 {0x00, 				 	RegModemStat,			 MASK_1, MOVE_BIT_2},
 {0x00, 				 	RegModemStat,			 MASK_1, MOVE_BIT_1},
 {0x00, 					RegModemStat, 			 MASK_1, MOVE_BIT_0}}, //ModemStatus[4];

//	PktSnrValue_t		  s_PktSnrValue;
{{0x00, 					RegPktSnrValue, 		MASK_8, MOVE_BIT_0}}, //PacketSnr[4];

//	PktRssiValue_t		  s_PktRssiValue;	
{{0x00, 					RegPktRssiValue, 		MASK_8, MOVE_BIT_0}}, //PacketRssi[4];

//	RssiValue_t 		  s_RssiValue;	
{{0x00, 					RegRssiValue_, 			MASK_8, MOVE_BIT_0}}, //Rssi[4];

//	HopChannel_t		  s_HopChannel;	
{{PLL_DID_LOCK, 			RegHopChannel, 			MASK_1, MOVE_BIT_7}, //PllTimeout[4];
 {HEADER_CRC_OFF, 			RegHopChannel, 			MASK_1, MOVE_BIT_6}, //CrcOnPayload
 {0x00, 					RegHopChannel, 			MASK_6, MOVE_BIT_0}}, //FhssPresentChannel[4];

//	ModemConfig1_t		  s_ModemConfig1;
{{KHZ_125, 					RegModemConfig1, 		MASK_4, MOVE_BIT_4}, //Bw[4];
 {RATE_4_5, 				RegModemConfig1, 		MASK_3, MOVE_BIT_1}, //CodingRate[4];
 {EXPLICIT_HEADER_MODE, 	RegModemConfig1, 		MASK_1, MOVE_BIT_0}}, //ImplicitHeaderModeOn[4]

//	ModemConfig2_t		  s_ModemConfig2; 
{{SF_07, 					RegModemConfig2, 		MASK_4, MOVE_BIT_4}, //SpreadingFactor[4];
 {NORMAL_MODE, 				RegModemConfig2, 		MASK_1, MOVE_BIT_3}, //TxContinuousMode[4];
 {CRC_DISABLE, 				RegModemConfig2, 		MASK_1, MOVE_BIT_2}, //RxPayloadCrcOn[4];
 {0x00, 					RegModemConfig2,		MASK_2, MOVE_BIT_0}}, //SymbTimeoutMsB[4];

//	SymbTimeoutLsb_t	  s_SymbTimeoutLsb;
{{0x64, 					RegSymbTimeoutLsb, 		MASK_8, MOVE_BIT_0}}, //SymbTimeoutLsb[4];

//	PreambleMsb_t		  s_PreambleMsb;
{{0x00, 					RegPreambleMsb, 		MASK_8, MOVE_BIT_0}}, //PreambleLengthMsb[4];

//	PreambleLsb_t		  s_PreambleLsb;
{{0x08, 					RegPreambleLsb, 		MASK_8, MOVE_BIT_0}}, //PreambleLengthLsb[4];

//	PayloadLength_t 	  s_PayloadLength;	 
{{0x01, 					RegPayloadLength, 		MASK_8, MOVE_BIT_0}}, //PayloadLength[4];

//	MaxPayloadLength_t	  s_MaxPayloadLength; 
{{0xff, 					RegMaxPayloadLength, 	MASK_8, MOVE_BIT_0}}, //PayloadMaxLength[4];

//	HopPeriod_t 		  s_HopPeriod;		  
{{0x00, 					RegHopPeriod, 			MASK_8, MOVE_BIT_0}}, //FreqHoppingPeriod[4];

//	FifoRxByteAddr_t	  s_FifoRxByteAddr;	
{{0x00, 					RegFifoRxByteAddr, 		MASK_8, MOVE_BIT_0}}, //FifoRxByteAddrPtr[4];

//	ModemConfig3_t		  s_ModemConfig3; 
{{OPTIMIZE_DISABLE, 		RegModemConfig3, 		MASK_1, MOVE_BIT_3}, //LowDataRateOptimize[4];
 {LNA_GAIN, 				RegModemConfig3, 		MASK_1, MOVE_BIT_2}}, //AgcAutoOn[4];

//	SyncWord_t 			  s_SyncWord;
{{0x12, 					RegSyncWord_, 			MASK_8, MOVE_BIT_0}}, //SyncWord[4];

//	DioMapping1_t		  s_DioMapping1;
{{0x00, 					RegDioMapping1, 		MASK_2, MOVE_BIT_6},//uint8_t Dio0[4];
{0x00, 						RegDioMapping1, 		MASK_2, MOVE_BIT_4},//uint8_t Dio1[4];
{0x00, 						RegDioMapping1, 		MASK_2, MOVE_BIT_2},//uint8_t Dio2[4];
{0x00, 						RegDioMapping1, 		MASK_2, MOVE_BIT_0}},//uint8_t Dio3[4];

//	DioMapping2_t		  s_DioMapping2;
{{0x00, 					RegDioMapping2, 		MASK_8, MOVE_BIT_0}}, //uint8_t DioMapping2[4];

//	Version_t			  s_Version;
{{0x12, 					RegVersion, 			MASK_8, MOVE_BIT_0}},//uint8_t Version[4];      

//	Tcxo_t				  s_Tcxo; 
{{CRYSTAL, 					RegTcxo, 				MASK_1, MOVE_BIT_4}}, //uint8_t Tcxo[4];

//	PaDac_t 			  s_PaDac;	
{{PA_DAC_DEFAULT, 			RegPaDac ,				MASK_7, MOVE_BIT_0}},//uint8_t PaDac[4];      

//	FormerTemp_t		  s_FormerTemp;	
{{0x00, 					RegFormerTemp, 			MASK_8, MOVE_BIT_0}}, //uint8_t FormerTemp[4];

//	AgcRef_t			  s_AgcRef;
{{0x13, 					RegAgcRef, 				MASK_6, MOVE_BIT_0}},//uint8_t AgcRef[4];     

//	AgcThresh1_t		  s_AgcThresh1;	
{{0x0e, 					RegAgcThresh1, 			MASK_8, MOVE_BIT_0}},//uint8_t AgcThresh1[4];    

//	AgcThresh2_t		  s_AgcThresh2;	
{{0x5b, 					RegAgcThresh2, 			MASK_8, MOVE_BIT_0}},//uint8_t AgcThresh2[4];   

//	AgcThresh3_t		  s_AgcThresh3;  
{{0xdb, 					RegAgcThresh3, 			MASK_8, MOVE_BIT_0}},//uint8_t AgcThresh3[4];

RX_DEVICE

};


uint8_t SPI_Read(uint8_t reg)
{
	uint8_t txByte = 0x00;
	uint8_t rxByte = 0x00;

	SPI_NSS_RESET;
	HAL_SPI_Transmit(&hspi2, &reg, 1, 1000);
	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);
	
	HAL_SPI_TransmitReceive(&hspi2, &txByte, &rxByte, 1, 1000);
	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);

	SPI_NSS_SET;
	return rxByte;
}

void SPI_Write(uint8_t reg, uint8_t cmd)
{
	reg = reg|0x80;
	
	SPI_NSS_RESET;
	HAL_SPI_Transmit(&hspi2, &reg, 1, 1000);
	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);

	HAL_SPI_Transmit(&hspi2, &cmd, 1, 1000);
	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);

	SPI_NSS_SET;
}


void SX1276_Segment_Write(uint8_t * sx1276, uint8_t cmd)
{
	uint8_t rxByte = 0x00;
	uint8_t txByte = 0x00;
	uint8_t reg = sx1276[REGISTER_E];
	uint8_t mask = sx1276[MASK_E];
	uint8_t move = sx1276[MOVE_E];
	
	rxByte = SPI_Read(reg);
	rxByte &=~(mask<<move);
	txByte = rxByte|(cmd<<move);
	
	SPI_Write(reg,txByte);
	sx1276[VALUE_E] = cmd;

}

void SX1276_Byte_Write(uint8_t reg, uint8_t txByte)
{
	SPI_Write(reg,txByte);
}

void SX1276_Gather_segment(uint8_t * sx1276, uint8_t cmd, uint8_t *txByte )
{
	uint8_t move = sx1276[MOVE_E];
	uint8_t mask = sx1276[MASK_E];
	
	cmd &=mask;
	*txByte |= (cmd<<move);
	
	sx1276[VALUE_E] = cmd;
}




void SX1276_BurstWrite(uint8_t * sx1276, uint8_t* txBuff, uint8_t length)
{
	uint8_t reg = sx1276[REGISTER_E];

	if(length<=1)return;
	
	SPI_NSS_RESET;
	HAL_SPI_Transmit(&hspi2, &reg, 1, 1000);
	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);
	
	for(uint8_t i =0 ;i < length;i++)
	{
		HAL_SPI_Transmit(&hspi2, txBuff+i, 1, 1000);
		while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);
	}

	SPI_NSS_SET;
}

uint8_t SX1276_Read(uint8_t * sx1276)
{
	uint8_t rxByte = 0x00;
	uint8_t rxValue = 0;
	uint8_t reg = sx1276[REGISTER_E];
	uint8_t mask = sx1276[MASK_E];
	uint8_t move = sx1276[MOVE_E];
	rxByte = SPI_Read(reg);
	
	rxByte &= (mask<<move);
	rxValue = rxByte >>move;
	return rxValue;
	
}

void SX1276_BurstRead(uint8_t * sx1276, uint8_t* rxBuff, uint8_t length)
{
	uint8_t reg = sx1276[REGISTER_E];
	uint8_t txByte = 0x00;
	if(length<=1)return;
	
	SPI_NSS_RESET;
	HAL_SPI_Transmit(&hspi2, &reg, 1, 1000);
	while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);
	
	for(uint8_t i =0 ;i < length;i++)
	{
		HAL_SPI_TransmitReceive(&hspi2, &txByte,rxBuff+i, 1, 1000);
		while (HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);
	}

	SPI_NSS_SET;
}

void SX1276_Init(uint64_t frequency,uint8_t SF, uint8_t Bw, uint8_t CR, uint8_t CRC_sum)
{
	if(GET_DIP_IN)
	{
		m_sx1276.device = TX_DEVICE;
	}
	else
	{
		m_sx1276.device = RX_DEVICE;
	}
	
	SPI_NSS_SET;
	SET_SX1276;

	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_SLEEP);///
	HAL_Delay(15);
	SX1276_Segment_Write(m_sx1276.s_OpMode.LongRangeMode,LORA_MODE);///
	SX1276_Segment_Write(m_sx1276.s_OpMode.LowFrequencyModeOn,LOW_FREQ_MODE);///

	uint64_t freq = ((uint64_t)frequency << 19) / 32000000;
	uint8_t freq_reg[3];
	freq_reg[0] = (uint8_t) (freq >> 16);
	freq_reg[1] = (uint8_t) (freq >> 8);
	freq_reg[2] = (uint8_t) (freq >> 0);
	SX1276_BurstWrite(m_sx1276.s_FrMsb.FrfMsb, freq_reg, 3);///

	SX1276_Segment_Write(m_sx1276.s_SyncWord.SyncWord,0x34);

	//RegPaConfig //17-(15-15) = 17dbm
	SX1276_Segment_Write(m_sx1276.s_PaConfig.PaSelect,PA_BOOST);
	SX1276_Segment_Write(m_sx1276.s_PaConfig.MaxPower,0x07);
	SX1276_Segment_Write(m_sx1276.s_PaConfig.OutputPower,0x0f);

	//RegOcp// //CCP DISABLE
	SX1276_Segment_Write(m_sx1276.s_Ocp.OcpOn,OCP_DISABLE);
	SX1276_Segment_Write(m_sx1276.s_Ocp.OcpTrim,0x0b);

	//RegLna
	SX1276_Segment_Write(m_sx1276.s_Lna.LnaGain,G1);
	SX1276_Segment_Write(m_sx1276.s_Lna.LnaBoostHf,BOOST_ON_150_LNA_CURRENT);

	//RegModemConfig1	
	SX1276_Segment_Write(m_sx1276.s_ModemConfig1.Bw,Bw);
	SX1276_Segment_Write(m_sx1276.s_ModemConfig1.CodingRate,CR);
	SX1276_Segment_Write(m_sx1276.s_ModemConfig1.ImplicitHeaderModeOn, EXPLICIT_HEADER_MODE );

	//RegModemConfig2
	SX1276_Segment_Write(m_sx1276.s_ModemConfig2.SpreadingFactor,SF);
	SX1276_Segment_Write(m_sx1276.s_ModemConfig2.RxPayloadCrcOn,CRC_sum);

	//RegModemConfig3
	SX1276_Segment_Write(m_sx1276.s_ModemConfig3.LowDataRateOptimize,OPTIMIZE_DISABLE); // 이건 시간 계산해서 넘으면 넣자
	SX1276_Segment_Write(m_sx1276.s_ModemConfig3.AgcAutoOn,AGC_GAIN); //오토? 아까는 g1왜 설정 했는데...

	//RegSymbTimeoutLsb
	SX1276_Segment_Write(m_sx1276.s_SymbTimeoutLsb.SymbTimeoutLsb,0x08); // rx 컨티어니서스 할꺼면 안쓴다 
	SX1276_Segment_Write(m_sx1276.s_DioMapping2.DioMapping2,0x01); //RegDioMapping2 DIO5=00, DIO4=01 // 귀찮아서 이렇게함 ㅎㅎ;;// 근데 이건 왜넣은거야? IO4 쓰지도 않으면서

	if(m_sx1276.device == TX_DEVICE)
	{
		SX1276_Segment_Write(m_sx1276.s_PaDac.PaDac,PA_DAC_BOOST);
		SX1276_Segment_Write(m_sx1276.s_DioMapping1.Dio0,TX_DONE);
		SX1276_Byte_Write(RegIrqFlagsMask, OPEN_TXDONE_IRQ);
	}
	else if(m_sx1276.device == RX_DEVICE)
	{
		SX1276_Segment_Write(m_sx1276.s_PaDac.PaDac,PA_DAC_DEFAULT);
		SX1276_Segment_Write(m_sx1276.s_DioMapping1.Dio0,RX_DONE);
		SX1276_Byte_Write(RegIrqFlagsMask, OPEN_RXDONE_IRQ);
	}

	//RegOpMode
	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_STDBY);///
}

uint8_t SX1276_TX_Entry(uint8_t length, uint32_t timeOut)
{
	uint8_t addr = 0;
	uint8_t temp = 0;
	
	SX1276_Byte_Write(RegIrqFlags, ALL_IRQ_CLEAR);

	SX1276_Segment_Write(m_sx1276.s_PayloadLength.PayloadLength,length);

	addr = SX1276_Read(m_sx1276.s_FifoTxBaseAddr.FifoTxBaseAddr);	
	SX1276_Segment_Write(m_sx1276.s_FifoAddrPtr.FifoAddrPtr,addr);

	while(1)
	{
		temp = SX1276_Read(m_sx1276.s_PayloadLength.PayloadLength); //이짓을 왜하지? 당연한거 아님?
		if(temp == length) return 1;

		timeOut--; // 이건 따로 타이머가 없기때문에 에지게 빨리 사라질것같다
		
		if(timeOut == 0)
		{
			HW_Reset();	
			SX1276_Init(434000000, SF_07, KHZ_125, RATE_4_5, CRC_ENABLE); // 아니다 이건 해야할듯
			return 0;
		}
	}

	
}
uint8_t SX1276_RX_Entry(uint32_t timeOut)
{
	uint8_t addr = 0;
	SX1276_Byte_Write(RegIrqFlags, ALL_IRQ_CLEAR);

	addr = SX1276_Read(m_sx1276.s_FifoRxBaseAddr.FifoRxBaseAddr);	
	SX1276_Segment_Write(m_sx1276.s_FifoAddrPtr.FifoAddrPtr,addr);

	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_RXCONTINUOUS); // 잘기억해 

	while(1)
	{
		if(SX1276_Read(m_sx1276.s_ModemStat.RX_on_going) == 1)
		{
			return 1;
		}
		
		timeOut--; // 이건 따로 타이머가 없기때문에 에지게 빨리 사라질것같다
		
		if(timeOut == 0)
		{
			HW_Reset();		
			SX1276_Init(434000000, SF_07, KHZ_125, RATE_4_5, CRC_ENABLE);// 아니다 이건 해야할듯
			return 0;
		}
		HAL_Delay(1);
	}
}


uint8_t SX1276_TX_Packet(uint8_t* txBuff, uint8_t lengh, uint32_t timeOut)
{
	SX1276_BurstWrite(0x00, txBuff, lengh);
	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_TX);

	while(1)
	{
		if(GET_IO0)
		{
			SX1276_Byte_Write(RegIrqFlags, ALL_IRQ_CLEAR);
			SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_STDBY);
		}
		
		timeOut--;
		
		if(timeOut == 0)
		{
			HW_Reset();		
			SX1276_Init(434000000, SF_07, KHZ_125, RATE_4_5, CRC_ENABLE);// 아니다 이건 해야할듯
			return 0;
		}
		HAL_Delay(1);
	}
	
}

uint8_t SX1276_RX_Packet(uint8_t* rxBuff, uint8_t lengh)
{
	uint8_t addr = 0;
	uint8_t packet_size = 0;

	
	if(GET_IO0)
	{
		memset(rxBuff, 0x00,SX1276_MAX_PACKET);
		addr = SX1276_Read(m_sx1276.s_FifoRxCurrentaddr.FifoRxCurrentAddr);	
		SX1276_Segment_Write(m_sx1276.s_FifoAddrPtr.FifoAddrPtr,addr);

		packet_size = SX1276_Read(m_sx1276.s_RxNbBytes);

		SX1276_BurstRead(0x00, rxBuff, packet_size);

		SX1276_Byte_Write(RegIrqFlags, ALL_IRQ_CLEAR);
		
	}
}


void HW_Reset()
{
	SPI_NSS_SET;
	RESET_SX1276;
	HAL_Delay(1);
	SET_SX1276;
	HAL_Delay(100);	
}



