#include <stdio.h>
#include <stdint.h>

int main(void)
{
  int lista_larga[] = {
      5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
      9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
      10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

  printf("=============================================\n");
  printf("CUESTIONARIO 2 - PRACTICO 1\n");

  int secuenciaVieja = 1, secuenciaNueva = 100;

  /* Complete su codigo aca*/
  for (int i = 1; i < 288; i++)
  {
    if (lista_larga[i - 1] == lista_larga[i])
    {
      secuenciaVieja++;
    }
    else
    {
      if (secuenciaVieja < secuenciaNueva)
      {
        secuenciaNueva = secuenciaVieja;
      }
      secuenciaVieja = 1;
    }
  }
  if (secuenciaVieja < secuenciaNueva)
    secuenciaNueva = secuenciaVieja;

  printf("La secuencia mas corta tiene una longitud de: %d", secuenciaNueva);

  // printf("\nnumeros en lista larga: %d\n", (sizeof(lista_larga) * 8) / 32);

  printf("\n=============================================\n");
  printf("CUESTIONARIO 2 - PRACTICO 2\n");

  int nums = 1, comp[10];

  comp[0] = lista_larga[0];

  for (int i = 1; i < 288; i++)
  {
    if (lista_larga[i - 1] != lista_larga[i])
    {
      comp[nums] = lista_larga[i];
      nums++;
    }
  }
  printf("\nLISTA COMP:\t");
  uint64_t mult = 1;

  for (int i = 0; i < 10; i++)
  {
    printf("%d\t", comp[i]);
    mult = mult * comp[i];
  }
  printf("\n");

  printf("La multiplicacion da = %llu", mult);
  return 0;
}