#ifndef __FIFO_H__
#define __FIFO_H__

#include "stm32f10x.h"
#define MAX_LEN 256
typedef uint16_t QElemType;
typedef struct
{
	QElemType buffer[MAX_LEN];
	unsigned int write;
	unsigned int read;
}*ring, ring_buff;

ring_buff * fifo_init(void);
int get_ring_buff_fullstate(ring_buff *p_ring_buff);
int get_ring_buff_emptystate(ring_buff *p_ring_buff);
int ring_buff_insert(ring_buff *p_ring_buff, QElemType data);
int ring_buff_get(ring_buff *p_ring_buff, QElemType *outdata);
int ring_buff_destory(ring_buff *p_ring_buff);

#endif
