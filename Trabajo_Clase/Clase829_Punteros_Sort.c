#include <stdio.h>
#include <stdint.h>
#define VECTORSIZE 17

void impVector(int vector[], int l);
void buscarMin(int vector[], int l, int ultimoMin, int *min);

int main(void)
{
    FILE *fp;
    int vector[VECTORSIZE], vOrden[VECTORSIZE];
    int i = 0, min = 0, ultMin = 0;

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

    impVector(vector, i);
    printf("\n");

    for (int c = 0; c < i; c++)
    {
        buscarMin(vector, i, ultMin, &min);
        vOrden[c] = min;
        ultMin = min;
    }

    impVector(vOrden, i);

    return 0;
}

void impVector(int vector[], int l)
{

    for (int i = 0; i < l; i++)
    {
        printf("%d\t", vector[i]);
    }

    return;
}

void buscarMin(int vector[], int l, int ultimoMin, int *min)
{
    int minimo = 100000;

    for (int i = 0; i < l; i++)
    {
        if (minimo > vector[i])
        {
            if (ultimoMin < vector[i])
            {
                minimo = vector[i];
            }
        }
    }

    *min = minimo;

    return;
}