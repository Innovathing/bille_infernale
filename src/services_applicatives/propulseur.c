#include "propulseur.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"
#include "tim.h"
#include "clock.h"
#include "tir.h"
 
void propulseur_init()
{
	RCC_APB2PeriphClockCmd(GPIO_PROPULSEUR_1, ENABLE);
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
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM_NVIC_PROPULSEUR;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	TIM_Cmd(PROPULSEUR_TIMER, ENABLE);

	ADC_InitTypeDef adc_init_struct;
	ADC_StructInit(&adc_init_struct);
	ADC_Init(PROPULSEUR_ADC, &adc_init_struct);
	ADC_RegularChannelConfig(PROPULSEUR_ADC, ADC_Channel_2, 1, ADC_SampleTime_7Cycles5);
	ADC_StartCalibration(PROPULSEUR_ADC);
	while(ADC_GetCalibrationStatus(PROPULSEUR_ADC) != SET){};
		
}
 

void TIM3_IRQHandler()
{
	TIM_ClearFlag(PROPULSEUR_TIMER,TIM_FLAG_Update);
	// ADC_SoftwareStartConvCmd(PROPULSEUR_ADC, ENABLE);
	ADC_Cmd(PROPULSEUR_ADC, ENABLE);
	while(ADC_GetFlagStatus(PROPULSEUR_ADC, ADC_FLAG_EOC) != SET){}
	tir_perform_mesure(0);
}


void propulseur_init_fire(){
			 
	// Tir à 1 : on empeche le tir
	GPIO_SetBits(GPIO_TIR, GPIO_TIR_PIN);
	
			 
	// Charge à 0 : on lance la charge
	GPIO_ResetBits(GPIO_DECHARGE, GPIO_DECHARGE_PIN);
 
	//TIM_TimeBaseInit(TIM1)
}

void propulseur_BOUM()
{
	GPIO_ResetBits(GPIO_TIR, GPIO_TIR_PIN);
			 
	// Charge à 0 : on lance la charge
	GPIO_ResetBits(GPIO_DECHARGE, GPIO_DECHARGE_PIN);
}
