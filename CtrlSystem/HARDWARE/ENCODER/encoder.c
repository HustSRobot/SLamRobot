#include "encoder.h"

void TIM4_Encoder_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;   	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_TIM4);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;         
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = 60000;//�趨��������װֵ   TIMx_ARR = 60000
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//TIM4ʱ��Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);              
                 
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising  ,TIM_ICPolarity_Rising);	//���ñ�����ģʽ����Դ�ͼ���
	
	TIM_ICStructInit(&TIM_ICInitStructure);																																		//�����˲���
	TIM_ICInitStructure.TIM_ICFilter = 6;
	TIM_ICInit(TIM4, &TIM_ICInitStructure);

  TIM_ClearFlag(TIM4, TIM_FLAG_Update);  //������б�־λ
  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE); //�����жϸ���

	TIM4->CNT = 0x7fff;//��ʼֵ 32767

	TIM_Cmd(TIM4, ENABLE);   //����TIM4��ʱ��
}

void TIM5_Encoder_Config(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;   	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM5);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;         
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 60000;//�趨��������װֵ   TIMx_ARR = 60000
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//TIM5ʱ��Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);              
                 
	TIM_EncoderInterfaceConfig(TIM5, TIM_EncoderMode_TI12, 
														 TIM_ICPolarity_Rising,
														 TIM_ICPolarity_Rising);	//���ñ�����ģʽ����Դ�ͼ���
	
	TIM_ICStructInit(&TIM_ICInitStructure);	//�����˲���
	TIM_ICInitStructure.TIM_ICFilter = 6;
	TIM_ICInit(TIM5, &TIM_ICInitStructure);

  TIM_ClearFlag(TIM5, TIM_FLAG_Update);  //������б�־λ
  TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE); //�����жϸ���

	TIM5->CNT = 0x7fff;//��ʼֵ 32767

	TIM_Cmd(TIM5, ENABLE);   //����TIM5��ʱ��
}

//��������������
void Encoder_Start(void)
{
  TIM_SetCounter(TIM4, 0);
  TIM_Cmd(TIM4, ENABLE);
	TIM_SetCounter(TIM9, 0);
  TIM_Cmd(TIM9, ENABLE);
}

//�رձ���������
void Encoder_Stop(void)
{
  TIM_Cmd(TIM4, DISABLE);
  TIM_SetCounter(TIM4, 0);
	TIM_Cmd(TIM9, DISABLE);
  TIM_SetCounter(TIM9, 0);
}

//��ȡ����������ֵ
short Encoder_GetSpeedLeft(void)
{
	int speed = 0;	
   speed = TIM4->CNT - 32767;
	TIM4->CNT = 0x7fff;
	return speed;
}

short Encoder_GetSpeedRight(void)
{
	int speed = 0;
	speed = TIM5->CNT - 32767;
	TIM5->CNT = 0x7fff;
	return speed;
}
