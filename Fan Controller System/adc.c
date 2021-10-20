/*
 * Module: ADC
 *
 * File name: adc.c
 *
 *  Created on: Oct 6, 2021
 *
 *  Author: Nadeen Magdy
 */


#include "common_macros.h"
#include "std_types.h"
#include "avr/io.h"
#include "adc.h"

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = 0;
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr -> ref_volt)<<6); // VREF = INTERNAL 2.56

	SET_BIT(ADCSRA, ADEN); //ENABLE ADC
	CLEAR_BIT(ADCSRA, ADIE); // DISABLE INTERRUPT
	// PRESCALER = 8
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr -> prescaler);

}

uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07); //ADMUX = CH_NUM
	SET_BIT(ADCSRA, ADSC); //START CONVERSION

	while(BIT_IS_CLEAR(ADCSRA,ADIF)); //POLLING

	SET_BIT(ADCSRA, ADIF); //CLEAR THE FLAG

	return ADC; //READ THE DATA
}
