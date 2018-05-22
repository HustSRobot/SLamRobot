#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
#include "pid.h"

void TIM3_PWM_Init(u32 arr,u32 psc);
void UpdatePwm(void);

#endif
