#include "main.h" 

void State_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOC,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);
}

void State_Forward_Left(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);
}

void State_Back_Left(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_3);
	GPIO_ResetBits(GPIOC,GPIO_Pin_2);
}

void State_Forward_Right(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);
}

void State_Back_Right(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_5);
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
}

void Chang_State(PID_Ctrl *pidLeft,PID_Ctrl *pidRight)
{
	if(pidLeft->output>0)
		State_Forward_Left();
	if(pidLeft->output<0){
		State_Back_Left();
		pidLeft->output = - pidLeft->output; 
	}
	if(pidRight->output>0)
		State_Forward_Right();
	if(pidRight->output<0){
		State_Back_Right();
		pidRight->output = - pidRight->output;
	}
}
