#include "modelo4header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* == == == == == PROTS  == == == == == */

void printGrilla(NodoGrilla *first);
void freeGrilla(NodoGrilla **first);
void delUltNodos(NodoGrilla *first, int N, int fil);
int difFils(NodoGrilla *first, int fil);
void fixGrilla(NodoGrilla *first);
int buscarMinFils(NodoGrilla *first);

/* == == == == == IMPRIMIR GRILLA  == == == == == */

void printGrilla(NodoGrilla *first)
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
    }

    printf("\n");
}

/* == == == == == = Ejercicio A == == == == == == */

void delUltNodos(NodoGrilla *first, int N, int fil) // toma la primer fil/col como la 0
{
    NodoGrilla *aux1 = first;
    NodoGrilla *auxlibera;

    for (int i = 0; i < fil; i++)
    {
        aux1 = aux1->down;
    }
    while (aux1->right != NULL)
    {
        aux1 = aux1->right;
    }
    for (int i = 0; i < N; i++)
    {
        if (aux1->up != NULL)
        {
            auxlibera = aux1->up;
            auxlibera->down = NULL;
        }
        if (aux1->down != NULL)
        {
            auxlibera = aux1->down;
            auxlibera->up = NULL;
        }
        aux1 = aux1->left;
        free(aux1->right);
    }
    aux1->right = NULL;
}

/* == == == == == = Ejercicio B == == == == == == */

int buscarMinFils(NodoGrilla *first)
{
    NodoGrilla *auxright = first;
    NodoGrilla *auxdown = first;
    int minfil = 100000, dif = 0;
    Posicion fcmin = {0, 0};
    Posicion fila = {0, 0};
    while (auxdown != NULL)
    {
        while (auxright != NULL)
        {
            auxright = auxright->right;
            fcmin.columna += 1;
        }
        if (minfil > fcmin.columna)
        {
            minfil = fcmin.columna;
        }
        fcmin.columna = 0;
        auxdown = auxdown->down;
        auxright = auxdown;
    }
    return minfil;
}

void difFilsejB(NodoGrilla *first, int fil)
{
    NodoGrilla *auxright = first;
    NodoGrilla *auxdown = first;
    int minfil = 0, dif = 0;
    Posicion fila = {0, 0};
    minfil = buscarMinFils(first);
    for (int i = 0; i < fil; i++)
    {
        auxdown = auxdown->down;
    }
    auxright = auxdown;
    while (auxright != NULL)
    {
        auxright = auxright->right;
        fila.columna += 1;
    }
    dif = fila.columna - minfil;
    printf("Largo minimo %d\n\n", minfil);
    printf("Largo fila %d: %d\n\n", fil, fila.columna);
    printf("Diferencia %d\n\n", dif);
    return;
}

/* == == == == == = Ejercicio C == == == == == == */

int difFilsejC(NodoGrilla *first, int fil)
{
    NodoGrilla *auxright = first;
    NodoGrilla *auxdown = first;
    int minfil = 0, dif = 0;
    Posicion fila = {0, 0};
    minfil = buscarMinFils(first);
    auxdown = first;
    for (int i = 0; i < fil; i++)
    {
        auxdown = auxdown->down;
    }
    auxright = auxdown;
    while (auxright != NULL)
    {
        auxright = auxright->right;
        fila.columna += 1;
    }
    dif = fila.columna - minfil;
    return dif;
}

void fixGrilla(NodoGrilla *first)
{
    NodoGrilla *aux1 = first;
    int fil = 0, dif = 0;
    while (aux1 != NULL)
    {
        dif = difFilsejC(first, fil);
        if (dif > 0)
        {
            delUltNodos(first, dif, fil);
        }
        aux1 = aux1->down;
        fil++;
    }
}

/* == == == == == = LIBERO == == == == == == */

void freeGrilla(NodoGrilla **first)
{
    NodoGrilla *aux1 = *first;
    NodoGrilla *aux2;
    NodoGrilla *sigFila;
    NodoGrilla *sigNodo;

    while (aux1 != NULL)
    {
        sigFila = aux1->down; // guardo el comienzo de la fila siguiente
        aux2 = aux1;

        while (aux2 != NULL)
        {
            sigNodo = aux2->right; // guardo el siguiente de la fila
            free(aux2);
            aux2 = sigNodo;
        }

        aux1 = sigFila;
    }
    *first = NULL;
}