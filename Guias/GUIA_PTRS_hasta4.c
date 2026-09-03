#include <stdio.h>
#include <stdint.h>

void intercambio(int *a, int *b);
int sumaArray(int vector[], int l);
int longCadena(char cadena[]);
void doblarArray(int *vector, int l);

int main(void)
{

  // 1. Escribe una función que intercambie los valores de dos variables enteras usando punteros. Luego, llama a esta función desde main y muestra los valores antes y después del intercambio.

  int a = 8, b = 3;
  printf("a = %d\nb = %d\n", a, b);
  intercambio(&a, &b);
  printf("a = %d\nb = %d\n", a, b);

  // 2. Escribe una función que reciba un puntero a un array de enteros y su tamaño, y devuelva la suma de sus elementos. Luego, llama a esta función desde main y muestra el resultado.
  int vector[5] = {2, 4, 6, 8, 10};
  printf("Suma = %d\n", sumaArray(vector, 5));

  // 3. Escribe una función que reciba un puntero a una cadena (\\0 representa el final de cadena) de caracteres (string) y devuelva su longitud. Luego, llama a esta función desde main y muestra el resultado.
  char cadena[50] = "hola como estas?";
  printf("Cantidad de caracteres = %d\n", longCadena(cadena));

  // 4. Escribe una función que reciba un puntero a un array de enteros y su tamaño, y multiplique cada elemento por 2. Luego, llama a esta función desde main y muestra los elementos del array antes y después de la modificación.
  printf("Vector antes  : ");
  for (int i = 0; i < 5; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");
  doblarArray(vector, 5);

  printf("Vector despues: ");
  for (int i = 0; i < 5; i++)
  {
    printf("%d\t", vector[i]);
  }
  printf("\n");

  return 0;
}

void intercambio(int *a, int *b)
{

  int aux = *a;
  *a = *b;
  *b = aux;

  return;
}

int sumaArray(int vector[], int l)
{
  int suma = 0;
  for (int i = 0; i < l; i++)
  {
    suma = suma + vector[i];
  }

  return suma;
}

int longCadena(char cadena[])
{
  int i = 0;
  while (cadena[i] != '\0')
  {
    i++;
  }
  return i;
}

void doblarArray(int *vector, int l)
{
  for (int i = 0; i < l; i++)
  {
    vector[i] = vector[i] * 2;
  }
  return;
}