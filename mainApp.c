#include "stm32f4xx_gpio.h"

void ConfigGPIO(void);
void ConfigADC(void);
unsigned int readADC1(unsigned char channel);
unsigned int val_conv;

int main()
{
	 ConfigADC();
	 ConfigGPIO();
	while(1)
	{
		val_conv = readADC1(0);
		for(int i=0;i<10000;i++);
	}
}

