#include "tir.h"
#include "poussoir.h"
#include "propulseur.h"
#include "galva.h"
#include "clock.h"

int decharge_nb;
int is_decharge;

void tir_init()
{
    poussoir_init();
    propulseur_init();
    galva_init();
}

void tir_perform_charge() {
	decharge_nb =0;
	is_decharge = 0;
	propulseur_init_fire();
}

void tir_perform_BOUM()
{
	propulseur_BOUM();
}

void tir_perform_mesure(int value)
{
		galva_do_afficher(value);
	if(value > 0x730 || is_decharge){
		if(decharge_nb > 100)
			is_decharge = 1;
		decharge_nb ++;
		propulseur_decharge(1);
	}
	else{
		decharge_nb=0;
		is_decharge = 0;
		propulseur_decharge(0);
	}
}
