#include"tim2.h"

void tim2_1hz_init(void)
{
	/*Enable clock access to tim2*/
	RCC->APB1ENR |= TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC = 16000-1;

	/*Set auto-reload value*/
	TIM2->ARR = 10000-1;

	/*Clear counter*/
	TIM2->CNT = 0;

	/*Enable timer*/
	TIM2->CR1 |= CR1_CEN;

	/*.Enable clock access to GPIOA*/
				RCC->AHB1ENR |= GPIOAEN;

			/*Set PA5 as output pin*/
						GPIOA->MODER |= (1U<<10);
						tim_delay();
						GPIOA->MODER &= ~(1U<<11);
						tim_delay();

						GPIOA->ODR ^= LED_PIN;

}

void tim_delay(void)
{

       /*Wait for UIF */
	while(!(TIM2->SR & SR_UIF)){}

	/*Clear UIF*/
	TIM2->SR &=~SR_UIF;

}
