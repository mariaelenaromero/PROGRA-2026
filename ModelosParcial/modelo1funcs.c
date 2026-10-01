#include "header.h"
#include <stdio.h>
#include <stdint.h>

/* Funciones Ejercicio 1 */
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
  printf("El nodo esta en la posicion (%d,%d)\n\n", fc.fila, fc.columna);
  return fc;
}

void camino(Posicion pos1, Posicion pos2, NodoGrilla *first)
{
  printf("Camino entre posiciones: (%d,%d) y (%d,%d)\n\n", pos1.fila, pos1.columna, pos2.fila, pos2.columna);
  NodoGrilla *nodo1 = first;
  for (int i = 0; i < pos1.fila; i++)
  {
    nodo1 = nodo1->down;
  }
  for (int i = 0; i < pos1.columna; i++)
  {
    nodo1 = nodo1->right;
  }
  NodoGrilla *aux = nodo1;
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
  printf("\n");
}
/* Funciones Ejercicio 2 */