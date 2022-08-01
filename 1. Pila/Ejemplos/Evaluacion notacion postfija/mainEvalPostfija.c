#include<stdio.h>
#include<stdlib.h>
#include "Pila.h"
#define TRUE 1
#define FALSE 0
#define TAMPILA 100

void leeExpresion(char * );
float evalua(PILA, char * );
void manejaError(int);
void liberaMemoria(PILA);

void main(){
	char cadena[100];
	float res;
	PILA S;

	S = crearPila();
    leeExpresion(cadena);
	res = evalua(S,cadena);
    printf("%s = %.2f\n", cadena,res);
	liberaMemoria(S);
}

void leeExpresion(char * cadena){
	int pos = 0;

	printf("\nEvaluacion de expresiones Postfijas\n");
    printf("Operaciones Basicas: Suma, REsta, Producto y division");
    printf("\n\nIntroduzca la expresion postfija: ");

    while( (cadena[pos++] = getchar()) !='\n');
    cadena[pos-1]='\0';
}

float evalua(PILA S,char * cadena){
    float a,b,aux;
    int pos = 0;
    char op[1];
    double conv;
    int i;

    while(cadena[pos] != '\0'){
		
        *op = cadena[pos++];

        switch(*op){
            case '+':   b = desapilar(S);
                        a = desapilar(S);
                        apilar(S,a+b);
                        break;
            case '-':   b = desapilar(S);
                        a = desapilar(S);
                        apilar(S,a-b);     
                        break;     
            case '*':   b= desapilar(S);
                        a = desapilar(S);
                        apilar(S,a*b);
                        break;
            case '/':   b = desapilar(S);
                        a = desapilar(S);
                        if(b==0){
                            manejaError(4);
                            return 0;
                            break;
                        }   
                        apilar(S,a/b);  
                        break;   
            case '^':   b = desapilar(S);
                        a = desapilar(S);
						if(b<1){
							manejaError(5);
                            return 0;
                            break;
						}
						aux = a;
						for(i=1;i<b;i++){
							aux*=a;
						}
						apilar(S,aux);     
						break;  
            default:    conv = atof(op);
                        apilar(S,conv);  
        }
    }

    return (desapilar(S));
}

void manejaError(int e){
	char *errores[] = {"No hay memoria disponible\n", "La Pila esta llena\n", "La Pila esta vacia\n", "\nMemoria liberada\n","\nDivision por cero\n","\nExponente menor que 1\n"};
	printf("%s", errores[e]);
}

void liberaMemoria(PILA S){
	free(S);
	manejaError(3);
}
