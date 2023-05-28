/*
 * SPI_int.h
 *
 *  Created on: Apr 6, 2023
 *      Author: D E L L
 */

#ifndef SPI_SPI_INT_H_
#define SPI_SPI_INT_H_
#include "STD.h"

void MSPI_voidInit(void);
void MSPI_voidTransmitData(u8 Copy_u8Data);
u8   MSPI_u8ReceiveData(void);

#endif /* SPI_SPI_INT_H_ */
