#include <stdio.h>
#include <stdlib.h>
#include "modelo4header.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modelo4header.h"

const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#$&@?~+";

NodoGrilla *CATEDRA_CrearGrillaIrregular()
{
    int cols[10] = {9, 16, 10, 11, 12, 13, 14, 11, 15, 9};

    NodoGrilla ***nodos = malloc(10 * sizeof(NodoGrilla **));

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        nodos[i] = malloc(cols[i] * sizeof(NodoGrilla *));

        for (int j = 0; j < cols[i]; j++)
        {
            nodos[i][j] = malloc(sizeof(NodoGrilla));

            nodos[i][j]->dato = charset[rand() % (sizeof(charset) - 1)];

            nodos[i][j]->up = NULL;
            nodos[i][j]->down = NULL;
            nodos[i][j]->left = NULL;
            nodos[i][j]->right = NULL;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            if (j > 0)
            {
                nodos[i][j]->left = nodos[i][j - 1];
            }

            if (j < cols[i] - 1)
            {
                nodos[i][j]->right = nodos[i][j + 1];
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        int minCols = cols[i] < cols[i + 1] ? cols[i] : cols[i + 1];

        for (int j = 0; j < minCols; j++)
        {
            nodos[i][j]->down = nodos[i + 1][j];
            nodos[i + 1][j]->up = nodos[i][j];
        }
    }

    return nodos[0][0];
}
