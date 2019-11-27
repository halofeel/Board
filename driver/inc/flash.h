#ifndef __FLASH_H__
#define __FLASH_H__
#include "user_type.h"


#define PAGE_SIZE	1024


#define BOOT_SIZE		74*1024	//74K
#define APP_SIZE		74*1024	//74K
#define FIREWARE_SIZE	74*1024	//74k
#define	CONFIG_SIZE		34*1024	//34K


#define BOOT_START		(0X08000000)
#define BOOT_END		(BOOT_START + BOOT_SIZE)
#define APP_START		(BOOT_END)
#define APP_END			(BOOT_END + APP_SIZE)
#define FIREWARE_START 	(APP_END)
#define FIREWARE_END	(FIREWARE_START + FIREWARE_SIZE)
#define CONFIG_START	(FIREWARE_END)
#define CONFIG_END		(Config_START + Config_SIZE)




int flash_write(uint32 addr,uint8 *buffer,uint16 bufferLen);
int flash_read(uint32 addr,uint8 *buffer,uint16 bufferLen);
uint16 FLASH_ReadHalfWord(uint32 address);













#endif



