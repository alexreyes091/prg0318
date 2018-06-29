#include <iostream>
#include <string>

#include "Vehiculo.h"

using namespace std;

Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
Vehiculo::Vehiculo(string codigo, string marca, string modelo, int anio, double precio){
	this -> SetCodigo(codigo);
	this -> SetMarca(marca);
	this -> SetModelo(modelo);
	this -> SetAnio(anio);
	this -> SetPrecio(precio);
}
//Setters
void Vehiculo::SetCodigo(string codigo){
	this -> codigo = codigo;
}
void Vehiculo::SetMarca(string marca){
	this -> marca = marca;
}
void Vehiculo::SetModelo(string modelo){
	this -> modelo = modelo;
}
void Vehiculo::SetAnio(int anio){
	this -> anio = anio;
}
void Vehiculo::SetPrecio(double precio){
	this -> precio = precio;
}
//Getters
string Vehiculo::GetCodigo(){
	return this -> codigo;
}
string Vehiculo::GetMarca(){
	return this -> marca;
}
string Vehiculo::GetModelo(){
	return this ->  modelo;
}
int Vehiculo::GetAnio(){
	return this -> anio;
}
double Vehiculo::GetPrecio(){
	return this -> precio;
}
//Otros Modelos
bool Vehiculo::ValidarCodigo(string codigo, vector <Vehiculo *> registroVehiculos){
	
		for(int x=0; x < registroVehiculos.size(); x++){	
		if(registroVehiculos.size() != 0){		
			if(codigo == registroVehiculos[x] -> GetCodigo()){
				return true; //Retorna verdadero si lo encuentra
			}
		}else{	
			return false;
		}
	}
	return false; //Retorna falso si no lo encuentra
}
void Vehiculo::AgregarVehiculo(Vehiculo * newRegistro, vector<Vehiculo *> &registroVehiculos){
	
	registroVehiculos.push_back(newRegistro);
	
}
void Vehiculo::EliminarVehiculo(string codigo, vector<Vehiculo *> &registroVehiculos){
	
	if(ValidarCodigo(codigo, registroVehiculos)){ //Validamos si ya existe el codigo
		//registroVehiculos.pop_back(newRegistro);
		cout << "Registro eliminado con exito con exito" << endl;
	}else{
		cout << "Advertencia: El registro ingresado no existe." << endl;
	}

} 
void Vehiculo::MostrarVehiculo(){
	cout << "Codigo: " << this ->  GetCodigo() << endl; 	
	cout << "Marca: " << this ->  GetMarca() << endl; 	
	cout << "Modelo: " << this ->  GetModelo() << endl; 	
	cout << "Anio: " << this ->  GetAnio() << endl; 	
	cout << "Precio: " << this ->  GetPrecio() << endl; 	
	cout << "-----------------------------------------" << endl;
}
