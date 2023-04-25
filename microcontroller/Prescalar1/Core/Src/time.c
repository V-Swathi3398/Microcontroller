#include"time.h"

void tim2_1hz_init(void)
{
	//Enable clock access to tim2/
	RCC->APB1ENR |= TIM2EN;

	//Enable clock access to AHB prescalar/
		RCC->CFGR |= (1U<<7);

	//Set prescaler value/
	TIM2-> PSC = 200;

	//Set auto-reload value/
	TIM2-> ARR = 10000-1;

	//Clear counter/
	TIM2-> CNT = 0;

	//Enable timer/
	TIM2-> CR1 |= CR1_CEN;
}

void tim_delay(void)
{

       /*Wait for UIF */
	while(!(TIM2->SR & SR_UIF)){}

	//Clear UIF/
	TIM2->SR &=~SR_UIF;

}
