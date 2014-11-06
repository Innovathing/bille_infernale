#include "poussoir.h"
#include "stm32f10x_gpio.h"
#include "tir.h"
#include "stm32f10x_exti.h"

static int exti_state;

void poussoir_init()
{
	RCC_APB2PeriphClockCmd(GPIO_FIRE_RCC, ENABLE);
	GPIO_InitTypeDef gpio_init = {PIN_FIRE, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING};
	GPIO_Init(GPIO_FIRE, &gpio_init);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,0);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = GPIO_EXTI;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
  exti_state = EXTI_STATE_WAIT_RISING;

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = GPIO_NVIC_EXTI;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Set_Wait_Rising()
{
		EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = GPIO_EXTI;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void EXTI_Set_Wait_Falling()
{
		EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = GPIO_EXTI;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void mask_EXTI()
{
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = GPIO_EXTI;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void unmask_EXTI()
{
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = GPIO_EXTI;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}


void EXTI1_IRQHandler(void) {
		EXTI_ClearITPendingBit(GPIO_EXTI);
		if(exti_state == EXTI_STATE_WAIT_RISING)
		{
			exti_state = EXTI_STATE_WAIT_FALLING;
			mask_EXTI();
			tir_perform_charge();
			unmask_EXTI();
			EXTI_Set_Wait_Falling();
		} else {
			exti_state = EXTI_STATE_WAIT_RISING;
			mask_EXTI();
			tir_perform_BOUM();
			unmask_EXTI();
			EXTI_Set_Wait_Rising();
		}
    
}
