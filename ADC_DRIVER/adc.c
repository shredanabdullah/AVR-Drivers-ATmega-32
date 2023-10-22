/*
 * adc.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Tobi
 */

#include "adc.h"
#include "common_macros.h"
#include "std_types.h"
#include <avr/io.h>


//volatile uint16 g_ADC_RETURN_VALU = 0;

//
//void ADC_init(void){
//	SET_BIT(ADMUX,REFS0);/*Reference Selection Bits (AVCC with external capacitor at AREF pin)*/
//	CLEAR_BIT(ADMUX,REFS1);
//
//	CLEAR_BIT(ADMUX,MUX0);/*Analog Channel and Gain Selection Bits (0)*/
//	CLEAR_BIT(ADMUX,MUX1);
//	CLEAR_BIT(ADMUX,MUX2);
//	CLEAR_BIT(ADMUX,MUX3);
//	CLEAR_BIT(ADMUX,MUX4);
//	CLEAR_BIT(ADMUX,ADLAR);
//
//
//	//CLEAR_BIT(ADCSRA,ADIE);/*CLEAR ADC Interrupt Enable to zero*/
//	SET_BIT(ADCSRA,ADIE);/*CLEAR ADC Interrupt Enable to one*/
//
//	SET_BIT(ADCSRA,ADPS0);/*ADC Prescaler Selections Division Factor 128 [ 1 1 1 ]*/
//	SET_BIT(ADCSRA,ADPS1);
//	SET_BIT(ADCSRA,ADPS2);
//	SET_BIT(ADCSRA,ADEN);/*ADC Enable*/
//}
//uint16 ADC_readChannel(uint8 ch_num){
//	ADMUX = (ADMUX & 0b11100000)| ch_num; /*insert ch_num*/
//	SET_BIT(ADCSRA,ADSC);/*ADC Start Conversion*/
//	while(BIT_IS_SET(ADCSRA,ADIF)){   /*polling until ADIF=1*/
//
//	}
//	SET_BIT(ADCSRA,ADIF);/*clear ADIF flag*/
//	return ADC;/*return data*/
//}
//
////ISR(ADC_vect){
////	g_ADC_RETURN_VALU=ADC;
////}
////void ADC_readChannel(uint8 ch_num){
////	ADMUX = (ADMUX & 0b11100000)| ch_num; /*insert ch_num*/
////	SET_BIT(ADCSRA,ADSC);/*ADC Start Conversion*/
////}
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* Puts the input value of Vref in ADMUX register last 2 bits */
	ADMUX = (ADMUX & 0x3F) | (((Config_Ptr -> ref_volt) & 0x03) << 6);

	/* Puts the input value of prescaler in ADCSRA register first 3 bits */
	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr -> prescaler) & 0x07);

	SET_BIT (ADCSRA, ADEN);           /* Enables the ADC peripheral */
}

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel (uint8 channelNum)
{
	ADMUX = (ADMUX & 0xE0) | (channelNum & 0x07);   /* Selects the ADC channel and puts it in ADMUX register */
	SET_BIT (ADCSRA, ADSC);  			   		    /* Start the conversion for this channel */
	while (BIT_IS_CLEAR (ADCSRA, ADIF)); 	        /* polling on the flag until the conversion is done */
	SET_BIT (ADCSRA, ADIF);    				        /* Reset the flag by putting logic high */
	return (ADC & 0x03FF);     					    /* Returning the digital value after conversion */
}

/*
 * Function responsible for de-initialize the ADC peripheral.
 */
void ADC_deinit (void)
{	/* Clear the whole ADC registers */
	ADMUX = 0;
	ADCSRA = 0;

	CLEAR_BIT (ADCSRA, ADEN);/* De-enable the ADC peripheral */
}
