#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"


ADC_InitTypeDef  ADC_init_structure;

void ConfigADC(void) 
{
				
//RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC, ENABLE);	//autorisation 
ADC_init_structure.ADC_DataAlign = ADC_DataAlign_Right;//data converted will be shifted to right  
ADC_init_structure.ADC_Resolution = ADC_Resolution_12b;//Input voltage is converted into a 12bit number giving a maximum value of 4096
ADC_init_structure.ADC_ContinuousConvMode = ENABLE; //the conversion is continuous, the input data is converted more than once    
ADC_init_structure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//no trigger for conversion  
ADC_init_structure.ADC_NbrOfConversion = 1; // un canal, une conversion  
ADC_init_structure.ADC_ScanConvMode = DISABLE;//The scan is configured in one channel  
//ADC_RegularChannelConfig(ADC1,ADC_Channel_14,1,ADC_SampleTime_144Cycles); 
ADC_Init(ADC1, &ADC_init_structure); 
  /* Enable ADC1 */
ADC_Cmd(ADC1, ENABLE);
					
}

u16 readADC1(u8 channel){ 
ADC_RegularChannelConfig(ADC1, channel, 1,ADC_SampleTime_3Cycles );
ADC_SoftwareStartConv(ADC1); //start conversion			
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET); 	//// Wait until conversion completion 	 
return ADC_GetConversionValue(ADC1); 	// Get the conversion value
}

