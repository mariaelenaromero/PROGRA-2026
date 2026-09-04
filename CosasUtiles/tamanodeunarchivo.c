#include <stdio.h>
#include <stdint.h>

int main(void)
{
  FILE *fp;

  fp = fopen("NOMBREDELARCHIVO.bin", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return 0;
  }
  fseek(fp, 0, SEEK_END);
  int tamano = ftell(fp);
  fclose(fp);

  printf("Cant de bytes: %d\n", tamano);

  return 0;
}