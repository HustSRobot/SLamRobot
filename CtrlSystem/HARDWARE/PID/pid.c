#include "main.h"

void PID_Set_P(PID_Ctrl *pid,float Pin)
{
	pid->kp = Pin;
}
void PID_Set_I(PID_Ctrl *pid,float Iin)
{
	pid->ki = Iin;
}
void PID_Set_D(PID_Ctrl *pid,float Din)
{
	pid->kd = Din;
}

void PID_Init(PID_Ctrl *pid)
{
	pid->kp = 0.8;
	pid->ki = 20;
	pid->kd = 0;
	pid->rp = 0;
	pid->ri = 0;
	pid->rd = 0;
	
	pid->riMax = 300;
	pid->output = 0;
	pid->outputMax = 635;
	
	pid->dderror = 0;
	pid->derror = 0;
	pid->error = 0;
	pid->lasterror = 0;
	pid->pasterror = 0;
}

void PID_Init_Position(PID_Ctrl *pid)
{
	PID_Init(pid);
//	PID_Set_P(pid,1);
//	PID_Set_D(pid,1);
}

void PID_Calc(PID_Ctrl *pid,float point_in,float target_point)
{
	pid->error = target_point - point_in;
	pid->derror = pid->error - pid->lasterror;
	pid->dderror = pid->error + pid->pasterror - 2*pid->lasterror;
	pid->pasterror = pid->lasterror;
	pid->lasterror = pid->error;
	
	pid->rp = pid->kp * pid->error;
	pid->ri = pid->ki * pid->derror;
	pid->rd = pid->kd * pid->dderror;
	if(pid->ri > pid->riMax) 
		pid->ri = pid->riMax;
	if(pid->ri < -pid->riMax)
		pid->ri = -pid->riMax;
	
	pid->output += pid->rp + pid->ri + pid->rd;
	if(pid->output > pid->outputMax)
			pid->output = pid->outputMax;
	if(pid->output < -pid->outputMax) 
			pid->output = -pid->outputMax;
}
