#include <stdio.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"

#include "usart.h"


#define USE_UART1
typedef struct
{
	GPIO_TypeDef* 		gpio_port;
	uint16_t 			gpio_pin_rx;
	uint16_t 			gpio_pin_tx;
	GPIOMode_TypeDef 	mode;
	GPIOSpeed_TypeDef 	speed;
	uint32_t			clock;
}USART_STRUCT;

USART_STRUCT usartList[UART_MAX] =
{
#ifdef USE_UART1
	{
	.gpio_port = GPIOA,
	.gpio_pin_rx = GPIO_Pin_10,
	.gpio_pin_tx = GPIO_Pin_9,
	.mode = GPIO_Mode_AF_PP,
	.speed = GPIO_Speed_50MHz,
	.clock = RCC_APB2Periph_GPIOA
	
	}
	
	
#endif
	




};



/*gpio初始化*/
void uart_init_f(void)
{
	GPIO_InitTypeDef gpioStruct;
	
	for(int i = 0;i<UART_MAX;i++)
	{
		RCC_APB2PeriphClockCmd(usartList[i].clock,ENABLE);
		gpioStruct.GPIO_Mode = usartList[i].mode;
		gpioStruct.GPIO_Pin = usartList[i].gpio_pin_rx|usartList[i].gpio_pin_tx;
		gpioStruct.GPIO_Speed = usartList[i].speed;
		GPIO_Init(usartList[i].gpio_port,&gpioStruct);
	}
}
/*uart初始化*/
void uart_init(void)
{
	uart_init_f();
	
	USART_InitTypeDef USART_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No ;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_Init(USART1,&USART_InitStruct);
	USART_Cmd(USART1,ENABLE);
	

}

int fputc(int ch,FILE *f)
{
	USART_SendData(USART1,(uint8_t)ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	return (ch);
}






















