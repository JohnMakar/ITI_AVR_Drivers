/*
 * EEPROM_int.h
 *
 *  Created on: Apr 19, 2023
 *      Author: D E L L
 */

#ifndef EEPROM_EEPROM_INT_H_
#define EEPROM_EEPROM_INT_H_

/* PROTOTYPES */
void HEEPROM_voidWriteDataByte(u16 Copy_u8Address,u8 Copy_u8WriteData);
void HEEPROM_voidReadDataByte(u16 Copy_u8Address,u8 *Copy_pu8ReadData);

#endif /* EEPROM_EEPROM_INT_H_ */
