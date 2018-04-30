#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Binaria(int a[], int inicio, int final);


int main(){
	int numero, i, j, a[10];
	char respuesta;
	//srand(time(NULL));
	for ( i = 0; i < 9; ++i){
		//numero = 1 + rand() % ((10+1) - 1);
		a[i] = i;
	}

	

	do{
		for ( i = 0; i < 9; ++i){
			printf("%d ", a[i]);
		}
		Binaria(a, 0, 8);
		printf("Deseas continuar\n");
		scanf("%c", &respuesta);
		system("pause");
		system("cls");
	} while (respuesta != 's');

	return 0;
}

void Binaria(int a[], int inicio, int final){
	int i, j, central, num, cont = 0;
	i = inicio; 
	j = final;
	central = (i+j)/2;
	printf("\ncentral: %d\n", central);
	printf("j: %d\n", j);
	printf("i: %d\n", i);
	printf("Contador: %d\n", cont);
	printf("\nDame un numero\n");
	scanf("%d", &num);	
	do{
		if (a[central] > num){
			j = central;
			printf("j: %d\n", j);
			printf("i: %d\n", i);
		} 
		if(a[central] < num){
			i = central+1;
			printf("j: %d\n", j);
			printf("i: %d\n", i);
		}
		central = (i+j)/2;
		printf("central: %d\n", central);
		cont++;
		printf("Contador: %d\n\n", cont);

		if (a[central] == num){
			printf("Numero encontrado\n");
			break;
		}
		if (i==j){
			
		}
	} while (a[central] != num && i!=j);
		//printf("Contador: %d\n", cont);
}