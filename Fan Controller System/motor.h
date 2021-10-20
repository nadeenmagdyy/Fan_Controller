/*
 * motor.h
 *
 *  Created on: Oct 6, 2021
 *      Author: HERO
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "common_macros.h"
#include "std_types.h"
#include "avr/io.h"
#include "PWM.h"

#define DC_MOTOR_PORT	 		PORTB_ID
#define DC_MOTOR_INPUT_PIN1		PIN0_ID
#define DC_MOTOR_INPUT_PIN2 	PIN1_ID

typedef enum
{
	Stop, Anticlockwise, Clockwise
}DcMotor_State;


void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
