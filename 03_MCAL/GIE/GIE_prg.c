/*
 * GIE_prg.c
 *
 *  Created on: Apr 19, 2023
 *      Author: D E L L
 */
#include "GIE_int.h"
#include "GIE_prv.h"
#include "GIE_cfg.h"
#include "BitMath.h"

void MGIE_voidEnable(void)
{
	//SET_BIT(S_REG,GIE_BIT);
	/*USING ASSEMBLE*/
	asm("SEI");
}
void MGIE_voidDisable(void)
{
	//CLR_BIT(S_REG,GIE_BIT);
	/*USING ASSEMBLE*/
	asm("CLI");
}
