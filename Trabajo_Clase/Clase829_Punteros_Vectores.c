#include <stdio.h>
#include <stdint.h>
#define VECTORSIZE 17

void buscarMax(int vector[], int l, int *max, int *min, float *prom);
void impVector(int vector[], int l);
void buscarMin(int vector[], int l);

int main(void)
{
    FILE *fp;
    int vector[VECTORSIZE];
    int i = 0, max = 0, min = 0;
    float prom = 0;

    fp = fopen("short_lista.bin", "rb");
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 0;
    }

    while (fread(&vector[i], sizeof(int), 1, fp))
    {
        i++;
    }

    fclose(fp);

    buscarMax(vector, i, &max, &min, &prom);

    printf("\nEl numero mayor del vector es: %d\n", max);
    printf("\nEl numero menor del vector es: %d\n", min);
    printf("\nEl promedio de los numeros del vector es: %.2f\n", prom);

    impVector(vector, i);

    return 0;
}

void buscarMax(int vector[], int l, int *max, int *min, float *prom)
{
    int maximo = vector[0], minimo = vector[0];
    float promedio = vector[0];

    for (int i = 1; i < l; i++)
    {
        if (maximo < vector[i])
        {
            maximo = vector[i];
        }
        if (minimo > vector[i])
        {
            minimo = vector[i];
        }
        promedio = promedio + vector[i];
    }

    promedio = promedio / l;

    *max = maximo;
    *min = minimo;
    *prom = promedio;

    return;
}

void impVector(int vector[], int l)
{

    for (int i = 0; i < l; i++)
    {
        printf("%d\t", vector[i]);
    }

    return;
}