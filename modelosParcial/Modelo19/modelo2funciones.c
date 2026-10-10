/* Utilice este archivo para escribir sus funciones */
#include <stdint.h>
#include <stdio.h>
#include "modelo2definiciones.h"

/* === EJERCICIO 1 === */
void printGrilla(NodoGrilla *first, int *filas)
{
    NodoGrilla *aux1 = first;
    NodoGrilla *aux2 = first;

    while (aux1 != NULL)
    {

        while (aux2 != NULL)
        {
            printf("%d ", aux2->dato);
            aux2 = aux2->right;
        }
        printf("\n");
        aux1 = aux1->down;
        aux2 = aux1;
        (*filas)++;
    }

    printf("\n");
}
void ordenarGrilla(NodoGrilla *first, int filas)
{
    NodoGrilla *aux1 = first;
    NodoGrilla *aux2 = aux1->down;
    NodoGrilla *aux3 = first;
    while (aux3 != NULL)
    {
        for (int i = 0; i < filas; i++)
        {
            aux1 = aux3;
            aux2 = aux1->down;
            while (aux1->down != NULL)
            {
                if (aux2->dato < aux1->dato)
                {
                    aux1->nextDato = aux2->dato;
                    aux2->dato = aux1->dato;
                    aux1->dato = aux1->nextDato;
                }
                aux1 = aux2;
                aux2 = aux2->down;
            }
        }
        aux3 = aux3->right;
        aux1 = aux3;
        if (aux1 == NULL)
        {
            return;
        }
        aux2 = aux1->down;
    }
}
/* === EJERCICIO 2 === */
NodoArbol *createNodo(int nuevoDato)
{
    NodoArbol *nuevoNodo = malloc(sizeof(NodoArbol));
    if (!nuevoNodo)
    {
        perror("Error en la creacion del nodo\n");
        exit(1);
    }
    nuevoNodo->cantidad = 1;
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

void insOrdenado(NodoArbol **PrimerNodo, int nuevoDato)
{
    NodoArbol *nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL)
    {
        *PrimerNodo = nuevoNodo;
        return;
    }

    NodoArbol *temp = *PrimerNodo;

    while (1)
    {
        if (temp->dato == nuevoNodo->dato)
        {
            temp->cantidad++;
            return;
        }
        if (temp->dato > nuevoNodo->dato)
        {

            if (temp->izq == NULL)
            {
                temp->izq = nuevoNodo;
                return;
            }
            temp = temp->izq;
        }

        else if (temp->dato < nuevoNodo->dato)
        {
            if (temp->der == NULL)
            {
                temp->der = nuevoNodo;
                return;
            }
            if (temp->der->dato == nuevoNodo->dato)
            {
                temp->der->cantidad++;
                return;
            }
            temp = temp->der;
        }
    }
}

void printTree(NodoArbol *n, int level, int isLeft)
{
    if (n == NULL)
    {
        return;
    }
    printf("\n");
    for (int i = 0; i < level; i++)
    {
        printf("  ");
    }
    printf("cant %d: %d", n->dato, n->cantidad);
    printTree(n->izq, level + 1, 0);
    printTree(n->der, level + 1, 0);
}

void printcant()
{
}