/*
 * SPI_prg.h
 *
 *  Created on: Apr 6, 2023
 *      Author: D E L L
 */


#include "SPI_cfg.h"
#include "SPI_int.h"
#include "SPI_prv.h"
#include "BitMath.h"
#include "STD.h"
void MSPI_voidInit(void)
{
	/*SELECT DATA ORDER AS LSB*/
	SET_BIT(SPCR_REG, DORD_BIT);

#if   (SPI_MODE == SPI_MASTER_MODE)

	SET_BIT(SPCR_REG,MSTR_BIT);

	/*SELECT CLK POLARITY*/
	CLR_BIT(SPCR_REG,2);
	CLR_BIT(SPCR_REG,3);

	/*SELECT PRESCALER_128*/
	SET_BIT(SPCR_REG,SPR0_BIT);
	SET_BIT(SPCR_REG,SPR1_BIT);

#elif (SPI_MODE == SPI_SLAVE_MODE)

	CLR_BIT(SPCR_REG,MSTR_BIT);
#endif

	SET_BIT(SPCR_REG,SPE_BIT);
}
void MSPI_voidTransmitData(u8 Copy_u8Data)
{
	SPDR_REG = Copy_u8Data;
	while(GET_BIT(SPSR_REG,SPIF_BIT) == 0);
}
u8   MSPI_u8ReceiveData(void)
{
	u8 Local_u8Val;
	if(GET_BIT(SPSR_REG,SPIF_BIT) == 0)
	{
		Local_u8Val = 0;
	}
	else
	{
		Local_u8Val = SPDR_REG;
	}
	//while(GET_BIT(SPSR_REG,SPIF_BIT) == 0);
	return Local_u8Val;
}
