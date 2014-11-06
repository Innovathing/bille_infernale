#ifndef PROPULSEUR_H
#define PROPULSEUR_H
 
#define GPIO_PROPULSEUR_1 RCC_APB2Periph_GPIOA
 
#define GPIO_TIR GPIOA
#define GPIO_TIR_PIN GPIO_Pin_3
 
#define GPIO_DECHARGE GPIOA
#define GPIO_DECHARGE_PIN GPIO_Pin_5
 
#define PROPULSEUR_TIMER TIM3
#define TIM_NVIC_PROPULSEUR TIM3_IRQn
 
#define PROPULSEUR_ADC ADC1
 
void propulseur_init();
void propulseur_init_fire();
void propulseur_BOUM();

#endif