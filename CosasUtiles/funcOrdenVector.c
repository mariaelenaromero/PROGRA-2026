#include <stdio.h>
#include <stdint.h>

#define VECTORSIZE 15

void buscarMin(int vector[], int l, int ultimoMin, int *min);
void printVector(int vector[], int size);

int main(void)
{
  int vector[] = {1, 5, 7, 433, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63}, vectorOrden[VECTORSIZE];
  int min = 0, ultMin = 0;

  printVector(vector, VECTORSIZE);
  printf("\n");

  for (int i = 0; i < VECTORSIZE; i++)
  {
    buscarMin(vector, VECTORSIZE, ultMin, &min);
    vectorOrden[i] = min;
    ultMin = min;
  }

  printVector(vectorOrden, VECTORSIZE);
  printf("\n");

  return 0;
}

void buscarMin(int vector[], int l, int ultimoMin, int *min)
{
  int minimo = 100000;

  for (int i = 0; i < l; i++)
  {
    if (minimo > vector[i])
    {
      if (ultimoMin < vector[i])
      {
        minimo = vector[i];
      }
    }
  }

  *min = minimo;

  return;
}

void printVector(int vector[], int size)
{
  printf("vector:\t");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", vector[i]);
  }

  return;
}