#include <stdio.h>
#include <stdint.h>

struct ID{
    char nombre[20];
    int nroCuenta;
    int argentino;

    union persona{
        int dni;
        char pasaporte[11];
    }persona;
};

void imprimir(struct ID p);

int main(void){

    struct ID p1 = {"Jose",1234,1, .persona.dni = 44185604};

    struct ID p2 = {"Josefa",4321,0, .persona.pasaporte = "CD674989"};

    imprimir(p1);
    imprimir(p2);

    return 0;
}

void imprimir(struct ID p){
    printf("%s \t",p.nombre);
    printf("%i \t",p.nroCuenta);
    if(p.argentino){
        printf("%i \n",p.persona.dni);
    }else{
        printf("%s \n",p.persona.pasaporte);
    }
}