/*
 * TWI_prv.h
 *
 *  Created on: Apr 19, 2023
 *      Author: D E L L
 */

#ifndef TWI_TWI_PRV_H_
#define TWI_TWI_PRV_H_


/*REGISTERS ADDRESS*/
#define TWBR_REG         (*((volatile u8*)0x20))
#define TWCR_REG         (*((volatile u8*)0x56))
#define TWDR_REG         (*((volatile u8*)0x23))
#define TWAR_REG         (*((volatile u8*)0x22))
#define TWSR_REG         (*((volatile u8*)0x21))

/*TWSR*/
#define TWPS0_BIT        0
#define TWPS1_BIT        1

/*TWCR*/
#define TWINT_BIT           7
#define  TWEA_BIT           6
#define TWSTA_BIT           5
#define TWSTO_BIT           4
#define  TWEN_BIT           2
#define  TWIE_BIT           0

/*TWDR*/
#define  TWD0_BIT           0


#endif /* TWI_TWI_PRV_H_ */
