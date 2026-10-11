#include <stdio.h>
#include <stdlib.h>
#include "modelo4CATEDRA_M18.c"
#include "modelo4header.h"
#include "modelo4funcs.c"

int main(void)
{
    printf("\n\n--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrillaIrregular();
    int *fmin = 0;
    int *elemsfil = 0;

    printf("\nOriginal:\n");

    printGrilla(primerNodo);

    printf("\nA)\n");

    delUltNodos(primerNodo, 2, 3);
    printGrilla(primerNodo);

    printf("\nB)\n");

    difFilsejB(primerNodo, 6);

    printf("\nC)\n");

    fixGrilla(primerNodo);
    printGrilla(primerNodo);

    printf("\n\n");

    freeGrilla(&primerNodo);

    return 0;
}