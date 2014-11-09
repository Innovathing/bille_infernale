#include "arbre_horloge.h"
#include "clock.h"
#include "stm32f10x_rcc.h"

void arbre_horloge_init() {
	CLOCK_Configure();

	#ifdef AH_TIM2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	#endif

	#ifdef AH_TIM3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	#endif

	#ifdef AH_TIM4
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	#endif

	#ifdef AH_TIM5
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	#endif

	#ifdef AH_TIM6
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	#endif

	#ifdef AH_TIM7
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
	#endif

	#ifdef AH_TIM1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	#endif

	#ifdef AH_TIM8
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
	#endif

	#ifdef AH_ADC1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	#endif

	#ifdef AH_ADC2
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);
	#endif

	#ifdef AH_ADC3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);
	#endif

	#ifdef AH_GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	#endif

	#ifdef AH_GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	#endif

	#ifdef AH_GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	#endif

	#ifdef AH_GPIOD
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	#endif

	#ifdef AH_GPIOE
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	#endif

	#ifdef AH_GPIOF
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	#endif

	#ifdef AH_GPIOG
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);
	#endif

	#ifdef AH_AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	#endif
}
