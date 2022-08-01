#include<stdio.h>
#include<stdlib.h>
#include "Pila.h"

void datosEntrada(PILA);
void mostrarPila(PILA, PILA);
void manejaError(int);
void liberaMemoria(PILA, PILA);

void main(){
	PILA S, INV;
	S = crearPila();
	INV = crearPila();
	datosEntrada(S);
	mostrarPila(S, INV);
	liberaMemoria(S, INV);
}


void datosEntrada(PILA S){
	int confi = 1;
	int elem;
	do{
		printf("Introduzca un elemento entero de la pila: ");
		scanf("%d", &elem);
		apilar(S, elem);
		printf("Desea ingresar otro elemento? [1 = Si, 0 = No]\n");
		scanf("%d", &confi);
	}while(confi == 1);
}

void mostrarPila(PILA S, PILA INV){
	int elem;
	while(es_vaciaPila(S) == FALSE){
		elem = desapilar(S);
		apilar(INV, elem);
	}
	printf("\nLOS ELEMENTOS DE LA PILA SON\n");
	while(es_vaciaPila(INV) == FALSE){
		elem = desapilar(INV);
		printf("%d, ", elem);
		apilar(S, elem);
	}
}

void manejaError(int e){
	char *errores[] = {"No hay memoria disponible\n", "La Pila esta llena\n", "La Pila esta vacia\n", "\nMemoria liberada\n"};
	printf("%s", errores[e]);
}

void liberaMemoria(PILA S, PILA INV){
	free(S);
	free(INV);
	manejaError(3);
}