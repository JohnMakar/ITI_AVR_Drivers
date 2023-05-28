/*
 * LM35_prg.c
 *
 *  Created on: Apr 2, 2023
 *      Author: D E L L
 */

#include "LM35_cfg.h"
#include "LM35_int.h"
#include "LM35_prv.h"
#include "ADC/ADC_int.h"


void HLM35_voidInit(void)
{
	/*Initialization Of ADC*/
	MADC_voidInit(V_AVCC,PRESCALER_128);

	/*SET Channel as OUT PIN*/
	MDIO_voidSetPinDirection(LM35_PORT,LM35_CHANNEL,PIN_IN);
}
u16   HLM35_u8ReadTemp(void)
{
	MADC_voidStartConversion(Channel_1);
	u16 Local_u16ADCRead;
	u16 Local_u16Readmv;

	/*READ DIGITAL VALUE FROM ADC*/
	Local_u16ADCRead = MADC_u16ADCReadSync();

	/*MAP DIGITAL VALUE TO ANALOG VALUE*/
	Local_u16Readmv = ((Local_u16ADCRead * 0.0048828125) * 100);

	/*RETURN TEMP*/
	return Local_u16Readmv;
}
