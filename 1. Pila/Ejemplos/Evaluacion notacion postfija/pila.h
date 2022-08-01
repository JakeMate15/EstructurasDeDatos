#ifndef _pila_
#define _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct{
    float pila[TAMPILA];
    int tope;
}Pila;

typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
int es_vaciaPila(PILA S);
void apilar(PILA S, float e);
float desapilar(PILA S);
float elemTope(PILA S);
#endif 