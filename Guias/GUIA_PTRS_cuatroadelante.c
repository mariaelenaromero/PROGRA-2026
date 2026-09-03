#include <stdio.h>
#include <stdint.h>

void cambiarCad(char cad1[], char cad2[]);
int *mayorArray(int vector[], int l);
int indice(char cad[], char letra);

int main(void)
{
  // Escribe una función que reciba dos punteros a cadenas de caracteres y copie el contenido de la segunda cadena en la primera. Luego, llama a esta función desde main y muestra las cadenas antes y después de la copia.
  char cad1[50] = "Hola que onda?", cad2[50] = "Todo bien, vos?";
  printf("Cadena 1: %s\n", cad1);
  printf("Cadena 2: %s\n", cad2);

  printf("\nCambio: \n");

  cambiarCad(cad1, cad2);
  printf("Cadena 1: %s\n", cad1);
  printf("Cadena 2: %s\n", cad2);

  // Escribe una función que reciba un puntero a un array de enteros y su tamaño, y devuelva un puntero al elemento de mayor valor en el array. Luego, llama a esta función desde main y muestra el valor del elemento de mayor valor.
  int vector[5] = {4, 12, 7, 25, 9};
  printf("El mayor valor es: %d\n", *mayorArray(vector, 5));

  // Escribe una función que reciba un puntero a una cadena de caracteres y un carácter, y devuelva la posición (índice) de la primera ocurrencia del carácter en la cadena. Si el carácter no se encuentra en la cadena, la función debe devolver -1. Luego, llama a esta función desde main y muestra el resultado.
  int idx = indice(cad2, '?');
  if (idx == -1)
  {
    printf("El caracter no esta en la cadena\n");
  }
  else
  {
    printf("El caracter esta en la cadena en la posicion: %d\n", idx + 1);
  }
  return 0;
}

void cambiarCad(char cad1[], char cad2[])
{
  int i = 0;
  while (cad2[i] != '\0')
  {
    cad1[i] = cad2[i];
    i++;
  }
  cad1[i] = '\0';
  return;
}

int *mayorArray(int vector[], int l)
{
  int *max = &vector[0];
  for (int i = 1; i < l; i++)
  {
    if (*max < vector[i])
    {
      max = &vector[i];
    }
  }
  return max;
}

int indice(char cad[], char letra)
{
  int i = 0;
  while (cad[i] != '\0')
  {
    if (letra == cad[i])
    {
      return i;
    }
    i++;
  }
  return -1;
}