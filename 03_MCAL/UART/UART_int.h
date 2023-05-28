/*
 * UART_int.h
 *
 *  Created on: Apr 4, 2023
 *      Author: D E L L
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_
#include "STD.h"

void MUART_voidInit(void);
void MUART_voidTransmitDataSync(u8 Copy_u8Data);
u8   MUART_u8ReceiveDataSync(void);

#endif /* UART_UART_INT_H_ */
