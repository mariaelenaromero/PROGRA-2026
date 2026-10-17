/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>
#include <stdlib.h>

/*=== EJERCICIO 1 ===*/

void printGrilla(NodoGrilla *first)
{
    NodoGrilla *auxabajo = first;
    NodoGrilla *auxder = first;

    while (auxabajo != NULL)
    {

        while (auxder != NULL)
        {
            printf("%c", auxder->dato);
            auxder = auxder->right;
        }
        printf("\n");
        auxabajo = auxabajo->down;
        auxder = auxabajo;
    }

    printf("\n");
}

void modifGrillaNext(NodoGrilla *first)
{
    NodoGrilla *auxabajo = first;
    NodoGrilla *auxder = first;
    int vecinos = 0;

    while (auxabajo != NULL)
    {
        while (auxder != NULL)
        {
            vecinos = 0;
            if (auxder->right != NULL)
            {
                if (auxder->right->dato == '#')
                {
                    vecinos++;
                }
            }
            if (auxder->down != NULL)
            {
                if (auxder->down->dato == '#')
                {
                    vecinos++;
                }
            }
            if (auxder->up != NULL)
            {
                if (auxder->up->dato == '#')
                {
                    vecinos++;
                }
            }
            if (auxder->left != NULL)
            {
                if (auxder->left->dato == '#')
                {
                    vecinos++;
                }
            }
            if (vecinos == 0 || vecinos == 4)
            {
                auxder->nextDato = ' ';
            }
            if (vecinos == 2 || vecinos == 1)
            {
                auxder->nextDato = '#';
            }
            if (vecinos == 3)
            {
                auxder->nextDato = auxder->dato;
            }
            auxder = auxder->right;
        }
        auxabajo = auxabajo->down;
        auxder = auxabajo;
    }
}

void modifGrilla(NodoGrilla *first)
{
    NodoGrilla *auxabajo = first;
    NodoGrilla *auxder = first;

    while (auxabajo != NULL)
    {

        while (auxder != NULL)
        {
            auxder->dato = auxder->nextDato;
            auxder = auxder->right;
        }
        auxabajo = auxabajo->down;
        auxder = auxabajo;
    }
}

/* === EJERCICIO 2 === */

void printNodo(NodoArbol *raiz)
{
    printf("Dato raiz: %d\n", raiz->dato);
    printf("Hijo izq-> dato: %d dist:%d\n", raiz->izq.nodo->dato, raiz->izq.distancia);
    printf("Hijo der-> dato: %d dist:%d\n\n", raiz->der.nodo->dato, raiz->der.distancia);
}

void findconprint(NodoArbol **PrimerNodo, int datofind)
{
    NodoArbol *temp = *PrimerNodo;
    if ((*PrimerNodo) == NULL)
    {
        return;
    }
    int suma = 0;
    printf("Camino hacia %d: %d", datofind, temp->dato);
    while (1)
    {
        if (temp->dato == datofind)
        {
            printf(" Suma de las distancias = %d", suma);
            printf("\n\n");
            return;
        }
        else if (temp->dato > datofind)
        {
            if (temp->izq.nodo == NULL)
            {
                printf("->NULL no esta el dato, suma de las distancias recorridas al buscarlo = %d\n\n", suma);
                return;
            }
            printf("->(%d-%d)", temp->izq.nodo->dato, temp->izq.distancia);
            suma += temp->izq.distancia;
            temp = temp->izq.nodo;
        }
        else if (temp->dato < datofind)
        {
            if (temp->der.nodo == NULL)
            {
                printf("->NULL no esta el dato, suma de las distancias recorridas al buscarlo = %d\n\n", suma);
                return;
            }
            printf("->(%d-%d)", temp->der.nodo->dato, temp->der.distancia);
            suma += temp->der.distancia;
            temp = temp->der.nodo;
        }
    }
    return;
}
int find(NodoArbol **PrimerNodo, int datofind)
{
    NodoArbol *temp = *PrimerNodo;
    if ((*PrimerNodo) == NULL)
    {
        return 0;
    }
    int suma = 0;
    while (1)
    {
        if (temp->dato == datofind)
        {
            return suma;
        }
        else if (temp->dato > datofind)
        {
            if (temp->izq.nodo == NULL)
            {
                return suma;
            }
            suma += temp->izq.distancia;
            temp = temp->izq.nodo;
        }
        else if (temp->dato < datofind)
        {
            if (temp->der.nodo == NULL)
            {
                return suma;
            }
            suma += temp->der.distancia;
            temp = temp->der.nodo;
        }
    }
    return suma;
}
void comparoDist(int datos[], NodoArbol **raiz)
{
    int tamanio = sizeof(*datos), sumadist = 0;
    for (int i = 0; i < tamanio; i++)
    {
        sumadist = 0;
        sumadist = find(raiz, datos[i]);
        if (sumadist > 20)
        {
            printf("La distancia hasta %d es %d (mayor a 20), modifico\n\n", datos[i], sumadist);
            modifDist(datos[i], raiz, sumadist);
        }
    }
}

void modifDist(int datofind, NodoArbol **raiz, int sumadist)
{
    NodoArbol *temp = *raiz;
    while (1)
    {
        if (temp->dato == datofind)
        {
            return;
        }
        else if (temp->dato > datofind)
        {
            if (temp->izq.nodo == NULL)
            {
                return;
            }
            else if (temp->izq.nodo->dato == datofind)
            {
                temp->izq.distancia = (temp->izq.distancia) - (sumadist - 20);
                return;
            }
            temp = temp->izq.nodo;
        }
        else if (temp->dato < datofind)
        {
            if (temp->der.nodo == NULL)
            {
                return;
            }
            else if (temp->der.nodo->dato == datofind)
            {
                temp->der.distancia = (temp->der.distancia) - (sumadist - 20);
                return;
            }
            temp = temp->der.nodo;
        }
    }
}
