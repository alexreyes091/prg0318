#include <iostream>
#include <string>

#include "Turismo.h"
#include "Vehiculo.h"

using namespace std;

//Constructores y Destructores
Turismo::Turismo(){}
Turismo::~Turismo(){}
Turismo::Turismo(string matricula, bool alquilado, double precioKm){
	SetVehiculo("Turismo");
	SetMatricula(matricula);
	SetAlquilado(alquilado);
	this -> SetPrecioKm(precioKm);
}

//Setters
void Turismo::SetPrecioKm(double precioKm){
	this -> precioKm = precioKm;
}

void Turismo::SetKmAlquiler(int kmAlquiler){
	this -> kmAlquiler = kmAlquiler;
}

void Turismo::SetKmDevolucion(int kmDevolucion){
	this -> kmDevolucion = kmDevolucion;
}

void Turismo::SetKmAcumulado(int kmAcumulado){
	this -> kmAcumulado = kmAcumulado;
}

//Getters
double Turismo::GetPrecioKm(){
	return this -> precioKm;
}

int Turismo::GetKmAlquiler(){
	return this -> kmAlquiler;
}

int Turismo::GetKmDevolucion(){
	return this -> kmDevolucion;
}

int Turismo::GetKmAcumulado(){
	return this -> kmAcumulado;
}

//Metodos
void Turismo::AlquilarVehiculo(int kmAlquiler){
	SetKmAlquiler(kmAlquiler); // Definimos el Kilometraje del vehiculo alquilado.
	SetAlquilado(true); // Cambiamos el estado del alquiler del vehiculo.
	
	cout << "> Detalles del Alquiler: " << endl;
	ShowInfo();
	cout << "  * Kilometraje inicial: " << GetKmAlquiler() << endl;
}

void Turismo::DevolverVehiculo(int nuevoKm){
	this -> kmAcumulado = nuevoKm - GetKmAlquiler(); //Calculamos el kilometraje utilizado
	this -> kmAlquiler = kmAlquiler + kmAcumulado; //Establecemos el nuevo Kilometraje.	
	this -> totalPago = this -> kmAcumulado * GetPrecioKm();
	SetAlquilado(false); // Cambiamos el estado del alquiler del vehiculo.
	
	cout << "> Detalles de la Devolucion: " << endl;
	ShowInfo();
	cout << "  * Nuevo Kilometraje: " << nuevoKm << endl;
	cout << "  * Kilometraje Acumulado: " << this -> kmAcumulado << endl;
	cout << "  --------------------------------------------------------- " << endl;
	cout << "  * Total a Pagar: L " << totalPago << endl;
}

void Turismo::ShowInfo(){
	//cout << "> Informacion del Vehiculo: " << endl;
	//cout << "----------------------------------------------" << endl;
	cout << "  * Tipo de Vehiculo: " << GetVehiculo() << endl;
	cout << "  * Matricula: " << GetMatricula() << endl;
	cout << "  * Nuevo Estado: " << GetAlquilado() << endl;
	cout << "  * Precio por Kilometro: " << this ->  precioKm << endl;
}
