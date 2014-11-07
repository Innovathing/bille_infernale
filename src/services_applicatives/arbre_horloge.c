#include "arbre_horloge.h"
#include "clock.h"
#include "stm32f10x_rcc.h"

void arbre_horloge_init() {
	CLOCK_Configure();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
}