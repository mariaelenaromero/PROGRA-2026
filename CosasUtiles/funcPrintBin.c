#include <stdio.h>
#include <stdint.h>

#define BITS 8
#define DATO 255

void printBinario(int dato);

int main(void)
{
  printBinario(DATO);
  return 0;
}

void printBinario(int dato)
{
  printf("0b ");
  for (int i = BITS - 1; i >= 0; i--)
  {
    printf("%lu", (dato >> i) & 0b1);
    if (i % 4 == 0)
    {
      printf(" ");
    }
  }
  printf("\n");
  return;
}
