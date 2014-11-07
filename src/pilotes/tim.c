#include "tim.h"
#include "stm32f10x_gpio.h"
#include "clock.h"
#include "stm32f10x_tim.h"


void tim_config_struct(TIM_TimeBaseInitTypeDef* tim_config, float Duree_us, float tim_clk) {

	float freq = 1.0e6/Duree_us;
	
	float psc = tim_clk / (freq*MAX_ARR); // calcul du PSC tronqué
	tim_config->TIM_Prescaler = psc;
	
	float arr = tim_clk / (freq*(tim_config->TIM_Prescaler+1)); // recalcul de ARR avec la valeur tronqué de PSC
	
	tim_config->TIM_Period = arr-1;
}