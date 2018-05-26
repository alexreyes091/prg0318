#include <iostream>
#include <string>

#include "Camion.h"
#include "Vehiculo.h"

using namespace std;

//Constructores y Destructores
Camion::Camion(){}
Camion::~Camion(){}
Camion::Camion(string matricula, bool alquilado, double precioDia){
	SetVehiculo("Camion");
	SetMatricula(matricula);
	SetAlquilado(alquilado);
	this -> SetPrecioDia(precioDia);
}

//Setters
void Camion::SetPrecioDia(double precioDia){
	this -> precioDia = precioDia;
}

void Camion::SetDiaAlquiler(int diaAlquiler){
	this -> diaAlquiler = diaAlquiler;
}

void Camion::SetDiaDevolucion(int diaDevolucion){
	this -> diaDevolucion = diaDevolucion;
}

void Camion::SetDiaAcumulado(int diaAcumulado){
	this -> diaAcumulado = diaAcumulado;
}

//Getters
double Camion::GetPrecioDia(){
	return this -> precioDia;
}

int Camion::GetDiaAlquiler(){
	return this -> diaAlquiler;
}

int Camion::GetDiaDevolucion(){
	return this -> diaDevolucion;
}

int Camion::GetDiaAcumulado(){
	return this -> diaAcumulado;
}

//Metodos
void Camion::AlquilarVehiculo(int diaAlquiler){
	SetDiaAlquiler(diaAlquiler); // Definimos el Kilometraje del vehiculo alquilado.
	SetAlquilado(true); // Cambiamos el estado del alquiler del vehiculo.
	
	cout << "> Detalles del Alquiler: " << endl;
	ShowInfo();
	cout << "  * Dia de Alquiler: " << GetDiaAlquiler() << endl;
}

void Camion::DevolverVehiculo(int nuevoDia){
	this -> diaAcumulado = nuevoDia - GetDiaAlquiler(); //Calculamos el kilometraje utilizado
	this -> diaAlquiler = diaAlquiler + diaAcumulado; //Establecemos el nuevo Kilometraje.	
	this -> totalPago = this -> diaAcumulado * GetPrecioDia();
	SetAlquilado(false); // Cambiamos el estado del alquiler del vehiculo.
	
	cout << "> Detalles de la Devolucion: " << endl;
	ShowInfo();
	cout << "  * Dia de entrega: " << nuevoDia << endl;
	cout << "  * Dias acumulados: " << this -> diaAcumulado << endl;
	cout << "  --------------------------------------------------------- " << endl;
	cout << "  * Total a Pagar: L " << totalPago << endl;
}

void Camion::ShowInfo(){
	//cout << "> Informacion del Vehiculo: " << endl;
	//cout << "----------------------------------------------" << endl;
	cout << "  * Tipo de Vehiculo: " << GetVehiculo() << endl;
	cout << "  * Matricula: " << GetMatricula() << endl;
	cout << "  * Nuevo Estado: " << GetAlquilado() << endl;
	cout << "  * Precio por Dia: " << this ->  precioDia << endl;
}
