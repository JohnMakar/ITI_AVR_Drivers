/*
 * SSD_prg.c
 *
 *  Created on: Mar 24, 2023
 *      Author: D E L L
 */

#include "SSD_cfg.h"
#include "SSD_prv.h"
#include "SSD/SSD_int.h"
#include "DIO/DIO_int.h"



void HSSD_void_SSDInit(void)
{
	/*ENABLE SSD PINS DIRECTION*/
	MDIO_voidSetPortDirection(HSSD_PORT,PORT_OUT);

	/*SET SSD PINS VALUE*/
	MDIO_voidSetPortValue(HSSD_PORT,PORT_LOW);
}
void HSSD_void_DisplayNumber(u8 Copy_u8Number)
{
	switch(Copy_u8Number)
	{
	case 0: MDIO_voidSetPortValue(HSSD_PORT,zero_cath);  break;
	case 1: MDIO_voidSetPortValue(HSSD_PORT,one_cath);   break;
	case 2: MDIO_voidSetPortValue(HSSD_PORT,two_cath);   break;
	case 3: MDIO_voidSetPortValue(HSSD_PORT,three_cath); break;
	case 4: MDIO_voidSetPortValue(HSSD_PORT,four_cath);  break;
	case 5: MDIO_voidSetPortValue(HSSD_PORT,five_cath);  break;
	case 6: MDIO_voidSetPortValue(HSSD_PORT,six_cath);   break;
	case 7: MDIO_voidSetPortValue(HSSD_PORT,seven_cath); break;
	case 8: MDIO_voidSetPortValue(HSSD_PORT,eight_cath); break;
	case 9: MDIO_voidSetPortValue(HSSD_PORT,nine_cath);  break;
    default:            /*DO NOTHING*/                       break;
	}
}


