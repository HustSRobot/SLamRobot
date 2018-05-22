#include "main.h"
/**@brief:control system
*@author:xzy
*@note: left motor: pwm PC6 
										fob PC2 PC3
										encoder PB6 PB7
				right motor:PC7
										fob PC4 PC5
										encoder PA0 PA1
*@attention:pwm tim3
						pid tim7
						encoder tim4 & tim5
*/
/**@brief:control left and right
*/
u32 pwmLeftMotor = 0;
u32 pwmRightMotor = 0;
PID_Ctrl pidLeft;
PID_Ctrl pidRight;
PID_Ctrl pidPositionLeft;
PID_Ctrl pidPositionRight;
short speedLeft = 0;
short speedRight = 0;
short positionLeft = 0;
short positionRight = 0;
short positionTargetLeft = 0;
short positionTargetRight = 0;

/**@brief:todo
u32 pwmStep; 
*/

/**@brief:following is used to debug
*@attention: delete them after debug!!!!!!
*/
	
int main(void)
{ 
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  
	uart_init(115200);		

	TIM4_Encoder_Config();
	TIM5_Encoder_Config();
	TIM3_PWM_Init(1000-1,4-1);//84M/4=21Mhz的计数频率,重装载值1000,所以PWM频率为 21M/1000=21Khz. 
	PID_Init(&pidLeft);
	PID_Init(&pidRight);
	PID_Init_Position(&pidPositionLeft);
	PID_Init_Position(&pidPositionRight);
	State_Init();
	TIM7_Int_Init(420-1,1000-1);//420*1000/42M = 0.01s
	
	while(1)
	{ 
		delay_ms(1000);
		printf("a\n");
		UpdatePwm();
	}
}
