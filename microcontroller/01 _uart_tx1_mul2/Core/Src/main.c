#include"uart.h"

int main()
{
	uart2_init();
	while(1)
	{
		uart2_write("Hello world\n");
		GPIOA->ODR |= 0x00000030;
		systickDelayMs(500);
		GPIOA->ODR &= ~0x00000020;
		systickDelayMs(500);

	}
}
