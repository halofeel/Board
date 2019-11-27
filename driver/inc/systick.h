#ifndef 	__SYSTICK_H__
#define 	__SYSTICK_H__


typedef unsigned long Tick;
void Systick_Init(void);
Tick tick_get(void);
int tick_time_out(Tick start,Tick timeout);


#endif
