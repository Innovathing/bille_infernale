#ifndef SERVO_H
#define SERVO_H
#include "stm32f10x.h"

typedef struct {
	GPIO_TypeDef* gpio;
	int pin;
	int pcent_ouvert;
	int pcent_ferme;
} Servo_TypeDef;

void servo_init(Servo_TypeDef* servo);

void servo_fermer_porte(Servo_TypeDef* servo, int degree);

#endif