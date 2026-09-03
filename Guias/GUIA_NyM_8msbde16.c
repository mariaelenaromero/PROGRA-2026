#include <stdio.h>
#include <stdint.h>

void printBinario(uint64_t num, int bits);

int main(void)
{
  // Realice un código que, tomando un uint16 como entrada, devuelva los 8 bits mas significativos.
  uint16_t u16 = 43672;
  uint8_t u8 = u16 >> 8;

  printBinario(u16, sizeof(uint16_t) * 8);

  printBinario(u8, sizeof(uint8_t) * 8);

  return 0;
}

void printBinario(uint64_t num, int bits)
{
  printf("Numero en binario: 0b");
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
