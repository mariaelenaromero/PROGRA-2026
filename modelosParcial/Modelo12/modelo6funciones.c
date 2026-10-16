/* Utilice este archivo para escribir sus funciones */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "modelo6definiciones.h"

void leerArchivo(nodo_t **first);
nodo_t *crear_nodo(char dato);
void insFirst(nodo_t **first, char dato);
void ins_last(nodo_t **first, char dato);
int verifCircularidad(nodo_t *first);
void hacerCirc(nodo_t **first);
void deshacerCirc(nodo_t **first);
void freeListCompleta(nodo_t **first);
void delLast(nodo_t **PrimerNodo);
void printlistCircular(nodo_t *first);
void printlist(nodo_t *first);

/* === EJERCICIO 1 === */

void leerArchivo(nodo_t **first)
{
  M12_t datosFile;
  uint16_t esCirc = 0;
  FILE *fp = fopen("modelo6M12.dat", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return;
  }
  int i = 0, size = 0;
  while (fread(&datosFile, sizeof(M12_t), 1, fp))
  {
    if (datosFile.mask == 10)
    {
      esCirc = verifCircularidad(*first);
      if (esCirc)
      {
        printf("Deshago circ: ");
        deshacerCirc(first);
        printlist(*first);
      }
      else
      {
        printf("Hago circ: ");
        hacerCirc(first);
        printlistCircular(*first);
      }
    }
    else if (datosFile.mask == 11)
    {
      freeListCompleta(first);
      printf("LIBERE LA LISTA\n");
    }
    else if (datosFile.mask == 0b0010)
    {
      printf("inserto %c en first: ", datosFile.dato);
      insFirst(first, datosFile.dato);
      esCirc = verifCircularidad(*first);
      if (esCirc)
      {
        printlistCircular(*first);
      }
      else
      {
        printlist(*first);
      }
    }
    else if (datosFile.mask == 0b0011)
    {
      printf("Borro last: ");
      delLast(first);
      esCirc = verifCircularidad(*first);
      if (esCirc)
      {
        printlistCircular(*first);
      }
      else
      {
        printlist(*first);
      }
    }
  }
  fclose(fp);
  freeListCompleta(first);
  return;
}

nodo_t *crear_nodo(char dato)
{
  nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));
  if (nodo == NULL)
  {
    printf("No se pudo crear el nodo %d\n", dato);
    return NULL;
  }
  nodo->dato = dato;
  nodo->next = NULL;
  return nodo;
}

void insFirst(nodo_t **first, char dato)
{
  nodo_t *nuevoNodo = crear_nodo(dato);
  if (*first == NULL)
  {
    *first = nuevoNodo;
    return;
  }
  int circ = ((*first != NULL) && verifCircularidad(*first));
  if (circ)
  {
    nodo_t *l = *first;
    while (l->next != *first)
    {
      l = l->next;
    }
    l->next = nuevoNodo;
  }
  nuevoNodo->next = *first;
  *first = nuevoNodo;
}

void ins_last(nodo_t **first, char dato)
{
  nodo_t *nuevoNodo = crear_nodo(dato);
  nodo_t *aux = (*first);
  if ((*first) == NULL)
  {
    (*first) = nuevoNodo;
    return;
  }
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  aux->next = nuevoNodo;
  return;
}

int verifCircularidad(nodo_t *first)
{
  if (first == NULL)
  {
    return 0;
  }
  nodo_t *aux = first->next;
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

void hacerCirc(nodo_t **first)
{
  if ((*first) == NULL)
  {
    return;
  }
  if ((*first)->next == NULL) // unico nodo
  {
    (*first)->next = *first;
    return;
  }
  nodo_t *aux = (*first)->next;
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  aux->next = *first;
}

void deshacerCirc(nodo_t **first)
{
  if ((*first) == NULL)
  {
    return;
  }
  if ((*first)->next == *first) // unico nodo
  {
    (*first)->next = NULL;
    return;
  }
  nodo_t *aux = (*first)->next;
  while (aux->next != *first)
  {
    aux = aux->next;
  }
  aux->next = NULL;
}

void freeListCompleta(nodo_t **first)
{
  if (first == NULL || *first == NULL)
    return;

  nodo_t *last = *first;
  while (last->next != NULL && last->next != *first)
    last = last->next;
  last->next = NULL;

  nodo_t *aux = *first;
  while (aux != NULL)
  {
    nodo_t *prox = aux->next;
    free(aux);
    aux = prox;
  }
  *first = NULL;
}

void delLast(nodo_t **PrimerNodo)
{
  if (*PrimerNodo == NULL)
  {
    return;
  }
  if ((*PrimerNodo)->next == NULL || (*PrimerNodo)->next == *PrimerNodo)
  {
    free(*PrimerNodo);
    *PrimerNodo = NULL;
    return;
  }

  nodo_t *actual = *PrimerNodo;
  nodo_t *prev = NULL;

  while (actual->next != NULL && actual->next != *PrimerNodo)
  {
    prev = actual;
    actual = actual->next;
  }
  if (actual->next == *PrimerNodo)
  {
    prev->next = *PrimerNodo;
  }
  if (actual->next == NULL)
  {
    prev->next = NULL;
  }
  free(actual);
}

void printlistCircular(nodo_t *first)
{
  nodo_t *aux = first->next;
  printf("Lista circular (imrpime de nuevo el primero para verif): %c -> ", first->dato);
  while (aux != first)
  {
    printf("%c -> ", aux->dato);
    aux = aux->next;
  }
  printf("%c\n", aux->dato); // imprime de nuevo el first
  return;
}

void printlist(nodo_t *first)
{
  nodo_t *auxi = first;
  while (auxi != NULL)
  {
    printf("%c -> ", auxi->dato);
    auxi = auxi->next;
  }
  printf("\n");
  return;
}

/* === EJERCICIO 2 === */

void printGrilla(qnode_t *first)
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

void recorroXp(qnode_t *first)
{
  qnode_t *der = first;
  qnode_t *abajo = first;

  while (abajo != NULL)
  {
    while (der != NULL)
    {
      if ((der->valor ^ (1 << 4)) % 7 == 0)
      {
        printf("X ");
      }
      else
      {
        printf(". ");
      }
      der = der->right;
    }
    printf("\n");
    abajo = abajo->down;
    der = abajo;
  }
  printf("\n");
}

void tomaPos(int fil, int col, qnode_t *first)
{
  printf("Posicion (%d,%d):", fil, col);
  qnode_t *nodo1 = first;
  for (int i = 0; i < fil; i++)
  {
    nodo1 = nodo1->down;
  }
  for (int i = 0; i < col; i++)
  {
    nodo1 = nodo1->right;
  }
  if ((nodo1->valor ^ (1 << 4)) % 7 == 0)
  {
    printf("mina\n\n");
  }
  else
  {
    int banderita = 0;
    if (nodo1->right != NULL)
    {
      if ((nodo1->right->valor ^ (1 << 4)) % 7 == 0)
      {
        banderita++;
      }
      if (nodo1->right->up != NULL)
      {
        if ((nodo1->right->up->valor ^ (1 << 4)) % 7 == 0)
        {
          banderita++;
        }
      }
      if (nodo1->right->down != NULL)
      {
        if ((nodo1->right->down->valor ^ (1 << 4)) % 7 == 0)
        {
          banderita++;
        }
      }
    }
    if (nodo1->left != NULL)
    {
      if ((nodo1->left->valor ^ (1 << 4)) % 7 == 0)
      {
        banderita++;
      }
      if (nodo1->left->up != NULL)
      {
        if ((nodo1->left->up->valor ^ (1 << 4)) % 7 == 0)
        {
          banderita++;
        }
      }
      if (nodo1->left->down != NULL)
      {
        if ((nodo1->left->down->valor ^ (1 << 4)) % 7 == 0)
        {
          banderita++;
        }
      }
    }
    if (nodo1->up != NULL)
    {
      if ((nodo1->up->valor ^ (1 << 4)) % 7 == 0)
      {
        banderita++;
      }
    }
    if (nodo1->down != NULL)
    {
      if ((nodo1->down->valor ^ (1 << 4)) % 7 == 0)
      {
        banderita++;
      }
    }

    if (banderita != 0)
    {
      printf("cant vecinos: %d\n", banderita);
    }
    else if (banderita == 0)
    {
      printf("Banderita\n");
    }
    printf("\n");
  }
}