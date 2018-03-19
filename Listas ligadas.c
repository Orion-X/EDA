#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
typedef struct Elemento{
    Item dato;
    struct Elemento *siguiente;
}Nodo;


/* Prototipos */
Nodo* crearNodo(Item entrada);
Nodo* insertarPrimero(Nodo** lista, Item entrada);
void inertFinal(Nodo** lista, Item entrada);
void insertarEnMedio(Nodo** lista, Item testigo, Item entrada);
Nodo* Localizar(Nodo* lista, Item destino);
void eliminar(Nodo** lista,Item entrada);
void recorrer(Nodo* lista);
void tamano(Nodo* lista);
void listaVacia(Nodo* lista);
void menu();

Nodo *lista = NULL;

int main(){
	menu();
	getch();
	return 0;
}


Nodo* crearNodo(Item entrada){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = entrada;
    nuevo->siguiente = NULL;

    return nuevo;
}

Nodo* insertarPrimero(Nodo **lista, Item entrada){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = entrada;
    nuevo ->siguiente = *lista;
    *lista = nuevo;  
}

void inertFinal(Nodo **lista, Item entrada){
    Nodo *ultimo;
    ultimo = *lista;

    if(ultimo == NULL){
        *lista = crearNodo(entrada);
    }
    else{
        for(;ultimo->siguiente;){
            ultimo = ultimo->siguiente;
        }
            ultimo->siguiente = crearNodo(entrada);
    }
}

void insertarEnMedio(Nodo** lista, Item testigo, Item entrada){
    Nodo *nuevo, *despues;
    nuevo = crearNodo(entrada);
    if(*lista == NULL){
        *lista = nuevo;
    }
    else{
        int esta = 0;
        despues = *lista;
        while((despues != NULL) && !esta){
            if(despues->dato != testigo){
                despues =despues->siguiente;
            }
            else{
                esta = 1;
            }
        }
        if(esta){
            nuevo->siguiente = despues->siguiente;
            despues ->siguiente = nuevo;
        }
    }
}

Nodo* Localizar(Nodo* lista, Item destino){
    Nodo* indice;
    for(indice = lista;indice != NULL;indice = indice->siguiente){
        if(destino == indice->dato){
            printf("Dato encontrado: %d\n",destino);
            return indice;
        }
    }
    return NULL;
}

void eliminar(Nodo **lista, Item entrada){
    Nodo *actual, *anterior;
    int encontrado = 0;

    actual = *lista;
    anterior = NULL;

    while((actual!=NULL) && (!encontrado)){
        encontrado = (actual->dato == entrada);
        if(!encontrado){
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if(actual != NULL){
        if(actual == *lista){
            *lista = actual ->siguiente;
        }
        else{
            anterior->siguiente = actual->siguiente;
        }
        free(actual);
    }
}

void recorrer(Nodo* lista){
    int k;
    printf("\n\t\t Lista Ordenada \n");
    for(k=0;lista;lista = lista->siguiente){
        printf("%d ",lista->dato);
        k++;
        printf("%c",(k%12 ?  ' ':'\n'));
    }
    printf("\n\n");
}

void tamano(Nodo* lista){
    int k, size = 0;
    printf("\n\t\t Lista Ordenada \n");
    for(k=0;lista;lista = lista->siguiente){
  
        k++;
        size++;
    }
    printf("%d\n", size);
    printf("\n\n");
}

void listaVacia(Nodo* lista){
    if (lista == NULL){
    	printf("La lista esta vacia\n");
    }
}

void menu(){
	int opcion, dato, dato2;
	do{
		printf("\t:Menu:.\n");
		printf("1. Crear lista\n");
		printf(" 2. Insertar primero\n");
		printf(" 3. Insertar al final\n");
		printf(" 4. Insertar en medio\n");
		printf(" 5. Localizar un elemento de la lista\n");
		printf(" 6. Eliminar un elemento de la lista\n");//No funciona
		printf(" 7. Recorrer la lista\n");
		printf(" 8. Mostrar el tamano de la lista\n");
		printf(" 9. Ver si la lista esta vacia\n");
		printf( "10. Salir\n");
		printf("Opcion: \n");
		scanf("%d", &opcion);

		switch(opcion){
			case 1:
				printf("Dame un numero: ");
				scanf("%d", &dato);
				crearNodo(dato);
				printf("\n");
				system("pause");
			break;

			case 2:
				printf("Dame un numero: ");
				scanf("%d", &dato);
				insertarPrimero(&lista,dato);
				printf("\n");
				system("pause");
			break;

			case 3:
				printf("Dame un numero: ");
				scanf("%d", &dato);
				inertFinal(&lista,dato);
				printf("\n");
				system("pause");
			break;

			case 4:
				printf("Dame un numero: ");
				scanf("%d", &dato);
                printf("Dame otro numero: ");
                scanf("%d", &dato2);
				insertarEnMedio(&lista,dato, dato2);
				printf("\n");
				system("pause");
			break;

			case 5:
			printf("Dame un numero: ");
				scanf("%d", &dato);
				Localizar(lista,dato);
				printf("\n");
				system("pause");
			break;

			case 6:
				printf("Dame un numero: ");
				scanf("%d", &dato);
				eliminar(&lista,dato);
				printf("\n");
				system("pause");
			break;

			case 7:
				recorrer(lista);
				printf("\n");
				system("pause");
			break;

			case 8:
				tamano(lista);
				printf("\n");
				system("pause");
			break;

			case 9:
				listaVacia(lista);
				printf("\n");
				system("pause");
			break;
		}
	system("cls");
	}while(opcion!=10);
}