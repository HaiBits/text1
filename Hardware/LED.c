#include "stm32f10x.h"                  // Device header

//LED灯初始化
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructre;
	GPIO_InitStructre.GPIO_Mode = GPIO_Mode_Out_PP ;
	GPIO_InitStructre.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructre.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructre);

	GPIO_SetBits(GPIOA, GPIO_Pin_1 |GPIO_Pin_2);
}

//LED灯开
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

//LED灯关
void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

//LED灯对应按键按位取反 进行开关灯
void LED1_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0) //看按键返回值是不是等于0
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}
