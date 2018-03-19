/**

	TODO:
	- Hacer una cola con arreglos para 10 personas usando la funcion random(Para definir
	el cupo de personas a atender).
	- Leer la cola.
	- Calcular el tiempo sumando los valores de la cola.
	- Calcular la longutid recorriendo la cola con un contador.

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
	int cola[100], n, i, numero, tiempo = 0, longutid = 0;
	srand(time(NULL));
	n = 1 + rand() % ( (10 + 1) - 1 );
	printf("%i\n", n);
	for (i = 0; i < n; i++){
		printf("Dame un numero\n");
		scanf("%d", &numero);
		cola[i] = numero;
	}

	for (i = n-1; i >= 0; i--){
		printf("%d ", cola[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++){
		if (cola[i] == -1){
			printf("La longitud es de: %d unidades\n", longutid);
			printf("El tiempo invertido fue de: %d m\n", tiempo);
			system("pause");
			exit(1);
		} else{
			longutid++;
			tiempo+= cola[i];
		}
	}

	return 0;
}