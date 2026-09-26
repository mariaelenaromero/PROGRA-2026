#ifndef DEF
#define DEF

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t
{
    int num;
    struct nodo_t *next;
} nodo_t;

nodo_t *crear_nodo(int dato);

#endif