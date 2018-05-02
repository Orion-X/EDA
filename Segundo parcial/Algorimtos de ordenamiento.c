/**

	Algoritmos de ordenamiento:
	- Insertion	(Listo)
	- Burbuja (Listo)
	- Burbuja mejorado (Listo)
	- Selection (Listo)
	- Selection Mejorado (Listo)
	- Shell (Listo)
	- Quicksort (Listo)
	- Bucketsort
	- Busqueda Binaria (Listo)

	- A[7,5,6,3,2,1,4,8]
 */

#include <stdio.h>

void ordBurbuja(int a[]);
void ordBurbuja2(int a[]);
void ordSeleccioanr(int a[]);
void ordSeleccioanr2(int a[]);
void ordeInsersion(int a[]);
void ordShell(int a[]);
void ordQuicksort(int a[], int primero, int ultimo);
void izq(int a[], int primero, int Final);
void der(int a[], int primero, int Final);
void ordQuicksortMedio(int a[], int primero, int ultimo);
//void ordQuicksortFinal(int a[], int primero, int ultimo);
//void ordQuicksortInicio(int a[], int primero, int ultimo);
void ordBucketsort(int a[]);
float num(int num);

int main(){
	int a[8], num, i, x, y;

	for (i = 0; i < 8; i++){
		printf("Dame un numero: ");
		scanf("%d",&a[i]);
	}
	printf("Arreglo desordenado\n");
	for (i = 0; i < 8; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	//ordBurbuja(a);
	//ordSeleccioanr(a);
	//ordeInsersion(a);

	//printf("\nNuevo metodo\n");
	//ordShell(a);
	/*printf("Inicio: ");
	scanf("%d",&x);
	printf("Dame Final: ");
	scanf("%d",&y);
	ordQuicksort(a, x, y);
*/
	ordBucketsort(a);

	return 0;
}

void ordBurbuja2(int a[]){
	int interruptor = 1;
	int aux, i, j, k;

	for (i = 0; i < 8 && interruptor; i++){
		for (j = 0; j < 7; j++){
			interruptor = 0;
			if (a[j] > a[j+1]){
				interruptor = 1;
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				printf("\n");
				for (k = 0; k < 5; k++){
					printf("\t %d", a[k]);
				}
			}
		}

	}

	printf("\nArreglo ordenado: ");
	for (i = 0; i < 5; i++){
		printf("%d", a[i]);
	}
}

void ordBurbuja(int a[]){
	int aux, i, j, k;

	for (i = 0; i < 8; i++){
		for (j = 0; j < 7; j++){
			if (a[j] > a[j+1]){
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				printf("\n");
				for (k = 0; k < 8; k++){
					printf("\t %d", a[k]);
				}
			}
		}

	}

	printf("\nArreglo ordenado: ");
	for (i = 0; i < 8; i++){
		printf("%d", a[i]);
	}
}

void ordSeleccioanr(int a[]){
	int i, j, k, aux, minimo;

	for (i = 0; i < 8; i++){
		minimo = i;
		for (j = i+1; j < 8; j++){
			if (a[j]< a[minimo]){
				minimo = j;
			}
		}
			aux = a[i];
			a[i] = a[minimo];
			a[minimo] = aux;
			printf("\n");
			for (k = 0; k < 5; k++){
				printf("\t %d", a[k]);
			}
	}
		printf("\n\nArreglo ordenado: ");
		for (i = 0; i < 8; i++){
			printf("\t %d", a[i]);
		}
}

void ordSeleccioanr2(int a[]){
	int i, j, k, aux, minimo, interruptor = 1;

	for (i = 0; i < 8 ; i++){
		minimo = i;
		for (j = i+1; j < 8; j++){
			if (a[j]< a[minimo]){
				minimo = j;
			}
		}
			if (i != minimo){
				aux = a[i];
				a[i] = a[minimo];
				a[minimo] = aux;
				printf("\n");
				for (k = 0; k < 8; k++){
					printf("\t %d", a[k]);
				}
			}
	}
		printf("\n\nArreglo ordenado: ");
		for (i = 0; i < 8; i++){
			printf("\t %d", a[i]);
		}
}

void ordeInsersion(int a[]){
	int i, j, k, tmp, aux;

	for (i = 1; i < 8; i++){
		aux = a[i];
		for (j = i+1; j >= 0; j--){
			if (aux < a[j-1]){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				printf("\n");
				for (k = 0; k < 8; k++){
					printf("\t %d", a[k]);
				}
			}
		}
	}
		printf("\n\nArreglo ordenado: ");
		for (i = 0; i < 8; i++){
			printf("\t %d", a[i]);
		}
}


void ordShell(int a[]){
	int tam = 8, tmp, i, j, intervalo, k, l;
	intervalo = tam/2;
	while(intervalo > 0){
		for (i = intervalo; i < tam; i++){
			j = i - intervalo;
			while(j >= 0){
				k = j + intervalo;
				if (a[j] <= a[k]){
					j = -1;
				}
				else{
					tmp = a[j];
					a[j] = a[k];
					a[k] = tmp;
					j-= intervalo;
					printf("\n");
					for (l = 0; l < 8; l++){
						printf("\t %d", a[l]);
					}
				}
			}
		}
		intervalo /= 2;
	}

	printf("\n\nArreglo ordenado: ");
	for (i = 0; i < 8; i++){
		printf("\t %d", a[i]);
	}
}
/*
void Quicksort(int a[], int primero, int ultimo){
	int aux, i, j, l, central, pivote;
	central = (primero+ultimo)/2;
	pivote = a[central];
	i = primero;
	j = ultimo;

	do
	{
		while (a[i] < pivote) i++;//0,|1
		while (a[j] > pivote) j--;//7,6,5|4

		if (i <= j){//0<5
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			printf("\n");
			for (l = 0; l < 8; l++){
				printf("\t %d", a[l]);
			}
			i++;//1
			j--;//4
		}
	} while (i<=j);

	if (primero < j){
		Quicksort(a, primero, j);
	}

	if (i < ultimo){
		Quicksort(a, i, ultimo);
	}

	printf("\nArreglo ordenado: ");
	for (i = 0; i < 8; i++){
		printf("%d", a[i]);
	}
}*/


void ordQuicksort(int a[], int primero, int ultimo){
 int aux, i, j, l, central, pivote;
	central = (primero+ultimo)/2;
	pivote = a[central];
	i = primero;
	j = ultimo;

	do
	{
		while (a[i] < pivote) i++;//0,|1
		while (a[j] > pivote) j--;//7,6,5|4

		if (i <= j){//0<5
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			printf("\n");
			for (l = 0; l < 8; l++){
				printf("\t %d", a[l]);
			}
			i++;//1
			j--;//4
		}
	} while (i<=j);

	if (primero < j){
		izq(a, primero, j);
	}

	if (i < ultimo){
		der(a, i, ultimo);
	}

	printf("\nArreglo ordenado: ");
	for (i = 0; i < 8; i++){
		printf("%d", a[i]);
	}
}

void izq(int a[], int primero, int ultimo){
 int aux, i, j, l, central, pivote;
	central = (primero+ultimo)/2;
	pivote = a[central];
	i = primero;
	j = ultimo;

	do
	{
		while (a[i] < pivote) i++;//0,|1
		while (a[j] > pivote) j--;//7,6,5|4

		if (i <= j){//0<5
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			printf("\n");
			for (l = 0; l < 8; l++){
				printf("\t %d", a[l]);
			}
			i++;//1
			j--;//4
		}
	} while (i<=j);
	/*
	if (primero < j){
		izq(a, primero, j);
	}

	if (i < ultimo){
		der(a, i, ultimo);
	}
	*/
	printf("\nArreglo ordenado: ");
	for (i = 0; i < 8; i++){
		printf("%d", a[i]);
	}
}

void der(int a[], int primero, int ultimo){
 int aux, i, j, l, central, pivote;
	central = (primero+ultimo)/2;
	pivote = a[central];
	i = primero;
	j = ultimo;

	do
	{
		while (a[i] < pivote) i++;//0,|1
		while (a[j] > pivote) j--;//7,6,5|4

		if (i <= j){//0<5
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			printf("\n");
			for (l = 0; l < 8; l++){
				printf("\t %d", a[l]);
			}
			i++;//1
			j--;//4
		}
	} while (i<=j);

	/*if (primero < j){
		izq(a, primero, j);
	}

	if (i < ultimo){
		der(a, i, ultimo);
	}
	*/
	printf("\nArreglo ordenado: ");
	for (i = 0; i < 8; i++){
		printf("%d ", a[i]);
	}
}

float num(int num){
	do{
		num/=10;
	} while (num>10);
	return num;
}
/* 25 56 49 1 15 35 26 22 */

void ordBucketsort(int a[]){
 int i, j, aux, tmp = 0;
 int copia[8][8], b[8], c[8];

	/* Inicializar la matriz en 0's */
 for (i = 0; i < 8; i++){
 	for (j = 0; j < 8; j++){
 		copia[i][j] = 0;
 	}
 }
	/*Guarda el primer digito del numero*/
 for (i = 0; i < 8; i++){
 	b[i] = num(a[i]);
 }
 /*
 for (i = 0; i < 8; i++){
 	printf("%d ", b[i]);
 }*/


 for (i = 0; i < 8; i++){
 	j=0;
 	while(copia[b[i]][j]!=0){
 		j++;
 	}
 		copia[b[i]][j]= a[i];
 }

 printf("\n\n matriz desordenada");
 for (i = 0; i < 8; i++){
 	printf("\n\n");
 	printf("[%d]:", i);
 	for (j = 0; j < 8; j++){
 		//if (copia[i][j] != 0){
 			printf("%d ", copia[i][j]);
 		//}
 	}
 }
 	/*Ordena los elementos de la matriz por renglon*/
 	for (i = 0; i < 8; i++){
 		for (j = 0; j < 7; j++){
 			while (copia[i][j] > copia[i][j+1] && /*copia[i][j] != 0 &&*/copia[i][j+1] != 0){
 			printf("\ni: %d i+1: %d\n", copia[i][j], copia[i][j+1]);
 				aux = copia[i][j];
 				copia[i][j] = copia[i][j+1];
 				copia[i][j+1] = aux;
 				i--;
 				//j--;
 			}
		}
	}

 printf("\n\n matriz ordenada");
 for (i = 0; i < 8; i++){
 	printf("\n\n");
 	printf("[%d]:", i);
 	for (j = 0; j < 8; j++){
 		//if (copia[i][j] != 0){
 			printf("%d ", copia[i][j]);
 		//}
 	}
 }


for (i = 0; i < 8; i++){
 	for (j = 0; j < 8; j++){
 		if (copia[i][j] != 0){
 			c[tmp++] = copia[i][j];
 		}
 	}
 }
/*
 for (i = 0; i < 8; i++){
 	j=0;
 	while(copia[i][j]!=0){
 		b[i] = copia[i][j];
 		j++;
 	}

 }*/

  printf("\n\n arreglo ordenada: ");
  for (i = 0; i < 8; i++){
 	printf("%d ", c[i]);
 }

}
