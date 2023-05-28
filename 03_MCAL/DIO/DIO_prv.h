/*
 * DIO_prv.h
 *
 *  Created on: Mar 21, 2023
 *      Author: D E L L
 */

#ifndef DIO_DIO_PRV_H_
#define DIO_DIO_PRV_H_

/**********  PORTA REGISTERS  **********/
#define MDIO_PORTA    (*((volatile u8*)0x3B))
#define  MDIO_DDRA    (*((volatile u8*)0x3A))
#define  MDIO_PINA    (*((volatile u8*)0x39))

/************  PORTB REGISTERS  ************/
#define MDIO_PORTB    (*((volatile u8*)0x38))
#define  MDIO_DDRB    (*((volatile u8*)0x37))
#define  MDIO_PINB    (*((volatile u8*)0x36))

/************  PORTC REGISTERS  ************/
#define MDIO_PORTC    (*((volatile u8*)0x35))
#define  MDIO_DDRC    (*((volatile u8*)0x34))
#define  MDIO_PINC    (*((volatile u8*)0x33))

/************ PORTD REGISTERS  **************/
#define MDIO_PORTD    (*((volatile u8*)0x32))
#define  MDIO_DDRD    (*((volatile u8*)0x31))
#define  MDIO_PIND    (*((volatile u8*)0x30))



#endif /* DIO_DIO_PRV_H_ */
