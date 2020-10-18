#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

GPIO_InitTypeDef  GPIO_config;

void ConfigGPIO(void) 
{

RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

//GPIO_config.GPIO_Speed=GPIO_Speed_2MHz;
GPIO_config.GPIO_Pin=GPIO_Pin_0;
GPIO_config.GPIO_Mode=GPIO_Mode_AN;
GPIO_Init(GPIOA,&GPIO_config);  
	
}
