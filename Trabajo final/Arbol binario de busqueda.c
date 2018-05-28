#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct nodo{
	int dato;
	struct nodo *der;
	struct nodo *izq;
	struct nodo *padre;
}Nodo;

Nodo *crearNodo(int, Nodo *);
void insertar(Nodo **, int, Nodo *);
void mostrar(Nodo *, int);
bool busqueda(Nodo *, int);
void Eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo*);
void remplazo(Nodo *, Nodo *);
void destruir(Nodo *);
void menu();


Nodo *arbol = NULL;
int main(){
	menu();

	getch();
	return 0;
}

void menu(){
	int dato, opcion, cont = 0;
	do{
		printf("\t MENU\n");
		printf("1. Insertar un nodo\n");
		printf("2. Ver arbol\n");
		printf("3. Buscar un elemento\n");
		printf("4. Eliminar un nodo\n");
		printf("5. Salir\n");
		printf("Opcion:	");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("Dame un numero\n");
				scanf("%d", &dato);
				insertar(&arbol, dato, NULL);
				printf("\n");
				system("pause");
			break;

			case 2:
				mostrar(arbol,cont);
				printf("\n");
				system("pause");
			break;

			case 3:
				printf("Dame un numero\n");
				scanf("%d", &dato);
				if (busqueda(arbol,dato) == true){
					printf("\nElemento: %d a sido encontrado en el arbol", dato);
				} else{
					printf("\nElemento no encontrado\n");
				}
				printf("\n");
				system("pause");
			break;

			case 4:
				printf("Dame un numero\n");
				scanf("%d", &dato);
				Eliminar(arbol,dato);
				printf("\n");
				system("pause");
			break;
		}
		system("cls");
	} while(opcion != 5);
}


Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevoNodo;
	nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
	nuevoNodo -> dato = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	nuevoNodo-> padre = padre;
	return nuevoNodo;
}

void insertar(Nodo **arbol, int n, Nodo *padre){
	if (*arbol == NULL){
		Nodo *nuevoNodo = crearNodo(n, padre);
		*arbol = nuevoNodo;
	} else{
		int raiz = (*arbol)->dato;
		if (n < raiz){
			insertar(&(*arbol)->izq,n,(*arbol));
		} else{
			if (n > raiz){
				insertar(&(*arbol)->der,n,(*arbol));
			}
		}
	}
}

void mostrar(Nodo *arbol, int cont){
	int i;
	if (arbol == NULL){
		return;
	} else{
		mostrar(arbol->der, cont+1);
		for (i = 0; i < cont; i++){
			printf("	");
		}
		printf("%d\n", arbol->dato);
		mostrar(arbol->izq, cont+1);
	}
}

bool busqueda(Nodo *arbol, int n){
	if (arbol == NULL){
		return false;
	} else if (arbol->dato == n){
			return true;
	} else if (n < arbol->dato){
		return busqueda(arbol->izq, n);
	} else{
		return busqueda(arbol->der, n);
	}
}

//Eliminar un nodo
void Eliminar(Nodo *arbol, int n){
	if (arbol == NULL){
		return;
	} else if(n < arbol->dato){
		Eliminar(arbol->izq, n);
	} else if(n > arbol->dato){
		Eliminar(arbol->der, n);
	} else{
		eliminarNodo(arbol);
	}
}
//Encontrar el mínimo a la izquierda
Nodo *minimo(Nodo *arbol){
	if (arbol == NULL){
		return NULL;
	}
	if (arbol->izq){
		return minimo(arbol->izq);
	} else{
		return arbol;
	}
}
//Remplazar dos nodos
void remplazo(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		} else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}

//Elimina un nodo
void destruir(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;

	free(nodo);
}
//Elimina el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	//Eliminar un nodo que tiene dos hijos
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	} else if(nodoEliminar->izq){
		//Eliminar un nodo con un hijo
		remplazo(nodoEliminar, nodoEliminar->izq);
		destruir(nodoEliminar);
	} else if(nodoEliminar->der){
		//Eliminar un nodo con un hijo
		remplazo(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
	} else{
		//Eliminar una hoja
		remplazo(nodoEliminar, NULL);
		destruir(nodoEliminar);
	}
}
