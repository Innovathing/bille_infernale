#include "capteur.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
void capteur_init(Capteur_TypeDef* cap){
	GPIO_InitTypeDef gpio_init = {cap->pin, GPIO_Speed_10MHz, GPIO_Mode_IPD};
	GPIO_Init(cap->gpio, &gpio_init);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,cap->pin);
	capteur_it_init(cap->extLine);

}
void capteur_it_init(uint32_t extLine){
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = extLine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	NVIC_InitTypeDef NVIC_InitStructure;
	switch(extLine){
		case EXTI_Line0: NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
		case EXTI_Line2: NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
		case EXTI_Line3: NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	}
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}