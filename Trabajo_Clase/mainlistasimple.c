#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "funcs.c"

int main()
{

    nodo_t *nodo0 = ins_first(NULL, 0);
    nodo0 = ins_first(nodo0, 1);
    nodo0 = ins_first(nodo0, 2);
    nodo0 = ins_first(nodo0, 3);

    printlist(nodo0);

    del_last(&nodo0);

    printlist(nodo0);

    ins_last(nodo0, -1);

    printlist(nodo0);

    del_first(&nodo0);

    printlist(nodo0);

    return 0;
}
