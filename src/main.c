#include "tir.h"
#include "arbre_horloge.h"
#include "porte.h"
int main(void)
{
	arbre_horloge_init();
	tir_init();
	porte_init();
	while(1){}
    return 0;
}
