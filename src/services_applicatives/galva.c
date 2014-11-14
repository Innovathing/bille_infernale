#include "galva.h"
#include <stm32f10x_gpio.h>
#include "tim.h"
#include "stm32f10x_tim.h"

void galva_init()
{
  GPIO_InitTypeDef gpio_init = {PIN_GALVA, GPIO_Speed_10MHz, GPIO_Mode_AF_PP};
	GPIO_Init(GPIO_GALVA, &gpio_init);

	

	
}
 
void galva_do_afficher(uint16_t value) {
	
}