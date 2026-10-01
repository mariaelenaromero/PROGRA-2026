#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "def.h"

nodo_t *crear_nodo(int dato)
{
    nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo %d\n", dato);
        return NULL;
    }
    nodo->num = dato;
    nodo->next = NULL;
    return nodo;
}

nodo_t *ins_first(nodo_t *first, int dato)
{
    nodo_t *nuevoNodo = crear_nodo(dato);
    nuevoNodo->next = first;
    return nuevoNodo;
}

void del_last(nodo_t **first)
{
    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }
    nodo_t *aux = *first;
    while (aux->next->next != NULL)
    {
        aux = aux->next;
    }
    nodo_t *aux2 = aux->next;
    free(aux2);
    aux->next = NULL;
}

void ins_last(nodo_t *first, int dato)
{
    nodo_t *nuevoNodo = crear_nodo(dato);
    nodo_t *aux = first;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = nuevoNodo;
    return;
}

void del_first(nodo_t **first)
{
    nodo_t *aux = *first;
    *first = (*first)->next;
    free(aux);
    return;
}

void printlist(nodo_t *first)
{
    nodo_t *aux = first;

    while (aux != NULL)
    {
        printf("%d -> ", aux->num);
        aux = aux->next;
    }
    printf("\n");
}
