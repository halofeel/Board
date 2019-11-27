
#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>

ring_buff * fifo_init(void)
{
	ring_buff* p = NULL;
	p = (ring_buff *)malloc(sizeof(ring_buff));
	if (NULL == p)
	{
		printf("fifo_init malloc error\n");
		return NULL;
	}
	p->read = 0;
	p->write = 0;
	return p;
}
int get_ring_buff_fullstate(ring_buff *p_ring_buff)
{
	if ((p_ring_buff->write - p_ring_buff->read) == MAX_LEN)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int get_ring_buff_emptystate(ring_buff *p_ring_buff)
{
	if (p_ring_buff->read == p_ring_buff->write)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int ring_buff_insert(ring_buff *p_ring_buff, QElemType data)
{
	if (p_ring_buff == NULL)
	{
		printf("p null\n");
		return 0;
	}
	if (get_ring_buff_fullstate(p_ring_buff))
	{
		printf("buff is full\n");
		return 0;
	}
	p_ring_buff->buffer[p_ring_buff->write%MAX_LEN] = data;
	p_ring_buff->write++;
	return -1;
}
int ring_buff_get(ring_buff *p_ring_buff, QElemType *outdata)
{
	//QElemType data = 0;
	if (p_ring_buff == NULL)
	{
		printf("p null\n");
		return 0;
	}
	if (get_ring_buff_emptystate(p_ring_buff))
	{
	//	printf("buff is empty\n");
		return 0;
	}
	*outdata = p_ring_buff->buffer[p_ring_buff->read%MAX_LEN];
	p_ring_buff->read++;
	return -1;
}
int ring_buff_destory(ring_buff *p_ring_buff)
{
	if (p_ring_buff == NULL)
	{
		printf("p null\n");
		return 0;
	}
	free(p_ring_buff);
	return -1;
}
