#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f4xx.h"



#define GPIOAEN				   (1U<<0)
#define PIN5				   (1U<<5)
#define LED				   		PIN5
#define 	LINE13		(1U<<13)
#define        GPIOCEN		(1U<<2)
#define        SYSCFGEN		(1U<<14)

void EXTI15_10_IRQHandler(void);
void pc13_exti_init(void);
static void exti_callback(void);

#endif /* INC_EXTI_H_ */
