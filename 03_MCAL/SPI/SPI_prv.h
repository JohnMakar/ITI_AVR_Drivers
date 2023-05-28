/*
 * SPI_prv.h
 *
 *  Created on: Apr 6, 2023
 *      Author: D E L L
 */

#ifndef SPI_SPI_PRV_H_
#define SPI_SPI_PRV_H_


#define SPI_MASTER_MODE                1
#define SPI_SLAVE_MODE                 2



/*REGISTER ADDRESS*/
#define SPCR_REG                     (*((volatile u8*)0x2D ))
#define SPDR_REG                     (*((volatile u8*)0x2F ))
#define SPSR_REG                     (*((volatile u8*)0x2E ))


/*SPSR_REG*/
#define SPIF_BIT                       7

/*SPCR_REG*/
#define  SPE_BIT                       6
#define DORD_BIT                       5
#define MSTR_BIT                       4
#define SPR1_BIT                       1
#define SPR0_BIT                       0



#endif /* SPI_SPI_PRV_H_ */
