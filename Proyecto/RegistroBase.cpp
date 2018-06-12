#include <iostream>
#include <string>

#include "RegistroBase.h"

using namespace std;

//constructores y destructores
RegistroBase::RegistroBase(){};
RegistroBase::~RegistroBase(){};
RegistroBase::RegistroBase( string usuario, string fecha, string tipoTransaccion){
	this -> SetUsuario(usuario);
	this -> SetFecha(fecha);
	this -> SetTipoTransaccion(tipoTransaccion);
}
//setters
void RegistroBase::SetUsuario(string usuario){
	this -> usuario = usuario;
}

void RegistroBase::SetFecha(string fecha){
	this -> fecha = fecha;
}

void RegistroBase::SetTipoTransaccion(string tipoTransaccion){
	this -> tipoTransaccion = tipoTransaccion;
}
//getters
string RegistroBase::GetUsuario(){
	return this -> usuario;
}
string RegistroBase::GetFecha(){
	return this -> fecha;
}
string RegistroBase::GetTipoTransaccion(){
	return this -> tipoTransaccion;
}
//otros metodos
void RegistroBase::MostrarInfo(){
	cout << "--------------------------------------------" << endl;
	cout << "Usuario: " << this -> GetUsuario() << endl;
	cout << "Fecha: " << this -> GetFecha() << endl;
	cout << "Tipo Transaccion: " << this -> GetTipoTransaccion() << endl;
}

