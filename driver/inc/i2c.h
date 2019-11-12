#ifndef __I2C_H__
#define __I2C_H__


#ifdef STM32F10X_HD
#include "stm32f10x_gpio.h"

#define IIC_PORT GPIOB
#define SCL_PIN	GPIO_Pin_13
#define SDA_PIN	GPIO_Pin_15
#define SCL(n) n?GPIO_SetBits(IIC_PORT,SCL_PIN):GPIO_ResetBits(IIC_PORT,SCL_PIN)
#define SDA(n) n?GPIO_SetBits(IIC_PORT,SDA_PIN):GPIO_ResetBits(IIC_PORT,SDA_PIN)


#endif

void soft_iic_gpio_init(void);

#endif
