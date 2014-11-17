#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "stm32f10x.h"
#define AH_GPIOC

#define GPIO_CAPTEURS GPIOC

#define PIN_CAPTEUR_0 GPIO_Pin_0
#define EXTI_Line_CAPTEUR_0 EXTI_Line0

#define PIN_CAPTEUR_1 GPIO_Pin_2
#define EXTI_Line_CAPTEUR_1 EXTI_Line2

#define PIN_CAPTEUR_2 GPIO_Pin_3
#define EXTI_Line_CAPTEUR_2 EXTI_Line3


void capteur_it_init();
void capteur_init();
void capteur_init_private(GPIO_TypeDef* gpio, int pin, int exti_line);




#endif