#ifndef GALVA_H
#define GALVA_H

#include "stm32f10x.h"

#define AH_GPIOA
#define GPIO_GALVA GPIOA
#define PIN_GALVA GPIO_Pin_8

void galva_init();

void galva_do_afficher(uint16_t value);
#endif
