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
  FILE *fp;
  modulo_t datos[10000];
  int i = 0;
  float promedio = 0;

  fp = fopen("modulos.bin", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return 0;
  }

  while (fread(&datos[i], sizeof(modulo_t), 1, fp))
  {
    i++;
  }

  for (int c = 0; c < i; c++)
  {
    promedio = promedio + datos[c].prioridad;
  }

  promedio = promedio / i;
  printf("Promedio prioridades: %.2f", promedio);

  return 0;
}