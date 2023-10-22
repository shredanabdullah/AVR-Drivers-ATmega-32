/*
 * adc.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Tobi
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_REF_VOLTAGE     5
#define ADC_MAXIMUM_VALUE   1023


void ADC_init(void);
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
