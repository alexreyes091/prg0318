#include <iostream>
#include <string>

#include "Base.h"

using namespace std;
//constructores y destructores
Base::Base();
Base::~Base();
Base::Base( string usuario, string fecha, string tipoTransaccion){
	this -> SetUsuario(usuario);
	this -> SetFecha(fecha);
	this -> SetTipoTransaccion(tipoTransaccion);
}
//setters
void Base::SetUsuario(string usuario){
	this -> usuario = usuario
}

void Base::SetFecha(string fecha){
	this -> fecha = fecha;
}

void Base::SetTipoTransaccion(string tipoTransaccion){
	this -> tipoTransaccion = tipoTransaccion;
}
//getters
string Base::GetUsuario(){
	return this -> usuario;
}
string Base::GetFecha(){
	return this -> fecha;
}
string Base::GetTipoTransaccion(){
	return this -> tipoTransaccion;
}
//otros metodos
void Base::MostrarInfo(){
	cout << "Usuario: " << this -> GetUsuario() << endl;
	cout << "Fecha: " << this -> GetFecha() << endl;
	cout << "Tipo Transaccion: " << this -> GettipoTransaccion() << endl;
}
