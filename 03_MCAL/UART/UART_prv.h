/*
 * UART_prv.h
 *
 *  Created on: Apr 4, 2023
 *      Author: D E L L
 */

#ifndef UART_UART_PRV_H_
#define UART_UART_PRV_H_

#define UCSRA_REG            (*((volatile u8*)0x2B))
#define UCSRB_REG            (*((volatile u8*)0x2A))
#define UCSRC_REG            (*((volatile u8*)0x40))
#define   UDR_REG            (*((volatile u8*)0x2C))
#define  UBRR_REG
#define UBRRL_REG            (*((volatile u8*)0x29))
#define UBRRH_REG            (*((volatile u8*)0x40))

/*UCSRA*/
#define MPCM_BIT             0
#define  U2X_BIT             1
#define   PE_BIT             2
#define  DOR_BIT             3
#define   FE_BIT             4
#define UDRE_BIT             5
#define  TXC_BIT             6
#define  RXC_BIT             7

/*UCSRB*/
#define  TXB8_BIT            0
#define  RXB8_BIT            1
#define UCSZ2_BIT            2
#define  TXEN_BIT            3
#define  RXEN_BIT            4
#define UDRIE_BIT            5
#define TXCIE_BIT            6
#define RXCIE_BIT            7

/*UCSRC*/
#define UCPOL_BIT            0
#define UCSZ0_BIT            1
#define UCSZ1_BIT            2
#define  USBS_BIT            3
#define  UPM0_BIT            4
#define  UPM1_BIT            5
#define UMSEL_BIT            6
#define URSEL_BIT            7

#define UART_POLLING_TIME        2000000
#define UART_FINISHED_TRAMITTING 1

#endif /* UART_UART_PRV_H_ */
