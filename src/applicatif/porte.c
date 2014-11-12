#include "porte.h"

#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"


void porte_init_gpio(GPIO_TypeDef* gpio){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//todo : define
}
void porte_init() {
	capteur_init(1);
	capteur_init(2);
	capteur_init(3);
	
	servo_init(1);
	servo_init(2);
	servo_init(3);
	

}