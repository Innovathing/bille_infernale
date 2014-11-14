#ifndef SERVO_H
#define SERVO_H
#define AH_TIM4
#define AH_GPIOB
#define AH_AFIO

#define PORTE_TIMER TIM4


#define GPIO_PORTE GPIOB
#define GPIO_PORTE_1 GPIO_Pin_6
#define GPIO_PORTE_2 GPIO_Pin_7
#define GPIO_PORTE_3 GPIO_Pin_8
#include "stm32f10x.h"

void servo_init();

void servo_init_private(GPIO_TypeDef* gpio, int pin);

void servo_fermer_porte(int num);
void servo_ouvrir_porte(int num);
void servo_init_general();

#endif