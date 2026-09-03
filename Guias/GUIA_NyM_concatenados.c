#include <stdio.h>
#include <stdint.h>

void printBinario(uint64_t num, int bits);

int main(void)
{
  // Realice un código que, a partir de dos uint8 devuelva un uint16 con los valores de los primeros 2, concatenados.
  uint8_t num1 = 73;
  printBinario(num1, 8);

  uint8_t num2 = 200;
  printBinario(num2, 8);

  uint16_t primeros8 = num1 << 8;
  uint16_t ultimos8 = num2 & 0xFF;

  uint16_t result = primeros8 | ultimos8;

  printBinario(result, 16);

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