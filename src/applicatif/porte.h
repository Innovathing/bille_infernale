#ifndef PORTE_H
#define PORTE_H

#include "stm32f10x.h"
#include "capteur.h"
#include "servo.h"
#define Portes_GPIO GPIOB
#define Porte_1_Capteur_Pin 0
#define Porte_1_Servo_Pin 4

#define Porte_2_Capteur_Pin 2 
#define Porte_2_Servo_Pin 5

#define Porte_3_Capteur_Pin 3
#define Porte_3_Servo_Pin 6
#define Porte_1_EXTI_Line EXTI_Line0
#define Porte_2_EXTI_Line EXTI_Line2
#define Porte_3_EXTI_Line EXTI_Line3



typedef struct {
	Capteur_TypeDef capteur;
	Servo_TypeDef servo;
} Porte_TypeDef;

Porte_TypeDef ascenseur[3];
void porte_init_gpio(GPIO_TypeDef* gpio);
void porte_init();

void porte_fermer(int capteurPin);

#endif
