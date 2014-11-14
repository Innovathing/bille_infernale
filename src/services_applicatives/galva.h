#ifndef GALVA_H
#define GALVA_H

#include "stm32f10x.h"


#define AH_GPIOB
#define AH_AFIO
#define AH_TIM2

#define GPIO_GALVA GPIOB
#define PIN_GALVA GPIO_Pin_10
#define GALVA_TIMER TIM2

void galva_init();

void galva_do_afficher(uint16_t value);
#endif
