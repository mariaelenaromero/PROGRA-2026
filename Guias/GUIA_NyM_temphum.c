#include <stdio.h>
#include <stdint.h>

void temp(uint8_t tyh);
void hum(uint8_t tyh);

int main(void)
{
  // Realice un código que, tomando un uint16 como entrada defina si el numero es o no par. a) utilizando el operador % b) sin utilizar el operador %
  uint16_t u16 = 0b1011001101011100;
  uint8_t temperatura = u16 >> 8;
  uint8_t humedad = u16 & 0xFF;

  temp(temperatura);
  hum(humedad);

  return 0;
}

void temp(uint8_t tyh)
{

  printf("La temperatura es: %u", tyh);
  printf("\n");

  return;
}

void hum(uint8_t tyh)
{

  printf("La humedad es: %u", tyh);
  printf("\n");

  return;
}