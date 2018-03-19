/**
	Tarea #2
	TODO:
	- Mantener un saldo
	- Guardar movimientos de cuenta
	- Mostrar estado de la cuenta
	- Hacer un cajero para 2 o n usuarios.
	- Terminar la fecha por movimientos de la cuenta.
	- Hacer menu (registro de cuentas, lectura y edición).

 */


#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

struct Fecha{
	unsigned dia, mes, anio;
};

struct Tiempo{
	unsigned hh,mm,ss;
};

struct registro_operaciones{
	long cuenta;
	double cantidad = 1000;
	double Deposito = 0;
	double Retiro = 0;
	int tipo_operacion;
	struct Fecha f;
	struct Tiempo t;
};

void lectura();

struct registro_operaciones entrada();
struct registro_operaciones nuevo();

int main(){
	int n = 2, cuentaNueva;
	struct registro_operaciones CUENTAS[n];
	
	for (int i = 0; i < n; i++){
		cout<<"\tBienvenido usuario ["<<i<<"]"<<endl;
		cout<<"Desea crear una cuenta nueva (1) o desea agregar otra cuenta (0): ";
		cin>>cuentaNueva;
		if (cuentaNueva == 1){
			CUENTAS[i] = entrada();
		}
			if(cuentaNueva == 0){
				CUENTAS[i] = nuevo();
		}
		
		

		cout<<"\n";
		cout<<"\tEl estado de tu cuenta es \n";
		cout<<"Operacion realizada: "<<CUENTAS[i].tipo_operacion<<endl;
		cout<<"Tu numero de cuenta es: "<<CUENTAS[i].cuenta<<endl;
		cout<<"Tu cantidad es: "<<CUENTAS[i].cantidad<<endl;
		if (CUENTAS[i].Deposito > 0){
			cout<<"Tu deposito fue de :"<<CUENTAS[i].Deposito<<endl;
		}
		if (CUENTAS[i].Retiro > 0){
			cout<<"Tu retiro fue de :"<<CUENTAS[i].Retiro<<endl;
			
		}
		getch();
		system("cls");
	}

	for (int i = 0; i < n; i++){
		cout<<"\n";
		cout<<"\tEl estado de tu cuentas es \n";
		cout<<"Operacion realizada: "<<CUENTAS[i].tipo_operacion<<endl;
		cout<<"Tu numero de cuenta es: "<<CUENTAS[i].cuenta<<endl;
		cout<<"Tu cantidad es: "<<CUENTAS[i].cantidad<<endl;
		if (CUENTAS[i].Deposito > 0){
			cout<<"Tu deposito fue de :"<<CUENTAS[i].Deposito<<endl;
		}
		if (CUENTAS[i].Retiro > 0){
			cout<<"Tu retiro fue de :"<<CUENTAS[i].Retiro<<endl;
			system("cls");
		}
	}

	cout<<"\nLos datos de su archivo son: "<<endl;
	system("pause");
	lectura();
	system("pause");

	return 0;
}

void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("Cuentas.txt", ios::in);

	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}

struct registro_operaciones entrada(){
	struct Tiempo t;
	struct Fecha f;
	struct registro_operaciones una;
	char respueta;
	int mov = 0, estados[mov];
	ofstream archivo;
	archivo.open("Cuentas.txt",ios::out);
	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	/* fecha/hora actual basado en el sistema actual */
	time_t now = time(0);

	/* Objeto de una estructura tm con fecha/hora local */
	tm * time = localtime(&now);

	vector<string> dia_semana;
	dia_semana.push_back("Domingo");
	dia_semana.push_back("Lunes");
	dia_semana.push_back("Martes");
	dia_semana.push_back("Miercoles");
	dia_semana.push_back("Jueves");
	dia_semana.push_back("Viernes");
	dia_semana.push_back("Sabado");

	vector<string> mes;
	mes.push_back("Enero");
	mes.push_back("Febrero");
	mes.push_back("Marzo");
	mes.push_back("Abril");
	mes.push_back("Mayo");
	mes.push_back("Junio");
	mes.push_back("Julio");
	mes.push_back("Agosto");
	mes.push_back("Septiembre");
	mes.push_back("Octubre");
	mes.push_back("Noviembre");
	mes.push_back("Diciembre");

	int year = 1900 + time->tm_year;	
	
	cout<<"Dame un numero de cuenta: ";
	cin>>una.cuenta;
	do
		{
	cout<<"====== Menu=====\n";
	cout<<"1. Deposito"<<endl;
	cout<<"2.Retiro"<<endl;
	cout<<"3. Estado de cuenta"<<endl;

	cout<<"Dame el tipo de operacion: "<<endl;
	cin>>una.tipo_operacion;
	archivo<<"Numero de cuenta: "<<una.cuenta<<endl;
	archivo<<"\n";
	
			if (una.tipo_operacion == 1){
				cout<<"Cuanto quieres depositar: ";
				cin>>una.Deposito;
				estados[mov] = una.Deposito;
				mov++;
				una.cantidad += una.Deposito;
				archivo<<"El deposito fue de: " <<una.Deposito<<endl;
				archivo << "Hoy " << dia_semana[time->tm_wday] << ", ";
				archivo << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
				archivo << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
				archivo<<"\n";
				
			} else if (una.tipo_operacion == 2){
				cout<<"Cuanto quieres retirar: ";
				cin>>una.Retiro;
				if (una.cantidad <= 0){
					cout<<"No tienes dinero en la cuenta";
			} 	else{
					estados[mov] = una.Retiro;
					mov++;
					una.cantidad-= una.Retiro;
					archivo<<"El retiro fue de: " <<una.Retiro<<endl;
					archivo << "Hoy " << dia_semana[time->tm_wday] << ", ";
					archivo << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
					archivo << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
					archivo<<"\n";
					
				}
			} else if (una.tipo_operacion == 3){
				cout<<"Operacion realizada: "<<una.tipo_operacion<<endl;
				cout<<"Numero de cuenta: "<<una.cuenta<<endl;
				cout<<"Cantidad: "<< una.cantidad<<endl;

				archivo<<"Operacion realizada: "<<una.tipo_operacion<<endl;
				archivo<<"Numero de cuenta: "<<una.cuenta<<endl;
				archivo<<"Cantidad: "<< una.cantidad<<endl;

				if (una.Deposito > 0){
					cout<<"Tu deposito fue de :"<<una.Deposito<<endl;
				}
					if (una.Retiro > 0){
						cout<<"Tu retiro fue de :"<<una.Retiro<<endl;
					}
						for (int i = 0; i < mov; i++){
							cout<<"Tus movimientos fueron: "<<estados[i]<<endl;
						}
							cout<< "Hoy " << dia_semana[time->tm_wday] << ", ";
							cout<< time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
							cout<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;

							archivo<< "Hoy " << dia_semana[time->tm_wday] << ", ";
							archivo<< time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
							archivo<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
							archivo<<"\n";
			}
				cout<<"Movimiento: "<<mov<<endl;
				cout<<"\nQuieres hacer otro movimiento? ";
				cin>>respueta;
				system("cls");
			} while (respueta == 's' or respueta == 'S');			
				getch();
				archivo.close();
				return una;

}

struct registro_operaciones nuevo(){
	struct Tiempo t;
	struct Fecha f;
	struct registro_operaciones una;
	char respueta;
	int mov = 0, estados[mov];
	ofstream archivo;
	archivo.open("Cuentas.txt",ios::app);
	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo<<"\n";
	/* fecha/hora actual basado en el sistema actual */
	time_t now = time(0);

	/* Objeto de una estructura tm con fecha/hora local */
	tm * time = localtime(&now);

	vector<string> dia_semana;
	dia_semana.push_back("Domingo");
	dia_semana.push_back("Lunes");
	dia_semana.push_back("Martes");
	dia_semana.push_back("Miercoles");
	dia_semana.push_back("Jueves");
	dia_semana.push_back("Viernes");
	dia_semana.push_back("Sabado");

	vector<string> mes;
	mes.push_back("Enero");
	mes.push_back("Febrero");
	mes.push_back("Marzo");
	mes.push_back("Abril");
	mes.push_back("Mayo");
	mes.push_back("Junio");
	mes.push_back("Julio");
	mes.push_back("Agosto");
	mes.push_back("Septiembre");
	mes.push_back("Octubre");
	mes.push_back("Noviembre");
	mes.push_back("Diciembre");

	int year = 1900 + time->tm_year;	
	
	cout<<"Dame un numero de cuenta: ";
	cin>>una.cuenta;
	do
		{
	cout<<"====== Menu=====\n";
	cout<<"1. Deposito"<<endl;
	cout<<"2.Retiro"<<endl;
	cout<<"3. Estado de cuenta"<<endl;

	cout<<"Dame el tipo de operacion: "<<endl;
	cin>>una.tipo_operacion;
	archivo<<"Numero de cuenta: "<<una.cuenta<<endl;
	archivo<<"\n";
			if (una.tipo_operacion == 1){
				cout<<"Cuanto quieres depositar: ";
				cin>>una.Deposito;
				estados[mov] = una.Deposito;
				mov++;
				una.cantidad += una.Deposito;
				archivo<<"El deposito fue de: " <<una.Deposito<<endl;
				archivo << "Hoy " << dia_semana[time->tm_wday] << ", ";
				archivo << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
				archivo << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
				archivo<<"\n";
				
			} else if (una.tipo_operacion == 2){
				cout<<"Cuanto quieres retirar: ";
				cin>>una.Retiro;
				if (una.cantidad <= 0){
					cout<<"No tienes dinero en la cuenta";
			} 	else{
					estados[mov] = una.Retiro;
					mov++;
					una.cantidad-= una.Retiro;
					archivo<<"El retiro fue de: " <<una.Retiro<<endl;
					archivo << "Hoy " << dia_semana[time->tm_wday] << ", ";
					archivo << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
					archivo << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
					archivo<<"\n";
					
				}
			} else if (una.tipo_operacion == 3){
				cout<<"Operacion realizada: "<<una.tipo_operacion<<endl;
				cout<<"Numero de cuenta: "<<una.cuenta<<endl;
				cout<<"Cantidad: "<< una.cantidad<<endl;

				archivo<<"Operacion realizada: "<<una.tipo_operacion<<endl;
				archivo<<"Numero de cuenta: "<<una.cuenta<<endl;
				archivo<<"Cantidad: "<< una.cantidad<<endl;

				if (una.Deposito > 0){
					cout<<"Tu deposito fue de :"<<una.Deposito<<endl;
				}
					if (una.Retiro > 0){
						cout<<"Tu retiro fue de :"<<una.Retiro<<endl;
					}
						for (int i = 0; i < mov; i++){
							cout<<"Tus movimientos fueron: "<<estados[i]<<endl;
						}
							cout<< "Hoy " << dia_semana[time->tm_wday] << ", ";
							cout<< time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
							cout<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;

							archivo<< "Hoy " << dia_semana[time->tm_wday] << ", ";
							archivo<< time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
							archivo<< time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
							archivo<<"\n";
			}
				cout<<"Movimiento: "<<mov<<endl;
				cout<<"\nQuieres hacer otro movimiento? ";
				cin>>respueta;
				system("cls");
			} while (respueta == 's' or respueta == 'S');			
				getch();
				archivo.close();
				return una;

}
