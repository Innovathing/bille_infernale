#include "porte.h"

#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"


void porte_init_gpio(GPIO_TypeDef* gpio){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//todo : define
}
void porte_init() {
	capteur_init();
	
	servo_init();
	

}

void porte_passage_capteur(int capnum) {
	servo_fermer_porte(capnum);
}