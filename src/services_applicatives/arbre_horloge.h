/**
 * \file
 * \brief Gestion de l'arbre d'horloge pour le projet
 * \author Hugo DJEMAA (INSA - Toulouse, France)
 * \author Jérémie BOUTOILLE (INSA - Toulouse, France)
 * \author Mickael GOUBIN (INSA - Toulouse, France)
 * \author David LIVET (INSA - Toulouse, France)
 * \version 1.0
 * \date 09/10/2014
 *
 * Ce service applicatif active les arbres d'horloges dont le projet à besoin
 *
 */

#ifndef __ARBRE_HORLOGE_H
#define __ARBRE_HORLOGE_H

/**
* \brief Active les horloges
*
* Active les horloges à l'aide des constantes suivantes :
* - Timers : AH_TIM1, AH_TIM2, AH_TIM3, AH_TIM4, AH_TIM5, AH_TIM6, AH_TIM7, AH_TIM8
* - Adc : AH_ADC1, AH_ADC2, AH_ADC3
* - GPIO : AH_GPIOA, AH_GPIOB, AH_GPIOC, AH_GPIOD, AH_GPIOE, AH_GPIOF, AH_GPIOG
* - AH_AFIO
*/
void arbre_horloge_init();

#endif
