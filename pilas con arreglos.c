#include <stdio.h>
#include <stdlib.h>

#define Tampila 10
typedef int tipoDato;

typedef struct{
	tipoDato listaPila[Tampila];
	int cima;
}Pila;

void crearPila(Pila *pila);
void Insetar(Pila *pila, tipoDato elemento);
tipoDato quitar(Pila *pila);
void limpiarPila(Pila * pila);
tipoDato cima(Pila pila);
int pilaVacia(Pila Pila);
int pilaLlena(Pila Pila);
void verPila(Pila pila);
void menu();

void crearPila(Pila *pila){
	pila->cima = -1;
}

void Insertar(Pila *pila, tipoDato elemento){
	if (pilaLlena(*pila)){
		puts("Desbordamiento pila");
		//exit(1);
	}
	pila->cima++;
	pila->listaPila[pila->cima] = elemento;
}

tipoDato quitar(Pila *pila){
	tipoDato tem;
	if (pilaVacia(*pila)){
		puts("Se intenta sacar un elemento en pila vacia");
		//exit(1);
	}
	tem = pila -> listaPila[pila->cima];
	pila->cima--;
	return tem;
}

tipoDato cima(Pila pila){
	if (pilaVacia(pila)){
		puts("Error de ejecucion, pila vacia");
		//exit(1);
	}
	return pila.listaPila[pila.cima];
}

void limpiarPila(Pila *pila){
	pila->cima = -1;
}

int pilaVacia(Pila pila){
	return pila.cima == -1;
}

int pilaLlena(Pila pila){
	return pila.cima == Tampila -1;
}

void verPila(Pila pila){
	if (pilaVacia(pila)){
		puts("Error de ejecucion, pila vacia");
		//exit(1);
	}
		while(!pilaVacia(pila)){
			printf("\n \t %d", cima(pila));
			quitar(&pila);
		}
}

void menu(){
	int opcion, dato;
	Pila pila;
	//crearPila(&pila);
	do{
		printf("\t:Menu:.\n");
		printf( "1. Crear lista\n");
		printf(" 2. Insertar\n");
		printf(" 3. Quitar\n");
		printf(" 4. Limpiar pila\n");
		printf(" 5. Obtener la cima\n");
		printf(" 6. Ver si la pila esta vacia\n");//No funciona
		printf(" 7. Ver si la pila esta llena\n");
		printf(" 8. Ver la pila\n");
		printf( "9. Salir\n");
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
				quitar(&pila);
				printf("\n");
				system("pause");
			break;

			case 4:
				limpiarPila(&pila);
				printf("\n");
				system("pause");
			break;

			case 5:
				cima(pila);
				printf("\n");
				system("pause");
			break;

			case 6:
				pilaVacia(pila);
				printf("\n");
				system("pause");
			break;

			case 7:
				pilaLlena(pila);
				printf("\n");
				system("pause");
			break;

			case 8:
				verPila(pila);
				printf("\n");
				system("pause");
			break;

			case 9:
			break;
		}
	system("cls");
	}while(opcion!=9);
}

int main(){
	menu();
	return 0;
}