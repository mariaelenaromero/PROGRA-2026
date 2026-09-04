#include <stdio.h>
#include <stdint.h>

// CONSIGNA: El archivo "C2_numbers.bin" tiene guardados structs de 152 bytes cada uno. Indique cuantos elementos contiene el archivo

typedef struct
{
  int a;
  float c;
  short b;
  union C2_u
  {
    float j;
    float p;
    float n;
    double w;
  } z;
  char pass[123];
} C2_t;

int main(void)
{

  int i = 0;
  C2_t datos[10000];
  FILE *fp;

  fp = fopen("C2_numbers.bin", "rb");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo");
    return 0;
  }
  while (fread(&datos[i], sizeof(C2_t), 1, fp))
  {
    i++;
  }
  fclose(fp);
  printf("Cant de structs: %d\n", i);
  return 0;
}