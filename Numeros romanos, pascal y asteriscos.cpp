/* 	Práctica #1

Hacer un programa que me cree una piramide de n estrellas, cinvierta numeros romanos
 a decimales y haga el triangulo de pascal */

#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void pascal();
void roma();
void asteriscos();

int main(){
	roma();

	//pascal();
	cout<<"\n";
	//asteriscos();

	return 0;
}
void asteriscos(){
	int asteriscos[100];
	int n;
	int x;

	cout<<"Cuantos niveles deseas tener: ";
	cin>>n;
	x =0;

	for (int i = 1; i <= n; i++){
		//Construir triangulo de pascal
		for (int j = x; j >= 0; j--){
			if (j == x or j == 0){
				asteriscos[j] = 1;
			} else{
				//llenar el centro
				asteriscos[j]+= asteriscos[j-1];
			}
		}
		x++;
		//salto de linea
		cout<<"\n";
		//imprimir el triangulo
		for (int j = 1; j <= n-i; j++){
			//esoacio del costado
			cout<<" ";
		}
		for (int j = 0; j < x; j++){
			cout<<" "<<"*";
		}
	}
}
void pascal(){
	int piramide[100];
	int n;
	int x;

	cout<<"Cuantos niveles deseas tener: ";
	cin>>n;
	x =0;

	for (int i = 1; i <= n; i++){
		//Construir triangulo de pascal
		for (int j = x; j >= 0; j--){
			if (j == x or j == 0){
				piramide[j] = 1;
			} else{
				//llenar el centro
				piramide[j]+= piramide[j-1];
			}
		}
		x++;
		//salto de linea
		cout<<"\n";
		//imprimir el triangulo
		for (int j = 1; j <= n-i; j++){
			//esoacio del costado
			cout<<" ";
		}
		for (int j = 0; j < x; j++){
			cout<<" "<<piramide[j];
		}
	}
}
/* numeros romanos a la derecha suman, a la izquierda restan */

//Los numeros se restan solo si el n-1 < n-ésimo término.
void roma(){
	char romanos[100];
	int valor[100];
	int i, n, suma = 0;
	
	cout<<"escribe el numero romano: ";
	cin>>romanos;

	n=strlen(romanos);

	for (i = 0; i < n; i++){
		if (romanos[i] == 'M' || romanos[i] == 'm'){
			valor[i]=1000;
		} /*else*/ 
		if(romanos[i] == 'D' || romanos[i] == 'd'){
			valor[i]=500;
		} /*else*/ 
		if (romanos[i] == 'C' || romanos[i] == 'c'){
			valor[i]=100;
		} /*else*/ 
		if (romanos[i] == 'L' || romanos[i] == 'l'){
			valor[i]=50;
		} /*else*/ 
		if (romanos[i] == 'X' || romanos[i] == 'x'){
			valor[i]=10;
		} /*else*/ 
		if (romanos[i] == 'V' || romanos[i] == 'v'){
			valor[i]=5;
		} /*else*/ 
		if (romanos[i] == 'I' || romanos[i] == 'i'){
			valor[i]=1;
		}
		//CDXCVI, MLC

	}
	//cout<<"Tu numero romano es: ";
	for (i = 0; i < n; i++){
		//cout<<"["<<i<<"]: "<<valor[i]<<", ";
		
		if (valor[i]==valor[i+1] && valor[i]==valor[i+2] && valor[i]==valor[i+3]){
            cout<<"No puedes poner mas de 3 veces seguidas el mismo valor"<<endl;
            break;
        }
        if(i==n-1){
			suma+=valor[i];
		}
        else if (valor[i]>=valor[i+1]){
            suma+=valor[i];
        }
        else if (valor[i]<=valor[i+1]){
            suma-=valor[i];
        }
    }
    	cout<<"El numero en decimal es: "<<suma<<endl;
	}
	/*cout<<"\n";
	/*if (suma < 0){
			suma*= -1;
			cout<<"El numero en decimal es: "<<suma<<endl;
		} else{
			cout<<"El numero en decimal es: "<<suma<<endl;
			}
	cout<<"El numero en decimal es: "<<suma<<endl;*/
//}