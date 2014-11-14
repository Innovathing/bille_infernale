#include "tir.h"
#include "arbre_horloge.h"

int main(void)
{
	arbre_horloge_init();
	tir_init();
	servo_init();
	while(1){}
    return 0;
}
