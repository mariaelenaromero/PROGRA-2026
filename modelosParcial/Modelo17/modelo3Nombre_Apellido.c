
#include <stdio.h>
#include <stdlib.h>
#include "modelo3header.h"
#include "modelo3Catedra_M17.c"
#include "modelo3funcs.c"

#define EJ1
#define EJ2

int main()
{

#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    int filas = 0;
    /* Imprimir Grilla */
    printGrilla(primerNodo, &filas);

    /* Info Item B  */
    NodoGrilla **targets;
    int size, distancia;
    NodoGrilla *start = CATEDRA_InfoRandom(primerNodo, &targets, &size, &distancia);

    /* Imprimir start, targets y distancia */
    printf("start: %c , size: %d , distancia: %d targets:", start->dato, size, distancia);
    for (int i = 0; i < size; i++)
    {
        printf("%c ", targets[i]->dato);
    }
    printf("\n\n");
    /* Imprimir los caminos que cumplan */
    camino(start, targets, size, distancia);

#endif // EJ1

#ifdef EJ2
    printf("--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    Node *first = CATEDRA_CrearLista();

    /* Item a --> Lista original */
    printlist(first);

    /* item b --> Lista original "marcada" */
    printlistMarc(first);

    /* Item c --> Funcion */
    uint8_t *vec = eliminardeLista(first, &tamanio);

    /* item d --> Lista final y vector*/
    printlistMarc(first);
    printVector(vec, tamanio);
#endif // EJ2
    return 0;
}