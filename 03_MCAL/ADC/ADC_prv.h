/*
 * ADC_prv.h
 *
 *  Created on: Apr 1, 2023
 *      Author: D E L L
 */

#ifndef ADC_ADC_PRV_H_
#define ADC_ADC_PRV_H_

/**********REGISTERS ADDRESS*****************/
#define  ADMUX_REG       (*((volatile u8*)0x27))
#define ADCSRA_REG       (*((volatile u8*)0x26))
#define  SFIOR_REG       (*((volatile u8*)0x50))
#define   ADCH_REG       (*((volatile u16*)0x25))
#define   ADCL_REG       (*((volatile u16*)0x24))
/********** ADMUX *************/
#define REFS1_BIT   7
#define REFS0_BIT   6
#define ADLAR_BIT   5

/********** ADCSRA *************/
#define  ADEN_BIT   7
#define  ADSC_BIT   6
#define ADATE_BIT   5
#define  ADIF_BIT   4
#define  ADIE_BIT   3
#define ADPS2_BIT   2
#define ADPS1_BIT   1
#define ADPS0_BIT   0

/*********** SFIOR **************/
#define ADTS2_BIT  7
#define ADTS1_BIT  6
#define ADTS0_BIT  5

/*Voltage*/
#define V_AREF     1
#define V_AVCC     2
#define RESERVED   3
#define INTERNAL   4


/*MUX_BITS*/
#define MUX0_BIT 0
#define MUX1_BIT 1
#define MUX2_BIT 2
#define MUX3_BIT 3
#define MUX4_BIT 4
#endif /* ADC_ADC_PRV_H_ */
