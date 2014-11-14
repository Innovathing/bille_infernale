#ifndef TIM_H
#define TIM_H

#include <stm32f10x_tim.h>

#define MAX_ARR 65536.0
void tim_config_struct(TIM_TimeBaseInitTypeDef* tim_config, float Duree_us, float tim_clk) ;


#endif