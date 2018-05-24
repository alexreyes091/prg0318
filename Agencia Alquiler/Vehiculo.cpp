#include <iostream>
#include <string>

#include "Vehiculo.h"

//Constructores y Destructores
Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
Vehiculo::Vehiculo(string vehiculo, bool alquilado){
	this -> SetVehiculo(vehiculo);
	this -> SetAlquilado(alquilado);
}

//Setters
void Vehiculo::SetVehiculo(string vehiculo){
	this -> vehiculo = vehiculo;
}

void Vehiculo::SetAlquilado(bool alquilado){
	this -> alquilado = alquilado;
}

//Getters
string Vehiculo::GetVehiculo(){
	return this -> vehiculo;
}

bool Vehiculo::GetAlquilado(){
	return this -> alquilado;
}

//Metodos
void Vehiculo::AlquilarVehiculo(){
	this -> alquilado = true;
}

void Vehiculo::DevolverVehiculo(){
	this -> alquilado = false;
}

void Vehiculo::ShowInfo(){
	cout << "Informacion del Vehiculo: " << endl;
}
