#ifndef CATEDRA_H
#define CATEDRA_H

typedef struct NodoGrilla
{
    char dato;
    struct NodoGrilla *up;
    struct NodoGrilla *down;
    struct NodoGrilla *left;
    struct NodoGrilla *right;
} NodoGrilla;

typedef struct
{
    int fila;
    int columna;
} Posicion;

#endif