#ifndef PORTE_H
#define PORTE_H

#include "stm32f10x.h"
#include "capteur.h"
#include "servo.h"
#define Portes_GPIO GPIOB
#define Porte_1_Servo_Pin 4

#define Porte_2_Servo_Pin 5

#define Porte_3_Servo_Pin 6

void porte_init_gpio(GPIO_TypeDef* gpio);
void porte_init();

void porte_passage_capteur(int capnum);

#endif
