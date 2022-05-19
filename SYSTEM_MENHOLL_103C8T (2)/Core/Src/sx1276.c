//sx1276.c

#include"common.h"



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

RX_DEVICE,  // txDevice or rxDevice

{0,0,0,0,0}		// rssi, rowRssi, rssipkt, snr
};

char buffer[512];

int message;
int message_length;

void Lora_config()
{
	if(m_sx1276.device == TX_DEVICE)
	{
		LED2_TOGGLE;
		HAL_Delay(1000);
		message_length = sprintf(buffer, "Hello %d", message);

		SX1276_TX_Entry(message_length, 2000);
		
		SX1276_TX_Packet(buffer,message_length,2000);

		message += 1;
	}
	else
	{
		LED2_TOGGLE;
		HAL_Delay(800);
		SX1276_RX_Packet(buffer);
		PCPrintf("%s \r\n",buffer);
		SX1276_Calculrate_SNR_Rssi();	
	}

}

#define EVENT_TYPE		1
#define POLLING_TYPE	2


void Lora_Event_Send_Msg(char* msg, uint16_t data)
{
	char txBuff[30] = {0,};
	char event_msg[15] = {0,};
	uint8_t length = 0;

	memcpy(txBuff, m_status.toMasterRute, strlen(m_status.toMasterRute));
	strcat(txBuff,m_status.myNodeName);
	
	sprintf(event_msg, "<E>[%s:%u]",msg, data);

	strcat(txBuff,event_msg);

	length = strlen(txBuff);


	SX1276_Change_rx_tx(TX_DEVICE);
	SX1276_TX_Entry(length, 2000);
			
	SX1276_TX_Packet(txBuff,length,2000);
	HAL_Delay(20);
	SX1276_Change_rx_tx(RX_DEVICE);
	
}


uint32_t preT = 0;
uint32_t termT = 0;

void Lora_Send_Msg(char* msg, uint16_t data)
{
	char txBuff[50] = {0,};
	uint8_t length = 0;

	if(data == NONE_VALUE)
	{
		length = sprintf(txBuff, "%s", msg);
	}
	else
	{
		length = sprintf(txBuff, "%s%u",msg, data);
	}

	preT = HAL_GetTick();
	SX1276_Change_rx_tx(TX_DEVICE);
	SX1276_TX_Entry(length, 2000);
	SX1276_TX_Packet(txBuff,length,2000);
	//HAL_Delay(20);
	SX1276_Change_rx_tx(RX_DEVICE);
	termT = HAL_GetTick() - preT;
	
	
}

uint8_t readMag[50] = {0,};
int no_rx_num[3] = {0,};
uint16_t tmp[5] = {0,};
void Master_Pass_Many_Node()//
{
	static uint8_t step = STEP1;
	static uint32_t timestemp = 0;
	char txBuff[20] = {0,};
	char nodeNum[10] = {0,};
	static uint16_t nodeCnt = 0;
	static uint16_t prenodeCnt =1;
	static uint8_t notRxCnt,notRxflag = 0;
	
	switch(step)
	{	
		case STEP1:

			if(prenodeCnt == nodeCnt) 
			{
				notRxCnt++;
				if(notRxCnt > 10)
				{
					notRxCnt = 0;
					notRxflag = 1;
					PCPrintf("Not recive = %d node \r\n",nodeCnt);
					nodeCnt++;
					nodeCnt %=3;
				}
			}
			
			memcpy(txBuff, m_status.toNodeRute, strlen(m_status.toNodeRute));
			strcat(txBuff,"#");

			sprintf(nodeNum,"00%u",nodeCnt);
			strcat(txBuff,nodeNum);
			
			Lora_Send_Msg(txBuff, NONE_VALUE);
			prenodeCnt = nodeCnt;
			timestemp = HAL_GetTick();
			step = STEP2;
			
		break;

		case STEP2:
			
			SX1276_RX_Packet(buffer);

			if(HAL_GetTick() - timestemp >600)
			{
				no_rx_num[nodeCnt]++;
				step = STEP1;
				
			}
			if(strncmp("&M",buffer ,2 )==0)
			{
				LED1_TOGGLE;
				sscanf(buffer, "&M#001[%u,%u,%u,]", tmp, tmp+1, tmp+2);
				PCPrintf("%s \r\n",buffer+2);
                notRxCnt = 0;
				memcpy(readMag,buffer,50);
			
                memset(buffer,0,512);
				timestemp = HAL_GetTick();
				nodeCnt++;
				nodeCnt %=3;
				step = STEP3;
			}
			
		break;

		case STEP3:
			if(HAL_GetTick() - timestemp >300)
			{

				step = STEP1;
			}
		break;
	}

}

uint32_t callbackTime= 0;

void Master_Pass_Many_Station()//
{
	static uint8_t step = STEP1;
	static uint32_t timestemp = 0;
	char txBuff[20] = {0,};
	char nodeNum[10] = {0,};
	static uint16_t nodeCnt = 0;
	static uint8_t notRxCnt,notRxflag = 0;
	static int success_rx_num = 0;
	static int fail_rx_num = 0;
	static int tx_rx_num = 0;
	switch(step)
	{	
		case STEP1:
			
			memcpy(txBuff, m_status.toNodeRute, strlen(m_status.toNodeRute));
			strcat(txBuff,"#");

			sprintf(nodeNum,"%u",nodeCnt);
			strcat(txBuff,nodeNum);
			LED2_TOGGLE;
			Lora_Send_Msg(txBuff, NONE_VALUE);
			timestemp = HAL_GetTick();
			step = STEP2;
			tx_rx_num++;
		break;

		case STEP2:
			
			SX1276_RX_Packet(buffer);

			if(HAL_GetTick() - timestemp >2000)
			{
				fail_rx_num++;
				step = STEP1;
				
			}
			if(strncmp("&M",buffer ,MASTER_HEAD_LEN )==0)
			{
				LED1_TOGGLE;
				success_rx_num++;
				callbackTime = HAL_GetTick() - timestemp;
				//sscanf(buffer, "&M#000[%u,%u,%u,]", tmp, tmp+1, tmp+2);
				PCPrintf("%st:%d r:%d e:%d t:%d\r\n", buffer+4, tx_rx_num, success_rx_num, fail_rx_num,callbackTime);
                notRxCnt = 0;
				memcpy(readMag,buffer,50);
			
                memset(buffer,0,512);
				timestemp = HAL_GetTick();
				step = STEP3;
			}
			
		break;

		case STEP3:
			if(HAL_GetTick() - timestemp >2000)
			{

				step = STEP1;
			}
		break;
	}

}

void Gateway_Pass()
{
	SX1276_RX_Packet(buffer);

	if(strncmp(m_status.stationName,buffer ,STATION_HEAD_LEN )==0)
	{
		LED1_TOGGLE;
		memcpy(readMag,buffer,50);
		HAL_Delay(LORA_DELAY);
		Lora_Send_Msg(buffer+STATION_HEAD_LEN, NONE_VALUE);
		memset(buffer,0,512);
	}

}

uint8_t sf_flag = 0;
void Node_Pass()
{
	char txBuff[50] = {0,};
	static uint16_t cnt = 0;
	uint8_t num = 0;
	SX1276_RX_Packet(buffer);
	
	if(strncmp(m_status.myNodeName,buffer ,NODE_HEAD_LEN )==0)
	{
			LED1_TOGGLE;
			memset(buffer,0,512);
			HAL_Delay(LORA_DELAY);
			memcpy(txBuff, m_status.toMasterRute, strlen(m_status.toMasterRute));
			strcat(txBuff,m_status.myNodeName);
			strcat(txBuff,"[");
			strcat(txBuff,m_status.polingDataStr);
			strcat(txBuff,"]");
			memcpy(readMag,txBuff,50);
			
			Lora_Send_Msg(txBuff, NONE_VALUE);

			memset(m_status.polingDataStr, 0, strlen(m_status.polingDataStr));

			Poling_Str_Add(cnt);
		  	Poling_Str_Add(cnt+100);
		  	Poling_Str_Add(cnt+200);
		  	cnt++;
	}
	else if(strncmp(CMD_SF,buffer ,2)==0)
	{
		num = atoi(buffer+2);
		
		if(SF_07<= num && num<= SF_12 )
		{
			HAL_Delay(100);
			SX1276_Control_SF(num);
		}	

	}
	memset(buffer,0,512);
}


void SX1276_Control_SF(uint8_t     data)
{
	SX1276_Segment_Write(m_sx1276.s_ModemConfig2.SpreadingFactor,data);
}
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




void SX1276_BurstWrite(uint8_t reg, uint8_t* txBuff, uint8_t length)
{
	reg |=0x80;

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

	sx1276[VALUE_E] = rxValue;
	return rxValue;
	
}

void SX1276_BurstRead(uint8_t reg, uint8_t* rxBuff, uint8_t length)
{

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

void SX1276_Init(uint64_t frequency,uint8_t SF, uint8_t Bw, uint8_t CR, uint8_t CRC_enable)
{
	if(m_status.device == 0x01)
	{
		m_sx1276.device = TX_DEVICE;
	}
	else
	{
		m_sx1276.device = RX_DEVICE;////
	}

	SPI_NSS_SET;
	SET_SX1276;

	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_SLEEP);///
	HAL_Delay(15);
	SX1276_Segment_Write(m_sx1276.s_OpMode.LongRangeMode,LORA_MODE);///
	SX1276_Segment_Write(m_sx1276.s_OpMode.LowFrequencyModeOn,HIGH_FREQ_MODE);///

	uint64_t freq = ((uint64_t)frequency << 19) / 32000000;
	uint8_t freq_reg[3];
	freq_reg[0] = (uint8_t) (freq >> 16);
	freq_reg[1] = (uint8_t) (freq >> 8);
	freq_reg[2] = (uint8_t) (freq >> 0);
	SX1276_BurstWrite(RegFrMsb, freq_reg, 3);///

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
	SX1276_Segment_Write(m_sx1276.s_ModemConfig2.RxPayloadCrcOn,CRC_enable);

	//RegModemConfig3
	SX1276_Segment_Write(m_sx1276.s_ModemConfig3.LowDataRateOptimize,OPTIMIZE_DISABLE); // 이건 시간 계산해서 넘으면 넣자
	SX1276_Segment_Write(m_sx1276.s_ModemConfig3.AgcAutoOn,AGC_GAIN); //오토? 아까는 g1왜 설정 했는데...

	//RegSymbTimeoutLsb
	SX1276_Segment_Write(m_sx1276.s_SymbTimeoutLsb.SymbTimeoutLsb,0x08); // rx 컨티어니서스 할꺼면 안쓴다 
	SX1276_Segment_Write(m_sx1276.s_DioMapping2.DioMapping2,0x01); //RegDioMapping2 DIO5=00, DIO4=01 // 귀찮아서 이렇게함 ㅎㅎ;;// 근데 이건 왜넣은거야? IO4 쓰지도 않으면서

	SX1276_Segment_Write(m_sx1276.s_PaDac.PaDac,PA_DAC_BOOST);
	if(m_sx1276.device == TX_DEVICE)
	{
		SX1276_Segment_Write(m_sx1276.s_DioMapping1.Dio0,TX_DONE);
		SX1276_Byte_Write(RegIrqFlagsMask, OPEN_TXDONE_IRQ);
	}
	else if(m_sx1276.device == RX_DEVICE)
	{
		SX1276_Segment_Write(m_sx1276.s_DioMapping1.Dio0,RX_DONE);
		SX1276_Byte_Write(RegIrqFlagsMask, OPEN_RXDONE_IRQ);
	}

	//RegOpMode
	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_STDBY);///
}
void SX1276_Change_rx_tx(uint8_t mode)
{
	if(mode == TX_DEVICE)
	{
		//SX1276_Segment_Write(m_sx1276.s_PaDac.PaDac,PA_DAC_BOOST);
		SX1276_Segment_Write(m_sx1276.s_DioMapping1.Dio0,TX_DONE);
		SX1276_Byte_Write(RegIrqFlagsMask, OPEN_TXDONE_IRQ);
		//SX1276_TX_Entry(16, 2000);
	}
	else if(mode == RX_DEVICE)
	{
		//SX1276_Segment_Write(m_sx1276.s_PaDac.PaDac,PA_DAC_DEFAULT);
		SX1276_Segment_Write(m_sx1276.s_DioMapping1.Dio0,RX_DONE);
		SX1276_Byte_Write(RegIrqFlagsMask, OPEN_RXDONE_IRQ);
		SX1276_RX_Entry(2000);
	}	
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
		if(temp == length) 
		{
			return 1;
		}
		timeOut--; // 이건 따로 타이머가 없기때문에 에지게 빨리 사라질것같다
		
		if(timeOut == 0)
		{
			HW_Reset();	
			SX1276_Init(922000000, SF_VALUE, KHZ_125, RATE_4_5, CRC_ENABLE); // 아니다 이건 해야할듯
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
			SX1276_Init(922000000, SF_VALUE, KHZ_125, RATE_4_5, CRC_ENABLE);// 아니다 이건 해야할듯
			return 0;
		}
		HAL_Delay(1);
	}
}


uint8_t SX1276_TX_Packet(char* txBuff, uint8_t lengh, uint32_t timeOut)
{
	SX1276_BurstWrite(0x00, (uint8_t *)txBuff, lengh);
	SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_TX);

	while(1)
	{
		if(GET_IO0)
		{
			SX1276_Byte_Write(RegIrqFlags, ALL_IRQ_CLEAR);
			SX1276_Segment_Write(m_sx1276.s_OpMode.Mode,MODE_STDBY);
			return 1;
		}
		
		timeOut--;
		
		if(timeOut == 0)
		{
			HW_Reset();		
			SX1276_Init(922000000, SF_VALUE, KHZ_125, RATE_4_5, CRC_ENABLE);// 아니다 이건 해야할듯
			return 0;
		}
		HAL_Delay(1);
	}
	
}

void SX1276_RX_Packet(char* rxBuff)
{
	uint8_t addr = 0;
	uint8_t packet_size = 0;

	
	if(GET_IO0)
	{
		memset(rxBuff, 0x00,SX1276_MAX_PACKET);
		addr = SX1276_Read(m_sx1276.s_FifoRxCurrentaddr.FifoRxCurrentAddr);	
		SX1276_Segment_Write(m_sx1276.s_FifoAddrPtr.FifoAddrPtr,addr);

		packet_size = SX1276_Read(m_sx1276.s_RxNbBytes.FifoRxBytesNb);

		if(packet_size !=0)SX1276_BurstRead(0x00, (uint8_t *)rxBuff, packet_size);

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


void SX1276_Calculrate_SNR_Rssi()
{
	int SNR = 0;
	uint8_t snr_tmp = 0;
	uint8_t snr_row = 0;
	uint8_t twos_com = 0;
	int Rssi = 0;
	uint8_t rssi_row = 0;
	uint8_t rssi_pkt_tmp = 0;

	rssi_pkt_tmp = SX1276_Read(m_sx1276.s_PktRssiValue.PacketRssi);

	snr_row = SX1276_Read(m_sx1276.s_PktSnrValue.PacketSnr);
	if(snr_row > 127 ) 
	{
		snr_tmp = ~snr_row;
		twos_com = snr_tmp +0x01;
		SNR = twos_com * -1;	
	}
	else
	{
		SNR = snr_row;
	}

	SNR = snr_row/4;

	if(SNR>0)
	{
		rssi_row = SX1276_Read(m_sx1276.s_RssiValue.Rssi);	
		Rssi = -RSSI_LF_CONSTANS + rssi_row;
	}
	else
	{
		Rssi = -RSSI_LF_CONSTANS + rssi_pkt_tmp + SNR;
	}

	m_sx1276.observ.Rssi = Rssi;
	m_sx1276.observ.SNR = SNR;
	m_sx1276.observ.rowRssi = rssi_row;
	m_sx1276.observ.pktRssi = rssi_pkt_tmp;
	m_sx1276.observ.rowSNR = snr_row;	

}
