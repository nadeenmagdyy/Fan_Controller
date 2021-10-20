/*
 * Module: Temperature sensor LM35
 *
 * File name: lm35.c
 *
 *  Created on: Oct 6, 2021
 *  Author: Nadeen Magdy
 */

#include "lm35.h"
#include "adc.h"


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	uint16 adcResult = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adcResult*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
