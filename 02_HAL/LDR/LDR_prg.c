/*
 * LDR_prg.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mariam
 */
#include "STD.h"
#include "BitMath.h"
#include "DIO/DIO_int.h"
#include "ADC/ADC_int.h"

#include "LDR/LDR_cfg.h"
#include "LDR/LDR_prv.h"
#include "LDR/LDR_int.h"

#include <util/delay.h>

void HLDR_voidInit(void)
{
	MADC_voidInit(V_AVCC,PRESCALER_16);
}
u16 HLDR_u16Read(void)
{
	u16 Local_u16ADCRead;
	u16 Local_u16LightIntensity;
	MADC_voidStartConversion(Channel_0);

	/*READ DIGITAL VALUE FROM ADC*/
	Local_u16ADCRead =  MADC_u16ADCReadSync();

	/*MAP DIGITAL VALUE TO ANALOG VALUE*/
	Local_u16LightIntensity = ((Local_u16ADCRead *2));

	/*RETURN Light Intensity Value*/
	return Local_u16ADCRead;
}
