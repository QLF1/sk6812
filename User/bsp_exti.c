#include "main.h"  
 /**
  * @brief  ����Ƕ�������жϿ�����NVIC
  * @param  ��
  * @retval ��
  */
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
  NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = KEY3_INT_EXTI_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = KEY4_INT_EXTI_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = KEY5_INT_EXTI_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&NVIC_InitStructure);
}

 /**
  * @brief  ���� IOΪEXTI�жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
  */
void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	NVIC_Configuration();
	
/*--------------------------KEY1����-----------------------------*/
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK,ENABLE);
  GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure);
	
  GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE); 
  EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
	
  /*--------------------------KEY2����-----------------------------*/	
	RCC_APB2PeriphClockCmd(KEY2_INT_GPIO_CLK,ENABLE);
  GPIO_InitStructure.GPIO_Pin = KEY2_INT_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);

  GPIO_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE, KEY2_INT_EXTI_PINSOURCE); 
  EXTI_InitStructure.EXTI_Line = KEY2_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
	
	  /*--------------------------KEY3����-----------------------------*/	
	RCC_APB2PeriphClockCmd(KEY3_INT_GPIO_CLK,ENABLE);
  GPIO_InitStructure.GPIO_Pin = KEY3_INT_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(KEY3_INT_GPIO_PORT, &GPIO_InitStructure);

  GPIO_EXTILineConfig(KEY3_INT_EXTI_PORTSOURCE, KEY3_INT_EXTI_PINSOURCE); 
  EXTI_InitStructure.EXTI_Line = KEY3_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
	
	  /*--------------------------KEY4����-----------------------------*/
	RCC_APB2PeriphClockCmd(KEY4_INT_GPIO_CLK,ENABLE);		
  GPIO_InitStructure.GPIO_Pin = KEY4_INT_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(KEY4_INT_GPIO_PORT, &GPIO_InitStructure);

  GPIO_EXTILineConfig(KEY4_INT_EXTI_PORTSOURCE, KEY4_INT_EXTI_PINSOURCE); 
  EXTI_InitStructure.EXTI_Line = KEY4_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
	
	  /*--------------------------KEY5����-----------------------------*/	
	RCC_APB2PeriphClockCmd(KEY5_INT_GPIO_CLK,ENABLE);
  GPIO_InitStructure.GPIO_Pin = KEY5_INT_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(KEY5_INT_GPIO_PORT, &GPIO_InitStructure);

  GPIO_EXTILineConfig(KEY5_INT_EXTI_PORTSOURCE, KEY5_INT_EXTI_PINSOURCE); 
  EXTI_InitStructure.EXTI_Line = KEY5_INT_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
}

 /**
  * @brief  IO�жϺ���
  * @param  temp:�����־λ��Led_Status��װ�װ�״̬��־λ
  * @retval ��
  */

u32 Hit_Count[6];										//��¼�������
volatile u8 temp[6];								//�����־λ
extern volatile u8 Led_Status[6]; 	//led״̬��־λ

void KEY1_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET)
	{
		//Hit_Count[1]++;
		if(Led_Status[1]!=LED_OFF)
		{
			while(GPIO_ReadInputDataBit(KEY1_INT_GPIO_PORT,KEY1_INT_GPIO_PIN)==1);
			digitalLo(GPIOA,LED1_GPIO_PIN2);
			digitalLo(GPIOA,LED1_GPIO_PIN1);
			temp[1]=HIT_SET;
		}
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);     
	}
	
	if(EXTI_GetITStatus(KEY2_INT_EXTI_LINE) != RESET)
	{	
		//Hit_Count[2]++;
		if(Led_Status[2]!=LED_OFF)
		{
			while(GPIO_ReadInputDataBit(KEY2_INT_GPIO_PORT,KEY2_INT_GPIO_PIN)==1);
			digitalLo(GPIOA,LED2_GPIO_PIN2);
			digitalLo(GPIOB,LED2_GPIO_PIN1);
			temp[2]=HIT_SET;
		}
		EXTI_ClearITPendingBit(KEY2_INT_EXTI_LINE);     
	}     
}

void KEY3_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY3_INT_EXTI_LINE) != RESET)
	{	
		//Hit_Count[3]++;
		if(Led_Status[3]!=LED_OFF)
		{
			while(GPIO_ReadInputDataBit(KEY3_INT_GPIO_PORT,KEY3_INT_GPIO_PIN)==1);
			digitalLo(GPIOA,LED3_GPIO_PIN2);
			digitalLo(GPIOA,LED3_GPIO_PIN1);
			temp[3]=HIT_SET;
		}
		EXTI_ClearITPendingBit(KEY3_INT_EXTI_LINE);     
	}
	if(EXTI_GetITStatus(KEY5_INT_EXTI_LINE) != RESET)
	{	
		//Hit_Count[5]++;
		if(Led_Status[5]!=LED_OFF)
		{
			while(GPIO_ReadInputDataBit(KEY5_INT_GPIO_PORT,KEY5_INT_GPIO_PIN)==1);
			digitalLo(GPIOB,LED5_GPIO_PIN2);
			digitalLo(GPIOB,LED5_GPIO_PIN1);
			temp[5]=HIT_SET;
		}
		EXTI_ClearITPendingBit(KEY5_INT_EXTI_LINE);     
	}  
	
}

void KEY4_IRQHandler(void)
{
	if(EXTI_GetITStatus(KEY4_INT_EXTI_LINE) != RESET)
	{	
		//Hit_Count[5]++;
		if(Led_Status[4]!=LED_OFF)
		{
			while(GPIO_ReadInputDataBit(KEY4_INT_GPIO_PORT,KEY4_INT_GPIO_PIN)==1);
			digitalLo(GPIOA,LED4_GPIO_PIN2);
			digitalLo(GPIOA,LED4_GPIO_PIN1);
			temp[4]=HIT_SET;
		}
		EXTI_ClearITPendingBit(KEY4_INT_EXTI_LINE);   
	}  
}

