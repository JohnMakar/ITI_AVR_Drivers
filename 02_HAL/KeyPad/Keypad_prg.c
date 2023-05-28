/*
 * Keypad_prg.c
 *
 *  Created on: Mar 25, 2023
 *      Author: D E L L
 */
#include "STD.h"
#include "Keypad_cfg.h"
#include "Keypad_int.h"
#include "Keypad_prv.h"
#include "DIO/DIO_int.h"



void HKPD_voidInit(void)
{

	/*Set Direction Rows Pins*/
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_R0,PIN_IN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_R1,PIN_IN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_R2,PIN_IN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_R0,PIN_IN);


	/*Set Direction Column Pins*/
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_C0,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_C1,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_C2,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_PIN_C3,PIN_OUT);

	/*Enables PullUp*/
	MDIO_voidSetPullUpResistor(KPD_PORT,KPD_PIN_R0);
	MDIO_voidSetPullUpResistor(KPD_PORT,KPD_PIN_R1);
	MDIO_voidSetPullUpResistor(KPD_PORT,KPD_PIN_R2);
	MDIO_voidSetPullUpResistor(KPD_PORT,KPD_PIN_R3);

	/*Set Row Pins Value High*/
	MDIO_voidSetPinValue(KPD_PORT,KPD_PIN_R0,PIN_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_PIN_R1,PIN_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_PIN_R2,PIN_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_PIN_R3,PIN_HIGH);
}

u8 HKPD_u8GetPressedKey(void)
{
	/*Create Array Of Columns*/
	u8 Local_u8ColumnArray[COLUMNS_NUM] = {KPD_PIN_C0,KPD_PIN_C1,KPD_PIN_C2,KPD_PIN_C3};

	/*Create Array Of ROWS*/
	u8 Local_u8RowsArray[ROWS_NUM] = {KPD_PIN_R0,KPD_PIN_R1,KPD_PIN_R2,KPD_PIN_R3};

	/*Create Variables Counters For PINS*/
	u8 Local_u8RowCounter;
	u8 Local_u8ColumnCounter;

	/*Create Variables For Pin State*/
	u8 Local_u8PinState;

	/*Create PressedKey Value = 0xff*/
	u8 Local_u8PressedKey = NOT_PRESSED;

	/*Create Button Array*/
	u8 Local_u8ButtonsArray[ROWS_NUM][COLUMNS_NUM] = CALCULATOR_VAL ;

	/*LOOP FOR COLUMNS*/
	for(Local_u8ColumnCounter = 0; Local_u8ColumnCounter < COLUMNS_NUM;Local_u8ColumnCounter++)
	{
		/*Set Columns LOW*/
		MDIO_voidSetPinValue(KPD_PORT,Local_u8ColumnArray[Local_u8ColumnCounter],PIN_LOW);

		/*LOOP FOR ROWS*/
		for(Local_u8RowCounter = 0; Local_u8RowCounter < ROWS_NUM;Local_u8RowCounter++)
		{
			/*Store The Value Of Rows And Columns In PinState*/
			Local_u8PinState = MDIO_u8GetPinValue(KPD_PORT,Local_u8RowsArray[Local_u8RowCounter]);

			/*Checking If Pin State Is LOW (Active Low)*/
			if(Local_u8PinState == PIN_LOW)
			{
				/*Saving The Row Number And Column Number In PressedKey*/
				Local_u8PressedKey = Local_u8ButtonsArray[Local_u8RowCounter][Local_u8ColumnCounter];

				/*To Avoid Reading Value Multi_times*/
				while (Local_u8PinState == PIN_LOW)
					Local_u8PinState = MDIO_u8GetPinValue(KPD_PORT,Local_u8RowsArray[Local_u8RowCounter]);

				/*Returning PressedKey*/
				return Local_u8PressedKey;
			}
		}
		/*Reset Value Of Columns*/
		MDIO_voidSetPinValue(KPD_PORT,Local_u8ColumnArray[Local_u8ColumnCounter],PIN_HIGH);
	}
	return Local_u8PressedKey;

}
