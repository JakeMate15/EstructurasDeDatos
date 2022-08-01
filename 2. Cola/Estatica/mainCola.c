#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

#define TRUE 1
#define FALSE 0

void manejaError(int e);
void datosEntrada(COLA c);
void imprimeCola(COLA c, COLA aux);
void liberaMemoria(COLA c, COLA c1);

void main(){
	COLA c,aux;
	
	c = crearCola();
	aux = crearCola();
	
	datosEntrada(c);
	imprimeCola(c,aux);
	
	liberaMemoria(c,aux);
}


void manejaError(int e){
	char *errores[] = {"No hay memoria disponible\n", "La Pila esta llena\n", "La Pila esta vacia\n", "\nCola llena\n", "\nCola vacia\n", "\nMemoria liberada\n"};
	printf("%s", errores[e]);
}

void datosEntrada(COLA c){
	int op = 1;
	int dato;
	
	do{
		printf("\nIngresa un numero: ");
		scanf("%d",&dato);
		encolar(c,dato);
		printf("¿Quiere agregar otro elemento? 1-Si 0-No: ");
		scanf("%d",&op);
	}while(op==1);
}

void imprimeCola(COLA c, COLA aux){
	int dato;
	
	printf("\nLos elementos de la cola son: \n");
	while(es_vaciaCola(c) == FALSE){
		dato = desencolar(c);
		
		printf("%d  ", dato);
		encolar(aux, dato);
	}
	
	while(es_vaciaCola(aux) == FALSE){
		dato = desencolar(aux);
		encolar(c, dato);
	}
}

void liberaMemoria(COLA c, COLA c1){
	free(c);
	free(c1);
	manejaError(5);
}