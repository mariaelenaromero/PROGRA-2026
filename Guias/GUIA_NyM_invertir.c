#include <stdio.h>
#include <stdint.h>

void printBinario(uint64_t num, int bits);

int main(void)
{
  // Realice un código que, a partir de un uint8 devuelva otro con los valores de los primeros y segundos 4 bits invertidos
  uint8_t num = 200;

  printf("Original en binario: 0b ");
  printBinario(num, 8);

  uint8_t ult4 = num >> 4;
  uint8_t prim4 = num << 4;

  uint8_t invertido = (prim4 | ult4);

  printf("Invertido en binario: 0b ");
  printBinario(invertido, 8);

  return 0;
}

void printBinario(uint64_t num, int bits)
{
  for (int i = bits - 1; i >= 0; i--)
  {
    printf("%d", (num >> i) & 1);
    if ((i % 4 == 0))
    {
      printf(" ");
    }
  }
  printf("\n");
  return;
}
