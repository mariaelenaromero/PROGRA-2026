#include <stdio.h>
#include <stdlib.h>
#include "modelo2Catedra_M19.c"
#include "modelo2definiciones.h"
#include "modelo2funciones.c"

#define EJ1
#define EJ2

int main(void)
{
#ifdef EJ1
    printf("\n ==== EJERCICIO 1 ==== \n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    int filas = 0;

    /* Imprimir grilla original */
    printGrilla(primerNodo, &filas);
    /* Ordenar grilla */
    ordenarGrilla(primerNodo, filas);
    /* Imprimir grilla ordenada */
    printGrilla(primerNodo, &filas);

#endif

#ifdef EJ2
    printf("\n ==== EJERCICIO 2 ==== \n");
    int numerosParaInsertar[] = {2, 4, 5, 6, 7, 8, 1, 3, 5, 4, 6, 8, 7, 9, 2};

    NodoArbol *raiz = NULL;
    /* Insertar numeros del vector de forma ordenada */
    for (int i = 0; i < 15; i++)
    {
        insOrdenado(&raiz, numerosParaInsertar[i]);
    }
    printTree(raiz, 0, 0);

#endif

    return 0;
}