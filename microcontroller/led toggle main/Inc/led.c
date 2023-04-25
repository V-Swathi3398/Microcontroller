/*
 * led.c
 *
 *  Created on: Apr 5, 2023
 *      Author: swathi
 */

#include "led.h"

void led_init(void)
{
	/* enable clock access to GPIOA */
		RCC_AHB1EN_R |= GPIOAEN;

		/*2.set pa5 as output pin*/
		GPIOA_MODE_R |= (1U<<10); /*  set bit 10 to 1 */
		GPIOA_MODE_R &= ~(1U<<11); /* set bit 11 to 0 */

}

void led_tog(void)
{
	/*3.set pa5 high*/
			//GPIOA_OD_R |= LED_PIN; /* turn on LED */ delayMs(500);

			/*4.experiment 2:toggle pa5*/
			GPIOA_OD_R ^= LED_PIN;

			for(int i=0; i<100000;i++){}
}

