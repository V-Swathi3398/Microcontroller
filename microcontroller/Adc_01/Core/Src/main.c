#include "adc.h"
#include <stdint.h>

uint32_t v = 0;

int main()
{
	pa1_adc_init();
	start_converstion();

	while(1)
	{

	    v = adc_read();

	}
	return 0;
}
