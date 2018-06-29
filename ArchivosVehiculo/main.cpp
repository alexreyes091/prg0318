#include <iostream>
#include <string>

#include "Vehiculo.h"

using namespace std;

void Menu();
void Agregar(vector <Vehiculo *> &);
void Eliminar(vector <Vehiculo *> &);
void Mostrar(vector <Vehiculo *>);

int main() {
	
	vector <Vehiculo *> registroVehiculo;
	int op;
	
	Menu(); //Llamamos el menu principal;
	cin >> op;
		
	while(op != -1){
		switch(op){
			case 1:
				system("cls");
				Agregar(registroVehiculo);
				system("pause");
				break;
			case 2:
				break;
			case 3:
				break;
			case -1: 
				break;
			
		}
		system("cls");
		Menu(); //Llamamos el menu principal;
		cin >> op;
	}
	
	
	return 0;
}

void Menu(){
	cout << "   Coorporacion Toyota   " << endl;
	cout << " --------------------------- " << endl;
	cout << " -> [01] Nuevo Vehiculo " << endl;
	cout << " -> [02] Listar Vehiculos " << endl;
	cout << " -> [03] Eliminar Vehiculo " << endl;
	cout << " -> [-1] Salir " << endl;
	cout << " --------------------------- " << endl;
	cout << " -> ";
}
void Agregar(vector <Vehiculo *> &registroVehiculos){
	//Variables de registro
	string codigo, marca, modelo;
	int anio;
	double precio;
	
	cout << "| Registro de Vehiculo" << endl;
	cout << "-----------------------------------" << endl;
	cout << "| Codigo: "; cin >> codigo;
	cout << "| Marca: "; cin >> marca;
	cout << "| Modelo: "; cin >> modelo;
	cout << "| Anio: "; cin >> anio;
	cout << "| Precio: "; cin >> precio; 
	
	//Objeto a guardar.
	Vehiculo * newRegistro = new Vehiculo(codigo, marca, modelo, anio, precio);
	//Cargo el objeto a mi vector
	newRegistro -> AgregarVehiculo(newRegistro, registroVehiculos);
}
void Eliminar(vector <Vehiculo *> &registroVehiculos){
	//Codigo a Eliminar
	string codigo;
	
	cout << "| Codigo de Vehiculo a eliminar" << endl;
	cout << "-----------------------------------" << endl;
	cout << "| Codigo: "; cin >> codigo;
	
	//Objeto a eliminar.
	Vehiculo * newRegistro = new Vehiculo(codigo, marca, modelo, anio, precio);
	//Cargo el objeto a mi vector
	newRegistro -> AgregarVehiculo(newRegistro, registroVehiculos);
}
void Mostrar(vector <Vehiculo *> registroVehiculos){
	
}
