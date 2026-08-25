#include <stdio.h>
#include <stdint.h>

void printBit (uint64_t dato, uint8_t  L);
void printBinario (uint64_t dato);
void encenderBit (uint64_t dato, uint8_t E);
void apagarBit (uint64_t dato, uint8_t A);

int main(void){

    //leer cualquier bit
    uint64_t dato = 13;
    int L = 2;
    printBit (dato,L);

    printBinario (dato);

    int E = 4;
    encenderBit(dato,E);
    
    int A = 2;
    apagarBit(dato,A);


    return 0;
}

void printBit(uint64_t dato, uint8_t L){
    printf("%lu\n",(dato>>L) & 0b1); //opcion 1

    uint64_t mask = dato & (0b1 << L);
    printf("%lu\n", mask == mask); //opcion 2
    //contando el primer bit como posicion 0 desde la derecha
    return;
}
void encenderBit (uint64_t dato, uint8_t E){
    dato = dato | (0b1<<E);
    printBinario (dato);
}

void apagarBit (uint64_t dato, uint8_t A){
    uint64_t mask = ~(0b1 << A);
    dato = dato & mask;
    printBinario (dato);
}

void printBinario(uint64_t dato){
    printf("0b");
    for (int i = 7; i>=0; i--){
        printf("%lu",(dato >> i) & 0b1);
        if(i % 4 == 0){
            printf(" ");
        }
    }
    printf("\n");
    return;
}
