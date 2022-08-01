#include<stdlib.h>
#include "Pila.h"
#define TRUE 1
#define FALSE 0 

void manejaError(int);

PILA crearPila(){
	PILA S;

	S = (PILA) malloc(sizeof(Pila));
	if(S == NULL){
		manejaError(0);
		exit(0);
	}

	S->tope = -1;
	return S;
}

int es_vaciaPila(PILA S){
	if(S->tope < 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

void apilar(PILA S, float e){
	if(S->tope == TAMPILA-1){
		manejaError(1);
		exit(0);
	}
	S->tope++;
	S->pila[S->tope] = e;
}

float desapilar(PILA S){
	float v;

	if(es_vaciaPila(S) == TRUE){
		manejaError(2);
		exit(0);
	}
	
	v = S->pila[S->tope];
	S->tope--;
	return v;
}

float elemTope(PILA S){
	float v;

	if(es_vaciaPila(S) == TRUE){
		manejaError(2);
		exit(0);
	}

	v = desapilar(S);
	apilar(S, v);
	
	return v;
}
