#include <stdio.h>
#include <stdint.h>

int main(void)
{
  int vector1[] = {11, 5, 7, 250, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63};
  uint8_t vector2[] = {11, 5, 7, 250, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63};
  uint16_t vector3[] = {11, 5, 7, 250, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63};
  uint32_t vector4[] = {11, 5, 7, 250, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63};
  uint64_t vector5[] = {11, 5, 7, 250, 3, 5, 6, 7, 4, 3, 33, 5, 6, 7, 63};
  char cadena1[] = "Hola como va";
  char cadena2[] = {'H', 'o', 'l', 'a', ' ', 'c', 'o', 'm', 'o', ' ', 'v', 'a'};

  printf("Elementos vector 1: %d\n", sizeof(vector1) * 8 / 32);
  printf("Elementos vector 2: %d\n", sizeof(vector2) * 8 / 8);
  printf("Elementos vector 3: %d\n", sizeof(vector3) * 8 / 16);
  printf("Elementos vector 4: %d\n", sizeof(vector4) * 8 / 32);
  printf("Elementos vector 5: %d\n", sizeof(vector5) * 8 / 64);
  printf("Elementos cadena 1: %d\n", sizeof(cadena1) * 8 / 8);
  printf("Elementos cadena 2: %d\n", sizeof(cadena2) * 8 / 8);

  return 0;
}