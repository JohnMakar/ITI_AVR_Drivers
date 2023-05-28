/*
 * PushButton_prg.c
 *
 *  Created on: Mar 31, 2023
 *      Author: D E L L
 */


#include "PushButton_int.h"
#include "PushButton_cfg.h"
#include "PushButton_prv.h"
#include "DIO/DIO_int.h"

#include <util/delay.h>

void HPushButton_voidInit(void)
{
	MDIO_voidSetPinDirection(PUSHBUTTON_PORT,PUSHBUTTON_PIN,PIN_IN);

}
u8   HPushButton_u8Read(void)
{
	u8 Local_u8Value = PUSHBUTTON_RELEASED;
	if(MDIO_u8GetPinValue(PUSHBUTTON_PORT,PUSHBUTTON_PIN) == PUSHBUTTON_PRESSED)
	{
		_delay_ms(120);
		if(MDIO_u8GetPinValue(PUSHBUTTON_PORT,PUSHBUTTON_PIN) == PUSHBUTTON_PRESSED)
		{
			Local_u8Value = PUSHBUTTON_PRESSED;
			/*wait until stop pressing the button*/
			while(MDIO_u8GetPinValue(PUSHBUTTON_PORT,PUSHBUTTON_PIN) == PUSHBUTTON_PRESSED);
		}
	}
	return Local_u8Value;
}
