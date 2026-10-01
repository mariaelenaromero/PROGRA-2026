#ifndef DEF
#define DEF

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct doblenodo_t
{
    int num;
    struct doblenodo_t *next;
    struct doblenodo_t *prev;
} doblenodo_t;

doblenodo_t *crear_nodo(int dato);

#endif
