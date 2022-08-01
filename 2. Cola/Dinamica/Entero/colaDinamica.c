#include <stdlib.h>
#include "colaDinamica.h"

void manejaError(int);

COLA crearCola(){
	COLA c;
	
	c = (COLA)malloc(sizeof(Cola));
	if(c==NULL){
		manejaError(0);
		exit(0);
	}
	c->primero=NULL;
	c->ultimo=NULL;
	
	return c;
}

Nodo_Cola * crearNodoCola(){
	Nodo_Cola * nvo;
	
	nvo=(Nodo_Cola*)malloc(sizeof(Nodo_Cola));
	if(nvo == NULL){
		manejaError(0);
		exit(0);
	}
	
	return nvo;
}

int primero(COLA c){
	int v;
	
	if(es_vaciaCola(c)==TRUE){
		manejaError(4);
		exit(0);
	}
	
	v = c->primero->dato;
	
	return v;
}

int es_vaciaCola(COLA S){
	if(S->primero==NULL && S->ultimo==NULL) 
		return TRUE;
	else 
		return FALSE;
}

char desencolar(COLA c){
	int v;
	Nodo_Cola* aux;
	
	
	if(es_vaciaCola(c)==TRUE){
		manejaError(4);
		exit(0);
	}
	
	aux = c->primero;
	v = aux->dato;
	c->primero = aux->siguiente;
	
	if(c->primero==NULL){
		c->ultimo = NULL;
	}
	
	free(aux);
	return v;
}

void encolar(COLA c, int elem){
	Nodo_Cola *nvo;
	
	nvo = crearNodoCola();
	nvo->dato = elem;
	nvo->siguiente = NULL;
	
	if(es_vaciaCola(c) == TRUE){
		c->primero = nvo;
	}
	else{
		c->ultimo->siguiente=nvo;
	}
	
	c->ultimo=nvo;
}
