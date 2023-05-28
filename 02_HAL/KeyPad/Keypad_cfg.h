/*
 * Keypad_cfg.h
 *
 *  Created on: Mar 25, 2023
 *      Author: D E L L
 */

#ifndef KEYPAD_KEYPAD_CFG_H_
#define KEYPAD_KEYPAD_CFG_H_


/************************************************************
 * KPD PORT:
 * PORTA , PORTB , PORTC , PORTD
 * *********************************************************/
#define KPD_PORT    PORTA

/************************ROWS PINS*************************/
#define KPD_PIN_R0  PIN0
#define KPD_PIN_R1  PIN1
#define KPD_PIN_R2  PIN2
#define KPD_PIN_R3  PIN3

/***********************COLUMN PINS*************************/
#define KPD_PIN_C0  PIN4
#define KPD_PIN_C1  PIN5
#define KPD_PIN_C2  PIN6
#define KPD_PIN_C3  PIN7


/********************** ColumnsNumber ************************/
#define COLUMNS_NUM 4

/*********************** RowsNumber **************************/
#define ROWS_NUM    4

/*Select KDP_MODE:
 * CalculatorMode , NumberMODE
 * */
#define CALCULATOR_VAL  {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'&',0,'=','+'}}
#define     KEYPAD_VAL  {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}

#endif /* KEYPAD_KEYPAD_CFG_H_ */
