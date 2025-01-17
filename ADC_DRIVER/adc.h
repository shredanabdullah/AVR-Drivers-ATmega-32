/*
 * adc.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Tobi
 */

#ifndef ADC_H_
#define ADC_H_

//#include "std_types.h"
//
//#define ADC_REF_VOLTAGE     5
//#define ADC_MAXIMUM_VALUE   1023
//
/////* Extern Public global variables to be used by other modules */
////extern volatile uint16 g_ADC_RETURN_VALU;
//

//
//typedef enum{
//	two1,two2,four,eight,sixteen,thirty_two,sixty_four,one_hundred_twenty_eight
//}ADC_Prescaler;
//
//typedef struct{
//	ADC_ReferenceVoltage ref_volt;
//	ADC_Prescaler prescaler;
//}ADC_ConfigType;
//void ADC_init(const ADC_ConfigType* Config_Ptr);
//uint16 ADC_readChannel(uint8 ch_num);
////void ADC_readChannel(uint8 ch_num);


#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Parameters Definitions */
#define ADC_REF_VOLTAGE                    2.56
#define ADC_MAXIMUM_VALUE                  1023

/*******************************************************************************
 *                               Enumerations                                  *
 *******************************************************************************/
typedef enum{
	AREF_Internal_Vref_turned_off, AVCC_with_external_capacitor, Internal_2_56V_Voltage_Reference=3
}ADC_ReferenceVoltage;

typedef enum{
	FCPU_2 = 1, FCPU_4, FCPU_8, FCPU_16, FCPU_32, FCPU_64, FCPU_128
} ADC_Prescaler;

/*******************************************************************************
 *                      Structures And Unions                                  *
 *******************************************************************************/
typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC peripheral.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel (uint8 channelNum);

/*
 * Description :
 * Function responsible for de-initialize the ADC peripheral.
 */
void ADC_deinit (void);

#endif /* ADC_H_ */
