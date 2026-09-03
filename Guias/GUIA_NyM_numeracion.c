#include <stdio.h>
#include <stdint.h>

#define N 43

int main(void)
{
  uint8_t u = 0b11111111;
  int8_t s = 0b10000000;

  uint32_t u32 = 0b11111111111111111111111111111111;
  int32_t s32 = 0b10000000000000000000000000000000;

  int num = N;

  printf("Tamanio char: %d bytes\n", sizeof(char));
  printf("Tamanio short: %d bytes\n", sizeof(short));
  printf("Tamanio int: %d bytes\n", sizeof(int));
  printf("Tamanio long: %d bytes\n", sizeof(long));
  printf("Tamanio float: %d bytes\n", sizeof(float));
  printf("Tamanio double: %d bytes\n", sizeof(double));

  printf("mayor Unsigned 8 bits 0b 1111 1111: %u\n", u);
  printf("menor Signed 8 bits 0b 1000 0000: %d\n", s);

  printf("mayor Unsigned 32 bits 0b 1111 1111 1111 1111 1111 1111 1111 1111: %u\n", u32);
  printf("menor Signed 32 bits 0b 1000 0000 0000 0000 0000 0000 0000 0000: %d\n", s32);

  printf("Decimal: %d\n", num);
  printf("Octal: %o\n", num);
  printf("Hexa: %X\n", num);
  printf("Binario: ");

  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (num >> i) & 1);
    if ((i % 4 == 0))
    {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}