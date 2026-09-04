#include <stdio.h>
#include <stdint.h>

typedef struct
{
  int op;
  union direc
  {
    char up;    // 0
    char right; // 1
    char down;  // 2
    char left;  // 3
  };
} RC1_t;

int main(void)
{
  FILE *fp;
  RC1_t opciones[10000];
  int i = 0, u = 0, r = 0, d = 0, l = 0, cambios = 1;
  fp = fopen("RecuC1.bin", "rb");

  if (fp == NULL)
  {
    printf("Error al abrir archivo");
    return 0;
  }

  while (fread(&opciones[i], sizeof(RC1_t), 1, fp))
  {
    if (opciones[i].op == 0)
    {
      u++;
    }
    if (opciones[i].op == 1)
    {
      r++;
    }
    if (opciones[i].op == 2)
    {
      d++;
    }
    if (opciones[i].op == 3)
    {
      l++;
    }
    i++;
  }
  fclose(fp);

  printf("up: %d\n", u);
  printf("right: %d\n", r);
  printf("down: %d\n", d);
  printf("left: %d\n", l);

  for (int c = 1; c < i; c++)
  {
    if (opciones[c].op != opciones[c - 1].op)
    {
      cambios++;
    }
  }

  printf("Cambios de direccion %d\n", cambios);

  return 0;
}