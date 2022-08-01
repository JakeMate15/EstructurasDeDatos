#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

#define TRUE 1
#define FALSE 0
#define TAMCOLA 100

void manejaError(int);

COLA crearCola(){
	COLA C;
	
	C = (COLA)malloc(sizeof(Cola));
	if(C == NULL){
		manejaError(0);
		exit(0);
	}
	
	C->primero = 0;
	C->ultimo = 0;
	C->tam = 0;
	
	return C;
}

void encolar(COLA C, int x){
	if(C->tam == TAMCOLA){
		manejaError(3); //Cola llena
		exit(0);
	}
	
	C->cola[C->ultimo] = x;
	C->ultimo = sig(C->ultimo);
	C->tam = C->tam+1;
}

int es_vaciaCola(COLA c){
	if(c->tam == 0){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

int sig(int i){
	int p;
	p = (i+1)%TAMCOLA;
	
	return p;
}


int desencolar(COLA c){
	int v;
	
	if(es_vaciaCola(c) == TRUE){
		manejaError(4); //cola vacia
		exit(0);
	}
	
	v = c->cola[c->primero];
	c->primero = sig(c->primero);
	c->tam = c->tam-1;
	
	return v;
}

int primero(COLA c){
	int v;
	
	if(es_vaciaCola(c) == TRUE){
		manejaError(4); // Cola vacia
		exit(0);
	}
	
	v = c->cola[c->primero];
	
	return v;
}