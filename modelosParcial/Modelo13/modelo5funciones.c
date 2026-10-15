/* Utilice este archivo para escribir sus funciones */

#include "modelo5definiciones.h"
#include <stdio.h>
#include <stdlib.h>
uint16_t leerArchivo();
void printCanvas(uint16_t dato);
void fixGrilla(qnode_t *first);

/* === EJERCICIO 1 === */

uint16_t leerArchivo()
{
  M13_t datosFile;
  uint16_t canvas = 0;
  FILE *fp = fopen("modelo5M13.bin", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return 0;
  }
  int i = 0, size = 0;
  while (fread(&datosFile, sizeof(M13_t), 1, fp))
  {
    if (datosFile.act == SET)
    {
      canvas = canvas | (0b1 << (datosFile.nrBits - 1));
    }
    else if (datosFile.act == RESET)
    {
      canvas = canvas & ~(0b1 << (datosFile.nrBits - 1));
    }
  }
  fclose(fp);
  return canvas;
}
void printCanvas(uint16_t dato)
{
  printf("0b");
  for (int i = 15; i >= 0; i--)
  {
    printf("%d", (dato >> i) & 0b1);
    if (i % 4 == 0)
    {
      printf(" ");
    }
  }
  printf("\n");
  printf("decimal: %d\n", dato);
  printf("Hexadecimal: %X\n", dato);
  return;
}

/* === EJERCICIO 2 === */

void printGrillaABAJODERECHA(qnode_t *first) // IMPRIME COLUMNAS COMO FILAS
{
  qnode_t *der = first;
  qnode_t *abajo = first;

  while (der != NULL)
  {
    while (abajo != NULL)
    {
      printf("%d ", abajo->valor);
      abajo = abajo->down;
    }
    printf("\n");
    der = der->right;
    abajo = der;
  }
  printf("\n");
}

void printGrillaDERECHAABAJO(qnode_t *first) // IMPRIME BIEN
{
  qnode_t *der = first;
  qnode_t *abajo = first;

  while (abajo != NULL)
  {
    while (der != NULL)
    {
      printf("%d ", der->valor);
      der = der->right;
    }
    printf("\n");
    abajo = abajo->down;
    der = abajo;
  }
  printf("\n");
}

void fixGrilla(qnode_t *first)
{
  qnode_t *der = first;
  qnode_t *abajo = first;

  while (abajo != NULL)
  {
    while (der != NULL)
    {
      while (der->right != NULL)
      {
        der = der->right;
      }
      if (der->up != NULL)
      {
        if (der->up->right != NULL)
        {
          der->right = der->up->right->down;
        }
      }
      else if (der->down != NULL)
      {
        if (der->down->right != NULL)
        {
          der->right = der->down->right->up;
        }
      }
      der = der->right;
    }
    abajo = abajo->down;
    der = abajo;
  }
}

/* === EJERCICIO 3 === */

void muevoNodo(dnode_t *drandom, dnode_t **first, dnode_t **last)
{
  int der = 0, izq = 0;
  *first = drandom;
  *last = drandom;
  if (drandom->prev == NULL && drandom->next == NULL)
  {
    return; // es el unico nodo
  }
  while ((*last)->next != NULL)
  {
    (*last) = (*last)->next;
    der++;
  }
  while ((*first)->prev != NULL)
  {
    (*first) = (*first)->prev;
    izq++;
  }
  if (drandom->prev == NULL)
  {
    return; // ya es el primero
  }
  if (drandom->next == NULL)
  {
    return; // ya es el ultimo
  }
  if (izq < der)
  {
    (*first)->prev = drandom;
    drandom->prev->next = drandom->next;
    drandom->next->prev = drandom->prev;
    drandom->next = (*first);
    drandom->prev = NULL;
    (*first) = drandom;
  }
  else
  { // si la dist es igual lo manda al ultimo
    (*last)->next = drandom;
    drandom->prev->next = drandom->next;
    drandom->next->prev = drandom->prev;
    drandom->prev = (*last);
    drandom->next = NULL;
    (*last) = drandom;
  }
}

void printlist(dnode_t *first, dnode_t *last)
{
  dnode_t *auxi = first;
  dnode_t *auxl = last;

  printf("Lista desde el pasado por first al last: ");
  while (auxi != NULL)
  {
    printf("%d -> ", auxi->dato);
    auxi = auxi->next;
  }
  printf("\n");
  printf("Lista desde el pasado por last al first: ");
  while (auxl != NULL)
  {
    printf("%d -> ", auxl->dato);
    auxl = auxl->prev;
  }
  printf("\n\n");
  return;
}

int verifCircularidadSoloFirst(dnode_t *first)
{
  dnode_t *aux = first->next;
  while (aux != first)
  {
    if (aux == NULL)
    {
      return 0;
    }
    aux = aux->next;
  }
  return 1;
}

int verifCircularidadFirstyLast(dnode_t *first, dnode_t *last)
{
  if (first->prev != last)
  {
    return 0;
  }
  return 1;
}

void hacerCirc(dnode_t **first, dnode_t **last)
{
  (*first)->prev = *last;
  (*last)->next = *first;
}

void deshacerCirc(dnode_t **first, dnode_t **last)
{
  (*first)->prev = NULL;
  (*last)->next = NULL;
}

void printlistCircular(dnode_t *first)
{
  dnode_t *aux = first->next;
  printf("Lista circular (imrpime de nuevo el primero para verif): %d -> ", first->dato);
  while (aux != first)
  {
    printf("%d -> ", aux->dato);
    aux = aux->next;
  }
  printf("%d\n", aux->dato); // imprime de nuevo el first
  return;
}

/* == == == == == = LIBERO == == == == == == */

void freeGrilla(qnode_t **first)
{
  qnode_t *aux1 = *first;
  qnode_t *aux2;
  qnode_t *sigFila;
  qnode_t *sigNodo;

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

void freeList(dnode_t **first)
{
  if (first == NULL)
    return;

  dnode_t *aux = *first;
  while (aux != NULL)
  {
    dnode_t *prox = aux->next;
    free(aux);
    aux = prox;
  }
  *first = NULL;
}

void freeListCompleta(dnode_t **first)
{
  if (first == NULL || *first == NULL)
    return;

  dnode_t *last = *first;
  while (last->next != NULL && last->next != *first)
    last = last->next;
  last->next = NULL;

  dnode_t *aux = *first;
  while (aux != NULL)
  {
    dnode_t *prox = aux->next;
    free(aux);
    aux = prox;
  }
  *first = NULL;
}