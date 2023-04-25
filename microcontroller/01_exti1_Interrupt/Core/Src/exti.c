#include "exti.h"


void pc13_exti_init(void)
{
	/*Disable global interrupts*/
	__disable_irq();

	/*Enable clock access for GPIOC*/
	RCC->AHB1ENR |= GPIOCEN;

	/*Set PC13 as input*/
	GPIOC->MODER &= ~(3U<<26);

	/*Enable clock access to SYSCFG*/
	RCC->APB2ENR |= SYSCFGEN;

	/*Select PORTC for EXTI13*/
	SYSCFG->EXTICR[3] |= (1U<<5);

	/*Unmask EXTI13*/
	EXTI->IMR |= (1U<<13);

	/*Select falling edge trigger*/
	EXTI->FTSR  |= (1U<<13);

	/*Enable EXTI13 line in NVIC*/
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	/*Enable global interrupts*/
	__enable_irq();

	/*1.Enable clock access to GPIOA*/
			RCC->AHB1ENR |= GPIOAEN;

			/*2.Set PA5 as output pin*/
			GPIOA->MODER |= (1U<<10);
			GPIOA->MODER &=~(1U<<11);


}

void EXTI15_10_IRQHandler(void) {
	if((EXTI->PR & LINE13)!=0)
	{
		/*Clear PR flag*/
		EXTI->PR |=LINE13;
		//Do something...
		exti_callback();
	}

}
static void exti_callback(void)
{
	//printf("BTN Pressed...\n\r");
	GPIOA->ODR ^=LED;
}


