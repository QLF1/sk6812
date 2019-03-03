#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"

#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		
#define LED1_GPIO_PIN1		GPIO_Pin_3	
#define LED1_GPIO_PIN2		GPIO_Pin_2		
#define LED3_GPIO_PIN1		GPIO_Pin_7
#define LED3_GPIO_PIN2		GPIO_Pin_6
#define LED4_GPIO_PIN1		GPIO_Pin_5			 
#define LED4_GPIO_PIN2		GPIO_Pin_4
#define LED2_GPIO_PIN2		GPIO_Pin_10         
#define LED6_GPIO_CLK 	    RCC_APB2Periph_GPIOB		
#define LED2_GPIO_PIN1		GPIO_Pin_1
#define LED5_GPIO_PIN2		GPIO_Pin_2
#define LED5_GPIO_PIN1		GPIO_Pin_10		

#define LED1_GPIO_PIN1_PORT			GPIOA
#define LED1_GPIO_PIN2_PORT			GPIOA
#define LED2_GPIO_PIN1_PORT			GPIOB
#define LED2_GPIO_PIN2_PORT			GPIOA
#define LED3_GPIO_PIN1_PORT			GPIOA
#define LED3_GPIO_PIN2_PORT			GPIOA
#define LED4_GPIO_PIN1_PORT			GPIOA
#define LED4_GPIO_PIN2_PORT			GPIOA
#define LED5_GPIO_PIN1_PORT			GPIOB
#define LED5_GPIO_PIN2_PORT			GPIOB

/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LED1(a)	if (a)	\
					GPIO_SetBits(GPIOA,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(GPIOA,LED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalLo(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalHi(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
#define LED1_TOGGLE		 digitalToggle(GPIOA,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(GPIOA,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(GPIOA,LED1_GPIO_PIN)

#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

#define LED4_TOGGLE		 digitalToggle(LED4_GPIO_PORT,LED4_GPIO_PIN)
#define LED4_OFF		   digitalHi(LED4_GPIO_PORT,LED4_GPIO_PIN)
#define LED4_ON			   digitalLo(LED4_GPIO_PORT,LED4_GPIO_PIN)

#define LED5_TOGGLE		 digitalToggle(LED5_GPIO_PORT,LED5_GPIO_PIN)
#define LED5_OFF		   digitalHi(LED5_GPIO_PORT,LED5_GPIO_PIN)
#define LED5_ON			   digitalLo(LED5_GPIO_PORT,LED5_GPIO_PIN)

#define LED6_TOGGLE		 digitalToggle(GPIOB,LED6_GPIO_PIN)
#define LED6_OFF		   digitalHi(GPIOB,LED6_GPIO_PIN)
#define LED6_ON			   digitalLo(GPIOB,LED6_GPIO_PIN)

/*led��״̬*/
#define LED_ON					1
#define LED_OFF					0

/*����״̬*/
#define HIT_SET					1
#define	HIT_RESET				0

typedef struct
{
	u8 R;
	u8 G;
	u8 B;
}ColorTypedef;


void LED_GPIO_Config(void);
void LED_AllON(void);
void LED_AllOFF(void);
void LED_Rand(void);
void Sk6812(u32 color);
void Send_Code1(void);
void Send_Code0(void);
#endif /* __LED_H */
