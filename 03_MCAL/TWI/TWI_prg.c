/*
 * TWI_prg.c
 *
 *  Created on: Apr 19, 2023
 *      Author: D E L L
 */

#include "STD.h"
#include "BitMath.h"
#include "TWI_prv.h"
#include "TWI_cfg.h"
#include "TWI_int.h"


void MTWI_voidMSTRInit(u8 Copy_u8MSTRAddress)
{
	/*SELECT FREQ*/
	TWBR_REG = 0x02;

	/*SET PRESCALER -> 16*/
	CLR_BIT(TWSR_REG,TWPS0_BIT);
	SET_BIT(TWSR_REG,TWPS1_BIT);

	/*SET MSTR ADDRESS*/
	TWAR_REG = (Copy_u8MSTRAddress << 1);

	/*SET ACK*/
	SET_BIT(TWCR_REG,TWEA_BIT);

	/*ENABLE TWI*/
	SET_BIT(TWCR_REG,TWEN_BIT);
}
void MTWI_voidSLVEInit(u8 Copy_u8MSLVEAddress)
{
	/*SET SLAVE ADRESS*/
	TWAR_REG = (Copy_u8MSLVEAddress << 1);

	/*SET ACK*/
	SET_BIT(TWCR_REG,TWEA_BIT);

	/*ENABLE TWI*/
	SET_BIT(TWCR_REG,TWEN_BIT);
}

void MTWI_voidSendStartCondition(void)
{
	/*SET STARTCONDITION BIT*/
	SET_BIT(TWCR_REG,TWSTA_BIT);

	/*CLR INT FLAG -->1*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*LOOPING ON INTERRUPT = 1*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 1);
}
void MTWI_voidSendRepeatedStart(void)
{
	/*SET STARTCONDITION BIT*/
	SET_BIT(TWCR_REG,TWSTA_BIT);

	/*CLR IF FLAG -->1*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*LOOPING ON INTERRUPT = 1*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 1);
}

void MTWI_voidSendSlaveAddressWrite(u8 Copy_u8SLVEAddress)
{
	/*CLR START CONDITION*/
	CLR_BIT(TWCR_REG,TWSTA_BIT);

	/*SET ADDRESS In TWDR*/
	TWDR_REG = Copy_u8SLVEAddress;

	/*CLR TWDR*/
	CLR_BIT(TWDR_REG,TWD0_BIT);

	/*CLR TWINT*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*LOOPING WHILE FLAG INT RAISING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 1);
}
void MTWI_voidSendSlaveAddressRead(u8 Copy_u8SLVEAddress)
{
	/*CLR START CONDITION*/
	CLR_BIT(TWCR_REG,TWSTA_BIT);

	/*SET ADDRESS In TWDR*/
	TWDR_REG = Copy_u8SLVEAddress;

	/*SET TWDR*/
	CLR_BIT(TWDR_REG,TWD0_BIT);

	/*CLR TWINT*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*LOOPING WHILE FLAG INT RAISING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 1);
}
void MTWI_voidMSTRWriteDataByte(u8 Copy_u8WriteData)
{
	/*SET DATA IN TWDR*/
	TWDR_REG = Copy_u8WriteData;

	/*CLR TWINT*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*LOOPING*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 1);
}
void MTWI_voidMSTRReadDataByte(u8 *Copy_Pu8ReadData)
{
	/*CLR INT*/
	SET_BIT(TWCR_REG,TWINT_BIT);

	/*WAIT*/
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 1);


	/*SET TWDR DATA IN PU8*/
	Copy_Pu8ReadData = TWDR_REG;
	while(Copy_Pu8ReadData != NULLPTR);
}
void MTWI_voidStopCondition(void)
{
	SET_BIT(TWCR_REG,TWSTO_BIT);

	/*CLR INT*/
	SET_BIT(TWCR_REG,TWINT_BIT);
}
