#ifndef __USART_H__
#define __USART_H__
#include "fifo.h"
enum
{
	USE_UART1 = 0,
	UART_MAX
};
extern ring pt_ring_buff ;
void uart_init(void);
#endif
