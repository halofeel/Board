#ifndef __SPI_SD_H__
#define __SPI_SD_H__



int MMC_disk_status(void);
int MMC_disk_initialize(void);
int MMC_disk_read(unsigned char *buff,int sector,int count);
int MMC_disk_write(const unsigned char *buff,int sector,int count);




#endif

