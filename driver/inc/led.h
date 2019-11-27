#ifndef __LED_H__
#define __LED_H__


#define USE_LED0
#define USE_LED1

typedef enum 
{

#ifdef USE_LED0
	LED0,
#endif
#ifdef USE_LED1
	LED1,
#endif
	LED_MAX
}LED;
typedef enum
{
	ON,
	OFF
}STATE;

void led_init(void);
void led_control(LED index,STATE state);
#endif
