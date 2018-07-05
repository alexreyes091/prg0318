#include <iostream>

#include "Persona.h"

using namespace std;

//constructores y destructores
Persona::Persona(){};
Persona::~Persona(){};
Persona::Persona(int codigo, string nombre, int edad){
	this -> SetCodigo(codigo);
	this -> SetNombre(nombre);
	this -> SetEdad(edad);
	Base::SetTipo('P');
}
Persona::Persona(int codigo, string nombre, int edad, char tipo, int familiar) : Base(tipo, familiar){
	this -> SetCodigo(codigo);
	this -> SetNombre(nombre);
	this -> SetEdad(edad);
}
//setters
void Persona::SetCodigo(int codigo){
	this -> codigo = codigo;
}
void Persona::SetNombre(string nombre){
	this -> nombre = nombre;
}
void Persona::SetEdad(int edad){
	this -> edad = edad;
}
//getters
int Persona::GetCodigo(){
	return this -> codigo;
}
string Persona::GetNombre(){
	return this -> nombre;
}
int Persona::GetEdad(){
	return this -> edad;
}
//Validaciones
bool Persona::ValidarEleccionPadre(int eleccion, vector <Persona *> personas){
	for(int x=0; x < personas.size(); x++){
		if(personas[x] -> GetTipo() == 'P' || personas[x] -> GetTipo() == 'p'){
			if(eleccion-1 == x){
				return true;	
			}
		}
	}
	return false;
}
bool Persona::ValidarEleccionCodigo(int eleccion, vector <Persona *> personas){
	for(int x=0; x < personas.size(); x++){
		if(eleccion == personas[x] -> GetCodigo()){
			return true;
		}
	}
	return false;
}
//Acciones
void Persona::MostrarPersonas(){
	cout << " Codigo: " << GetCodigo() << endl;
	cout << " Nombre: " << GetNombre() << endl;
	cout << " Edad: " << GetEdad() << endl;
	cout << " Tipo de Persona: " << GetTipo() << endl;
	cout << " ------------------------" << endl;
	
}
void Persona::MostrarPadres(vector <Persona*> personas){
	for(int x=0; x < personas.size(); x++){
		if(personas[x] -> GetTipo() == 'P' || personas[x] -> GetTipo() == 'p'){
			cout << " Codigo: " << personas[x] -> GetCodigo() << endl;
			cout << " Nombre: " << personas[x] -> GetNombre() << endl;
			cout << " Edad: " << personas[x] -> GetEdad() << endl;
			cout << " Tipo de Persona: " << personas[x] -> GetTipo() << endl;
			cout << " --------------------------" << endl;
			for(int i=0; i < personas.size(); i++){
				if(personas[i] -> GetFamiliar() == personas[x] -> GetFamiliar()){
					cout << "Hijo #" << i << ": " << personas[i] -> GetNombre() << endl;
				}
			}
			cout << " ------------------------" << endl;
		}
	}
}
void Persona::MostrarHijos(vector <Persona*> personas){
	for(int x=0; x < personas.size(); x++){
		if(personas[x] -> GetTipo() == 'H' || personas[x] -> GetTipo() == 'h'){
			cout << " Codigo: " << personas[x] -> GetCodigo() << endl;
			cout << " Nombre: " << personas[x] -> GetNombre() << endl;
			cout << " Edad: " << personas[x] -> GetEdad() << endl;
			cout << " Tipo de Persona: " << personas[x] -> GetTipo() << endl;
			cout << " --------------------------" << endl;
			for(int i=0; i < personas.size(); i++){
				if(personas[i] -> GetFamiliar() == personas[x] -> GetFamiliar()){
					cout << "Padre #" << i << ": " << personas[i] -> GetNombre() << endl;
				}
			}
			cout << " ------------------------" << endl;
		}
	}
}
void Persona::ListarPadres(vector <Persona*> personas){
	int cont=1;
	cout << "Lista de Padres: " << endl;
	cout << "---------------" << endl;
	for(int x=0; x < personas.size(); x++){
		if(personas[x] -> GetTipo() == 'P' || personas[x] -> GetTipo() == 'p'){
			cout << "  P " << cont << " : " << personas[x] -> GetNombre() << endl;
			cont++;
		}
	}
	cout << "---------------" << endl;
}
