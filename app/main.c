#include <stdio.h>
#include "stm32f10x.h"


#include "flash.h"
#include "fifo.h"
#include "led.h"
#include "usart.h"
#include "systick.h"
#include "ff.h"

void delay(void)
{
	int i = 0,j;
	for(i = 0;i<300;i++)
	{
	for(j = 0;j<300;j++);
	}
	//while(--i);
}
typedef struct
{
	char name[10];
	char age;
	int telephone;
}Person;

Person Ran =
{
	.name = {"ransong"},
	.age = 23,
	.telephone = 3212,
};
int main(void)
{
//	uint16_t data;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Systick_Init();
	uart_init();
	delay();
	printf("hello!!%d\n",__LINE__);
	
	
	printf("Boot start addr:%x\n",BOOT_START);
	printf("App start addr:%x\n",APP_START);
	printf("Fireware start addr:%x\n",FIREWARE_START);
	printf("Config start addr:%x\n",CONFIG_START);
	
	FIL *fp;
	
	f_open(fp,"1:/test.c",FA_CREATE_NEW);
	
	
	
	led_init();
	//led_control(LED0,ON);
	STATE state = ON;
	Tick strat = tick_get();
	
	//char buffer[10] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
	//flash_write(CONFIG_START,(uint8 *)&Ran,sizeof(Ran));
	//uint8 bufferl[20] = {0};
	//flash_read(CONFIG_START,bufferl,sizeof(bufferl));
	
	
	while(1)
	{
		if(tick_time_out(strat,500))
		{
			printf("%02x\n",1);
			strat = tick_get();
			led_control(LED0,state);
			state = !state;
		}
	}
	
}
