#ifndef _cola_ 
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct{
	int cola[TAMCOLA];
	int primero, ultimo;
	int tam;
}Cola;

typedef Cola*COLA;

COLA crearCola(void);
void encolar(COLA c, int x);
int es_vaciaCola(COLA c);
int sig(int i);
int desencolar(COLA c);
int primero(COLA c);

#endif 