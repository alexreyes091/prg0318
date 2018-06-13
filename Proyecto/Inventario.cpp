#include <iostream>
#include <string>
#include <vector>

#include "Inventario.h"

using namespace std;

//constructores y destructores
Inventario::Inventario(){};
Inventario::~Inventario(){};
Inventario::Inventario(string codigo){
	this -> SetCodigo(codigo);
}
Inventario::Inventario(string codigo, string descripcion){
	this -> SetCodigo(codigo);
	this -> SetDescripcion(descripcion);
}
Inventario::Inventario(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion) : RegistroBase(usuario, fecha, tipoTransaccion){
	this -> SetCodigo(codigo);
	this -> SetDescripcion(descripcion);
}
//setters
void Inventario::SetCodigo(string codigo){
	this -> codigo = codigo;
}
void Inventario::SetDescripcion(string descripcion){
	this -> descripcion = descripcion;
}
//getters
string Inventario::GetCodigo(){
	return this -> codigo;
}
string Inventario::GetDescripcion(){
	return this -> descripcion;
}
//otros metodos

bool Inventario::ValidarCodigo(string codigo, vector <Inventario *> newRegistro){ //Valida si un codigo ya existe

	for(int x=0; x < newRegistro.size(); x++){	
		if(newRegistro.size() != 0){		
			if(codigo == newRegistro[x] -> GetCodigo()){
				return true; //Returna verdadero si no lo encuentra
			}
		}else{	
			return false;
		}
	}
	return false; //Returno falso si no lo encuentra
}

void Inventario::MostrarInfo(){ //Solo para fines de prueba
	RegistroBase::MostrarInfo();
	cout << "Codigo: " << this -> GetCodigo() << endl;
	cout << "Descripcion: " << this -> GetDescripcion() << endl;
}

