#include <stdio.h>
#include <stdlib.h>
#include "Catedra_M20.c"
#include "definiciones.h"
#include "funciones.c"

#define EJ1
#define EJ2

int main(void)
{
#ifdef EJ1
    printf("\n==== EJERCICIO 1 ====\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();

    /* Imprimir grilla original */
    printf("\nORIGINAL:\n");
    printGrilla(primerNodo);

    /* Editar gtilla */
    modifGrillaNext(primerNodo);
    modifGrilla(primerNodo);

    /* Imprimir grilla resultante */
    printf("\nMODIFICADA:\n");
    printGrilla(primerNodo);

#endif

#ifdef EJ2
    printf("\n ==== EJERCICIO 2 ==== \n\n");
    NodoArbol *raiz = CATEDRA_CrearArbol();

    /* Imprimir raiz */
    printNodo(raiz);

    /* Encontrar nodo y distancia */
    findconprint(&raiz, 1); // imprimo un par para ver que lo hice bien
    findconprint(&raiz, 12);
    findconprint(&raiz, 16);
    findconprint(&raiz, 0);
    findconprint(&raiz, 100);

    /* Modificar distancia */
    int datos[4] = {1, 6, 12, 16};
    comparoDist(datos, &raiz); // FUNCION QUE MODIFICA LAS DISTANCIAS
    findconprint(&raiz, 16);   // COMPRUEBO QUE FUNCIONE (solo el 16 se pasaba)

#endif
    return 0;
}
