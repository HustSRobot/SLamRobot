#ifndef __ENCODER_H
#define __ENCODER_H

#include "stm32f4xx.h"


void TIM4_Encoder_Config(void);
void TIM5_Encoder_Config(void);
short Encoder_GetSpeedLeft(void);
short Encoder_GetSpeedRight(void);
void Encoder_Start(void);
void Encoder_Stop(void);
#endif
