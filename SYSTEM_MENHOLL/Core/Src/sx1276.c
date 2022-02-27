//sx1276.c

#include "sx1276.h"
#include "main.h"

SX1276_T m_sx1276 = 
{
{{0x00, 					RegFifo, 				MASK_8, MOVE_BIT_0}},//Fifo[4];

{{FSK_OOK_MODE, 		   	RegOpMode, 				MASK_1, MOVE_BIT_7},//LongRangeMode[4];
 {ACCESS_LORA_PAGE, 		RegOpMode, 				MASK_1, MOVE_BIT_6},//AccessSharedReg[4];
 {LOW_FREQ_MODE, 			RegOpMode, 				MASK_1, MOVE_BIT_3},//LowFrequencyModeOn[4];
 {MODE_STDBY, 				RegOpMode, 				MASK_3, MOVE_BIT_0}},//Mode[4];


{{0x6c, 					RegFrMsb, 				MASK_8, MOVE_BIT_0}},//FrfMsb[4];

{{0x80, 					RegFrMid, 				MASK_8, MOVE_BIT_0}}, //FrfMid[4];

{{0x00, 					RegFrLsb, 				MASK_8, MOVE_BIT_0}}, //FrfLsb[4];

{{PA_BOOST, 				RegPaConfig, 			MASK_1, MOVE_BIT_7}, //PaSelect[4];
 {0x04, 					RegPaConfig, 			MASK_3, MOVE_BIT_4}, //MaxPower[4];
 {0x0f, 					RegPaConfig, 			MASK_4, MOVE_BIT_0}}, //OutputPower[4];

{{US40, 					RegPaRamp, 				MASK_4, MOVE_BIT_0}}, //PaRamp[4];

{{OCP_ENABLE, 				RegOcp, 				MASK_1, MOVE_BIT_5}, //OcpOn[4];
 {0x0b, 					RegOcp, 				MASK_5, MOVE_BIT_0}}, //OcpTrim[4];

{{G1, 						RegLna, 				MASK_3, MOVE_BIT_5}, //LnaGain[4];
 {0x00, 					RegLna, 				MASK_2, MOVE_BIT_3}, //LnaBoostLf[4];
 {DEFAULT_LNA_CURRENT, 		RegLna, 				MASK_2, MOVE_BIT_0}}, //LnaBoostHf[4];

{{0x00, 					RegFifoAddrPtr, 		MASK_8, MOVE_BIT_0}}, //FifoAddrPtr[4];

{{0x80, 					RegFifoTxBaseAddr, 		MASK_8, MOVE_BIT_0}}, //FifoTxBaseAddr[4];

{{0x00, 					RegFifoRxBaseAddr, 		MASK_8, MOVE_BIT_0}}, //FifoRxBaseAddr[4];

{{0x00, 					RegFifoRxCurrentaddr, 	MASK_8, MOVE_BIT_0}}, //FifoRxCurrentAddr[4];

{{0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_7}, //RxTimeoutMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_6}, //RxDoneMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_5}, //PayloadCrcErrorMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_4}, //ValidHeaderMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_3}, //TxDoneMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_2}, //CadDoneMask[4];
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_1}, //FhssChangeChannelMask[4
 {0x00, 					RegIrqFlagsMask, 		MASK_1, MOVE_BIT_0}}, //CadDetectedMask[4];

{{0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_7}, //RxTimeout[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_6}, //RxDone[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_5}, //PayloadCrcError[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_4}, //ValidHeader[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_3}, //TxDone[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_2}, //CadDone[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_1}, //FhssChangeChannel[4];
 {0x00, 					RegIrqFlags, 			MASK_1, MOVE_BIT_0}}, //CadDetected[4];

{{0x00, 					RegRxNbBytes, 			 MASK_8, MOVE_BIT_0}}, //FifoRxBytesNb[4];

{{0x00, 					RegRxHeaderCntValueMsb,  MASK_8, MOVE_BIT_0}}, //ValidHeaderCntMsb[4];

{{0x00, 					RegRxHeaderCntValueLsb,  MASK_8, MOVE_BIT_0}}, //ValidHeaderCntLsb[4];

{{0x00, 					RegRxPacketCntValueMsb,  MASK_8, MOVE_BIT_0}}, //ValidPacketCntMsb[4];

{{0x00, 					RegRxPacketCntValueLsb,  MASK_8, MOVE_BIT_0}}, //ValidPacketCntLsb[4];

{{0x00, 					RegModemStat, 			MASK_3, MOVE_BIT_5}, //RxCodingRate[4];
 {0x00, 					RegModemStat, 			MASK_5, MOVE_BIT_0}}, //ModemStatus[4];

{{0x00, 					RegPktSnrValue, 		MASK_8, MOVE_BIT_0}}, //PacketSnr[4];

{{0x00, 					RegPktRssiValue, 		MASK_8, MOVE_BIT_0}}, //PacketRssi[4];

{0x00, 						RegRssiValue_, 			MASK_8, MOVE_BIT_0}, //Rssi[4];

{{PLL_DID_NOT_LOCK, 		RegHopChannel, 			MASK_1, MOVE_BIT_7}, //PllTimeout[4];
 {HEADER_CRC_ON, 			RegHopChannel, 			MASK_1, MOVE_BIT_6}, //CrcOnPayload
 {0x00, 					RegHopChannel, 			MASK_6, MOVE_BIT_0}}, //FhssPresentChannel[4];

{{KHZ_125, 					RegModemConfig1, 		MASK_4, MOVE_BIT_4}, //Bw[4];
 {RATE_4_5, 				RegModemConfig1, 		MASK_3, MOVE_BIT_1}, //CodingRate[4];
 {EXPLICIT_HEADER_MODE, 	RegModemConfig1, 		MASK_1, MOVE_BIT_0}}, //ImplicitHeaderModeOn[4]

{{SF_07, 					RegModemConfig2, 		MASK_4, MOVE_BIT_4}, //SpreadingFactor[4];
 {NORMAL_MODE, 				RegModemConfig2, 		MASK_1, MOVE_BIT_3}, //TxContinuousMode[4];
 {CRC_ENABLE, 				RegModemConfig2, 		MASK_1, MOVE_BIT_2}, //RxPayloadCrcOn[4];
 {0x00, 					RegModemConfig2,		MASK_2, MOVE_BIT_0}}, //SymbTimeoutMsB[4];

{{0x64, 					RegSymbTimeoutLsb, 		MASK_8, MOVE_BIT_0}}, //SymbTimeoutLsb[4];

{{0x00, 					RegPreambleMsb, 		MASK_8, MOVE_BIT_0}}, //PreambleLengthMsb[4];

{{0x08, 					RegPreambleLsb, 		MASK_8, MOVE_BIT_0}}, //PreambleLengthLsb[4];

{{0x01, 					RegPayloadLength, 		MASK_8, MOVE_BIT_0}}, //PayloadLength[4];

{{0xff, 					RegMaxPayloadLength, 	MASK_8, MOVE_BIT_0}}, //PayloadMaxLength[4];

{{0x00, 					RegHopPeriod, 			MASK_8, MOVE_BIT_0}}, //FreqHoppingPeriod[4];

{{0x00, 					RegFifoRxByteAddr, 		MASK_8, MOVE_BIT_0}}, //FifoRxByteAddrPtr[4];

{{OPTIMIZE_DISABLE, 		RegModemConfig3, 		MASK_1, MOVE_BIT_3}, //LowDataRateOptimize[4];
 {LNA_GAIN, 				RegModemConfig3, 		MASK_1, MOVE_BIT_2}}, //AgcAutoOn[4];

{{0x00, 					RegDioMapping1, 			MASK_8, MOVE_BIT_0}},
{{0x00, 					RegDioMapping2, 			MASK_8, MOVE_BIT_0}},  

{{0x12, 					RegVersion, 				MASK_8, MOVE_BIT_0}},        

{{CRYSTAL, 					RegTcxo, 				MASK_1, MOVE_BIT_4}},

{{PA_DAC_DEFAULT, 			RegPaDac ,				MASK_3, MOVE_BIT_0}},       

{{0x00, 					RegFormerTemp, 			MASK_8, MOVE_BIT_0}},   

{{0x13, 					RegAgcRef, 				MASK_6, MOVE_BIT_0}},     

{{0x0e, 					RegAgcThresh1, 			MASK_8, MOVE_BIT_0}},    

{{0x5b, 					RegAgcThresh2, 			MASK_8, MOVE_BIT_0}},   

{{0xdb, 					RegAgcThresh3, 			MASK_8, MOVE_BIT_0}}    
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


void SX1276_Write(uint8_t * sx1276, uint8_t cmd)
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


