#include <stdio.h>
#include <stdlib.h>

typedef int tipoDato;

typedef struct nodo{
	tipoDato elemento;
	struct nodo *siguiente;
}Nodo;

//typedef struct nodo Nodo;
typedef struct{
	Nodo *frente;
	Nodo *finalito;
}Cola;

void crearCola(Cola *cola);
void insertar(Cola *cola, tipoDato entrada);
tipoDato quitar(Cola *cola);
void borrarCola(Cola *cola);
tipoDato frente(Cola cola);
int colaVacia(Cola cola);
void verCola(Cola *cola);
void menu();
Nodo *crearNodo(tipoDato elemento);

int main(){
	
	menu();

	return 0;
}

void crearCola(Cola *cola){
	cola -> frente = cola -> finalito = NULL;
	printf("Se ha creado una nueva cola\n");
}

Nodo *crearNodo(tipoDato elemento){
	Nodo *t;
	t = (Nodo *)malloc(sizeof(Nodo));
	t->elemento = elemento;
	t->siguiente = NULL;
	return t;
}

int colaVacia(Cola cola){
	/*if (cola.frente == NULL){
		
		puts("Cola vacia");
	}*/
	return (cola.frente == NULL);
}

void insertar(Cola *cola, tipoDato entrada){
	Nodo *a;
	a = crearNodo(entrada);
	if (colaVacia(*cola)){
		cola->frente = a;
	} else{
		cola->finalito->siguiente = a;
	}
	cola ->finalito = a;
}

tipoDato frente(Cola cola){
	if (colaVacia(cola)){
		puts("Error: Cola vacia");
	}
	return (cola.frente->elemento);
}

tipoDato quitar(Cola *cola){
	tipoDato tmp;
	if (!colaVacia(*cola)){
		Nodo *a;
		a = cola->frente;
		tmp = cola->frente->elemento;
		cola->frente = cola->frente->siguiente;
		free(a);
	} else{
		puts("Error cometido al eliminar de una cola vacia");
	}
	return tmp;
}

void verCola(Cola *cola){
	while(!colaVacia(*cola)){
		printf("%d ", quitar(cola));
	}
}

void borrarCola(Cola *cola){
	for (; cola->frente != NULL;){
		Nodo *n;
		n = cola->frente;
		cola->frente=cola->frente->siguiente;
		free(n);
	}
}

void menu(){
	int opcion, dato;
	Cola cola;
	//typedef struct Cola *cola;
	//typedef struct Nodo *nodo;

	do{
		printf("\t:Menu:.\n");
		printf(" 1. Crear Cola\n");
		printf(" 2. Insertar\n");
		printf(" 3. Borrar todos los elementos de la cola\n");
		printf(" 4. Quitar un elemento de la cola\n");
		printf(" 5. Ver frente\n");
		printf(" 6. Ver si la cola esta vacia\n");
		printf(" 7. Ver cola\n");
		printf( "8. Salir\n");
		printf("Opcion: \n");
		scanf("%d", &opcion);

		switch(opcion){
			case 1:
				crearCola(&cola);
				printf("\n");
				system("pause");
			break;

			case 2:
				printf("Dame un numero: ");
				scanf("%d", &dato);
				insertar(&cola,dato);
				printf("\n");
				system("pause");
			break;

			case 3:
				borrarCola(&cola);
				printf("\n");
				system("pause");
			break;

			case 4:
				quitar(&cola);
				printf("\n");
				system("pause");
			break;

			case 5:
				printf("%d", frente(cola));
				printf("\n");
				system("pause");
			break;

			case 6:
				if (colaVacia(cola)){
					puts("Cola vacia");
				}
					printf("\n");
					system("pause");
			break;

			case 7:
				verCola(&cola);
				printf("\n");
				system("pause");
			break;

			case 8:
			break;
		}
	system("cls");
	}while(opcion!=8);
}
