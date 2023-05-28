/*
 * BitMath.h
 *
 *  Created on: Mar 21, 2023
 *      Author: D E L L
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define NULLPTR (void *)0
#define SET_BIT(VAR,BITNO) ((VAR) |= (1 << (BITNO)))
#define CLR_BIT(VAR,BITNO) ((VAR) &=~(1 << (BITNO)))
#define TOG_BIT(VAR,BITNO) ((VAR) ^= (1 << (BITNO)))
#define GET_BIT(VAR,BITNO) ( ((VAR) >> (BITNO)) & 1)

#endif /* BITMATH_H_ */
