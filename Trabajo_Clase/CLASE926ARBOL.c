#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "CLASE926arboldef.h"
#include "CLASE926arbolfuncs.c"

int main()
{
    Nodo *PrimerNodo = NULL;

    insOrdenado(&PrimerNodo, 10);
    insOrdenado(&PrimerNodo, 5);
    insOrdenado(&PrimerNodo, 15);
    insOrdenado(&PrimerNodo, 7);
    insOrdenado(&PrimerNodo, 20);
    insOrdenado(&PrimerNodo, 18);
    insOrdenado(&PrimerNodo, 23);

    find(&PrimerNodo, 0);
    find(&PrimerNodo, 23);
    find(&PrimerNodo, 7);
    find(&PrimerNodo, 18);
    find(&PrimerNodo, 9);
    find(&PrimerNodo, 100);

    return 0;
}
