#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ultimomodelodefiniciones.h"

// ARBOL

NodoArbol *createNodo(int nuevoDato)
{
  NodoArbol *nuevoNodo = malloc(sizeof(NodoArbol));
  if (!nuevoNodo)
  {
    perror("Error en la creacion del nodo\n");
    exit(1);
  }
  nuevoNodo->cantidad = 1;
  nuevoNodo->dato = nuevoDato;
  nuevoNodo->der = NULL;
  nuevoNodo->izq = NULL;

  return nuevoNodo;
}

void insOrdenado(NodoArbol **PrimerNodo, int nuevoDato)
{
  NodoArbol *nuevoNodo = createNodo(nuevoDato);

  if (*PrimerNodo == NULL)
  {
    *PrimerNodo = nuevoNodo;
    return;
  }

  NodoArbol *temp = *PrimerNodo;

  while (1)
  {
    if (temp->dato == nuevoNodo->dato)
    {
      temp->cantidad++;
      return;
    }
    if (temp->dato > nuevoNodo->dato)
    {

      if (temp->izq == NULL)
      {
        temp->izq = nuevoNodo;
        return;
      }
      temp = temp->izq;
    }

    else if (temp->dato < nuevoNodo->dato)
    {
      if (temp->der == NULL)
      {
        temp->der = nuevoNodo;
        return;
      }
      if (temp->der->dato == nuevoNodo->dato)
      {
        temp->der->cantidad++;
        return;
      }
      temp = temp->der;
    }
  }
}

void find(NodoArbol **PrimerNodo, int datof)
{
  NodoArbol *temp = *PrimerNodo;
  int suma = 0;
  printf("Camino hacia %d: ", datof);
  while (1)
  {
    printf("%d->", temp->dato);
    suma += temp->dato;
    if (temp->dato == datof)
    {
      printf("NULL  suma del camino = %d", suma);
      printf("\n\n");
      return;
    }
    else if (temp->dato > datof)
    {
      if (temp->izq == NULL)
      {
        printf("NULL  no esta el dato, suma camino recorrido al buscarlo = %d\n\n", suma);
        return;
      }
      temp = temp->izq;
    }
    else if (temp->dato < datof)
    {
      if (temp->der == NULL)
      {
        printf("NULL  no esta el dato, suma camino recorrido al buscarlo = %d\n\n", suma);
        return;
      }
      temp = temp->der;
    }
  }
}

void printTree(NodoArbol *n, int level)
{
  if (n == NULL)
  {
    return;
  }
  printf("\n");
  for (int i = 0; i < level; i++)
  {
    printf("    ");
  }
  printf("└── %d", n->dato);
  printTree(n->der, level + 1);
  printTree(n->izq, level + 1);
}

// EJERCICIO 2

void printlist(Node *first, Node *last)
{
  Node *auxi = first;
  Node *auxl = last;
  printf("\n");

  printf("de p a f humedad: ");

  while (auxi != NULL)
  {
    printf("%d -> ", auxi->data.humedad);
    auxi = auxi->next;
  }
  printf("\n");
  printf("al reves: ");
  while (auxl != NULL)
  {
    printf("%d -> ", auxl->data.humedad);
    auxl = auxl->prev;
  }
  printf("\n\n");

  auxi = first;
  auxl = last;

  printf("de p a f temp: ");

  while (auxi != NULL)
  {
    printf("%d -> ", auxi->data.temp);
    auxi = auxi->next;
  }
  printf("\n");
  printf("al reves: ");
  while (auxl != NULL)
  {
    printf("%d -> ", auxl->data.temp);
    auxl = auxl->prev;
  }
  return;
}

void borroHumNeg(Node **first, Node **last)
{
  Node *auxi = *first;
  while (auxi != NULL)
  {
    Node *sig = auxi->next;
    if (auxi->data.humedad < 0)
    {
      if (auxi == *first)
      {
        del_first(first, last);
      }
      else if (auxi == *last)
      {
        del_last(first, last);
      }
      else
      {
        del_mid(&auxi);
      }
    }
    auxi = sig;
  }
  printf("\n\n");
  return;
}
void del_first(Node **first, Node **last)
{
  Node *aux = *first;
  if ((*first) == NULL || (*first)->next == NULL)
  {
    free(*first);
    *last = NULL;
    *first = NULL;
    return;
  }
  *first = (*first)->next;
  (*first)->prev = NULL;
  free(aux);
  return;
}
void del_last(Node **first, Node **last)
{
  if ((*last) == NULL || (*last)->prev == NULL)
  {
    free(*last);
    *last = NULL;
    *first = NULL;
    return;
  }
  Node *aux = (*last)->prev;
  free(*last);
  aux->next = NULL;
  *last = aux;
  return;
}

void del_mid(Node **nodob)
{
  Node *aux = *nodob; // lo guardo para liberar
  (*nodob)->prev->next = (*nodob)->next;
  (*nodob)->next->prev = (*nodob)->prev;
  free(aux);
}

void printlistH80T2(Node *first, Node *last)
{
  Node *auxi = first;
  Node *auxl = last;
  printf("\n");

  printf("de p a f humedad (H>80 & T<2): ");

  while (auxi != NULL)
  {
    if (auxi->data.humedad > 80 && auxi->data.temp < 2)
    {
      printf("%d -> ", auxi->data.humedad);
    }
    auxi = auxi->next;
  }
  printf("\n");
  printf("al reves: ");
  while (auxl != NULL)
  {
    if (auxl->data.humedad > 80 && auxl->data.temp < 2)
    {
      printf("%d -> ", auxl->data.humedad);
    }
    auxl = auxl->prev;
  }
  printf("\n\n");

  auxi = first;
  auxl = last;

  printf("de p a f temp(H>80 & T<2): ");

  while (auxi != NULL)
  {
    if (auxi->data.humedad > 80 && auxi->data.temp < 2)
    {
      printf("%d -> ", auxi->data.temp);
    }
    auxi = auxi->next;
  }
  printf("\n");
  printf("al reves: ");
  while (auxl != NULL)
  {
    if (auxl->data.humedad > 80 && auxl->data.temp < 2)
    {
      printf("%d -> ", auxl->data.temp);
    }
    auxl = auxl->prev;
  }
  return;
}

void crearLista(Node *first, NodoSimple **tempsfirst)
{
  Node *auxi = first;
  while (auxi != NULL)
  {
    (*tempsfirst) = ins_first(*tempsfirst, auxi->data.temp);
    auxi = auxi->next;
  }
}

NodoSimple *crear_nodo(int dato)
{
  NodoSimple *nodo = (NodoSimple *)malloc(sizeof(NodoSimple));
  if (nodo == NULL)
  {
    printf("No se pudo crear el nodo %d\n", dato);
    return NULL;
  }
  nodo->temp = dato;
  nodo->next = NULL;
  return nodo;
}

NodoSimple *ins_first(NodoSimple *first, int dato)
{
  NodoSimple *nuevoNodo = crear_nodo(dato);
  nuevoNodo->next = first;
  return nuevoNodo;
}

void printlistsimple(NodoSimple *first)
{
  NodoSimple *aux = first;

  while (aux != NULL)
  {
    printf("%d -> ", aux->temp);
    aux = aux->next;
  }
  printf("\n");
}

void freeList(Node **first)
{
  if (first == NULL)
    return;

  Node *aux = *first;
  while (aux != NULL)
  {
    Node *prox = aux->next;
    free(aux);
    aux = prox;
  }
  *first = NULL;
  printf("\nLISTA LIBERADA\n");
}