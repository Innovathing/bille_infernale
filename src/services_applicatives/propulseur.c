#include "propulseur.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "tim.h"
#include "clock.h"
#include "tir.h"

void propulseur_init()
{
	// init gpio tir
	GPIO_InitTypeDef init_gpio_tir = { GPIO_TIR_PIN,GPIO_Speed_10MHz,GPIO_Mode_Out_PP };
	GPIO_Init(GPIO_TIR, &init_gpio_tir);

	// init gpio charge
	GPIO_InitTypeDef init_gpio_charge = { GPIO_DECHARGE_PIN,GPIO_Speed_10MHz,GPIO_Mode_Out_PP };
	GPIO_Init(GPIO_DECHARGE, &init_gpio_charge);

	GPIO_ResetBits(GPIO_TIR, GPIO_TIR_PIN);
	GPIO_ResetBits(GPIO_DECHARGE, GPIO_DECHARGE_PIN);

	TIM_TimeBaseInitTypeDef tim_config;
	TIM_TimeBaseStructInit(&tim_config);
	tim_config_struct(&tim_config, 100000.0, (float) CLOCK_GetTIMCLK(PROPULSEUR_TIMER));
	TIM_TimeBaseInit(PROPULSEUR_TIMER, &tim_config);
	TIM_ITConfig(PROPULSEUR_TIMER, TIM_IT_Update, ENABLE);

	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(PROPULSEUR_ADC, &ADC_InitStructure);
	ADC_RegularChannelConfig(PROPULSEUR_ADC, ADC_Channel_2, 1, ADC_SampleTime_7Cycles5);
	ADC_Cmd(PROPULSEUR_ADC, ENABLE);
	 /* Enable ADC1 reset calibration register */   
  ADC_ResetCalibration(PROPULSEUR_ADC);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(PROPULSEUR_ADC));

  /* Start ADC1 calibration */
  ADC_StartCalibration(PROPULSEUR_ADC);
  /* Check the end of ADC1 calibration */
  while(ADC_GetCalibrationStatus(PROPULSEUR_ADC));

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM_NVIC_PROPULSEUR;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(PROPULSEUR_TIMER, ENABLE);
}


void TIM3_IRQHandler()
{
	TIM_ClearFlag(PROPULSEUR_TIMER,TIM_FLAG_Update);
	ADC_SoftwareStartConvCmd(PROPULSEUR_ADC, ENABLE);
	while(ADC_GetFlagStatus(PROPULSEUR_ADC, ADC_FLAG_EOC) != SET){}
	tir_perform_mesure(ADC_GetConversionValue(PROPULSEUR_ADC));
}


void propulseur_init_fire(){

	// Tir � 1 : on empeche le tir
	GPIO_SetBits(GPIO_TIR, GPIO_TIR_PIN);


	// Charge � 0 : on lance la charge
	GPIO_ResetBits(GPIO_DECHARGE, GPIO_DECHARGE_PIN);

	//TIM_TimeBaseInit(TIM1)
}

void propulseur_BOUM()
{
	GPIO_ResetBits(GPIO_TIR, GPIO_TIR_PIN);

	// Charge � 0 : on lance la charge
	GPIO_ResetBits(GPIO_DECHARGE, GPIO_DECHARGE_PIN);
}
