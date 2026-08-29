#include <stdio.h>

/*1) Escribir una función que, al llamarla, imprima "Hola, Mundo!"
2) Implemente un código para hacer una calculadora, esta debe tener 4 opciones, sumar, restar, multiplicar y dividir. Cada una de estas operaciones debe estar contenida en una funcion la cual debe tomar los 2 numeros a operar como parametros.
3) Escriba una función que reciba tres números enteros como argumentos y devuelva el mayor de ellos. Luego, llama a esta función desde main y muestra el resultado.
4) Escribir una función recursiva que calcule el n-ésimo término de la secuencia de Fibonacci. La función debe recibir un número entero n como argumento y devolver el n-ésimo término de la secuencia. Luego, llama a esta función desde main y muestra el resultado.
5) Escribir una función que reciba dos números enteros y devuelva su máximo común divisor (MCD). Utiliza el algoritmo de Euclides para encontrar el MCD. Luego, llama a esta función desde main y muestra el resultado.
6) Escribir una función que reciba un número entero y devuelva la cantidad de dígitos que tiene. Luego, llama a esta función desde main y muestra el resultado.*/
void saludo(void);
void calculadora(void);
float suma(float a, float b);
float resta(float a, float b);
float multip(float a, float b);
float div(float a, float b);
void mayorde3(void);
void ejercicio4(void);
int fibonacci(int n);
void ejercicio5(void);
void ejercicio6(void);

int main(void)
{

  // saludo();
  // calculadora();
  // mayorde3();
  // ejercicio4();
  // ejercicio5();
  // ejercicio6();

  return 0;
}

void saludo()
{
  printf("Hola mundo!");
}

void calculadora(void)
{
  float a = 0, b = 0, result = 0;
  char c;
  printf("Ingrese los 2 numeros a operar y la operacion deseada (+,-,*,/)\n");
  scanf("%f %f %c", &a, &b, &c);
  switch (c)
  {
  case '+':
    result = suma(a, b);
    break;
  case '-':
    result = resta(a, b);
    break;
  case '*':
    result = multip(a, b);
    break;
  case '/':
    result = div(a, b);
    break;
  default:
    printf("operacion invalida\n");
    return;
  }
  printf("El resultado es: %f \n", result);
}

float suma(float a, float b)
{
  float result = a + b;
  return result;
}

float resta(float a, float b)
{
  float result = a - b;
  return result;
}

float multip(float a, float b)
{
  float result = a * b;
  return result;
}

float div(float a, float b)
{
  if (b != 0)
  {
    float result = a / b;
    return result;
  }
  else
  {
    printf("operacion invalida\n");
    return 0;
  }
}

void mayorde3(void)
{
  int a = 0, b = 0, c = 0;
  printf("ingrese 3 numeros enteros\n");
  scanf("%i %i %i", &a, &b, &c);
  int aux = a;

  if (aux < b)
  {
    aux = b;
  }
  if (aux < c)
  {
    aux = c;
  }
  printf("el numero mas grande fue: %i \n", aux);
}

void ejercicio4(void)
{
  int n = 0, result = 0;
  printf("termino seccuencia fibonacci\n");
  scanf("%i", &n);
  result = fibonacci(n);
  printf("el termino %i es el numero %i", n, result);
}
int fibonacci(int n)
{
  if (n == 1)
  {
    return 0;
  }
  else if (n == 2)
  {
    return 1;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

void ejercicio6(void)
{
  int a = 0, cantdig = 0;
  printf("Ingresar un numero entero\n");
  scanf("%i", &a);
  while (a != 0)
  {
    a = a / 10;
    cantdig++;
  }
  printf("La cantidad de digitos es %i\n", cantdig);
}
void ejercicio5(void)
{
  int a = 0, b = 0, resto = 0;
  printf("Ingresar dos numero entero\n");
  scanf("%i %i", &a, &b);
  while (b != 0)
  {
    resto = a % b;
    a = b;
    b = resto;
  }
  printf("El MCD es: %i\n", a);
}