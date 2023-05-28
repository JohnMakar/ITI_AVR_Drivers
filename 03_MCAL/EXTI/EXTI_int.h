/*
 * EXTI_int.h
 *
 *  Created on: Mar 30, 2023
 *      Author: D E L L
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_

#include "STD.h"

#define EXTI_INT2_ID  5
#define EXTI_INT0_ID  6
#define EXTI_INT1_ID  7
/*************************** TRIGGERS DEFINES ****************************/
#define EXTI_TRG_LOW_LEVEL  	0
#define EXTI_TRG_ANY_CHANGE 	1
#define EXTI_TRG_FALLING_EDGE 	2
#define EXTI_TRG_RAISING_EDGE 	3


/***************************** PROTOTYPES ****************************/
void MEXTI_void_EXTIEnable(u8 Copy_u8IntID,u8 Copy_u8Trigg);
void MEXTI_void_EXTIDisable(u8 Copy_u8IntID);
void EXTI0_SetCallBack(void (*ptr)(void));
void EXTI1_SetCallBack(void (*ptr)(void));
void EXTI2_SetCallBack(void (*ptr)(void));

#endif /* EXTI_EXTI_INT_H_ */
