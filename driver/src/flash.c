#include "flash.h"
#include "string.h"
#include "stm32f10x_flash.h"

int flash_write(uint32 addr,uint8 *buffer,uint16 bufferLen)
{
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPRTERR|FLASH_FLAG_OPTERR);
	uint32 addr_end = addr + bufferLen;
	uint8 div = bufferLen/PAGE_SIZE;
	uint8 count = (bufferLen%PAGE_SIZE)?(div+1):div;//计算需要擦出的扇区数量

	for(int i = 0;i<count;i++)
	{
		FLASH_ErasePage(addr + i*PAGE_SIZE);
	}
	while( addr < addr_end )
	{
		FLASH_ProgramHalfWord(addr,*(uint16 *)buffer);
		buffer += 2;
		addr += 2;	
	}
	//	
	FLASH_Lock();
	return -1;
}
int flash_read(uint32 addr,uint8 *buffer,uint16 bufferLen)
{
	memcpy((void *)buffer,(void *)addr,bufferLen);
	
	return -1;
//	*buffer = *(char *)addr;
//	return -1;
}
uint16 FLASH_ReadHalfWord(uint32 address)
{
	return *(__IO uint16_t*)address; 
}
int flash_erase(uint8 addr,uint8 *buffer,uint16 bufferLen)
{


	return -1;
}

















