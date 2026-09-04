#include <stdio.h>
#include <stdint.h>

typedef struct
{
  int prioridad;
  int estado;
  char tipo[15];
} modulo_t;

int main(void)
{
  int i = 0, prom[10000];
  modulo_t vector[10000];
  float promedio = 0;
  FILE *fp;
  fp = fopen("modulos.bin", "rb");
  if (fp == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return 0;
  }

  while (fread(&vector[i], sizeof(modulo_t), 1, fp))
  {
    i++;
  }

  fclose(fp);

  for (int c = 0; c < i; c++)
  {
    prom[c] = vector[c].prioridad;
    promedio = promedio + prom[c];
  }

  promedio = promedio / i;

  printf("prom: %.2f\n", promedio);

  return 0;
}
