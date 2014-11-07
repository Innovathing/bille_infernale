#include "porte.h"

#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"


void porte_init_gpio(GPIO_TypeDef* gpio){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//todo : define
}
void porte_init() {
	Capteur_TypeDef cap1 = {Portes_GPIO, Porte_1_Capteur_Pin, Porte_1_EXTI_Line};
	Capteur_TypeDef cap2 = {Portes_GPIO, Porte_2_Capteur_Pin, Porte_2_EXTI_Line};
	Capteur_TypeDef cap3 = {Portes_GPIO, Porte_3_Capteur_Pin, Porte_3_EXTI_Line};
	capteur_init(&cap1);
	capteur_init(&cap2);
	capteur_init(&cap3);
	Servo_TypeDef serv1 = {Portes_GPIO, Porte_1_Servo_Pin, 4, 8}; //attention on va perdre du temps la a verifier ces valeurs wesh
	Servo_TypeDef serv2 = {Portes_GPIO, Porte_2_Servo_Pin, 10, 4};
	Servo_TypeDef serv3 = {Portes_GPIO, Porte_3_Servo_Pin, 4, 8};
	servo_init(&serv1);
	servo_init(&serv2);
	servo_init(&serv3);

	ascenseur[0].capteur = cap1;
	ascenseur[0].servo = serv1;
	ascenseur[1].capteur = cap2;
	ascenseur[1].servo = serv2;
	ascenseur[2].capteur = cap3;
	ascenseur[2].servo = serv3;
	

}