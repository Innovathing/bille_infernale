#include "tir.h"
#include "poussoir.h"
#include "propulseur.h"
#include "galva.h"
#include "clock.h"

void tir_init()
{
		tir_init_clocks();
    poussoir_init();
    propulseur_init();
    galva_init();
}

void tir_perform_charge() {
	propulseur_init_fire();
}

void tir_perform_BOUM()
{
	propulseur_BOUM();
}

void tir_perform_mesure(int value)
{
		galva_do_afficher(value);
}
