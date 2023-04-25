#include"pwm.h"

void pwm_init(void)
{

	 /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA5 mode to alternate function*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	/*Set PA5 alternate function type to TIM2_CH1 (AF01)*/
	GPIOA->AFR[0] |=AFR5_TIM;

	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000

	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	/*Set output compare toggle mode ccmr1*/
    	 TIM2->CCMR1 |= 0x30;

	/*Enable tim2 ch1 in compare mode ccer*/
     TIM2->CCER |= 0x1;

     /* pulse width 1/3 of the period */
     TIM2->CCR1 = 2000;

	/*Clear counter*/
	TIM2->CNT = 0;
	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;
}
