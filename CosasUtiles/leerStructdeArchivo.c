#include <stdio.h>
#include <stdint.h>

typedef struct
{
  char a;
  int b;
  float c;
} struct_mio;

int main(void)
{
  int recorro = 0;
  struct_mio datos[10000];
  FILE *fp;

  fp = fopen("NOMBREARCHIVO.bin", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return 0;
  }

  while (fread(&datos[recorro], sizeof(struct_mio), 1, fp))
  {
    recorro++;
  }

  fclose(fp);

  return 0;
}