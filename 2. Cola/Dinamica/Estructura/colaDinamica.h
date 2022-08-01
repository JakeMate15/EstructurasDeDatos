#ifndef _colaDinamica_
#define _colaDinamica_
#define TRUE 1
#define FALSE 0

typedef struct Libro{
	char titulo[30];
	char autor[30];
	char editorial[30];
	int year;
}Libro;

typedef struct Nodo_Cola{
	Libro dato;
	struct Nodo_Cola * siguiente;
}Nodo_Cola;

typedef struct{
	Nodo_Cola *primero;
	Nodo_Cola *ultimo;
}Cola;

typedef Cola *COLA;

COLA crearCola();
Nodo_Cola* crearNodoCola();
int es_vaciaCola(COLA);
Libro primero(COLA);
void encolar(COLA, Libro);
Libro desencolar(COLA);

#endif
