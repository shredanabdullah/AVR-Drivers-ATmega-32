/*
 * main.c
 *
 *  Created on: ٣٠‏/٠٩‏/٢٠٢٣
 *      Author: Tobi
 */


#include "lcd.h"

int main(void){
	LCD_init();
	//LCD_SendData('A');
	LCD_displayString("shery");
	while(1){



	}
	return 0;
}
