/*
 * SM_int.h
 *
 *  Created on: Mar 29, 2023
 *      Author: D E L L
 */

#ifndef STEPPER_MOTOR_SM_INT_H_
#define STEPPER_MOTOR_SM_INT_H_
#include "STD.h"


#define  STEPPER_INIT_ITERATION  0
#define STEPPER_TOTAL_ITERATION  512

void HStepperMotor_voidStepperInit(void);
void HStepperMOTOR_voidStepperFullStepCW(void);
void HStepperMOTOR_voidStepperFullStepCCW(void);
void HStepperMOTOR_voidStepperSpecificDegreeCW(u8 Copy_u8Degree);
void HStepperMOTOR_voidStepperSpecificDegreeCCW(u8 Copy_u8Degree);



#endif /* STEPPER_MOTOR_SM_INT_H_ */
