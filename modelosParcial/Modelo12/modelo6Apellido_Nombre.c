#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "modelo6Catedra_M12.c"
#include "modelo6definiciones.h"
#include "modelo6funciones.c"

int main(void)
{

#ifdef EJ1
    printf("\n=== EJERCICIO 1 ===\n");
    nodo_t *primero = NULL;
    leerArchivo(&primero);

#endif

#ifdef EJ2
    printf("\n=== EJERCICIO 2 ===\n");
    qnode_t *first = CATEDRA_CrearGrilla();
    printGrilla(first);
    recorroXp(first);
    tomaPos(5, 8, first);
    tomaPos(5, 5, first);
    tomaPos(1, 6, first);
    tomaPos(9, 3, first);
    tomaPos(14, 0, first);
    tomaPos(0, 0, first);
#endif
    printf("FIN para ver que no quede trabado ningun bucle\n\n");
    return 0;
}