#ifndef __STATE_H
#define __STATE_H
#include "sys.h"
#include "pid.h"

void State_Init(void);
void State_Forward_Left(void);
void State_Back_Left(void);
void State_Forward_Right(void);
void State_Back_Right(void);
void Chang_State(PID_Ctrl *pidLeft,PID_Ctrl *pidRight);

#endif
