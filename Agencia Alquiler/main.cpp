#include <iostream>
#include <string>
#include <vector>

#include "Vehiculo.h"
#include "Turismo.h"
#include "Camion.h"

using namespace std;

//Prototipo de Funciones
void MenuPrincipal();
//Creacion de Vehiculos
Camion NuevoCamion();
Turismo NuevoTurismo();
//Opciones de Vehiculos
void AlquilarVehiculo();
void DevolverVehiculo();
void MostrarInformacionVehiculo();

int main() {
	system("color 0E"); //color de sistema
	int op = 0;
	vector <Vehiculo> listaVehiculos;
	int obj = 0;
	
	MenuPrincipal();
	cin >> op;
	
	while(op != 7){
		switch(op){
			
			case 1: 
				system("cls");
				listaVehiculos.push_back(NuevoCamion());
				obj++;
				system("pause");
				break;
			
			case 2: 
				system("cls");
				listaVehiculos.push_back(NuevoTurismo());
				obj++;
				system("pause");
				break;
			
			default:
				cout << " Opcion no valida, intentelo nuevamente. " << endl;
				system("pause");
				system("cls");
				break;
		}
		
		MenuPrincipal();
		cin >> op;
	}
	
	for(int i = 0; i < listaVehiculos.size(); i++)
    {
        listaVehiculos[i].ShowInfo();
    }
	
	return 0;
}

//Menu Inicial
void MenuPrincipal(){
	cout << "AGENCIA ALQUILER " << endl;
	cout << " ---------------------------- " << endl;
	cout << " 1- Registrar Nuevo Camion" << endl;
	cout << " 2- Registrar Nuevo Turismo" << endl;
	cout << " 3- Alquiler de Vehiculo" << endl;
	cout << " 4- Devolucion de Vehiculo" << endl;
	cout << " 5- Listar Vehiculos" << endl;
	cout << " 6- Eliminar Vehiculo" << endl;
	cout << " 7- Salir" << endl;
	cout << " --------------------------- " << endl;
	cout << " >> ";
}

Camion NuevoCamion(){
	//Variables de registro
	string vehiculo = "Camion", matricula; 
	double precioDia;

	//Generar el nuevo Registro;
	cout << "Registrar Camion: " << endl;
	cout << " -> Tipo de Vehiculo: " << vehiculo << endl;
	cout << " -> Matricula: "; cin >> matricula;
	cout << " -> Precio por dia: "; cin >> precioDia;
	
	//Cargar Objeto;
	Camion newCamion(matricula, false, precioDia);
	
	//Devolvemos el objeto creado;
	return newCamion;
}

Turismo NuevoTurismo(){
	//Variables de registro
	string vehiculo = "Turismo", matricula; 
	double precioKm;

	//Generar el nuevo Registro;
	cout << "Registrar Turismo: " << endl;
	cout << " -> Tipo de Vehiculo: " << vehiculo << endl;
	cout << " -> Matricula: "; cin >> matricula;
	cout << " -> Precio por Km: "; cin >> precioKm;
	
	//Cargar Objeto;
	Turismo newTurismo(matricula, false, precioKm);
	
	//Devolvemos el objeto creado;
	return newTurismo;
}

