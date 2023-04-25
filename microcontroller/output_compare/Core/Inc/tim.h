
#ifndef INC_TIM_H_
#define INC_TIM_H_

#include "stm32f4xx.h"



#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)


#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)

void tim2_pa5_output_compare(void);

#endif /* INC_TIM_H_ */


