#include "main.h"
 /**
  * @brief  1ms��ȷ��ʱ
  * @param  ��
  * @retval ��
  */

void Tim3_Config(void)
{
	
	TIM_TimeBaseInitTypeDef tim_init;
	
	TIM_DeInit(TIM3);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	tim_init.TIM_Period=7200-1;
	tim_init.TIM_Prescaler=10-1;
	tim_init.TIM_CounterMode=TIM_CounterMode_Up;
	tim_init.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&tim_init);
	
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);
	TIM_Cmd(TIM3,ENABLE);
	while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)!=SET);
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);
	TIM_Cmd(TIM3,DISABLE);
	
}

void Tim4_Config(void)
{
	TIM_TimeBaseInitTypeDef tim_init;
	NVIC_InitTypeDef nvic;
	
	TIM_DeInit(TIM4);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	tim_init.TIM_Period=2-1;
	tim_init.TIM_Prescaler=36;
	tim_init.TIM_CounterMode=TIM_CounterMode_Up;
	tim_init.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM4,&tim_init);
	
	//TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	//TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
	TIM_Cmd(TIM4,DISABLE);	
	
	nvic.NVIC_IRQChannel = TIM4_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 1;
	nvic.NVIC_IRQChannelSubPriority = 2;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);
}

void Tim2_Config(void)
{
	TIM_TimeBaseInitTypeDef tim_init;
	NVIC_InitTypeDef nvic;
	//��ʱ0.3us
	TIM_DeInit(TIM2);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	tim_init.TIM_Period= 3-1;
	tim_init.TIM_Prescaler= 7-1;
	tim_init.TIM_CounterMode=TIM_CounterMode_Up;
	tim_init.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2,&tim_init);
	
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	//TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_Cmd(TIM2,DISABLE);
	
	nvic.NVIC_IRQChannel = TIM2_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 1;
	nvic.NVIC_IRQChannelSubPriority = 2;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);
}

u32 Us_Time;
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update) != RESET)
	{
		Us_Time--;
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}


u32 Ns_Time;
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
	{
		Ns_Time --;
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
}

 /**
  * @brief  ������ʱ,ҶƬ��ȫ������ʱ�˳�
  * @param  ��
  * @retval ��
  */

extern volatile u8 temp[6];				//�����־λ
extern volatile u8 Led_Status[6];	//װ�װ�״̬λ
void Delay_Ms(u32 time,u8 led_num)
{
	u8 num,i;
	while(time--)
	{
		Tim3_Config();
		if((temp[led_num]!=HIT_RESET)&&(Led_Status[led_num]!=LED_OFF))
			return;
	}
	
	for(num=1;num<6;num++)
	{
		if((Led_Status[num]!=LED_OFF)&&(temp[num]==HIT_RESET))
		{
			for(i=1;i<6;i++)
			{
				temp[i]=HIT_RESET;
				Led_Status[i]=LED_OFF;
			}
			LED_AllOFF();
			break;
		}
	}
	return;
	
}

void Delay_Us(u32 time)
{
	//Us_Time = time;
	while(time--)
	{
		TIM_Cmd(TIM4,ENABLE);
		while(TIM_GetFlagStatus(TIM4,TIM_FLAG_Update)!=SET);
		TIM_ClearFlag(TIM4,TIM_FLAG_Update);
		TIM_Cmd(TIM4,DISABLE);
	}
}

u8 a=9;
void Delay_125Ns(u32 time)
{
	while(time--)
	{
		while(a--);
	}
}

void Delay_300Ns(u32 time)
{
		while(time--)
	{
		TIM_Cmd(TIM2,ENABLE);
		while(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)!=SET);
		TIM_ClearFlag(TIM2,TIM_FLAG_Update);
		TIM_Cmd(TIM2,DISABLE);
	}	
}
