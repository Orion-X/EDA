#include <stdio.h>
#include <stdlib.h>

typedef int tipoDato;

typedef struct nodo{
	tipoDato elemento;
	struct nodo *siguiente;
}Nodo;

void crearPila(Nodo **pila);
void Insertar(Nodo **pila, tipoDato elemento);
void Suprimir(Nodo **pila);
tipoDato quitar(Nodo **pila);
void verPila(Nodo *pila);
tipoDato cima(Nodo *pila);
int pilaVacia(Nodo *pila);
void limpiarPila(Nodo **pila);
void menu();

Nodo *pila;

int main(){
	
	menu();

	return 0;
}

void crearPila(Nodo **pila){
	*pila = NULL;
}

int pilaVacia(Nodo *pila){
	return pila == NULL;
	printf("Pila vacia\n");
}

void Insertar(Nodo **pila, tipoDato elemento){
	Nodo *nuevo;
	nuevo=(Nodo *)malloc(sizeof(Nodo));
	nuevo->elemento=elemento;
	nuevo->siguiente =*pila;
	(*pila)=nuevo;
}

void Suprimir(Nodo **pila){
	if (!pilaVacia(*pila)){
		Nodo *f;
		f = *pila;
		(*pila) = (*pila) -> siguiente;
		free(f);
	}
}

tipoDato cima(Nodo *pila){
	if (pilaVacia(pila)){
		puts("Error de ejecucion, pila vacia");
	}
	printf("%d\n", pila->elemento);
}

tipoDato quitar(Nodo **pila){
	tipoDato tem;
	Nodo *q;
	if (pilaVacia(*pila)){
		puts("Se intetna sacar un elemento en pila vacia");
	}
	tem = (*pila) -> elemento;
	q = *pila;
	(*pila) = (*pila) -> siguiente;
	free(q);
	return tem;
	printf("%d\n", tem);
}

void limpiarPila(Nodo **pila){
	while(!pilaVacia(*pila)){
		Suprimir(pila);
	}
}

void verPila(Nodo *pila){
	if (pilaVacia(pila)){
		printf("Pila vacia\n");
	}
	int k;
    printf("\n\t\t Pila \n");
    for(k=0;pila;pila = pila->siguiente){
        printf("%d ",pila->elemento);
        k++;
        printf("%c",(k%12 ?  ' ':'\n'));
    }
    printf("\n\n");
}

void menu(){
	int opcion, dato, dato2;
	do{
		printf("\t:Menu:.\n");
		printf(" 1. Crear Pila\n");
		printf(" 2. Insertar\n");
		printf(" 3. Suprimir\n");
		printf(" 4. Quitar\n");
		printf(" 5. Ver pila\n");
		printf(" 6. Ver la cima\n");//No funciona
		printf(" 7. Pila vacia\n");
		printf(" 8. Limpiar pila\n");
		printf( "10. Salir\n");
		printf("Opcion: \n");
		scanf("%d", &opcion);

		switch(opcion){
			case 1:
				crearPila(&pila);
				printf("\n");
				system("pause");
			break;

			case 2:
				printf("Dame un numero: ");
				scanf("%d", &dato);
				Insertar(&pila,dato);
				printf("\n");
				system("pause");
			break;

			case 3:
				Suprimir(&pila);
				printf("\n");
				system("pause");
			break;

			case 4:
				quitar(&pila);
				printf("\n");
				system("pause");
			break;

			case 5:
				verPila(pila);
				printf("\n");
				system("pause");
			break;

			case 6:
				cima(pila);
				printf("\n");
				system("pause");
			break;

			case 7:
				pilaVacia(pila);
				printf("\n");
				system("pause");
			break;

			case 8:
				limpiarPila(&pila);
				printf("\n");
				system("pause");
			break;

			case 9:
			break;
		}
	system("cls");
	}while(opcion!=9);
}