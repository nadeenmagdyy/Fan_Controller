/*
 * Module: ADC
 *
 * File name: adc.h
 *
 *  Created on: Oct 6, 2021
 *      Author: HERO
 */

#ifndef ADC_H_
#define ADC_H_
#include "common_macros.h"
#include "std_types.h"
#include "avr/io.h"

#define ADC_MAXIMUM_VALUE 1023
#define ADC_REF_VOLT_VALUE 2.56

typedef enum
{
	AREF = 0b00 ,AVCC = 0b01 ,RESERVED = 0b10 ,INTERNAL = 0b11
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_2 = 0b001, F_CPU_4 = 0b010, F_CPU_8 = 0b011, F_CPU_16 = 0b100, F_CPU_32 = 0b101, F_CPU_64 = 0b110, F_CPU_128 = 0b111
}ADC_Prescaler;

typedef struct{
	 ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
