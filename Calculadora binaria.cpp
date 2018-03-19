/* Tarea #1 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

using namespace std;

void decimalBinario();
void binarioDecimal();
void complementoEEI754();
void menu();

int main(){

	menu();

	system("pause");
	return 0;
}

void decimalBinario(){
	int n1, n2, binario1[100], binario2[100],Suma[100], acarreo = 0,sumaDecimal = 0;
	/*=====================================
	=            Primer numero            =
	=====================================*/
	
	cout<<"Dame un numero: ";
	cin>>n1;
	sumaDecimal+=n1;

	for (int i = 7; i >= 0; i--){
	binario1[i] = n1%2;
	n1/=2;
	}
	cout<<"El numero en binario es:\n";

	for (int i = 0; i < 8; i++){
		cout<<binario1[i];
	}
	cout<<"\n";
	
		/*=====  End of Primer numero  ======*/
	/*======================================
	=            Segundo numero            =
	======================================*/

	cout<<"Dame otro numero: ";
	cin>>n2;
	sumaDecimal+=n2;
	for (int i = 7; i >= 0; i--){
		binario2[i] = n2%2;
		n2/=2;
	}
	cout<<"El numero en binario es:\n";

	for (int i = 0; i < 8; i++){
		cout<<binario2[i];
	}

	/*=====  End of Segundo numero  ======*/
	cout<<"\n";
	/*===============================================
	=            Suma binaria con 8 bits            =
	===============================================*/

	for (int i = 7; i >= 0; i--){
		
		if (binario1[i] == 0 && binario2[i] == 0 && acarreo == 0){
			Suma[i] = 0;
		}

		else  if(binario1[i] == 1 && binario2[i] == 0 && acarreo == 0){
			Suma[i] = 1;
		}

		else  if(binario1[i] == 1 && binario2[i] == 1 && acarreo == 0){
			Suma[i] = 0;
			acarreo = 1;
		}

		else  if(binario1[i] == 0 && binario2[i] == 1 && acarreo == 0){
			Suma[i] = 1;
		}

		else  if(binario1[i] == 0 && binario2[i] == 0 && acarreo == 1){
			Suma[i] = 1;
			acarreo = 0;
		}

		else  if(binario1[i] == 1 && binario2[i] == 0 && acarreo == 1){
			Suma[i] = 0;
			acarreo = 1;
		}

		else  if(binario1[i] == 1 && binario2[i] == 1 && acarreo == 1){
			Suma[i] = 1;
			acarreo = 1;
		}

		else if(binario1[i] == 0 && binario2[i] == 1 && acarreo == 1){
			Suma[i] = 0;
			acarreo = 1;
		}	
		}

	cout<<"La suma en binario es:\n";
	cout<<"\n";
	for (int i = 0; i < 8; i++){
	cout<<Suma[i];
	}
	cout<<"\n";
	/*=====  End of Suma binaria con 8 bits  ======*/

	cout<<"La suma es: "<<sumaDecimal<<endl;

   //	system("pause");
	getch();
	system("cls");
	
}

void binarioDecimal(){
	int n1, binario1[100], decimal = 0;
	char respuesta;
	
	cout<<"Dame un numero: ";
	cin>>n1;

	for (int i = 0; i < 8; i++){
		binario1[i] = n1%2;
		n1/=2;
	}
	cout<<"El numero en binario es: ";

	for (int i = 7; i >= 0; i--){
		cout<<binario1[i];
	}
	cout<<"\n";

	for (int i = 0; i < 8; i++){
		decimal += binario1[i] * pow(2,i);
		//cout<<"La suma es: "<<decimal<<endl;
	}
	cout<<"\n";

	cout<<"Tu numero es: "<<decimal<<endl;

	/*cout<<"Quieres poner otro numero (S/N-s/n): ";
	cin>>respuesta;*/
	//decimal = 0;
	
	getch();
	system("cls");
}

void complementoEEI754(){
	float numero, decimal, corte = 0, enteros = 0;
 	int entero, binario[100], signo[1], decimales = 0, binarioDecimal[100];
 	int mantiza = 127, mantisa[100], complemento = 0, recorrido = 1, parte = 0;
 	int cono = 7;

	cout<<"Dame un numero: ";
	cin>>numero;

	entero = (int)numero;
	decimal = numero - entero; 

	/*=============================
	=            Signo            = Hecho
	=============================*/
	
	if (entero < 0){
		signo[0] = 1;
		cout<<"Numero entero: "<<entero<<endl;
		entero*=-1;
		decimal*=-1;
	} else{
		signo[0] = 0;
		cout<<"Numero entero: "<<entero<<endl;
	}
	cout<<"Numero decimal: "<<decimal<<endl; 
	cout<<"Signo: ";
	for (int i = 0; i < 1; i++){
		cout<<signo[i]<<endl;
	}

	/*=====  End of Signo  ======*/

	/*============================================================
	=            Conversión de parte entera a binaria            =Hecho
	============================================================*/
	
	for (int i = 7; i >= 0; i--){
		binario[i] = entero%2;
		entero/=2;
	}

	cout<<"Numero en binario: ";
	for (int i = 0; i < 8; i++){
		cout<<binario[i];
	}

	cout<<".";
	
	/*=====  End of Conversión de parte entera a binaria  ======*/
	
	/*=============================================================
	=            Conversión de parte decimal a binaria            =
	=============================================================*/

	while(decimal != 0 and decimales != 8){
		binarioDecimal[decimales] = decimal*2;
		decimal*=2;

		entero = (int)decimal;
		decimal -= entero;
		decimales++;

	}
	for (int i = 0; i < decimales; i++){
		cout<<binarioDecimal[i];
	}
	cout<<"\n";
	/*=====  End of Conversión de parte decimal a binaria  ======*/

	/*===============================
	=       Area del expoenente     =
	===============================*/
	for (int i = 0; i < 8; i++){
		//cout<<binario[i];
		if (binario[i] == 0){
			recorrido++;
		} else if (binario[i] == 1){
			break;
		}
	}
	recorrido -= 8;
	recorrido*=-1;
	mantiza += recorrido;
	//Mantiza en decimal
	cout<<"Mantiza: "<<mantiza<<endl;
	
	for (int i = 7; i >= 0; i--){
		mantisa[i] = mantiza%2;
		mantiza/=2;
	}

	cout<<"Area del exponente: ";
	for (int i = 0; i < 8; i++){
		cout<<mantisa[i];
	}

	/*=====  End of Area del expoenente  ======*/
	cout<<"\n";

	cout<<"Mantiza: ";
	for (int i = 1; i < 8; i++){
		cout<<binario[i];
	}

	for (int i = 0; i < decimales; i++){
		cout<<binarioDecimal[i];
	}
	
	complemento = 23-(8+decimales);
	for (int i = 0; i < complemento; i++){
		cout<<"0";
	}

	cout<<"\n";

	cout<<"El numero en formato IEEE 354 es: ";

	for (int i = 0; i < 1; i++){
		cout<<signo[i];
	}
	cout<<" ";

	for (int i = 0; i < 8; i++){
		cout<<mantisa[i];
	}
	cout<<" ";
	//mantiza1
	for (int i = 1; i < 8; i++){
		cout<<binario[i];
	}
	///Mantiza2
	for (int i = 0; i < decimales; i++){
		cout<<binarioDecimal[i];
	}
	
	for (int i = 0; i < complemento; i++){
		cout<<"0";
	}
	cout<<"0";
	
	cout<<"\n";
	cout<<"Recorrido: "<<recorrido<<endl;
	//cout<<"Mantiza: "<<mantiza<<endl;
	

	cout<<"\nConversion de IEEE 754 a Decimal"<<endl;

	for (int i = 0; i < 8; i++){
		parte += mantisa[i] * pow(2,cono);
		cono--;
	}
		cout<<"\n";
		cout<<"La Mantiza en decimal es: "<<parte<<endl;
		parte-=127;
		cout<<"El recorrido fue de: "<<parte<<endl;

		cono = 0;
		int l = 7;
		while(cono < 8 and l >= 0){
			enteros += binario[l] * pow(2,cono);
			cono++;
			l--;
		}
			//cout<<"El numero binario en decimal es: "<<enteros<<".";
		
			for (int i = 0; i < decimales; i++){
				corte += binarioDecimal[i] * pow(0.5,i+1);
			}
			enteros+=corte;
			for (int i = 0; i < 1; i++){
				if (signo[i] == 1){
					enteros*=-1;
				}
			}
				cout<<"El numero es: "<<enteros<<endl;
		getch();
		system("cls");
}

void menu(){
	int opcion;
	system("cls");
	while(opcion != 4){
	cout<<"--------MENU--------"<<endl;
	cout<<"1. Conversion de decimal a binario y al reves"<<endl;
	cout<<"2. Suma binaria"<<endl;
	cout<<"3. Conversion de decimal a formate IEEE 754 de 32 bits"<<endl;
	cout<<"4. Salir"<<endl;

	cout<<"Elige una opcion: ";
	cin>>opcion;

		switch(opcion){
		case 1:
			binarioDecimal();
		break;

		case 2:
			decimalBinario();
		break;

		case 3:
			complementoEEI754();
		break;

		case 4:

		break;

	}
	}
}