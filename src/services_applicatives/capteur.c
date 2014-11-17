#include "capteur.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "misc.h"
#include "porte.h"
void capteur_init(){
		capteur_init_private(GPIO_CAPTEURS, PIN_CAPTEUR_0, EXTI_Line_CAPTEUR_0);
		capteur_init_private(GPIO_CAPTEURS, PIN_CAPTEUR_1, EXTI_Line_CAPTEUR_1);
		capteur_init_private(GPIO_CAPTEURS, PIN_CAPTEUR_2, EXTI_Line_CAPTEUR_2);

}

void capteur_init_private(GPIO_TypeDef* gpio, int pin, int extLine) {
	GPIO_InitTypeDef gpio_init = {pin, GPIO_Speed_10MHz, GPIO_Mode_IPU};
	GPIO_Init(gpio, &gpio_init);
	switch(pin){
		case PIN_CAPTEUR_2:
			pin = 3;
			break;
		case PIN_CAPTEUR_1:
			pin = 2;
			break;
		case PIN_CAPTEUR_0:
			pin = 0;
			break;
		default:
			break;
	}		
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,pin);
	capteur_it_init(extLine);
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
		case EXTI_Line0: 
			NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
			break;
		case EXTI_Line2: 
			NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
			break;
		case EXTI_Line3: 
			NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
			break;
	}
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI0_IRQHandler(void) {
	EXTI_ClearITPendingBit(EXTI_Line_CAPTEUR_0);
	porte_passage_capteur(0);
}

void EXTI2_IRQHandler(void) {
	EXTI_ClearITPendingBit(EXTI_Line_CAPTEUR_1);
	porte_passage_capteur(1);

}

void EXTI3_IRQHandler(void) {
	EXTI_ClearITPendingBit(EXTI_Line_CAPTEUR_2);
	porte_passage_capteur(2);

}