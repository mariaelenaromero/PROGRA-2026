#include "modelo3header.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

Posicion position(NodoGrilla *random);
void printCamino(Posicion pos1, Posicion pos2, NodoGrilla *first);
void camino(NodoGrilla *start, NodoGrilla *targets[], int size, int dist);
void printlist(Node *first);
void printlistMarc(Node *first);
uint8_t *eliminardeLista(Node *first, int *tamanio);
void del_mid(Node *nodo);

/* Funciones Ejercicio 1 */
void printGrilla(NodoGrilla *first, int *filas)
{
    NodoGrilla *aux1 = first;
    NodoGrilla *aux2 = first;

    while (aux1 != NULL)
    {

        while (aux2 != NULL)
        {
            printf("%c ", aux2->dato);
            aux2 = aux2->right;
        }
        printf("\n");
        aux1 = aux1->down;
        aux2 = aux1;
        (*filas)++;
    }

    printf("\n");
}
Posicion position(NodoGrilla *random)
{
    NodoGrilla *auxleft = random;
    NodoGrilla *auxup = random;
    Posicion fc = {-1, -1};
    while (auxleft != NULL)
    {
        auxleft = auxleft->left;
        fc.columna += 1;
        while (auxup != NULL)
        {
            auxup = auxup->up;
            fc.fila += 1;
        }
    }
    return fc;
}
void camino(NodoGrilla *start, NodoGrilla *targets[], int size, int dist)
{
    Posicion posStart = position(start);
    Posicion posTargets[size];
    int difcol = 0, distancia = 0, secumple = 0;
    int diffil = 0;
    for (int i = 0; i < size; i++)
    {
        posTargets[i] = position(targets[i]);
        difcol = (posTargets[i].columna - posStart.columna);
        diffil = (posTargets[i].fila - posStart.fila);
        if (difcol < 0)
        {
            difcol = difcol * (-1);
        }
        if (diffil < 0)
        {
            diffil = diffil * (-1);
        }
        distancia = difcol + diffil;
        if (distancia == dist)
        {
            printf("Camino entre %c y %c: \n", start->dato, targets[i]->dato);
            printCamino(posStart, posTargets[i], start);
            secumple = 1;
        }
    }
    if (secumple == 0)
    {
        printf("Ninguno estaba a la distancia pedida\n");
    }
}
void printCamino(Posicion pos1, Posicion pos2, NodoGrilla *start)
{

    NodoGrilla *aux = start;
    if (pos1.fila < pos2.fila)
    {
        while (pos1.fila != pos2.fila)
        {
            printf("%c d ", aux->dato);
            aux = aux->down;
            pos1.fila += 1;
        }
    }
    if (pos1.fila > pos2.fila)
    {
        while (pos1.fila != pos2.fila)
        {
            printf("%c ^ ", aux->dato);
            aux = aux->up;
            pos1.fila -= 1;
        }
    }
    if (pos1.columna < pos2.columna)
    {
        while (pos1.columna != pos2.columna)
        {
            printf("%c > ", aux->dato);
            aux = aux->right;
            pos1.columna += 1;
        }
    }
    if (pos1.columna > pos2.columna)
    {
        while (pos1.columna != pos2.columna)
        {
            printf("%c < ", aux->dato);
            aux = aux->left;
            pos1.columna -= 1;
        }
    }
    printf("%c", aux->dato);
    printf("\n\n");
}
/* Funciones Ejercicio 2 */

void printlist(Node *first)
{
    Node *aux = first->next;
    printf("%d -> ", first->dato);
    while (aux != first)
    {
        printf("%d -> ", aux->dato);
        aux = aux->next;
    }
    printf("NULL\n");
    return;
}

void printlistMarc(Node *first)
{
    Node *aux = first->next;
    if ((first->dato & 0b00000011) == 3)
    {
        printf("(%d) -> ", first->dato);
    }
    else
    {
        printf("%d -> ", first->dato);
    }
    while (aux != first)
    {
        if ((aux->dato & 0b00000011) == 3)
        {
            printf("(%d) -> ", aux->dato);
        }
        else
        {
            printf("%d -> ", aux->dato);
        }
        aux = aux->next;
    }
    printf("NULL\n");
    return;
}

uint8_t *eliminardeLista(Node *first, int *tamanio)
{
    uint8_t *vec = NULL;
    Node *aux = first;
    int pos = 2;
    while (aux->next != first)
    {
        if (((aux->next->dato & 0b00000011) == 3) && (pos % 2 == 0))
        {
            (*tamanio)++;
            if (vec == NULL)
            {
                vec = malloc(sizeof(uint8_t));
                if (vec == NULL)
                {
                    printf("Error de asignación de memoria");
                    return NULL;
                }
                vec[(*tamanio) - 1] = aux->next->dato;
            }
            else
            {
                vec = (uint8_t *)realloc(vec, sizeof(uint8_t) * (*tamanio));
                if (vec == NULL)
                {
                    printf("Error de asignación de memoria");
                    return NULL;
                }
                vec[(*tamanio) - 1] = aux->next->dato;
            }
            del_mid(aux);
        }
        else
        {
            aux = aux->next;
            pos++;
        }
    }
    return vec;
}

void del_mid(Node *prev)
{
    Node *aux = prev->next; // lo guardo para liberar
    prev->next = prev->next->next;
    free(aux);
}

void printVector(uint8_t vec[], int tamanio)
{
    printf("Vector: ");
    for (int i = 0; i < tamanio; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}