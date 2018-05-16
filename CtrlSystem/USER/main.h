#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f4xx.h"
#include "encoder.h"
#include "pid.h"
#include "pwm.h"
#include "math.h"
#include "tim7.h"
#include "delay.h"  
#include "usart.h"   
#include "sys.h"
#include "state.h"
#include "JY901_IIC.h"

/**@brief:control left and right
*/
extern u32 pwmLeftMotor;
extern u32 pwmRightMotor;
extern PID_Ctrl pidLeft;
extern PID_Ctrl pidRight;
extern PID_Ctrl pidPositionLeft;
extern PID_Ctrl pidPositionRight;
extern short speedLeft;
extern short speedRight;
extern short positionLeft;
extern short positionRight;
extern short positionTargetLeft;
extern short positionTargetRight;

/**@brief:following is used to debug
*@attention: delete them after debug!!!!!!
*/
	
#endif
