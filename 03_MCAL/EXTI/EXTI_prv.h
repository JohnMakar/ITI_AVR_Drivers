/*
 * EXTI_prv.h
 *
 *  Created on: Mar 30, 2023
 *      Author: D E L L
 */

#ifndef EXTI_EXTI_PRV_H_
#define EXTI_EXTI_PRV_H_

/************* EXTERNAL INTERRUPT REGISTERS *******************/
#define      S_REG          (*((volatile u8*)0x5F))
#define  MCUCR_REG          (*((volatile u8*)0x55))
#define MCUCSR_REG          (*((volatile u8*)0x54))
#define   GICR_REG          (*((volatile u8*)0x5B))

//SREG
#define GIE_BIT         7

//GICR
#define INT1_BIT		7	//IE of EXT1
#define INT0_BIT		6	//IE of EXT0
#define INT2_BIT		5	//IE of EXT2

//MCUCR
#define ISC00_BIT		0 	//INT0 SENSE CONTROL 0
#define ISC01_BIT		1   //INT0 SENSE CONTROL 1

#define ISC10_BIT		2   //INT1 SENSE CONTROL 0
#define ISC11_BIT		3   //INT1 SENSE CONTROL 1

#define ISC2_BIT		6
#endif /* EXTI_EXTI_PRV_H_ */
