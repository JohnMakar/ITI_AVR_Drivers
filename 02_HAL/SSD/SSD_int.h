/*
 * SSD_int.h
 *
 *  Created on: Mar 24, 2023
 *      Author: D E L L
 */

#ifndef SSD_SSD_INT_H_
#define SSD_SSD_INT_H_
#include "STD.h"



typedef enum
{
	zero_cath  = 0b0111111,
	one_cath   = 0b00000110,
	two_cath   = 0b1011011,
	three_cath = 0b1001111,
	four_cath  = 0b1100110,
	five_cath  = 0b1101101,
	six_cath   = 0b1111101,
	seven_cath = 0b0000111,
	eight_cath = 0b1111111,
	nine_cath  = 0b1100111,
}CATHODE;



void HSSD_void_SSDInit(void);
void HSSD_void_DisplayNumber(u8 Copy_u8Number);

#endif /* SSD_SSD_INT_H_ */
