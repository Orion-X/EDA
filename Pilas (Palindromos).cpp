#include <iostream>
#include <conio.h>
#include <stdlib.h> /* Para usar New */
#include <string.h>

/* Filosofía: El último en entrar es el primero en salir */


using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;
};


void agregarPila(Nodo *&, char); /* Prototipo */
char sacarPila(Nodo *&, char &); /* Prototipo */
void mostrarLista(Nodo *);


int main(){
	Nodo *pila = NULL;
	char dato, respuesta, inversa[50], original[50];
	int m = 0, n = 0, suma = 0;

	do{	
	cout<<"Dame una letra: "; 
	cin>>dato;
	original[m] = dato;
	m++;
	agregarPila(pila, dato);
	cout<<"\nTerminaste la palabra? ";
	cin>>respuesta;
} while (respuesta == 'n' or respuesta == 'N');
	
	cout<<"Los elementos de la pila son: ";
	mostrarLista(pila);
	cout<<"NULL";

	cout<<"\nSacando los elementos de la pila: ";

	/* Mientras no sea el final de la pila */
	while(pila != NULL){ 
		inversa[n] = sacarPila(pila, dato);
		n++;
		//cout<<"La inversa es: \n";	
		//cout<<inversa;
		
	}

	cout<<"\n";
	for (int i = 0; i < n; i++){
		cout<<inversa[i];
	}

	cout<<"\n";
	for (int i = 0; i < m; i++){
		cout<<original[i];
	}
	cout<<"\n";
	for (int i = 0; i < m; i++){
		if (original[i] == inversa[i]){
			suma++;
		}
	}
		if (suma == m){
			cout<<"Es palindromo: ";
		} else{
			cout<<"No es palindromo";	
		}

	getch();
	return 0;
}

void agregarPila(Nodo *&pila, char n){
	/* Crear el espacio de  memoria para almacenar un nodo*/	
	Nodo *nuevo_nodo = new Nodo();
	/*Cargar el valor dentro del nodo(dato)*/	
	nuevo_nodo->dato=n;
	/*Cargar el puntero pila dentro del nodo siguiente*/	
	nuevo_nodo->siguiente=pila;
	/*Asignar el nuevo nodo pila a pila*/	
	pila = nuevo_nodo;

	cout<<"\nElemento: " <<n<<" agregado a la pila correctamente"<<endl;
}

char sacarPila(Nodo *&pila, char &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
	return n;
}

void mostrarLista(Nodo *pila){
	//mientras no sea el final de la lsita
	while(pila != NULL){
		cout<<pila->dato<< " -> ";
		//avanzamos una posición en la lista
		pila=pila->siguiente;
	}
}