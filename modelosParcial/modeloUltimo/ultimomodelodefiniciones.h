#ifndef definiciones
#define definiciones

#define EJ1
#define EJ2

typedef struct
{
    int temp;
    int humedad;
} data_t;

typedef struct Node Node;

struct Node
{
    Node *next;
    Node *prev;
    data_t data;
};

typedef Node dnode_t;

typedef struct NodoArbol
{
    int dato;
    int cantidad;
    struct NodoArbol *der;
    struct NodoArbol *izq;
} NodoArbol;

typedef struct NodoSimple
{
    int temp;
    struct NodoSimple *next;
} NodoSimple;

/* ============= Comienzo de sus prototipos ============= */
#define MAX_LIST_SIZE 1000
void printlist(Node *first, Node *last);
void borroHumNeg(Node **first, Node **last);
void del_first(Node **first, Node **last);
void del_last(Node **first, Node **last);
void del_mid(Node **nodob);
void printlistH80T2(Node *first, Node *last);
void crearLista(Node *first, NodoSimple **tempsfirst);
NodoSimple *crear_nodo(int dato);
NodoSimple *ins_first(NodoSimple *first, int dato);
void printlistsimple(NodoSimple *first);
void freeList(Node **first);

/* ===============  Fin de sus prototipos =============== */

/* ============ Prototipos Catedra (NO USAR) ============ */
void CATEDRA_CrearListaDoble(Node **primerNodo, Node **ultimoNodo);
#endif