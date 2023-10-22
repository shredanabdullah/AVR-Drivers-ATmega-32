/*
 * adc.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Tobi
 */

#include "common_macros.h"
#include "adc.h"
#include <avr/io.h>

void ADC_init(void){
	SET_BIT(ADMUX,REFS0);/*Reference Selection Bits (AVCC with external capacitor at AREF pin)*/
	CLEAR_BIT(ADMUX,REFS1);

	CLEAR_BIT(ADMUX,MUX0);/*Analog Channel and Gain Selection Bits (0)*/
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX3);
	CLEAR_BIT(ADMUX,MUX4);
	CLEAR_BIT(ADMUX,ADLAR);


	CLEAR_BIT(ADCSRA,ADIE);/*CLEAR ADC Interrupt Enable to zero*/

	SET_BIT(ADCSRA,ADPS0);/*ADC Prescaler Selections Division Factor 128 [ 1 1 1 ]*/
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADEN);/*ADC Enable*/
}
uint16 ADC_readChannel(uint8 ch_num){
	ADMUX = (ADMUX & 0b11100000)| ch_num; /*insert ch_num*/
	SET_BIT(ADCSRA,ADSC);/*ADC Start Conversion*/
	while(BIT_IS_SET(ADCSRA,ADIF)){   /*polling until ADIF=1*/

	}
	SET_BIT(ADCSRA,ADIF);/*clear ADIF flag*/
	return ADC;/*return data*/
}
