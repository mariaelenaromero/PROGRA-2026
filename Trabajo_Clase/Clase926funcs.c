#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "def.h"

doblenodo_t *crear_nodo(int dato)
{
    doblenodo_t *nodo = (doblenodo_t *)malloc(sizeof(doblenodo_t));
    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo %d\n", dato);
        return NULL;
    }
    nodo->num = dato;
    nodo->next = NULL;
    nodo->prev = NULL;
    return nodo;
}

void ins_first(doblenodo_t **first, doblenodo_t **last, int dato)
{
    doblenodo_t *nuevoNodo = crear_nodo(dato);
    if ((*first) == NULL)
    {
        *first = nuevoNodo;
        *last = nuevoNodo;
        return;
    }
    (*first)->prev = nuevoNodo;
    nuevoNodo->next = *first;
    (*first) = nuevoNodo;
    return;
}

void del_last(doblenodo_t **last, doblenodo_t **first)
{
    if ((*last) == NULL || (*last)->prev == NULL)
    {
        free(*last);
        *last = NULL;
        *first = NULL;
        return;
    }
    doblenodo_t *aux = (*last)->prev;
    free(*last);
    aux->next = NULL;
    *last = aux;
    return;
}

void ins_last(doblenodo_t **first, doblenodo_t **last, int dato)
{
    doblenodo_t *nuevoNodo = crear_nodo(dato);
    if ((*last) == NULL)
    {
        (*first) = nuevoNodo;
        (*last) = nuevoNodo;
        return;
    }
    (*last)->next = nuevoNodo;
    nuevoNodo->prev = *last;
    (*last) = nuevoNodo;
    return;
}

void del_first(doblenodo_t **first, doblenodo_t **last)
{
    doblenodo_t *aux = *first;
    if ((*first) == NULL || (*first)->next == NULL)
    {
        free(*first);
        *last = NULL;
        *first = NULL;
        return;
    }
    *first = (*first)->next;
    (*first)->prev = NULL;
    free(aux);
    return;
}

void printlist(doblenodo_t *first, doblenodo_t *last)
{
    doblenodo_t *auxi = first;
    doblenodo_t *auxl = last;

    while (auxi != NULL)
    {
        printf("%d -> ", auxi->num);
        auxi = auxi->next;
    }
    printf("\n");
    while (auxl != NULL)
    {
        printf("%d -> ", auxl->num);
        auxl = auxl->prev;
    }
    printf("\n");
    return;
}
