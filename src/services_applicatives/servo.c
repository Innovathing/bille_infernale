#include "servo.h"
#include "clock.h"
#include "stm32f10x_tim.h"
#include "tim.h"

TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  SERVO1_TIM_OCInitStructure;
TIM_OCInitTypeDef  SERVO2_TIM_OCInitStructure;
TIM_OCInitTypeDef  SERVO3_TIM_OCInitStructure;
float SERVO1_OPEN_Val = 0.01;
float SERVO2_OPEN_Val = 0.4;
float SERVO3_OPEN_Val = 0.05;
float SERVO1_CLOSE_Val = 0.20;
float SERVO2_CLOSE_Val = 0.05;
float SERVO3_CLOSE_Val = 0.20;

uint16_t PrescalerValue = 0;


void servo_init(){

	servo_init_general();
	servo_init_private(GPIO_PORTE, GPIO_PORTE_1);
	servo_init_private(GPIO_PORTE, GPIO_PORTE_2);
	servo_init_private(GPIO_PORTE, GPIO_PORTE_3);
	
  TIM_ARRPreloadConfig(PORTE_TIMER, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(PORTE_TIMER, ENABLE);
}
void servo_init_general(){
	/* Time base configuration */
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	tim_config_struct(&TIM_TimeBaseStructure, 10000 ,CLOCK_GetTIMCLK(TIM1) );
  TIM_TimeBaseInit(PORTE_TIMER, &TIM_TimeBaseStructure);
	
	/* GPIO configuration */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIO_PORTE, &GPIO_InitStructure);
}
void servo_init_private(GPIO_TypeDef* gpio, int pin) {
	switch(pin){
		case GPIO_PORTE_1:
			SERVO1_TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
			SERVO1_TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
			SERVO1_TIM_OCInitStructure.TIM_Pulse = SERVO1_OPEN_Val * TIM_TimeBaseStructure.TIM_Period;
			SERVO1_TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
			TIM_OC1Init(PORTE_TIMER, &SERVO1_TIM_OCInitStructure);
			TIM_OC1PreloadConfig(PORTE_TIMER, TIM_OCPreload_Enable);
			break;
			
		case GPIO_PORTE_2:
			SERVO2_TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
			SERVO2_TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
			SERVO2_TIM_OCInitStructure.TIM_Pulse = SERVO2_OPEN_Val * TIM_TimeBaseStructure.TIM_Period;
			SERVO2_TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
			TIM_OC2Init(PORTE_TIMER, &SERVO2_TIM_OCInitStructure);
			TIM_OC2PreloadConfig(PORTE_TIMER, TIM_OCPreload_Enable);
			break;
		case GPIO_PORTE_3:
			SERVO3_TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
			SERVO3_TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
			SERVO3_TIM_OCInitStructure.TIM_Pulse = SERVO3_OPEN_Val * TIM_TimeBaseStructure.TIM_Period;
			SERVO3_TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
			TIM_OC3Init(PORTE_TIMER, &SERVO3_TIM_OCInitStructure);
			TIM_OC3PreloadConfig(PORTE_TIMER, TIM_OCPreload_Enable);
			break;
			
		default:
			break;
					
	}

  /* PWM1 Mode configuration: Channel1 */

}

void servo_fermer_porte(int num){

}