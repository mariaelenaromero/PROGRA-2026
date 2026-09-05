#include <stdio.h>
#include <stdint.h>

int main(void)
{
  int vector[100000], recorro = 0;
  FILE *fp;

  fp = fopen("NOMBREARCHIVO.bin", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return 0;
  }

  while (fread(&vector[recorro], sizeof(int), 1, fp))
  {
    recorro++;
  }
  fclose(fp);

  return 0;
}