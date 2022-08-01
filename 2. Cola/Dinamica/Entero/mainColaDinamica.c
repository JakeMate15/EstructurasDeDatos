#include <stdlib.h>
#include <stdio.h>
#include "colaDinamica.h"

void manejaError(int);
void liberarMemoria(COLA, COLA);
void darDatos(COLA);
void mostrarDatos(COLA, COLA);

void main(){
	COLA a, aux;
	
	a = crearCola();
	aux = crearCola();

	darDatos(a);
	
	mostrarDatos(a,aux);
	liberarMemoria(a, aux);

}


void liberarMemoria(COLA a, COLA aux){
	free(a);
	free(aux);
	manejaError(2);
}

void darDatos(COLA S){
	int op = 1;
	int elem;
	
	printf("Introduzca un elemento a la cola: \n");
	do{
		scanf("%d", &elem);
		encolar(S, elem);
		printf("Quiere seguir introduciendo? 1-Si 0-No: ");
		scanf("%d", &op);
	}while(op == 1);
}

void mostrarDatos(COLA q, COLA aux){
	int dato;

	printf("\nLOS DATOS DE LA COLA SON\n");
	while(!es_vaciaCola(q)){
		dato = desencolar(q);
		encolar(aux, dato);
	}

	while(!es_vaciaCola(aux)){
		dato = desencolar(aux);
		printf("%d ", dato);
		encolar(q, dato);	
	}
}

void manejaError(int opcion){
	char *mensaje[] = {"No hay memoria disponible", "Pila vacia", "Liberando memoria"};
	printf("\n%s\n", mensaje[opcion]);
}
