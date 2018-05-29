#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define m 5

typedef struct pagina{
	int claves[m];
	struct pagina *ramas[m];
	int cuenta;
}Pagina;

Pagina *raiz = NULL;

int nodoLLeno(Pagina *actual);
int nodoSemiVacio(Pagina *actual);
void escribeNodo(Pagina *actual);
void dividirNodo(Pagina *actual, int c1, Pagina *rd, int k, int *mediana, Pagina **nuevo);
void crearArbol(Pagina **raiz);
Pagina *buscar(Pagina *actual, int c1, int *k);
int buscarNodo(Pagina *actual, int c1, int *k);
void insertar(Pagina **raiz, int c1);
void meterHoja(Pagina *actual, int c1, Pagina *rd, int k);
void eliminar(Pagina **raiz, int c1);
void quitar(Pagina *actual, int K);
void sucesor(Pagina *actual, int k);
void restablecer(Pagina *actual, int k);
void moverDerecha(Pagina *actual, int K);
void moverIzquierda(Pagina *actual, int K);
void combina(Pagina *actual, int K);
void listarCreciente(Pagina *actual);
void eliminarRegistro(Pagina *actual, int c1, int *encontrado);
void empujar(Pagina *actual, int c1, int *subeArriba, int *mediana, Pagina **nuevo);
void annadeNclaves(Pagina ** actual, int n);
void menu();

int main(){

	menu();
	getch();

	return 0;
}

int nodoLLeno(Pagina *actual){
	return (actual->cuenta == m-1);
}

int nodoSemiVacio(Pagina *actual){
	return (actual->cuenta < m/2);
}

void escribeNodo(Pagina *actual){
	int k;
	printf("\nNodo: ");
	for (k = 1; k <= actual->cuenta; k++){
		printf(" %d ", actual->claves[k]);
		printf("\n");
	}
}
void crearArbol(Pagina **raiz){
	*raiz = NULL;
}

int buscarNodo(Pagina *actual, int c1, int *k){
	int encontrado;
	if(c1 < actual->claves[1]){
		encontrado = 0;
		*k = 0;
	} else{
		*k = actual->cuenta;
		while((c1<actual->claves[*k]) && (*k > 1)){
			(*k)--;
		}
		encontrado = (c1 == actual->claves[*k]);
	}
	return encontrado;
}

Pagina *buscar(Pagina *actual, int c1, int * indice){
	if(actual == NULL){
		return NULL;
	} else{
		int esta;
		esta = buscarNodo(actual, c1, indice);
		if(esta){
			return actual;
		} else{
			return buscar(actual->ramas[*indice], c1, indice);
		}
	}
}

void empujar(Pagina *actual, int c1, int *subeArriba, int *mediana, Pagina **nuevo){
	int k;
	if(actual == NULL){
		*subeArriba = 1;
		*mediana = c1;
		*nuevo = NULL;
	} else{
		int esta;
		esta = buscarNodo(actual, c1, &k);
		if(esta){
			puts("\nClave duplicada");
			*subeArriba = 0;
			return;
		}
		empujar(actual->ramas[k], c1, subeArriba, mediana, nuevo);

		if(*subeArriba){
			if(nodoLLeno(actual)){
				dividirNodo(actual, *mediana, *nuevo, k, mediana, nuevo);
			} else{
				*subeArriba = 0;
				meterHoja(actual, *mediana, *nuevo, k);
			}
		}
	}
}

void insertar(Pagina **raiz, int c1){
	int subeArriba;
	int mediana;
	Pagina *p, *nd;

	empujar(*raiz, c1, &subeArriba, &mediana, &nd);

	if (subeArriba){
		p = (Pagina *)malloc(sizeof(Pagina));
		p->cuenta = 1;
		p->claves[1] = mediana;
		p->ramas[0] = *raiz;
		p->ramas[1] = nd;
		*raiz = p;
	}
}

void meterHoja(Pagina *actual, int c1, Pagina *rd, int k){
	int i;
	for (i = actual->cuenta; i >= k+1; i--){
		actual->claves[i+1] = actual->claves[i];
		actual->ramas[i+1] = actual->ramas[i];
	}
	actual->claves[i+1] = c1;
	actual->ramas[i+1] = rd;
	actual->cuenta++;
}

void dividirNodo(Pagina *actual, int c1, Pagina *rd, int k, int *mediana, Pagina **nuevo){
	int i, posMdna;
	posMdna = (k<=m/2)? m/2: m/2+1;
	(*nuevo) = (Pagina*) malloc(sizeof(Pagina));
	for (i = posMdna+1; i < m; i++){
		(*nuevo)->claves[i-posMdna] = actual->claves[i];
		(*nuevo)->ramas[i-posMdna] = actual-> ramas[i];
	}
	(*nuevo)->cuenta = (m-1) - posMdna;
	actual -> cuenta = posMdna;
	if(k<=m/2){
		meterHoja(actual,c1,rd,k);
	} else{
		meterHoja(*nuevo,c1,rd,k-posMdna);
	}
	*mediana = actual->claves[actual->cuenta];
	(*nuevo)->ramas[0] = actual->ramas[actual->cuenta];
	actual->cuenta--;
}


void eliminar(Pagina **raiz, int c1){
	int encontrado;
	eliminarRegistro(*raiz, c1, &encontrado);
	if(encontrado){
		printf("Clave %d eliminada\n", c1);
		if((*raiz)-> cuenta == 0){
			Pagina *p = *raiz;
			*raiz = (*raiz) ->ramas[0];
			free(p);
		}
	} else{
		puts("La clave no se encuentre en el arbol\n");
	}
}

void eliminarRegistro(Pagina *actual, int c1, int *encontrado){
	int k;
	if(actual != NULL){
		*encontrado = buscarNodo(actual,c1,&k);
		if(*encontrado){
			if(actual->ramas[k-1] == NULL){
				quitar(actual,k);
			} else{
				sucesor(actual,k);
				eliminarRegistro(actual->ramas[k], actual->claves[k], encontrado);
			}
		}else{
			eliminarRegistro(actual->ramas[k],c1, encontrado);
		}
	if(actual->ramas[k] != NULL){
		if(actual->ramas[k]->cuenta < m/2){
			restablecer(actual,k);
		}
	}
 } else{
 	*encontrado = 0;
 }
}

void quitar(Pagina *actual, int k){
	int j;
	for (j = k+1; j <= actual->cuenta; j++){
		actual->claves[j-1] = actual->claves[j];
		actual->ramas[j-1] = actual->ramas[j];
	}
	actual->cuenta--;
}

void sucesor(Pagina *actual, int k){
	Pagina *q;
	q = actual->ramas[k];
	while(q->ramas[0] != NULL){
		q = q->ramas[0];
	}
	actual->claves[k] = q->claves[1];
}

void restablecer(Pagina *actual, int k){
	if(k > 0){
		if(actual->ramas[k-1]->cuenta > m/2){
			moverDerecha(actual, k);
		} else{
			combina(actual,k);
		}
	} else{
		if(actual->ramas[1]->cuenta > m/2){
			moverIzquierda(actual, 1);
		} else{
			combina(actual, 1);
		}
	}
}

void moverDerecha(Pagina *actual, int k){
	int j;
	Pagina *nodProblema = actual->ramas[k];
	Pagina *nodoIzqdo = actual->ramas[k-1];
	for (j = nodProblema->cuenta; j >= 1; j--){
		nodProblema->claves[j-1] = nodProblema->claves[j];
		nodProblema->ramas[j-1] = nodProblema->ramas[j];
	}
	nodProblema->cuenta++;
	nodProblema->ramas[1] = nodProblema->ramas[0];
	nodProblema->claves[1] = actual->claves[k];
	actual->claves[k] = nodoIzqdo->claves[nodoIzqdo->cuenta];
	nodProblema->ramas[0] = nodoIzqdo->ramas[nodoIzqdo->cuenta];
	nodoIzqdo->cuenta--;
}

void moverIzquierda(Pagina *actual, int k){
	int j;
	Pagina *nodProblema = actual->ramas[k-1];
	Pagina *nodoDrcho = actual->ramas[k];

	nodProblema->cuenta++;
	nodProblema->claves[nodProblema->cuenta] = actual->claves[k];
	nodProblema->ramas[nodProblema->cuenta] = nodoDrcho->ramas[0];

	actual->claves[k] = nodoDrcho->claves[1];
	nodoDrcho->ramas[1] = nodoDrcho->ramas[0];
	nodoDrcho->cuenta--;

	for (j = 1; j <= nodoDrcho->cuenta; j++){
		nodoDrcho->claves[j] = nodoDrcho->claves[j+1];
		nodoDrcho->ramas[j] = nodoDrcho->ramas[j+1];
	}
}

void combina(Pagina *actual, int k){
	int j;
	Pagina *nodoIzqdo, *q;

	q = actual->ramas[k];
	nodoIzqdo = actual->ramas[k-1];

	nodoIzqdo->cuenta++;
	nodoIzqdo->claves[nodoIzqdo->cuenta] = actual->claves[k];
	nodoIzqdo->ramas[nodoIzqdo->cuenta] = q->ramas[0];

	for (j = 1; j <= q->cuenta; j++){
		nodoIzqdo->cuenta++;
		nodoIzqdo->claves[nodoIzqdo->cuenta] = q->claves[j];
		nodoIzqdo->ramas[nodoIzqdo->cuenta] = q->ramas[j];
	}

	for (j = k; j <= actual->cuenta-1; j++){
		actual->claves[j] = actual->claves[j+1];
		actual->ramas[j] = actual->ramas[j+1];
	}
	actual->cuenta--;
	free(q);
}

void listarCreciente(Pagina *actual){
	if(actual != NULL){
		int j;
		listarCreciente(actual->ramas[0]);
		for (j = 1; j <= actual->cuenta; j++){
			printf("%d\t", actual->claves[j]);
			listarCreciente(actual->ramas[j]);
		}
	}
}

void annadeNclaves(Pagina ** actual, int n){
	int k;
	for (k = 1; k <= n; k++){
		int c1;
		printf("Dame un numero\n");
		scanf("%d", &c1);
		insertar(&raiz, c1);
		printf("%d", c1);
	}
}

void menu(){
	int dato, opcion, posicion;
	Pagina *p;
	do{
		printf("\t MENU\n");
		printf("1. Insertar un nodo\n");//
		printf("2. Ver arbol\n");//
		printf("3. Buscar un elemento\n");
		printf("4. Eliminar un nodo\n");//
		printf("5. Salir\n");
		printf("Opcion:	");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("Dame un numero\n");
				scanf("%d", &dato);
				annadeNclaves(&raiz, dato);
				printf("\n");
				system("pause");
			break;

			case 2:
				listarCreciente(raiz);
				printf("\n");
				system("pause");
			break;

			case 3:
				printf("Dame un numero\n");
				scanf("%d", &dato);

				p = buscar(raiz, dato, &posicion);
				if(p != NULL){
					printf("Clave encontrada dentro del nodo :");
					escribeNodo(p);
					printf("\t en posicion %d \n", posicion);
				} else{
					puts("Clave no encontrada en el arbol");
				}

				printf("\n");
				system("pause");
			break;

			case 4:
				printf("Dame un numero\n");
				scanf("%d", &dato);
				eliminar(&raiz,dato);
				printf("\n");
				system("pause");
			break;
		}
		system("cls");
	} while(opcion != 5);
}
