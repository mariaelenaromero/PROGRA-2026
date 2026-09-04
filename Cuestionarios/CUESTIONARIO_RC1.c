#include <stdio.h>
#include <stdint.h>

typedef struct
{
  int op;
  union direc
  {
    uint8_t up;
    uint8_t right;
    uint8_t down;
    uint8_t left;
  };
} RC1_t;

int main(void)
{
  int i = 0, cont0 = 0, cont1 = 0, cont2 = 0, cont3 = 0;
  RC1_t vector[100000];

  FILE *fp;
  fp = fopen("RecuC1.bin", "rb");
  if (fp == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return 0;
  }

  while (fread(&vector[i], sizeof(RC1_t), 1, fp))
  {
    i++;
  }

  for (int c = 0; c < i; c++)
  {
    if (vector[c].op == 1)
    {
      cont1++;
    }
    if (vector[c].op == 0)
    {
      cont0++;
    }
    if (vector[c].op == 2)
    {
      cont2++;
    }
    if (vector[c].op == 3)
    {
      cont3++;
    }
  }

  printf("up: %d\n", cont0);
  printf("right: %d\n", cont1);
  printf("down: %d\n", cont2);
  printf("left: %d\n", cont3);
  fclose(fp);

  return 0;
}
