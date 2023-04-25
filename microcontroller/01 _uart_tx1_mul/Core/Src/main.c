#include"uart.h"

int main()
{

	uart2_init();
	while(1)
	{
		uart2_write('y');


	}
	return 0;
}
