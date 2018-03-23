/**

	TODO:
	- Declarar una cadena que se usará para evaluar
	- Evaluar la cadena declarada 3 veces, es decir, ver si la cadena se repite
	  3 vece seguidas en la cadena adn.

	- Una vez hecho eso haremos lo mismo con la cadena 2; pero esta vez la 
	  compararemos 4 veces a partir de la última posición en la que se comparamos
	  la cadena1.

	- La cadena dos contiene la letra "N" y esta puede cambiarse por una "TCGA"
	  y puede escribirse al reves para compararla con la cadena adn 
	  (que es desconocida).
---------------------------------------------------------------------------------------
	- Una vez confirmado que la cadena1 se repite 3 veces y la cadena2 se 
	  repite 4 veces, entonces podemos decir que es una cadena base.

	  Cadena1: 13 caracteres.
	  Cadena2: 9 caracteres y viseversa.

	  N: T,C,G,A. Esto quiere decir que existen 16 diferentes tipos de
	  combinaciones.

	  Nota: Hacer un arreglo que contenga las letras de n para no hacer 
	  las 4 o 16 combinaciones por escrito.

	  Nota2: Si ambas se cumplen entonces es una cadena base.

	  Nota3: 5,489,613 caracteres.

	  Nota4: Crear una función que me de la posición de las n's.

	  Nota5: Extraer la información del archivo con fread y guardarla dentro de un arreglo.
 */

/**

	TODO:
	- Crear una función que me diga la cantidad de caracteres que tiene el archivo.
	- Crear una función que me guarde la información del archivo en un arreglo usando fread.
 */

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int posicion1();
int posicion2(int n);
void combinaciones(int a, int b);
void copiador();

int main(){
	/*int a, b;

	a = posicion1();
	b = posicion2(a);
	
	combinaciones(a,b);*/
	copiador();

	return 0;
}

int posicion1(){
	int i;
	char Cadena1[8] = {'T', 'T', 'N', 'C', 'G', 'G', 'A', 'N'};

	for (i = 0; i < 8; i++){
		if (Cadena1[i] == 'N'){
			return i;
		}
	}
}

int posicion2(int n){
	int k;
	char Cadena1[8] = {'T', 'T', 'N', 'C', 'G', 'G', 'A', 'N'};

	for (k = n+1; k < 8; k++){
		if (Cadena1[k] == 'N'){
			return k;
		}
	}
}

void combinaciones(int a, int b){
	int i, j, k, l, primera = 0, segunda = 0, repetisiones = 0, inicio = 0, finalito = 8,
	combinaciones = 0;
	char N[4] = {'T', 'C', 'G', 'A'};
	char Cadena1[8] = {'T', 'T', 'N', 'C', 'G', 'G', 'A', 'N'}, Copia[24], respuesta;
	char ADN[24] = {
	'T', 'T', 'T', 'C', 'G', 'G', 'A', 'T',//[0,7]
	'T', 'T', 'T', 'C', 'G', 'G', 'A', 'T',//[8,15]
	'T', 'T', 'T', 'C', 'G', 'G', 'A', 'T'};//[16,23]

	do{
		//system("cls");
		fflush(stdin);
		printf("\n");

		/*============================================================
		=            Generador de todas las combinaciones            =
		============================================================*/

		/* El primer for genera las combinaciones de la primera N */	
		for (i = 0+primera; i < 1+primera; i++){
			Cadena1[a] = N[i];
		/* Imprime las combinacones de la segunda N */
			for (j = 0+segunda; j < 1+segunda; j++){
				Cadena1[b] = N[j];
				/* Imprime toda la cadena */				
					for (k = 0; k < 8; k++){
						printf("%c", Cadena1[k]);
					}
				printf("\n");
			}
		}
		//printf("Combinacion[%i]: ", i);

		//printf("\nPrimera N es: %d\n", primera);
		printf("Segunda N es: %d\n", segunda);
		//printf("El valor de i es: %i\n", i);

		/*=====  End of Generador de todas las combinaciones  ======*/
		
		/*====================================================
		=            Clonador de cada combinación            =
		====================================================*/
		
		for (i = 0; i < 8; i++){
			Copia[i] = Cadena1[i];
		}

		printf("La copia es: ");
		printf("\n");
		for (i = 0; i < 8; i++){
			printf("%c", Copia[i]);
		}
			printf("\n");
		/*=====  End of Clonador de cada combinación  ======*/
		

		/*===================================================================
		=            Compraración del clonador con la cadena ADN            =
		===================================================================*/
		
			if (combinaciones > 0 && inicio <= 16 && finalito <= 24){
				inicio+=8;
				finalito+=8;
			}

			printf("Inicio: %d\n", inicio);
			printf("finalito: %d\n", finalito);
			printf("    Copia  |  ADN\n");

			for (l = inicio; l < finalito; l++){
				//printf("[ %c ] [ %c ] [%i]", ADN[l], Copia[l], l);
				printf("[%i]: [ %c ] ", l, ADN[l]);
				//printf("|[%i]:  [ %c ]", l, Copia[l]);
				if (Copia[l] == ADN[l]){
					repetisiones++;
					printf("Caracteres repetidos: %d\n", repetisiones);
				}
			}
			/*----------  Aumenta en 1 las veces que se repite
										y
						  recetea el contador de la comparación   ----------*/
			
			if (repetisiones == 8){
				combinaciones++;
				repetisiones = 0;
				segunda--;
			}

			printf("\nLas repeticiones son: %d\n", combinaciones);
			printf("\n");
		/*=====  End of Compraración del clonador con la cadena ADN  ======*/

		printf("Pulsa enter para seguir... \n");
		scanf("%c", &respuesta);
		segunda++;
		/* Permite ver avanzar a la siguietne n de la primera combinación */		
		if (segunda == 4){
			segunda = 0;
			primera++;
		}
		
		if (combinaciones == 3){
			printf("Es una cadena basica\n");
			exit(1);
		}
		
	} while(respuesta == '\n' && primera < 4 && segunda < 4);
	printf("\n");
	//printf("El toatal de combinaciones fueron  %d\n", combinaciones);
	//printf("%d\n", repetisiones);
}

void copiador(){
	int i, j, k, l, primera = 0, segunda = 0, repetisiones = 0, inicio = 0, finalito = 8,
	combinaciones = 0;
	char N[4] = {'T', 'C', 'G', 'A'};
	char Cadena1[8] = {'T', 'T', 'N', 'C', 'G', 'G', 'A', 'N'}, Copia[24], respuesta;
	char ADN[24] = {
	'T', 'T', 'T', 'C', 'G', 'G', 'A', 'T',//[0,7]
	'T', 'T', 'T', 'C', 'G', 'G', 'A', 'T',//[8,15]
	'T', 'T', 'T', 'C', 'G', 'G', 'A', 'T'};//[16,23]

		while (inicio <= 16 && finalito <= 24){
			//printf("Inicio: %d\n", inicio);
			//printf("finalito: %d\n", finalito);

			for (i = inicio; i < finalito; i++){
				Copia[i] = Cadena1[i];
			}
			inicio+=8;
			finalito+=8;
		}
}