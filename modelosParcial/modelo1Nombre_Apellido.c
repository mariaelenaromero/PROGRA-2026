
#include <stdio.h>
#include <stdlib.h>
#include "modelo1header.h"
#include "modelo1Catedra_M16.c"
#include "modelo1funcs.c"

#define EJ1
#define EJ2

int main()
{

#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    /* Imprimir Grilla */
    printGrilla(primerNodo);

    /* Caminos que cumplen (ejercicio 2) */
    NodoGrilla *nodoRand = CATEDRA_NodoRandom(primerNodo);
    printf("El dato del nodo es: %c\n", nodoRand->dato);
    position(nodoRand);

    Posicion pos1 = {4, 6};
    Posicion pos2 = {0, 0};

    camino(pos1, pos2, primerNodo);

#endif // EJ1

#ifdef EJ2
    printf("--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    customElement *vec = CATEDRA_CrearVector(&tamanio);
    printVector(vec, tamanio);

    NodoDoble *first = NULL;
    ordenarLista(vec, &tamanio, &first);
    vec = (customElement *)realloc(vec, tamanio * sizeof(customElement));
    printVector(vec, tamanio);
    printlist(first);

#endif // EJ2
    return 0;
}