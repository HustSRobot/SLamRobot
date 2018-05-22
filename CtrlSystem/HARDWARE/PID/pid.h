#ifndef __PID_H

#define __PID_H

#include "stm32f4xx.h"
typedef struct __PID_Ctrl
{
	float kp;
	float ki;
	float kd;
	float rp;
	float ri;
	float rd;
	
	float riMax;
	float output;
	float outputMax;

	float error;
	float derror;
	float dderror;
	float pasterror;
	float lasterror;
} PID_Ctrl;

void PID_Set_P(PID_Ctrl *pid,float Pin);
void PID_Set_I(PID_Ctrl *pid,float Iin);
void PID_Set_D(PID_Ctrl *pid,float Din);
void PID_Init(PID_Ctrl *pid);
void PID_Init_Position(PID_Ctrl *pid);
void PID_Calc(PID_Ctrl *pid,float point_in,float target_point);
#endif
