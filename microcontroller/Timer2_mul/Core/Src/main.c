#include"tim2.h"


int main()
{
	tim2_1hz_init();

	while(1)
	{

		GPIOA->ODR ^= LED_PIN;
		tim_delay();

	}
	return 0;
}
