/*
 * UART_prg.c
 *
 *  Created on: Apr 4, 2023
 *      Author: D E L L
 */

#include "UART_int.h"
#include "UART_cfg.h"
#include "UART_prv.h"
#include "BitMath.h"

#define BAUD_RATE_RESULT 51

void MUART_voidInit(void)
{
	u8 Local_u8UBRR = 0;

	/*SELECT BAUD_RATE -> 9600*/
	Local_u8UBRR = ( (u8) BAUD_RATE_RESULT );
	UBRRH_REG = ( (u8)BAUD_RATE_RESULT >> 8 );
	UBRRL_REG =( (u8) Local_u8UBRR );

	/*SELECT CONFIGURATION AS ASYNC*/
	SET_BIT(Local_u8UBRR,URSEL_BIT);

	/*SELECT SLECET CHARACHER SIZE -> 8_BITS*/
	SET_BIT(Local_u8UBRR,UCSZ0_BIT);
	SET_BIT(Local_u8UBRR,UCSZ1_BIT);
	CLR_BIT(UCSRB_REG,UCSZ2_BIT);

	/*DISABLE PARITY*/
	CLR_BIT(UCSRC_REG,UPM0_BIT);
	CLR_BIT(UCSRC_REG,UPM1_BIT);

	/*SELECT STOP BIT -> 1BIT*/
	UCSRC_REG = Local_u8UBRR;

	/*ENABLE TX CICUIT*/
	SET_BIT(UCSRB_REG,TXEN_BIT);

	/*ENABLE RX CICUIT*/
	SET_BIT(UCSRB_REG,RXEN_BIT);
}
void MUART_voidTransmitDataSync(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA_REG,UDRE_BIT) == 0);
	UDR_REG = Copy_u8Data;
}
u8   MUART_u8ReceiveDataSync(void)
{
	while(GET_BIT(UCSRA_REG,RXC_BIT) == 0);
	return UDR_REG;
}
