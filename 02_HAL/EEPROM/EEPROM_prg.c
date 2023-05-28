/*
 * EEPROM_prg.c
 *
 *  Created on: Apr 19, 2023
 *      Author: D E L L
 */

#include "TWI_int.h"
#include "STD.h"
#include "EEPROM_prv.h"
#include "EEPROM_cfg.h"
#include "EEPROM_int.h"
#include "util/delay.h"

void HEEPROM_voidWriteDataByte(u16 Copy_u8Address,u8 Copy_u8WriteData)
{
	MTWI_voidSendStartCondition();
	MTWI_voidSendSlaveAddressWrite( ((0x50 |(0 << 3)| (Copy_u8Address >> 7)) << 1) );
	MTWI_voidMSTRWriteDataByte( ((u8) Copy_u8WriteData) );
	MTWI_voidMSTRWriteDataByte(Copy_u8WriteData);
	MTWI_voidStopCondition();
	_delay_ms(10);
}
void HEEPROM_voidReadDataByte(u16 Copy_u8Address,u8 *Copy_pu8ReadData)
{
	MTWI_voidSendStartCondition();
	MTWI_voidSendSlaveAddressWrite( (0x50 | (0 << 3) | Copy_u8Address >> 7) << 1);
	MTWI_voidMSTRWriteDataByte((u8) Copy_u8Address);
	MTWI_voidSendRepeatedStart();
	MTWI_voidSendSlaveAddressRead( (0x50 | (0 << 3) | Copy_u8Address >> 7) << 1);
	MTWI_voidMSTRReadDataByte(Copy_pu8ReadData);
	_delay_ms(10);
}

