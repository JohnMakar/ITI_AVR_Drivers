/*
 * DIO_prg.c
 *
 *  Created on: Mar 21, 2023
 *      Author: D E L L
 */

#include "STD.h"
#include "BitMath.h"
#include "DIO_cfg.h"
#include "DIO_prv.h"
#include "DIO_int.h"


void MDIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir)
{
	switch(Copy_u8Port)
	{
	case PORTA :
		switch(Copy_u8Dir)
		{
		case  PIN_IN: CLR_BIT(MDIO_DDRA,Copy_u8Pin); break;
		case PIN_OUT: SET_BIT(MDIO_DDRA,Copy_u8Pin); break;
		}
		break;
	case PORTB :
		switch(Copy_u8Dir)
		{
			case  PIN_IN: CLR_BIT(MDIO_DDRB,Copy_u8Pin); break;
			case PIN_OUT: SET_BIT(MDIO_DDRB,Copy_u8Pin); break;
		}
		break;
	case PORTC :
		switch(Copy_u8Dir)
		{
			case  PIN_IN: CLR_BIT(MDIO_DDRC,Copy_u8Pin); break;
			case PIN_OUT: SET_BIT(MDIO_DDRC,Copy_u8Pin); break;
		}
		break;
	case PORTD :
		switch(Copy_u8Dir)
		{
			case  PIN_IN: CLR_BIT(MDIO_DDRD,Copy_u8Pin); break;
			case PIN_OUT: SET_BIT(MDIO_DDRD,Copy_u8Pin); break;
		}
		break;
	}
}
void MDIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
		{
		case PORTA :
			switch(Copy_u8Value)
			{
			case  PIN_LOW: CLR_BIT(MDIO_PORTA,Copy_u8Pin); break;
			case PIN_HIGH: SET_BIT(MDIO_PORTA,Copy_u8Pin); break;
			}
			break;
		case PORTB :
			switch(Copy_u8Value)
			{
			case  PIN_LOW: CLR_BIT(MDIO_PORTB,Copy_u8Pin); break;
			case PIN_HIGH: SET_BIT(MDIO_PORTB,Copy_u8Pin); break;
			}
			break;
		case PORTC :
			switch(Copy_u8Value)
			{
			case  PIN_LOW: CLR_BIT(MDIO_PORTC,Copy_u8Pin); break;
			case PIN_HIGH: SET_BIT(MDIO_PORTC,Copy_u8Pin); break;
			}
			break;
		case PORTD :
			switch(Copy_u8Value)
			{
			case  PIN_LOW: CLR_BIT(MDIO_PORTD,Copy_u8Pin); break;
			case PIN_HIGH: SET_BIT(MDIO_PORTD,Copy_u8Pin); break;
			}
			break;
		}
}
u8 MDIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Data;
	switch(Copy_u8Port)
	{
	case PORTA : Local_u8Data = GET_BIT(MDIO_PINA,Copy_u8Pin); break;
	case PORTB : Local_u8Data = GET_BIT(MDIO_PINB,Copy_u8Pin); break;
	case PORTC : Local_u8Data = GET_BIT(MDIO_PINC,Copy_u8Pin); break;
	case PORTD : Local_u8Data = GET_BIT(MDIO_PIND,Copy_u8Pin); break;
	}
	return Local_u8Data;
}

void MDIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Dir)
{
	switch(Copy_u8Port)
	{
	case PORTA: MDIO_DDRA = Copy_u8Dir; break;
	case PORTB: MDIO_DDRB = Copy_u8Dir; break;
	case PORTC: MDIO_DDRC = Copy_u8Dir; break;
	case PORTD: MDIO_DDRD = Copy_u8Dir; break;
	}
}

void MDIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case PORTA: MDIO_PORTA = Copy_u8Value; break;
	case PORTB: MDIO_PORTB = Copy_u8Value; break;
	case PORTC: MDIO_PORTC = Copy_u8Value; break;
	case PORTD: MDIO_PORTD = Copy_u8Value; break;
	}
}

u8 MDIO_u8GetPortValue(u8 Copy_u8Port)
{
	u8 Local_u8Data;
	switch(Copy_u8Port)
	{
	case PORTA : Local_u8Data = MDIO_PORTA; break;
	case PORTB : Local_u8Data = MDIO_PORTB; break;
	case PORTC : Local_u8Data = MDIO_PORTC; break;
	case PORTD : Local_u8Data = MDIO_PORTD; break;
	}
	return Local_u8Data;
}

void MDIO_voidSetPullUpResistor(u8 Copy_u8Port,u8 Copu_u8Pin)
{
	switch (Copy_u8Port)
	{
	case PORTA: SET_BIT(MDIO_PORTA,Copu_u8Pin); break;
	case PORTB: SET_BIT(MDIO_PORTB,Copu_u8Pin); break;
	case PORTC: SET_BIT(MDIO_PORTC,Copu_u8Pin); break;
	case PORTD: SET_BIT(MDIO_PORTD,Copu_u8Pin); break;
	default:                                     break;
	}
}

void MDIO_u8TOGGPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
	case PORTA: TOG_BIT(MDIO_PORTA,Copy_u8Pin); break;
	case PORTB: TOG_BIT(MDIO_PORTB,Copy_u8Pin); break;
	case PORTC: TOG_BIT(MDIO_PORTC,Copy_u8Pin); break;
	case PORTD: TOG_BIT(MDIO_PORTD,Copy_u8Pin); break;
	default:    break;
	}
}

