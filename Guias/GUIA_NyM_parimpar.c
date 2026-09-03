#include <stdio.h>
#include <stdint.h>

void parconresto(uint16_t num);
void parsinresto(uint16_t num);

int main(void)
{
  // Realice un código que, tomando un uint16 como entrada defina si el numero es o no par. a) utilizando el operador % b) sin utilizar el operador %
  uint16_t u16 = 43672;

  parconresto(u16);
  parsinresto(u16);

  return 0;
}

void parconresto(uint16_t num)
{
  if (num % 2 == 0)
  {
    printf("CON RESTO: El numero %u es par\n", num);
  }
  else
  {
    printf("CON RESTO: El numero %u es impar\n", num);
  }
}

void parsinresto(uint16_t num)
{
  if (num & 0b1)
  {
    printf("SIN RESTO: El numero %u es impar\n", num);
  }
  else
  {
    printf("SIN RESTO: El numero %u es par\n", num);
  }
}