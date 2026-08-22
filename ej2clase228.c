#include <stdio.h>
#include <stdint.h>


struct ID{
    char nombre[20];
    uint32_t nroCuenta;

    union persona{
        uint32_t dni;
        char pasaporte[11];
    }persona;
};

void imprimir(struct ID p);
uint32_t encenderBit (uint32_t nroCuenta, uint8_t E);

int main(void){

    struct ID p1 = {"Jose",99999999, .persona.dni = 44185604};

    struct ID p2 = {"Josefa",99999999, .persona.pasaporte = "CD674989"};

    p1.nroCuenta = encenderBit(p1.nroCuenta, 31);


    imprimir(p1);
    imprimir(p2);

    return 0;
}

void imprimir(struct ID p){
    printf("%s \t",p.nombre);
    printf("%i \t",p.nroCuenta & 0xFFFFFFF);
    
    if((p.nroCuenta>>31) & 0b1){
        printf("%i \n",p.persona.dni);
    }else{
        printf("%s \n",p.persona.pasaporte);
    }
}

uint32_t encenderBit (uint32_t nroCuenta, uint8_t E){
    nroCuenta = nroCuenta | (0b1<<E);
    return nroCuenta;
}
