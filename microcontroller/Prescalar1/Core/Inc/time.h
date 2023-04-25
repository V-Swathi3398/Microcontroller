#ifndef INC_TIME_H_
#define INC_TIME_H_

#include<stm32f4xx.h>

#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define SR_UIF        (1U<<0)

void tim2_1hz_init(void);
void tim_delay(void);


#endif /* INC_TIME_H_ */
