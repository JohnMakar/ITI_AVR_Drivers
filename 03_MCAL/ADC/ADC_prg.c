/*
 * ADC_prg.c
 *
 *  Created on: Apr 1, 2023
 *      Author: D E L L
 */

#include "STD.h"
#include "BitMath.h"

#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_prv.h"


static void(*MADC_ReadAsync)(void) = NULLPTR;
static u16 *Global_u16Data = NULLPTR;
void MADC_voidInit(u8 Copy_u8Volt,u8 Copy_u8Prescaler)
{
	/***** VOLTAGE_MODE ******/
	switch (Copy_u8Volt)
	{
	case V_AREF:
		CLR_BIT(ADMUX_REG,REFS0_BIT);
		CLR_BIT(ADMUX_REG,REFS1_BIT);
		break;
	case V_AVCC:
		SET_BIT(ADMUX_REG,REFS0_BIT);
		CLR_BIT(ADMUX_REG,REFS1_BIT);
		break;
	case RESERVED:
		CLR_BIT(ADMUX_REG,REFS0_BIT);
		SET_BIT(ADMUX_REG,REFS1_BIT);
		break;
	case INTERNAL:
		SET_BIT(ADMUX_REG,REFS0_BIT);
		SET_BIT(ADMUX_REG,REFS1_BIT);
		break;
	default: /*DO NOTHING*/      break;
	}

	/*ADLAR RIGHT ADJUSTMENT*/
	CLR_BIT(ADMUX_REG,ADLAR_BIT);

	/*CHOOSE PRESCALER*/
	switch(Copy_u8Prescaler)
	{
	case 0:
		CLR_BIT(ADCSRA_REG,ADPS0_BIT);
		CLR_BIT(ADCSRA_REG,ADPS1_BIT);
		CLR_BIT(ADCSRA_REG,ADPS2_BIT);
		break;

	case 1:
		SET_BIT(ADCSRA_REG,ADPS0_BIT);
		CLR_BIT(ADCSRA_REG,ADPS1_BIT);
		CLR_BIT(ADCSRA_REG,ADPS2_BIT);
		break;

	case 2:
		CLR_BIT(ADCSRA_REG,ADPS0_BIT);
		SET_BIT(ADCSRA_REG,ADPS1_BIT);
		CLR_BIT(ADCSRA_REG,ADPS2_BIT);
		break;

	case 3:
		SET_BIT(ADCSRA_REG,ADPS0_BIT);
		SET_BIT(ADCSRA_REG,ADPS1_BIT);
		CLR_BIT(ADCSRA_REG,ADPS2_BIT);
		break;

	case 4:
		CLR_BIT(ADCSRA_REG,ADPS0_BIT);
		CLR_BIT(ADCSRA_REG,ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADPS2_BIT);
		break;

	case 5:
		SET_BIT(ADCSRA_REG,ADPS0_BIT);
		CLR_BIT(ADCSRA_REG,ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADPS2_BIT);
		break;
	case 6:
		CLR_BIT(ADCSRA_REG,ADPS0_BIT);
		SET_BIT(ADCSRA_REG,ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADPS2_BIT);
		break;

	case 7:
		SET_BIT(ADCSRA_REG,ADPS0_BIT);
		SET_BIT(ADCSRA_REG,ADPS1_BIT);
		SET_BIT(ADCSRA_REG,ADPS2_BIT);
		break;
	default: /*Do NOTHING*/     break;
	}


	/*ADC ENABLE SET_BIT*/
	SET_BIT(ADCSRA_REG,ADEN_BIT);

}
void MADC_voidStartConversion(u8 Copy_u8Channel)
{
	/*SELECT CHANNEL*/
	switch(Copy_u8Channel)
	{
	case Channel_0:
		CLR_BIT(ADMUX_REG,MUX0_BIT);
		CLR_BIT(ADMUX_REG,MUX1_BIT);
		CLR_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_1:
		SET_BIT(ADMUX_REG,MUX0_BIT);
		CLR_BIT(ADMUX_REG,MUX1_BIT);
		CLR_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_2:
		CLR_BIT(ADMUX_REG,MUX0_BIT);
		SET_BIT(ADMUX_REG,MUX1_BIT);
		CLR_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_3:
		SET_BIT(ADMUX_REG,MUX0_BIT);
		SET_BIT(ADMUX_REG,MUX1_BIT);
		CLR_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_4:
		CLR_BIT(ADMUX_REG,MUX0_BIT);
		CLR_BIT(ADMUX_REG,MUX1_BIT);
		SET_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_5:
		SET_BIT(ADMUX_REG,MUX0_BIT);
		CLR_BIT(ADMUX_REG,MUX1_BIT);
		SET_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_6:
		CLR_BIT(ADMUX_REG,MUX0_BIT);
		SET_BIT(ADMUX_REG,MUX1_BIT);
		SET_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
		break;
	case Channel_7:
		SET_BIT(ADMUX_REG,MUX0_BIT);
		SET_BIT(ADMUX_REG,MUX1_BIT);
		SET_BIT(ADMUX_REG,MUX2_BIT);
		CLR_BIT(ADMUX_REG,MUX3_BIT);
		CLR_BIT(ADMUX_REG,MUX4_BIT);
	}

	/*ADC START CONVERSION SET_BIT*/
	SET_BIT(ADCSRA_REG,ADSC_BIT);

}
 u16 MADC_u16ADCReadSync(void)
 {
	 u16 Local_u16Data;

	 /*Read SYNCHRONOUSLY*/
	 while (GET_BIT(ADCSRA_REG,ADIF_BIT) == 0);
	 Local_u16Data  = ADCL_REG ;
	 Local_u16Data |= (ADCH_REG << 8);

	 /*SET_BET ADCSRA,ADIF*/
	 SET_BIT(ADCSRA_REG,ADIF_BIT);
	 return Local_u16Data;
 }

 void MADC_voidEnable(void)
 {
	 SET_BIT(ADCSRA_REG,ADIE_BIT);
 }
 void MADC_voidDisable(void)
 {
	 CLR_BIT(ADCSRA_REG,ADIE_BIT);
 }


 void MADC_voidReadAsync(void(*ptr)(void),u16 *Copy_pu16Data)
 {
	 if(ptr != NULLPTR)
	 {
		 MADC_ReadAsync = ptr;
	 }
	 if(Copy_pu16Data != NULLPTR)
	 {
		 Global_u16Data = Copy_pu16Data;
	 }
 }

 void __vector_17(void) __attribute__ ((signal));
 void __vector_17(void)
 {
	 if(Global_u16Data != NULLPTR)
	 {
		 *Global_u16Data |= (ADCH_REG << 8);

	 }

	 if(MADC_ReadAsync != NULLPTR)
	 {
		 MADC_ReadAsync();
	 }
 }


