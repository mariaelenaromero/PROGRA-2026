#include <stdio.h>
#include <stdint.h>

#define NOTAPROBACION 4

struct alumno{
        char nombre[20];
        float nota;
};

void imprimir(struct alumno a);
void check(struct alumno a);
/*PIENSE ESTRUCTURA PARA GUARDAR EL NOMBRE Y NOTA DE ALUMNO*/


int main(void){

    struct alumno a1 = {
        .nombre = "Maru",
        .nota = 9
    };

    struct alumno a2 = {
        .nombre = "Meli",
        .nota = 3
    };

    struct alumno a3 = {
        .nombre = "Cati",
        .nota = 8
    };

    imprimir(a1);
    imprimir(a2);
    imprimir(a3);
    check(a1);
    check(a2);
    check(a3);

    return 0;
}

void imprimir(struct alumno a){
    printf("%s \t",a.nombre);
    printf("%.2f \n\n",a.nota);
    return;
}

void check(struct alumno a){
    if(a.nota<NOTAPROBACION){
        printf("%s desaprobo, ingrese nota de recu\n",a.nombre);
        scanf("%f", &a.nota);
        printf("%s \t",a.nombre);
        printf("%.2f \n\n",a.nota);
    }
}