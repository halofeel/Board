#include <stdio.h>
#include "stm32f10x.h"

#include "usart.h"

void delay(void)
{
	int i = 0,j;
	for(i = 0;i<300;i++)
	{
	for(j = 0;j<300;j++);
	}
	//while(--i);
}
int main(void)
{

	uart_init();
	delay();
	printf("hello!!%d",__LINE__);
	while(1)
	{

	}
	
}
