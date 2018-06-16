#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Bodega.h"

using namespace std;

//constructores y destructores
Bodega::Bodega(){};
Bodega::~Bodega(){};
Bodega::Bodega(string codigo, string descripcion, string codigoProducto, int existencia, 
				vector <Producto *> registro) : Inventario(codigo, descripcion){
	this -> SetCodigoProducto(codigoProducto, registro);
	this -> SetExistencia(existencia);
}
Bodega::Bodega(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion,	string codigoProducto, 
				int existencia, vector <Producto *> registro) : Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetCodigoProducto(codigoProducto, registro);
	this -> SetExistencia(existencia);
}
//setters
void Bodega::SetCodigoProducto(string codigoProducto, vector <Producto *> registro){
	//se evalua si el codigo del producto existe para enlazar los modulos
	
	Producto * newRegistro = new Producto; //Creo un objeto vacio solo para poder buscar el codigo en el registro de tipos de productos
	
	if(newRegistro -> ValidarCodigo(codigoProducto, registro)){
		this -> codigoProducto = codigoProducto; //Si es verdadero registra el codigo del tipo de producto.
		this -> validarCodigoProducto = true;
	}else{
		this -> validarCodigoProducto = false;
	}
	
	delete newRegistro;
}
void Bodega::SetExistencia(int existencia){
	this -> existencia = existencia;
}
//getters
string Bodega::GetCodigoProducto(){
	return this -> codigoProducto;
}
bool Bodega::GetValidarCodigoProducto(){
	return this -> validarCodigoProducto;
}
int Bodega::GetExistencia(){
	return this -> existencia;
}
//otros metodos
bool Bodega::ValidarCodigo(string codigo, vector <Producto *> newRegistro){ //Valida si un codigo ya existe

	for(int x=0; x < newRegistro.size(); x++){	
		if(newRegistro.size() != 0){		
			if(codigo == newRegistro[x] -> GetCodigo()){
				return true; //Retorna verdadero si lo encuentra
			}
		}else{	
			return false;
		}
	}
	return false; //Retorna falso si no lo encuentra
}
void Bodega::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << setw(23) << "Codigo Producto: " << this -> GetCodigoProducto() << endl;
	cout << setw(23) << "Existencia: " << this -> GetExistencia() << endl;
}

