#include "i2c.h"


void soft_iic_gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); 	//��GPIOBʱ��
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;			//����Ϊ��©ģʽ
	GPIO_InitStruct.GPIO_Pin = SCL_PIN|SDA_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(IIC_PORT,&GPIO_InitStruct);
}

void iic_start(void)
{
	

}
















