#include <iostream>
#include <iomanip>
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
	cout << "\n | REGISTRO:" << endl;
	cout << " -----------"<< endl;
	cout << left << setw(15) << " | Usuario: " << left << setw(20) << " | Fecha: " << left << setw(30) << " | Tipo Transaccion: " << endl;
	cout << left << " - " << setw(12) << this -> GetUsuario();
	cout << left << " - " << setw(17) << this -> GetFecha();
	cout << left << " - " << setw(27
	) << this -> GetTipoTransaccion() << endl;
}

