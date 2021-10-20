/*
 * motor.c
 *
 *  Created on: Oct 6, 2021
 *      Author: HERO
 */


#include "common_macros.h"
#include "std_types.h"
#include "avr/io.h"
#include "PWM.h"
#include "motor.h"
#include "gpio.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_INPUT_PIN1, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_INPUT_PIN2, PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_INPUT_PIN1, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_INPUT_PIN2, LOGIC_LOW);

}


void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_INPUT_PIN1, (state >> DC_MOTOR_INPUT_PIN1));
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_INPUT_PIN2, (state >> DC_MOTOR_INPUT_PIN2));
	PWM_Timer0_Init(speed);
}
