/*
 * Switch_prg.c
 *
 *  Created on: Mar 28, 2023
 *      Author: D E L L
 */
#include "Switch_cfg.h"
#include "Switch_int.h"
#include "Switch_prv.h"
#include "DIO/DIO_int.h"

void HSwtich_voidInit(u8 Copy_u8Switch)
{
	switch(Copy_u8Switch)
	{
	case SWITCH_ONE:   MDIO_voidSetPinDirection(SWITCH_PORT,SWITCH1_PIN,PIN_OUT); break;
	case SWITCH_TWO:   MDIO_voidSetPinDirection(SWITCH_PORT,SWITCH2_PIN,PIN_OUT); break;
	case SWITCH_THREE: MDIO_voidSetPinDirection(SWITCH_PORT,SWITCH3_PIN,PIN_OUT); break;
	default:                                                                        break;
	}
}
void HSwtich_voidOn(u8 Copy_u8Switch)
{
	switch(Copy_u8Switch)
		{
		case SWITCH_ONE:   MDIO_voidSetPinValue(SWITCH_PORT,SWITCH1_PIN,PIN_HIGH); break;
		case SWITCH_TWO:   MDIO_voidSetPinValue(SWITCH_PORT,SWITCH2_PIN,PIN_HIGH); break;
		case SWITCH_THREE: MDIO_voidSetPinValue(SWITCH_PORT,SWITCH3_PIN,PIN_HIGH); break;
		default:                                                                      break;
		}
}
void HSwtich_voidOff(u8 Copy_u8Switch)
{
	switch(Copy_u8Switch)
		{
		case SWITCH_ONE:   MDIO_voidSetPinValue(SWITCH_PORT,SWITCH1_PIN,PIN_LOW); break;
		case SWITCH_TWO:   MDIO_voidSetPinValue(SWITCH_PORT,SWITCH2_PIN,PIN_LOW); break;
		case SWITCH_THREE: MDIO_voidSetPinValue(SWITCH_PORT,SWITCH3_PIN,PIN_LOW); break;
		default:                                                                       break;
		}
}


