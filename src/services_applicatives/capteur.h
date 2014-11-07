#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "stm32f10x.h"

typedef struct {
	GPIO_TypeDef* gpio;
	int pin;
	uint32_t extLine;
	
} Capteur_TypeDef;

void capteur_it_init(uint32_t);
void capteur_init(Capteur_TypeDef*);




#endif