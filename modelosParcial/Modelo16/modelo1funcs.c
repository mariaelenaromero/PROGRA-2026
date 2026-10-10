#include "modelo1header.h"
#include <stdio.h>
#include <stdint.h>

void printVector(customElement *vector, int tamanio);
void ordenarLista(customElement *vector, int *tamanio, NodoDoble **first);
NodoDoble *crear_nodo(int dato);
void ins_first(NodoDoble **first, int dato);
void ins_last(NodoDoble *last, int dato);
void insertarOrdenado(NodoDoble **first, int dato);
void ins_medio(NodoDoble *anterior, int dato);
void printlist(NodoDoble *first);

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

void printVector(customElement *vector, int tamanio)
{
  for (int i = 0; i < tamanio; i++)
  {
    if (vector[i].esNro)
    {
      printf("%d ", vector[i].dato.numero);
    }
    else
    {
      printf("%c ", vector[i].dato.caracter);
    }
  }
  printf("\n");
}

void ordenarLista(customElement *vector, int *tamanio, NodoDoble **first)
{
  for (int i = 0; i < (*tamanio); i++)
  {
    if (vector[i].esNro)
    {
      insertarOrdenado(first, vector[i].dato.numero);

      for (int c = i; c < (*tamanio) - 1; c++)
      {
        vector[c] = vector[c + 1];
      }
      (*tamanio)--;
      i--;
    }
  }
  printf("\n");
}

NodoDoble *crear_nodo(int dato)
{
  NodoDoble *nodo = (NodoDoble *)malloc(sizeof(NodoDoble));
  if (nodo == NULL)
  {
    printf("No se pudo crear el nodo %d\n", dato);
    return NULL;
  }
  nodo->numero = dato;
  nodo->next = NULL;
  nodo->prev = NULL;
  return nodo;
}
void ins_first(NodoDoble **first, int dato)
{
  NodoDoble *nuevoNodo = crear_nodo(dato);
  if ((*first) == NULL)
  {
    *first = nuevoNodo;
    return;
  }
  (*first)->prev = nuevoNodo;
  nuevoNodo->next = *first;
  (*first) = nuevoNodo;
  return;
}
void ins_last(NodoDoble *last, int dato)
{
  NodoDoble *nuevoNodo = crear_nodo(dato);
  if (last == NULL)
  {
    return;
  }
  last->next = nuevoNodo;
  nuevoNodo->prev = last;
  return;
}

void insertarOrdenado(NodoDoble **first, int dato)
{

  if (*first == NULL || dato < (*first)->numero)
  {
    ins_first(first, dato);
    return;
  }

  NodoDoble *aux = *first;
  while (aux->next != NULL && aux->next->numero <= dato)
  {
    aux = aux->next;
  }
  if (aux->next == NULL)
  {
    ins_last(aux, dato);
    return;
  }
  else
  {
    ins_medio(aux, dato);
    return;
  }
}

void ins_medio(NodoDoble *anterior, int dato)
{
  NodoDoble *nuevoNodo = crear_nodo(dato);

  nuevoNodo->next = anterior->next;
  nuevoNodo->prev = anterior;
  anterior->next->prev = nuevoNodo;
  anterior->next = nuevoNodo;
  return;
}

void printlist(NodoDoble *first)
{
  NodoDoble *aux = first;

  while (aux != NULL)
  {
    printf("%d -> ", aux->numero);
    aux = aux->next;
  }
  printf("\n");
  return;
}