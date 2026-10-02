#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "CLASE926arboldef.h"

Nodo *createNodo(int nuevoDato)
{
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    if (!nuevoNodo)
    {
        perror("Error en la creacion del nodo\n");
        exit(1);
    }

    nuevoNodo->dato = nuevoDato;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

void insOrdenado(Nodo **PrimerNodo, int nuevoDato)
{
    Nodo *nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL)
    {
        *PrimerNodo = nuevoNodo;
        return;
    }

    Nodo *temp = *PrimerNodo;

    while (1)
    {
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
            temp = temp->der;
        }
    }
}

void find(Nodo **PrimerNodo, int datof)
{
    Nodo *temp = *PrimerNodo;
    while (1)
    {
        printf("%d->", temp->dato);
        if (temp->dato == datof)
        {
            printf("\n");
            return;
        }
        else if (temp->dato > datof)
        {
            if (temp->izq == NULL)
            {
                printf("no esta\n");
                return;
            }
            temp = temp->izq;
        }
        else if (temp->dato < datof)
        {
            if (temp->der == NULL)
            {
                printf("no esta \n");
                return;
            }
            temp = temp->der;
        }
    }
}