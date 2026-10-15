#include <stdio.h>
#include "modelo5definiciones.h"
#include "modelo5Catedra_M13.c"
#include "modelo5funciones.c"
#include <stdlib.h>

// #define EJ1
// #define EJ2
#define EJ3

int main(void)
{
#ifdef EJ1
  printf("\n ==== EJERCICIO 1 ==== \n");
  uint16_t canvas = leerArchivo();
  printCanvas(canvas);

#endif

#ifdef EJ2
  printf("\n ==== EJERCICIO 2 ==== \n");
  qnode_t *qfirst = CATEDRA_CrearGrilla();
  printf("\n ==== ORIGINAL: ==== \n");
  // printGrillaABAJODERECHA(qfirst);
  printGrillaDERECHAABAJO(qfirst);
  fixGrilla(qfirst);
  printf("\n ==== ARREGLADA: ==== \n");
  printGrillaDERECHAABAJO(qfirst);
  freeGrilla(&qfirst);

#endif

#ifdef EJ3
  printf("\n ==== EJERCICIO 3 ==== \n");

  dnode_t *drandom = CATEDRA_CrearDList();
  dnode_t *first = NULL, *last = NULL;
  printlist(drandom, drandom); // me va a imprimir desde el random al inicio y al final
  muevoNodo(drandom, &first, &last);
  printlist(first, last); // imprime arreglado en doble sentido
  int esCirc = verifCircularidadFirstyLast(first, last);
  if (esCirc)
  {
    deshacerCirc(&first, &last);
    printlist(first, last);
  }
  else
  {
    hacerCirc(&first, &last);
    printlistCircular(first);
  }
  freeListCompleta(&first);

#endif

  /* Libere la memoria dinamica utilizada*/

  return 0;
}