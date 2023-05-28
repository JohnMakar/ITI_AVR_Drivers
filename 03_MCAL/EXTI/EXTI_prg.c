/*
 * EXTI_prg.c
 *
 *  Created on: Mar 30, 2023
 *      Author: D E L L
 */

#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"
#include "DIO/DIO_int.h"
#include "BitMath.h"


void (*EXTI_INT0_CallBack)(void);
void (*EXTI_INT1_CallBack)(void);
void (*EXTI_INT2_CallBack)(void);

void MEXTI_void_EXTIEnable(u8 Copy_u8IntID,u8 Copy_u8Trigg)
{
	/*ENABLE GLOBAL INT (SET (SREG,7))*/
	SET_BIT(S_REG,GIE_BIT);

	/*SWITCH INTID */
	switch(Copy_u8IntID)
	{
	case EXTI_INT0_ID:
		MDIO_voidSetPinDirection(PORTD,PIN2,PIN_IN);
		MDIO_voidSetPullUpResistor(PORTD,PIN2);
		switch(Copy_u8Trigg)
		{
		case EXTI_TRG_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC00_BIT);
			CLR_BIT(MCUCR_REG,ISC01_BIT);
			break;
		case EXTI_TRG_ANY_CHANGE:
			SET_BIT(MCUCR_REG,ISC00_BIT);
			CLR_BIT(MCUCR_REG,ISC01_BIT);
			break;
		case EXTI_TRG_FALLING_EDGE:
			CLR_BIT(MCUCR_REG,ISC00_BIT);
			SET_BIT(MCUCR_REG,ISC01_BIT);
			break;
		case EXTI_TRG_RAISING_EDGE:
			SET_BIT(MCUCR_REG,ISC00_BIT);
			SET_BIT(MCUCR_REG,ISC01_BIT);
			break;
		}
		break;
		case EXTI_INT1_ID:
			MDIO_voidSetPinDirection(PORTD,PIN3,PIN_IN);
			MDIO_voidSetPullUpResistor(PORTD,PIN3);

			switch(Copy_u8Trigg)
			{
			case EXTI_TRG_LOW_LEVEL:
				CLR_BIT(MCUCR_REG,ISC10_BIT);
				CLR_BIT(MCUCR_REG,ISC11_BIT);
				break;
			case EXTI_TRG_ANY_CHANGE:
				SET_BIT(MCUCR_REG,ISC10_BIT);
				CLR_BIT(MCUCR_REG,ISC11_BIT);
				break;
			case EXTI_TRG_FALLING_EDGE:
				CLR_BIT(MCUCR_REG,ISC10_BIT);
				SET_BIT(MCUCR_REG,ISC11_BIT);
				break;
			case EXTI_TRG_RAISING_EDGE:
				SET_BIT(MCUCR_REG,ISC10_BIT);
				SET_BIT(MCUCR_REG,ISC11_BIT);
				break;
			}
			break;
			case EXTI_INT2_ID :
				MDIO_voidSetPinDirection(PORTB,PIN2,PIN_IN);
				MDIO_voidSetPullUpResistor(PORTB,PIN2);
				switch(Copy_u8Trigg)
				{
				case EXTI_TRG_FALLING_EDGE:
					CLR_BIT(MCUCSR_REG,ISC2_BIT);
					break;
				case EXTI_TRG_RAISING_EDGE:
					SET_BIT(MCUCSR_REG,ISC2_BIT);
					break;
				}
				break;
	}
}

void MEXTI_void_EXTIDisable(u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{
	case EXTI_INT0_ID:
		CLR_BIT(GICR_REG,INT0_BIT);
		break;
	case EXTI_INT1_ID:
		CLR_BIT(GICR_REG,INT1_BIT);
		break;
	case EXTI_INT2_ID:
		CLR_BIT(GICR_REG,INT2_BIT);
		break;
	}
}

void EXTI0_SetCallBack(void (*ptr)(void))
{
	EXTI_INT0_CallBack = ptr;
}

void EXTI1_SetCallBack(void (*ptr)(void))
{
	EXTI_INT1_CallBack = ptr;
}

void EXTI2_SetCallBack(void (*ptr)(void))
{
	EXTI_INT2_CallBack = ptr;
}

void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	EXTI_INT0_CallBack();
}

void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{
	EXTI_INT1_CallBack();
}

void __vector_3(void) __attribute__ ((signal));
void __vector_3(void)
{
	EXTI_INT2_CallBack();
}
