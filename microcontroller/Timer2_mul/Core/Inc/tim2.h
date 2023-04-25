/*
 * tim2.h
 *
 *  Created on: Apr 17, 2023
 *      Author: swathi
 */

#ifndef INC_TIM2_H_
#define INC_TIM2_H_

#include"stm32f4xx.h"

#define TIM2EN		(1U<<0)
#define CR1_CEN	    (1U<<0)
#define SR_UIF      (1U<<0)

#define GPIOAEN				(1U<<0)

#define PIN5				(1U<<5)
#define LED_PIN				 PIN5

void tim2_1hz_init(void);
void tim_delay(void);


#endif /* INC_TIM2_H_ */
