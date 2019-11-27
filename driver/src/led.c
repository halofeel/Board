#include "led.h"
#include "stm32f10x_gpio.h"


typedef struct 
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_PIN;
	uint32_t CLOCK;
	GPIOMode_TypeDef mode;
}LED_STRUCT;

LED_STRUCT led[LED_MAX] = 
{
#ifdef USE_LED0
	{
	.GPIOx = GPIOA,
	.GPIO_PIN = GPIO_Pin_8,
	.CLOCK = RCC_APB2Periph_GPIOA,
	.mode = GPIO_Mode_Out_PP,
	},
#endif
	
	
#ifdef USE_LED1
	{
	.GPIOx = GPIOD,
	.GPIO_PIN = GPIO_Pin_2,
	.CLOCK = RCC_APB2Periph_GPIOD,
	.mode = GPIO_Mode_Out_PP,
	}
#endif

};
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	int index = 0;
	for(index = 0;index<LED_MAX;index++)
	{
		RCC_APB2PeriphClockCmd(led[index].CLOCK,ENABLE); 	//打开GPIOB时钟
		GPIO_InitStruct.GPIO_Mode = led[index].mode;			//设置为开漏模式
		GPIO_InitStruct.GPIO_Pin = led[index].GPIO_PIN;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(led[index].GPIOx,&GPIO_InitStruct);
		GPIO_WriteBit(led[index].GPIOx,led[index].GPIO_PIN,OFF);
	}
	
}

void led_control(LED index,STATE state)
{
	GPIO_WriteBit(led[index].GPIOx,led[index].GPIO_PIN,state);
}
