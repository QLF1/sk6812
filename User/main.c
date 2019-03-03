#include "main.h" 

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
u32 color=0xffffff;
u8 Status;
int main(void)
{	
	SystemInit();
	System_Config();
	
	while(1)
	{
		//LED_Rand();
		//LED_AllON();
		//LED_AllOFF();
		Sk6812(color);
	}
}


/**
  * @brief  系统初始化
  * @param  无  
  * @retval 无
  */
void System_Config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	LED_GPIO_Config();	
	Tim4_Config();	
	Tim2_Config();
	//EXTI_Key_Config();
  //SysTick_Config(SystemCoreClock/100000);
	//LED_AllON();
	//LED_AllOFF();
}


void SysTick_Handler(void)
{
	TimingDelay_Decrement();	
}

void Delay(__IO uint32_t nCount)	 
{
	for(; nCount != 0; nCount--);
}

