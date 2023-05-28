/*
 * SM_prg.c
 *
 *  Created on: Mar 29, 2023
 *      Author: D E L L
 */

#include "STD.h"
#include "BitMath.h"
#include "DIO/DIO_int.h"
#include "SM_int.h"
#include "SM_prv.h"
#include "SM_cfg.h"
#include <util/delay.h>

void HStepperMotor_voidStepperInit(void)
{
	/*SET STEPPER MOTOTR PINS DIRECTION*/
	MDIO_voidSetPinDirection(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_OUT);
	MDIO_voidSetPinDirection(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_OUT);
	MDIO_voidSetPinDirection(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_OUT);
	MDIO_voidSetPinDirection(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_OUT);
	/*SET STEPPER MOTOTR PINS VALUE*/
	MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_HIGH);
}

void HStepperMOTOR_voidStepperFullStepCW(void)
{
	u8 Local_u8Iteration;
	for(Local_u8Iteration = STEPPER_INIT_ITERATION;Local_u8Iteration < STEPPER_TOTAL_ITERATION;Local_u8Iteration++)
	{
		/*COIL 1*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 2*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 3*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 4*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_HIGH);
		_delay_ms(2);
	}
}
void HStepperMOTOR_voidStepperFullStepCCW(void)
{
	u8 Local_u8Iteration;
	for(Local_u8Iteration = STEPPER_INIT_ITERATION;Local_u8Iteration < STEPPER_TOTAL_ITERATION;Local_u8Iteration++)
	{
		/*COIL 1*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_HIGH);
		_delay_ms(2);
		/*COIL 2*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		_delay_ms(2);
		/*COIL 3*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 4*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
	}
}
void HStepperMOTOR_voidStepperSpecificDegreeCW(u8 Copy_u8Degree)
{
	u16 Local_u8Iteration;
	Copy_u8Degree = (((Copy_u8Degree/11.25)*64)/4);
	for(Local_u8Iteration = STEPPER_INIT_ITERATION;Local_u8Iteration < Copy_u8Degree;Local_u8Iteration++)
	{
		/*COIL 1*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 2*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 3*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 4*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_HIGH);
		_delay_ms(2);
	}
}

void HStepperMOTOR_voidStepperSpecificDegreeCCW(u8 Copy_u8Degree)
{
	u8 Local_u8Iteration;
	Copy_u8Degree = (((Copy_u8Degree/11.25)*64)/4);
	for(Local_u8Iteration = STEPPER_INIT_ITERATION;Local_u8Iteration < Copy_u8Degree;Local_u8Iteration++)
	{
		/*COIL 1*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_HIGH);
		_delay_ms(2);
		/*COIL 2*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		_delay_ms(2);
		/*COIL 3*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
		/*COIL 4*/
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN1,PIN_HIGH);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN2,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN3,PIN_LOW);
		MDIO_voidSetPinValue(STEPPER_MOTTOR_PORT,STEPPER_MOTTOR_PIN4,PIN_LOW);
		_delay_ms(2);
	}
}

