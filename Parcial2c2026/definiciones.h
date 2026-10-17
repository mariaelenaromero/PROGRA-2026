#ifndef _DEF_H
#define _DEF_H

typedef struct NodoGrilla
{
    char dato;
    char nextDato;
    struct NodoGrilla *up;
    struct NodoGrilla *down;
    struct NodoGrilla *left;
    struct NodoGrilla *right;
} NodoGrilla;

typedef struct NodoArbol NodoArbol;

typedef struct
{
    int distancia;
    NodoArbol *nodo;
} DatosNodo;

struct NodoArbol
{
    int dato;
    DatosNodo der;
    DatosNodo izq;
};

#endif

// PROTS EJ 1

void printGrilla(NodoGrilla *first);
void modifGrillaNext(NodoGrilla *first);
void modifGrilla(NodoGrilla *first);

// PROTS EJ 2

void printNodo(NodoArbol *raiz);
void findconprint(NodoArbol **PrimerNodo, int datofind);
int find(NodoArbol **PrimerNodo, int datofind);
void comparoDist(int datos[], NodoArbol **raiz);
void modifDist(int datofind, NodoArbol **raiz, int sumadist);