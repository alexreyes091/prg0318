#include <iostream>

#include "Persona.h"

using namespace std;

//Prototipos de Funcion
void CargarPersona();
void CargarPadre(int, string, int);
void CargarHijo(int, string, int, char, int);

void BuscarPersona();


//Globales
bool registroInicial = false;
vector <Persona *> registroPersona;

int main() {
	
	CargarPersona();

	CargarPersona();
	
	return 0;
}
//Funciones
void CargarPersona(){
	//Variables de registro
	int codigo, edad, familiar;
	string nombre;
	char tipo;
	bool control = true;
	
	if(!registroInicial){
		cout << "\nNuevo Registro" << endl;
		cout << "--------------" << endl;
		cout << "  Codigo: "; cin >> codigo;
		cout << "  Nombre: "; cin >> nombre;
		cout << "    Edad: "; cin >> edad;
		Persona * newPersona = new Persona(codigo, nombre, edad);
		registroPersona.push_back(newPersona);
		registroInicial = true;
		system("pause");
		system("cls");
		return;
	}
	
	//Objeto Temporal
	Persona * temp = new Persona();
	cout << "\nNuevo Registro" << endl;
	cout << "--------------" << endl;
	cout << " Tipo Persona: (P/H): "; cin >> tipo;
	while(control){
		switch(tipo){
			case 'P':
			case 'p':
				cout << "  Codigo: "; cin >> codigo;
				if(!temp -> ValidarEleccionCodigo(codigo, registroPersona)){
					cout << "  Nombre: "; cin >> nombre;
					cout << "    Edad: "; cin >> edad;
					CargarPadre(codigo, nombre, edad);
				}else{
					cout << "ALERTE: Eleccion de Codigo no valido.\n --> Registro no fue guardado." << endl;
					system("pause");
				}
				break;
				
			case 'H':
			case 'h':
				cout << "  Codigo: "; cin >> codigo;
				if(!temp -> ValidarEleccionCodigo(codigo, registroPersona)){
					cout << "  Nombre: "; cin >> nombre;
					cout << "    Edad: "; cin >> edad;
					temp -> ListarPadres(registroPersona);
					cout << "Familiar: "; cin >> familiar;
					if(temp -> ValidarEleccionPadre(familiar, registroPersona)){
						CargarHijo(codigo, nombre, edad, tipo, familiar);
					}else{
						cout << "ALERTE: Eleccion de Padre no valido.\n --> Registro no fue guardado." << endl;
						system("pause");
						break;
					}
				}else{
					cout << "ALERTE: Eleccion de Codigo no valido.\n --> Registro no fue guardado." << endl;
					system("pause");
				}
				break;
				
			case 'S':
			case 's':
				control = false;
				break;
				
			default:
				cout << " -> Registro no valido." << endl;
		}
		system("pause");
		system("cls");
		cout << "\nNuevo Registro" << endl;
		cout << "--------------" << endl;
		cout << " [S] Salir! " << endl; 
		cout << "--------------" << endl;
		cout << " Tipo Persona: (P/H): "; cin >> tipo;
	}
	
}
void CargarPadre(int codigo, string nombre, int edad){
	Persona * newPersona = new Persona(codigo, nombre, edad);
	registroPersona.push_back(newPersona);
}
void CargarHijo(int codigo, string nombre, int edad, char tipo, int familiar){
	Persona * newPersona = new Persona(codigo, nombre, edad, tipo, familiar);
	registroPersona.push_back(newPersona);
}
