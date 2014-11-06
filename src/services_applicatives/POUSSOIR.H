#ifndef POUSSOIR_H
#define POUSSOIR_H

/*
 * Bouton fire sur le GPIOA0 car il est sur EXTI0.
 */
#define PIN_FIRE GPIO_Pin_1
#define GPIO_FIRE GPIOA
#define GPIO_FIRE_RCC RCC_APB2Periph_GPIOA
#define GPIO_EXTI EXTI_Line1
#define GPIO_NVIC_EXTI EXTI1_IRQn

#define EXTI_STATE_WAIT_RISING 0
#define EXTI_STATE_WAIT_FALLING 1

void poussoir_init();

#endif