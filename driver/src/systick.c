#include "systick.h"

#include "stm32f10x.h"
#include "led.h"
volatile uint64_t SysCount = 0;

void Systick_Init(void)
{
	if(SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}
	//SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}
volatile unsigned long time_delay;
void SysTick_Handler(void)
{
    SysCount ++;
	//static int state = 0;
//	if(SysCount>= 500)
//	{
//		//state = !ON;
//		//led_control(LED0,state);
//		printf("%d\n",SysCount);
//		SysCount = 0;
//	}
//	
//	if(time_delay)
//        time_delay--;
}
Tick tick_get()
{
	return SysCount;
}
int tick_time_out(Tick start,Tick timeout)
{
	Tick now = tick_get();
//	if(now < start)
//	{
//		
//	}
	return ((now - start)>timeout)?1:0;
}

void delay_ms(volatile unsigned long nms)
{
	if (SysTick_Config(SystemCoreClock/1000))
	{
		while (1);
	}
	time_delay=nms;//读取定时时间
	while(time_delay);
	SysTick->CTRL=0x00; //关闭计数器
	SysTick->VAL =0X00; //清空计数器
}

