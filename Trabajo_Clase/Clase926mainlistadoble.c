#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "funcs.c"

int main()
{

    doblenodo_t *nodo0 = NULL;
    doblenodo_t *nodol = nodo0;
    ins_first(&nodo0, &nodol, 1);
    ins_first(&nodo0, &nodol, 2);
    ins_first(&nodo0, &nodol, 3);

    printlist(nodo0, nodol);

    del_last(&nodol, &nodo0);
    printlist(nodo0, nodol);

    del_last(&nodol, &nodo0);
    printlist(nodo0, nodol);

    del_last(&nodol, &nodo0);
    printlist(nodo0, nodol);

    ins_last(&nodo0, &nodol, -1);

    printlist(nodo0, nodol);

    del_first(&nodo0, &nodol);

    printlist(nodo0, nodol);

    return 0;
}
