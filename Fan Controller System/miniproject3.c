/*
 * File name: miniproject3.c
 *
 *  Created on: Oct 6, 2021
 *
 *  Author: Nadeen Magdy
 */


#include "adc.h"
#include "lcd.h"
#include "lm35.h"
#include "motor.h"

int main (void)
{
	uint8 temp = 0;
	ADC_ConfigType ADC_Config = {INTERNAL,F_CPU_8};
	ADC_init(&ADC_Config);

	LCD_init();
	DcMotor_Init();

	LCD_displayStringRowColumn(0, 4, "FAN is ");
	LCD_moveCursor(1,4);

	LCD_displayString("TEMP =    C");

	while(1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(0,11);
		if(temp < 30)
		{
			DcMotor_Rotate(Stop, 0);
			LCD_displayString("OFF");
		}
		else if(temp >=30 && temp < 60)
		{
			DcMotor_Rotate(Clockwise, 25);
			LCD_displayString("ON");
		}

		else if(temp >=60 && temp < 90)
		{
			DcMotor_Rotate(Clockwise, 50);
			LCD_displayString("ON");
		}

		else if(temp >=90 && temp < 120)
		{
			DcMotor_Rotate(Clockwise, 75);
			LCD_displayString("ON");
		}

		else if(temp >=120)
		{
			DcMotor_Rotate(Clockwise, 100);
			LCD_displayString("ON");
		}

		LCD_moveCursor(1,11);

		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}

		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}

	}


}
