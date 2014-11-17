#include "galva.h"
#include <stm32f10x_gpio.h>
#include "tim.h"
#include "clock.h"
#include "stm32f10x_tim.h"

void galva_init()
{
  GPIO_InitTypeDef gpio_init = {PIN_GALVA, GPIO_Speed_50MHz, GPIO_Mode_AF_PP};
	GPIO_Init(GPIO_GALVA, &gpio_init);
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef tim_config;
	TIM_TimeBaseStructInit(&tim_config);
	tim_config_struct(&tim_config, 10000.0, (float) CLOCK_GetTIMCLK(GALVA_TIMER));
	TIM_TimeBaseInit(GALVA_TIMER, &tim_config);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0x0;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC3Init(GALVA_TIMER, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(GALVA_TIMER, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(GALVA_TIMER, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(GALVA_TIMER, ENABLE);
}
 
void galva_do_afficher(uint16_t value) {
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = value;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC3Init(GALVA_TIMER, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(GALVA_TIMER, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(GALVA_TIMER, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(GALVA_TIMER, ENABLE);
	
}