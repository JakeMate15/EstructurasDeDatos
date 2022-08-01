#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colaDinamica.h"

void manejaError(int);
void menu(COLA, COLA);
void lectura(char*);
void darDatos(COLA);
void sacaElemento(COLA,COLA);
void mostrarDatos(COLA, COLA);
void vaciarCesta(COLA);
void liberarMemoria(COLA, COLA);

void main(){
	COLA a, aux;
	
	a = crearCola();
	aux = crearCola();

	menu(a, aux);
	
	liberarMemoria(a, aux);

}


void liberarMemoria(COLA a, COLA aux){
	free(a);
	free(aux);
	manejaError(1);
}

void menu(COLA a, COLA aux){
	int opcion;

	do{
		printf("\n\nMENU DE OPCIONES \n 1.- Introduzca un elemento a la cesta\n 2.- Sacar un elemento de la cesta\n 3.- Imprime los elementos de la cesta\n 4.- Vacia la cesta\n Introduzca cualquier otro numero para salir del programa:");
		printf("\n\n(Introduzca una opcion): ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:	darDatos(a);
					break;
			case 2:	sacaElemento(a, aux);
					break;
			case 3:	mostrarDatos(a,aux);
					break;
			case 4:	vaciarCesta(a);
					break;
			default:manejaError(6);
		}
	}while(opcion > 0 && opcion < 5);
	
}

void lectura(char *elemento){
	printf("Ingrese el elemento: ");
	scanf("%s",elemento);
	getchar();
}

void darDatos(COLA s){
	Cadena cad;
	
	lectura(cad.cad);

	encolar(s,cad);
}

void sacaElemento(COLA a, COLA b){
	char elemento[20];
	Cadena cad;

	if(es_vaciaCola(a)==FALSE){
		lectura(elemento);

		while(!es_vaciaCola(a)){
			cad = desencolar(a);

			if(strcasecmp(cad.cad,elemento)!=0){
				encolar(b, cad);
			}
			
		}
		
		while(!es_vaciaCola(b)){
			cad = desencolar(b);
			
			encolar(a,cad);
		}
	}
	else{
		manejaError(4);
	}
}

void mostrarDatos(COLA q, COLA aux){
	Cadena cad;

	if(es_vaciaCola(q)==FALSE){
		printf("LOS ELEMENTOS EN LA CESTA SON\n");

		while(!es_vaciaCola(q)){
			cad = desencolar(q);
			encolar(aux,cad);
			printf("%s ", cad.cad);
		}

		while(!es_vaciaCola(aux)){
			cad = desencolar(aux);
			encolar(q, cad);	
		}
	}
	else{
		manejaError(4);
	}
}

void vaciarCesta(COLA a){
	if(es_vaciaCola(a)==FALSE){
		while(!es_vaciaCola(a)){
			desencolar(a);
		}
		manejaError(5);
	}
	else{
		manejaError(4);
	}
}

void manejaError(int opcion){
	char *mensaje[] = {"No hay memoria disponible", "Memoria Liberada", "Pila vacia","Cola vacia","Cesta vacia","Se ha vaciado la cesta","Saliendo del programa"};
	printf("\n%s\n", mensaje[opcion]);
}
