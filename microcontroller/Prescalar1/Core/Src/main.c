#include"time.h"

int main()
{
	tim2_1hz_init();
	tim_delay();

	RCC->AHB1ENR |= 1; /* enable GPIOA clock */
	GPIOA->MODER &= ~0x00000C00; /* clear pin mode */
	GPIOA->MODER |= 0x00000400; /* set pin to output mode */

	while(1)
	{

		GPIOA->ODR |= 0x00000020; /* turn on LED */
		tim_delay();
		GPIOA->ODR &= ~0x00000020; /* turn off LED */
		tim_delay();

	}
}
