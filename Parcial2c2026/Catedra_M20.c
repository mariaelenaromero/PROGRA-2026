#include <stdio.h>
#include <stdlib.h>

#include "definiciones.h"

NodoGrilla* CATEDRA_CrearGrilla(void) {
    char matriz[6][7] = {
        {' ', '#', ' ', '#', '#', ' ', '#'}, {'#', ' ', '#', ' ', ' ', '#', ' '}, {' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' '}, {' ', '#', ' ', '#', '#', '#', ' '}, {'#', ' ', '#', ' ', ' ', ' ', '#'},
    };

    int rows = 6;
    int cols = 7;

    NodoGrilla* nodos[6][7];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nodos[i][j] = (NodoGrilla*)malloc(sizeof(NodoGrilla));
            if (nodos[i][j] == NULL) {
                perror("Memory allocation failed!\n");
                exit(1);
            }
            nodos[i][j]->dato = matriz[i][j];
            nodos[i][j]->nextDato = ' ';
            nodos[i][j]->up = NULL;
            nodos[i][j]->down = NULL;
            nodos[i][j]->left = NULL;
            nodos[i][j]->right = NULL;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) {
                nodos[i][j]->up = nodos[i - 1][j];
            }
            if (i < rows - 1) {
                nodos[i][j]->down = nodos[i + 1][j];
            }
            if (j > 0) {
                nodos[i][j]->left = nodos[i][j - 1];
            }
            if (j < cols - 1) {
                nodos[i][j]->right = nodos[i][j + 1];
            }
        }
    }

    return nodos[0][0];
}

static NodoArbol* crear_nodo_arbol(int dato) {
    NodoArbol* nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));
    if (nuevo == NULL) {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    nuevo->dato = dato;
    nuevo->der.distancia = 0;
    nuevo->der.nodo = NULL;
    nuevo->izq.distancia = 0;
    nuevo->izq.nodo = NULL;
    return nuevo;
}

NodoArbol* CATEDRA_CrearArbol(void) {
    /* Arbol ordenado de ejemplo:
                8 (der:5, izq:3)
               / \
              3   10
             / \    \
            1   6    14
                     / \
                    12 16
       Distancias totales desde raiz (consigna C, objetivo 20):
         1 -> 3+2 = 5 | 6 -> 3+4 = 7 | 12 -> 5+6+8 = 19 | 16 -> 5+6+12 = 23 (>20)
    */
    NodoArbol* raiz = crear_nodo_arbol(8);
    raiz->izq.nodo = crear_nodo_arbol(3);
    raiz->izq.distancia = 3;
    raiz->der.nodo = crear_nodo_arbol(10);
    raiz->der.distancia = 5;

    raiz->izq.nodo->izq.nodo = crear_nodo_arbol(1);
    raiz->izq.nodo->izq.distancia = 2;
    raiz->izq.nodo->der.nodo = crear_nodo_arbol(6);
    raiz->izq.nodo->der.distancia = 4;

    raiz->der.nodo->der.nodo = crear_nodo_arbol(14);
    raiz->der.nodo->der.distancia = 6;

    raiz->der.nodo->der.nodo->izq.nodo = crear_nodo_arbol(12);
    raiz->der.nodo->der.nodo->izq.distancia = 8;

    raiz->der.nodo->der.nodo->der.nodo = crear_nodo_arbol(16);
    raiz->der.nodo->der.nodo->der.distancia = 12;

    return raiz;
}
