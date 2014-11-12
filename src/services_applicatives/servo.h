#ifndef SERVO_H
#define SERVO_H
#include "stm32f10x.h"

void servo_init(int num);

void servo_init_private(GPIO_TypeDef* gpio, int pin);

void servo_fermer_porte(int num);


#endif