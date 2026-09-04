#include <stdio.h>
#include <stdint.h>

void printVector(int vector[], int size);

int main(void)
{
  int vector[] = {1, 5, 3, 3, 4, 56, 7, 3};
  printVector(vector, 8);

  return 0;
}

void printVector(int vector[], int size)
{

  for (int i = 0; i < size; i++)
  {
    printf("%d\t", vector[i]);
  }

  return;
}