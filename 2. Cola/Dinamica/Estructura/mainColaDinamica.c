#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "colaDinamica.h"

void manejaError(int);
void liberarMemoria(COLA, COLA, COLA);
void darDatos(COLA);
void mostrarDatos(COLA, COLA);
void titulo(COLA, COLA);

void main(){
	COLA a, b, aux;
	
	a = crearCola();
	b = crearCola();
	aux = crearCola();
	
	darDatos(a);
	titulo(a,b);
	
	mostrarDatos(a,aux);
	liberarMemoria(a, aux,b);

}


void liberarMemoria(COLA a, COLA aux, COLA b){
	free(a);
	free(aux);
	free(b);
	manejaError(2);
}

void darDatos(COLA S){
	int op = 1;
	char tit[30],autor[30],editorial[30];
	int year;
	
	printf("Introduzca los datos del libro: \n");
	do{
		Libro elem;
		
		printf("Titulo del libro: ");
		scanf("%[^\n]",elem.titulo);
		getchar();
		
		printf("Autor del libro: ");
		scanf("%[^\n]",elem.autor);
		getchar();
		
		printf("Editorial del libro: ");
		scanf("%[^\n]",elem.editorial);
		
		printf("Año del libro: ");
		scanf("%d", &elem.year);
		
		encolar(S, elem);
		printf("\n\nQuiere dar los datos de otro libro? 1-Si 0-No: ");
		scanf("%d", &op);
		getchar();
	}while(op == 1);
}

void titulo(COLA a, COLA b){
	Libro dato;
	char nombre[30];

	while(!es_vaciaCola(a)){
		dato = desencolar(a);
		encolar(b, dato);
	}
	
	while(!es_vaciaCola(b)){
		dato = desencolar(b);
		strcpy(nombre,dato.titulo);
		
		
		for(int i=0; i<strlen(nombre);i++){
			nombre[i] = tolower(nombre[i]);
		}
		
		
		if(strcmp(nombre,"fundamentos de programacion")== 0){
			encolar(a,dato);
		}
	}
}

void mostrarDatos(COLA q, COLA aux){
	Libro dato;
	char tit[30],autor[30],editorial[30];
	int year;

	printf("\nLOS DATOS DE LA COLA SON\n");
	while(!es_vaciaCola(q)){
		dato = desencolar(q);
		encolar(aux, dato);
	}

	while(!es_vaciaCola(aux)){
		dato = desencolar(aux);
		
		printf("\nTitulo del libro: %s \n", dato.titulo);
		printf("Autor del libro: %s \n", dato.autor);
		printf("Editorial del libro: %s \n", dato.editorial);
		printf("Año del libro: %d \n", dato.year);
		
		encolar(q, dato);	
	}
}

void manejaError(int opcion){
	char *mensaje[] = {"No hay memoria disponible", "Pila vacia", "Memoria Liberada"};
	printf("\n%s\n", mensaje[opcion]);
}
