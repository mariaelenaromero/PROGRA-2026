#include <stdio.h>
#include <stdint.h>

void ordenarVector(int vector[], int l, int *min, int ultMin);

int main(void)
{
  FILE *fp;
  int vector[10000], vectorOrden[10000], cont = 0, suma = 0, min = 0, ultMin = 0;
  uintptr_t promMemoria = 0;

  fp = fopen("lista.bin", "rb");

  if (fp == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return 0;
  }

  while (fread(&vector[cont], sizeof(int), 1, fp))
  {
    // printf("%d\t", vector[cont]);
    suma = suma + vector[cont];
    promMemoria = promMemoria + (uintptr_t)&vector[cont];
    cont++;
  }
  fclose(fp);

  // printf("La suma de los numeros del array es: %d\n", suma);

  promMemoria = promMemoria / cont;

  // printf("El promedio de las direcciones de memoria de los numeros del vector es: %lu\n", promMemoria);

  printf("\n");
  printf("\n");

  for (int i = 0; i < cont; i++)
  {
    ordenarVector(vector, cont, &min, ultMin);
    vectorOrden[i] = min;
    ultMin = min;
    printf("%d\t", vectorOrden[i]);
  }

  printf("\n");

  return 0;
}

void ordenarVector(int vector[], int l, int *min, int ultMin)
{
  int minimo = 1000000, n = vector[0];

  for (int i = 0; i < l; i++)
  {
    if (minimo > vector[i])
    {
      if (ultMin < vector[i])
      {
        minimo = vector[i];
      }
    }
  }
  *min = minimo;
  return;
}
