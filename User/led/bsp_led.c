#include "main.h"

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( LED1_GPIO_CLK |LED6_GPIO_CLK , ENABLE);
	  //GPIO_InitStructure.GPIO_Pin =	(LED1_GPIO_PIN1| LED2_GPIO_PIN2 |LED1_GPIO_PIN2|LED3_GPIO_PIN1|LED3_GPIO_PIN2|LED4_GPIO_PIN1|LED4_GPIO_PIN2);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	
		GPIO_InitStructure.GPIO_Pin =	(LED2_GPIO_PIN1|LED5_GPIO_PIN2 |LED5_GPIO_PIN1|GPIO_Pin_0);
		GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void LED_AllON(void)
{
	GPIO_SetBits(GPIOA,LED1_GPIO_PIN2);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOA,LED1_GPIO_PIN1);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOA,LED2_GPIO_PIN2);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOB,LED2_GPIO_PIN1);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOA,LED3_GPIO_PIN2);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOA,LED3_GPIO_PIN1);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOA,LED4_GPIO_PIN2);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOA,LED4_GPIO_PIN1);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOB,LED5_GPIO_PIN2);
	Delay(0x4fffff);
	GPIO_SetBits(GPIOB,LED5_GPIO_PIN1);
	Delay(0x4fffff);	
}
void LED_AllOFF(void)
{
	GPIO_ResetBits(GPIOB,LED1_GPIO_PIN2);
	GPIO_ResetBits(GPIOB,LED2_GPIO_PIN1);
	GPIO_ResetBits(GPIOB,LED5_GPIO_PIN1);
	GPIO_ResetBits(GPIOA,LED1_GPIO_PIN1);
	GPIO_ResetBits(GPIOA,LED2_GPIO_PIN2);
	GPIO_ResetBits(GPIOA,LED3_GPIO_PIN1);
	GPIO_ResetBits(GPIOA,LED3_GPIO_PIN2);
	GPIO_ResetBits(GPIOA,LED4_GPIO_PIN1);
	GPIO_ResetBits(GPIOA,LED4_GPIO_PIN2);
	GPIO_ResetBits(GPIOA,LED5_GPIO_PIN2);
	Delay(0x4fffff);	
}

 /**
  * @brief  随机亮灯程序
  * @param  无
  * @retval 无
  */

extern __IO u32  TimingDelay;
extern u8 temp[6];					//打击标志位
u32 randd;
int randonnum;
volatile u8 Led_Status[6];	//亮灯标志位

void LED_Rand(void)
{
		u32 Set_Time=2500;					//亮灯时间
	//randd=ADReact();
	//srand((randd&0x00ffff));
	  srand(TimingDelay);
		randonnum=rand()%6;
    Delay(0x2ffff);
		switch(randonnum)
		{
			case 1:
			{
				if(temp[1]!=HIT_RESET)
					break;
				else
				{
					Led_Status[1]=LED_ON;
					GPIO_SetBits(GPIOA,LED1_GPIO_PIN2);
					Delay_Ms(Set_Time,1);					//延时时间，灯编号
					//Delay(0x4fffff);
				}
				if(temp[1]!=HIT_RESET)
					break;
				else
				{
					Led_Status[1]=LED_OFF;
					GPIO_ResetBits(GPIOA,LED1_GPIO_PIN2);
					//Delay(0x4fffff);
				}
				break;
			}
			
			case 2:
			{
				if(temp[2]!=HIT_RESET)
					break;
				else
				{
					Led_Status[2]=LED_ON;
					GPIO_SetBits(GPIOA,LED2_GPIO_PIN2);
					Delay_Ms(Set_Time,2);				
					//Delay(0x4fffff);
				}
				if(temp[2]!=HIT_RESET)
					break;
				else
				{
					Led_Status[2]=LED_OFF;
					GPIO_ResetBits(GPIOA,LED2_GPIO_PIN2);
					//Delay(0xfffff);
				}
				break;
			}
			
			case 3:
			{
				if(temp[3]!=HIT_RESET)
					break;
				else
				{
					Led_Status[3]=LED_ON;
					GPIO_SetBits(GPIOA,LED3_GPIO_PIN2);
					Delay_Ms(Set_Time,3);
					//Delay(0x4fffff);
				}
				if(temp[3]!=HIT_RESET)
					break;
				else
				{
					Led_Status[3]=LED_OFF;
					GPIO_ResetBits(GPIOA,LED3_GPIO_PIN2);
					//Delay(0xfffff);
				}
				break;
			}
			
			case 4:
			{
				if(temp[4]!=HIT_RESET)
					break;
				else
				{
					Led_Status[4]=LED_ON;
					GPIO_SetBits(GPIOA,LED4_GPIO_PIN2);
					Delay_Ms(Set_Time,4);
					//Delay(0x4fffff);
				}
				if(temp[4]!=HIT_RESET)
					break;
				else
				{
					Led_Status[4]=LED_OFF;
					GPIO_ResetBits(GPIOA,LED4_GPIO_PIN2);
					//Delay(0xfffff);
				}
				break;
			}		
			
			case 5:
			{
				if(temp[5]!=HIT_RESET)
					break;
				else
				{
					Led_Status[5]=LED_ON;
					GPIO_SetBits(GPIOB,LED5_GPIO_PIN2);
					Delay_Ms(Set_Time,5);
					//Delay(0x4fffff);
				}
				if(temp[5]!=HIT_RESET)
					break;
				else
				{
					Led_Status[5]=LED_OFF;
					GPIO_ResetBits(GPIOB,LED5_GPIO_PIN2);
					//Delay(0xfffff);
				}
				break;
			}
		}
}

ColorTypedef Sk_Color;
void Sk6812(u32 color)
{
	u8 Flag;
	short i;
	
	Sk_Color.R = color >> 16 & 0xff;
	Sk_Color.G = color >> 8 & 0xff;
	Sk_Color.B = color & 0xff;
	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	//Delay_Us(100);
	
	for(i=7;i>=0;i--)
	{
		Flag = Sk_Color.R >> i & 0x01;
		if(Flag==1)
			Send_Code1();
		else 
			Send_Code0();
	}
		for(i=7;i>=0;i--)
	{
		Flag = Sk_Color.G >> i & 0x01;
		if(Flag==1)
			Send_Code1();
		else 
			Send_Code0();
	}
		for(i=7;i>=0;i--)
	{
		Flag = Sk_Color.B >> i & 0x01;
		if(Flag==1)
			Send_Code1();
		else 
			Send_Code0();
	}
	Delay_Us(100);
}

void Send_Code1(void)
{
	u8 nCount = 5;
	GPIO_SetBits(GPIOA,GPIO_Pin_11);
	for(; nCount != 0; nCount--);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	nCount = 5;
	for(; nCount != 0; nCount--);
	Delay_300Ns(3);
}

void Send_Code0(void)
{
	u8 nCount = 1;
	GPIO_SetBits(GPIOA,GPIO_Pin_11);
	for(; nCount != 0; nCount--);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	nCount = 8;
	for(; nCount != 0; nCount--);
}
