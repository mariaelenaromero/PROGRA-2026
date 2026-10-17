/* Modelo Parcial
 * - Escriba su código sobre este archivo.
 * - Las funciones deben estar definidas en el archivo funciones.c
 */

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ultimomodelodefiniciones.h"
#include "ultimomodelofunciones.c"
#include "ultimomodeloCatedra.c"

int main()
{
#ifdef EJ1
    /* Comienzo de su codigo */
    /* Fin de su codigo */
    // EJ 1 ARBOL dado un arbol ordenado modifique findNode() para que, ademas de imprimir el camino hasta el nodo, sume los valores de todos los nodos por los que pasa e imprima el resultado
    printf("\n ==== EJERCICIO 1 ==== \n");
    int numerosParaInsertar[] = {2, 4, 5, 6, 7, 8, 1, 3, 5, 4, 6, 8, 7, 9, 2};

    NodoArbol *raiz = NULL;
    /* Insertar numeros del vector de forma ordenada */
    for (int i = 0; i < 15; i++)
    {
        insOrdenado(&raiz, numerosParaInsertar[i]);
    }
    printf("ARBOL:");
    printTree(raiz, 0);
    printf("\n\n");
    find(&raiz, 2);
    find(&raiz, 8);
    find(&raiz, 0);
    find(&raiz, 9);
    find(&raiz, 5);

#endif

#ifdef EJ2
    Node *primerNodo;
    Node *ultimoNodo;
    NodoSimple *tempsfirst = NULL;
    CATEDRA_CrearListaDoble(&primerNodo, &ultimoNodo);
    printf("\nORIGINAL:\n");
    printlist(primerNodo, ultimoNodo);
    borroHumNeg(&primerNodo, &ultimoNodo);
    printf("\nBORRO HUM NEG:\n");
    printlist(primerNodo, ultimoNodo);
    printf("\n\nIMPRIMO SOLO CONDICION:\n");
    printlistH80T2(primerNodo, ultimoNodo);
    printf("\n\nLISTA CON TEMPS:");
    crearLista(primerNodo, &tempsfirst);
    printlistsimple(tempsfirst);
    freeList(&primerNodo);

    /* Comienzo de su codigo */
    /* Fin de su codigo */
#endif
    printf("\nverificacion de bucles\n\n");
    return 0;
}
