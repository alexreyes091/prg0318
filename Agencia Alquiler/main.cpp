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
void NuevoCamion();
void NuevoTurismo();
//Opciones de Vehiculos
void AlquilarVehiculo();
void DevolverVehiculo();
void MostrarInformacionVehiculo();

//Variables Globales
vector <Vehiculo*> listaVehiculos;

int main() {
	system("color 0E"); //color de sistema
	int op = 0;
	
	MenuPrincipal();
	cin >> op;
	
	while(op != 7){
		switch(op){
			
			case 1: 
				system("cls");
				NuevoCamion();
				system("pause");
				system("cls");
				break;
			
			case 2: 
				system("cls");
				NuevoTurismo();
				system("pause");
				system("cls");
				break;
				
			case 3:
				system("cls");
				AlquilarVehiculo();
				system("pause");
				system("cls");
			
			default:
				cout << " Opcion no valida, intentelo nuevamente. " << endl;
				system("pause");
				system("cls");
				break;
		}
		
		MenuPrincipal();
		cin >> op;
	}
    
	listaVehiculos.clear(); //Limpia la lista del vector creada.
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

void NuevoCamion(){
	//Variables de registro
	string vehiculo = "Camion", matricula; 
	double precioDia;

	//Generar el nuevo Registro;
	cout << "Registrar Camion: " << endl;
	cout << " -> Tipo de Vehiculo: " << vehiculo << endl;
	cout << " -> Matricula: "; cin >> matricula;
	cout << " -> Precio por dia: "; cin >> precioDia;
	
	//Cargar Objeto;
	Camion * newCamion = new Camion(matricula, false, precioDia);
	
	//Prueba de Carga
	listaVehiculos.push_back(newCamion);
	
	//Limpia el objeto creado.
	delete newCamion;
}

void NuevoTurismo(){
	//Variables de registro
	string vehiculo = "Turismo", matricula; 
	double precioKm;

	//Generar el nuevo Registro;
	cout << "Registrar Turismo: " << endl;
	cout << " -> Tipo de Vehiculo: " << vehiculo << endl;
	cout << " -> Matricula: "; cin >> matricula;
	cout << " -> Precio por Km: "; cin >> precioKm;
	
	//Cargar Objeto;
	Turismo * newTurismo = new Turismo(matricula, false, precioKm);
	
	//Prueba de Carga
	listaVehiculos.push_back(newTurismo);
	
	//Limpia el objeto creado.
	delete newTurismo;
}

/*********************************************************************
En esta parte del codigo volvi a tener problemas, me guarda la info 
*********************************************************************/
void AlquilarVehiculo(){
	string matricula;
	
	cout << "Alquiler de Vehiculo" << endl;
	cout << "\nIngrese la Matricula del Vehiculo que desea alquilar: ";
	cin >> matricula;
	
	for(int x=0; x < listaVehiculos.size(); x++){
		
		if(matricula == listaVehiculos[x] -> GetMatricula() && listaVehiculos[x] -> GetAlquilado() == true){
			cout << "Lo siento el Vehiculo ya se encuentra alquilado." << endl;
			system("pause");
			return;
		}
		
		if(matricula == listaVehiculos[x] -> GetMatricula() && listaVehiculos[x] -> GetAlquilado() == false){
			listaVehiculos[x] -> SetAlquilado(true);
			listaVehiculos[x] -> ShowInfo();
			system("pause");
			return;
		}	
	}
	
	cout << "Lo siento matricula no encontrada." << endl;
}

void DevolverVehiculo(){
	
}

void MostrarInformacionVehiculo(){
	
}

