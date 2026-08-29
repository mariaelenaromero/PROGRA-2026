#include <stdio.h>
#include <stdint.h>

void intercambio(int *ptr1,int *ptr2);

int main(void)
{
    //funcion que intercambia los valores de dos variables enteras usando punteros

    int uno = 5, dos = 10;

    printf("Var1: %d\n Var2: %d\n",uno,dos);

    intercambio(&uno,&dos);

    printf("Var1: %d\n Var2: %d\n",uno,dos);

    return 0;
}

void intercambio(int *ptr1,int *ptr2)
{
    int aux = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = aux;
    
    return;
}
