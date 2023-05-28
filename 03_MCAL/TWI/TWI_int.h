/*
 * TWI_int.h
 *
 *  Created on: Apr 19, 2023
 *      Author: D E L L
 */

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_
#include "STD.h"


/* PROTOTYPES */
void MTWI_voidMSTRInit(u8 Copy_u8MSTRAddress);
void MTWI_voidSLVEInit(u8 Copy_u8SLVEAddress);
void MTWI_voidSendStartCondition(void);
void MTWI_voidSendRepeatedStart(void);
void MTWI_voidSendSlaveAddressWrite(u8 Copy_u8SLVEAddress);
void MTWI_voidSendSlaveAddressRead(u8 Copy_u8SLVEAddress);
void MTWI_voidMSTRWriteDataByte(u8 Copy_u8WriteData);
void MTWI_voidMSTRReadDataByte(u8 *Copy_Pu8ReadData);
void MTWI_voidStopCondition(void);

#endif /* TWI_TWI_INT_H_ */
