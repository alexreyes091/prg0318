#include <iostream>
#include <string>

#include "Vehiculo.h"

//Constructores y Destructores
Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
Vehiculo::Vehiculo(string matriula, bool alquilado){
	this -> SetMatricula(matricula);
	this -> SetAlquilado(alquilado);
}
Vehiculo::Vehiculo(string matriula, string vehiculo, bool alquilado){
	this -> SetMatricula(matricula);
	this -> SetVehiculo(vehiculo);
	this -> SetAlquilado(alquilado);
}

//Setters
void Vehiculo::SetMatricula(string matricula){
	this -> matricula = matricula;
}

void Vehiculo::SetVehiculo(string vehiculo){
	this -> vehiculo = vehiculo;
}

void Vehiculo::SetAlquilado(bool alquilado){
	this -> alquilado = alquilado;
}

//Getters
string Vehiculo::GetMatricula(){
	return this -> matricula;
}

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
