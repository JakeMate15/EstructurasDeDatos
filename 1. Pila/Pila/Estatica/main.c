#include<stdio.h>
#include<stdlib.h>
#include "Pila.h"
#define TRUE 1
#define FALSE 0
#define TAMPILA 100

void darDatos(PILA);
void imprimeDatos(PILA , PILA);
void manejaError(int);
void liberaMemoria(PILA);

void main(){
	PILA s, aux;

	s = crearPila();
    aux = crearPila();

    darDatos(s);
	imprimeDatos(s,aux);

	liberaMemoria(s);
    liberaMemoria(aux);
}

void darDatos(PILA pila){
	int op, dato;

    do{
        printf("\nIngresa un elemento a la pila: ");
        scanf("%d",&dato);
        apilar(pila,dato);

        printf("Quieres agregar otro elemento? Si-1 No-0 ");
        scanf("%d",&op);
    }while(op==1);
}

void imprimeDatos(PILA a, PILA b){
    int dato;

    printf("\nLos elementos de la pila son: \n");

    while(!es_vaciaPila(a)){
        dato = desapilar(a);
        apilar(b,dato);
    }

    while(!es_vaciaPila(b)){
        dato = desapilar(b);
        apilar(a,dato);
        printf("%d ",dato);
    }

}

void manejaError(int e){
	char *errores[] = {"No hay memoria disponible\n", "La Pila esta llena\n", "La Pila esta vacia\n", "\nMemoria liberada\n","\nDivision por cero\n","\nExponente menor que 1\n"};
	printf("%s", errores[e]);
}

void liberaMemoria(PILA S){
	free(S);
	manejaError(3);
}
