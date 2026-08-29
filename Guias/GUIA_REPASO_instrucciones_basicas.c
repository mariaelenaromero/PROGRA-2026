#include <stdio.h>

/*1 Implemente un código que pida al usuario un número y determine si es par o impar. LISTO
2 Implemente un código que imprima los números del 1 al 10 usando un bucle for.
3 Implemente un código que pida números (maximo 20 numeros) hasta que el usuario ingrese 0 a. calcule la suma de los números ingresados. b. devuelva el numero mas grande.
4 Implemente un código que pida al usuario un número del 1 al 7 y muestre el día de la semana correspondiente.
5 Implemente un código que declare un vector de 5 enteros, pida al usuario que ingrese los valores y luego los imprima.
6 Implemente un código que pida al usuario un número y calcule su factorial utilizando un bucle for/while.
7 Implemente un código que pida al usuario una frase y cuente cuántas vocales hay en la frase.
8 Implemente un código que pida al usuario dos números y una operación (+, -, *, /) y realice la operación correspondiente.*/

int main()
{
    /*
    //EJERCICIO 1
    int num = 0;
    printf("Ingrese un numero\n");
    scanf("%d", &num);
    printf("El numero ingresado es: %d\n", num);
    if (num % 2 == 0)
    {
        printf("El numero es par\n");
    }
    else
    {
        printf("El numero es impar\n");
    }

    //EJERCICIO 2
    printf("Los numeros del 1 al 10 son:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", i + 1);
    }

    //EJERCICIO 3
    printf("Ingrese como maximo 20 numeros, cuando no quiera ingresar mas ingrese 0 \n");

    int a = 1, b = 0, suma = 0;
    int v[20];

    scanf("%d", &a);

    int max = a;

    while (a != 0 && b < 20)
    {
        v[b] = a;
        suma += a;

        if (a > max)
        {
            max = a;
        }

        b++;

        scanf("%d", &a);
    }
    printf("la suma de los numeros ingresados es: %d \n", suma);
    printf("el numero mas grande es: %d \n", max);

    //EJERCICIO 4
    int dia = 0;
    printf("Ingrese un numero del 1 al 7\n");
    char semana[7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    scanf("%d", &dia);
    printf("El dia de la semana %d es el: %s \n", dia, semana[dia - 1]);

    //EJERCICIO 5
    int v[5];

    printf("Ingrese 5 numeros:\n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("Los numeros ingresados son:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }

    //EJERCICIO 6
    int n;
    int factorial = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }

    printf("El factorial de %d es: %d\n", n, factorial);

    //EJERCICIO 7
    char frase[100];
    int vocales = 0;

    printf("Ingrese una frase: ");
    gets(frase);

    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' ||
            frase[i] == 'o' || frase[i] == 'u')
        {
            vocales++;
        }
    }

    printf("La frase tiene %d vocales\n", vocales);

    //EJERCICIO 8
    float num1, num2, resultado;
    char operacion;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);

    printf("Ingrese la operacion (+, -, *, /): ");
    scanf(" %c", &operacion);

    switch (operacion)
    {
    case '+':
        resultado = num1 + num2;
        break;

    case '-':
        resultado = num1 - num2;
        break;

    case '*':
        resultado = num1 * num2;
        break;

    case '/':
        resultado = num1 / num2;
        break;

    default:
        printf("Operacion invalida\n");
        return 0;
    }

    printf("El resultado es: %.2f\n", resultado);

    */
    return 0;
}
