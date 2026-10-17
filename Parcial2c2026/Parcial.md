# Parcial (M20) - Programacion en C - 2026C2

# Consideraciones 

- Las resoluciones deben ser genéricas
- No deben usar ni modificar nada del archivo Catedra_M18.c
- Un punto del exámen queda asociado a:

    - Utilización del formato provisto de la catedra
    - Claridad y orden de su código
    - Presentación clara y concisa de resultados
    - Utilización correcta de los recursos
    
- Recuerde liberar toda la memoria utilizada al finalizar el programa


## Ejercicio 1

La función CATEDRA_CrearGrilla devuelve la dirección de memoria de el primer nodo de una grilla (el de arriba a la izquierda), cada nodo de la grilla cumple la siguiente estructura.

```c
typedef struct NodoGrilla {
    char dato;
    char nextDato;
    struct NodoGrilla* up;
    struct NodoGrilla* down;
    struct NodoGrilla* left;
    struct NodoGrilla* right;
} NodoGrilla;
```

dato puede tomar dos valores '#' o ' ' 

*Consigna:*
Escriba una función que:

- Recorra la grilla por primera vez y en funcion de los valores de los nodos vecinos (ignorando las diagnoales) al actual, establezca el valor de nextDato. 
  - Si 0 o 4 vecinos son '#' : nextDato = ' '
  - Si   3   vecinos son '#' : nextDato = dato
  - Si 2 o 1 vecinos son '#' : nextDato = '#'

- Recorra la grilla por segunda vez y reeplaze todos los 'dato' por 'nextDato'


* * *

## Ejercicio 2

La función CATEDRA_CrearArbol genera un arbol ordenado y devuelve la dirección de memoria del nodo raiz del mismo, donde cada nodo sigue la siguente escructura

```c
typedef struct NodoArbol {
    int dato;
    struct DatosNodo der;
    struct DatosNodo izq;
} NodoArbol;

typedef struct {
    int distancia;
    struct NodoArbol* nodo;
} DatosNodo;
```

*Consignas:*
- A) Imprima la raiz, los dos primeros hijos y sus distancias.

- B) Escriba una función que encuentre un nodo a partir de su valor e imprima: 
    el camino que recorrio y la distancia total (si el numero no existe en el arbol se debe indicar esto en un mensaje).

- C) Uno de los siguientes datos {1 - 6 - 12 - 16} tiene la distancia total sea mayor a 20:
    - encuentre cual 
    - modifique la distancia (en la ultima conexion) para sea exactamente 20.

