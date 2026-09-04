#include <stdio.h>
#include <stdint.h>

#define VECTORSIZE 15

void buscarMinMax(int vector[], int l, int *max, int *min, float *prom);

int main(void)
{
  int vector[] = {-11, 5, 7, 433, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63};
  int max = 0, min = 0;
  float prom = 0;

  buscarMinMax(vector, VECTORSIZE, &max, &min, &prom);

  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  printf("Prom: %.2f\n", prom);

  return 0;
}

void buscarMinMax(int vector[], int l, int *max, int *min, float *prom)
{
  int minimo = vector[0], maximo = vector[0];
  float promedio = vector[0];

  for (int i = 1; i < l; i++)
  {
    if (minimo > vector[i])
    {
      minimo = vector[i];
    }
    if (maximo < vector[i])
    {
      maximo = vector[i];
    }
    promedio = promedio + vector[i];
  }

  *min = minimo;
  *max = maximo;
  *prom = promedio / l;

  return;
}