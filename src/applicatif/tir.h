#ifndef TIR_H
#define TIR_H

/*
Fonction qui s'occupe de mettre en place les timers & cie pour que le tir fonctionne
*/
void tir_init();

void tir_init_clocks();

/*
Gestion des actions lors de l'appuis sur le bouton de tir
*/
void tir_perform_charge();

void tir_perform_BOUM();

/*

*/
void tir_perform_mesure(int value);

#endif