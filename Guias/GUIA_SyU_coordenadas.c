#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct
{
  float x;
  float y;
  float z;
} coordenadas;

float distancia(coordenadas p1, coordenadas p2);

int main(void)
{
  coordenadas p1, p2;
  p1.x = 2;
  p1.y = 8;
  p1.z = 3;

  p2.x = 7;
  p2.y = 1;
  p2.z = 3;

  distancia(p1, p2);

  printf("\nla distancia es %.2f\n\n", distancia(p1, p2));

  return 0;
}

float distancia(coordenadas p1, coordenadas p2)
{

  float dist = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z));

  return dist;
}
