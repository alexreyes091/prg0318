#include <iostream>
#include <string>
#include <vector>

#include "Producto.h"

using namespace std;

//constructores y destructores
Producto::Producto(){};
Producto::~Producto(){};
Producto::Producto(string marcaProducto, int existenciaBodegaPrincipal, int existenciaBodegaEnfermeria){
	this -> SetMarcaProducto(marcaProducto);
	this -> SetExistenciaBodegaPrincipal(existenciaBodegaPrincipal);
	this -> SetExistenciaBodegaEnfermeria(existenciaBodegaEnfermeria);
}
Producto::Producto(string usuario, string fecha, string tipoTransaccion,  string codigo, string descripcion, string marcaProducto, string codigoTipoProducto,
					vector <TipoProducto *> newRegistro) : Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetCodigoTipoProducto(codigoTipoProducto, newRegistro);
	this -> SetMarcaProducto(marcaProducto);
	this -> SetExistenciaBodegaPrincipal(0);
	this -> SetExistenciaBodegaEnfermeria(0);
}
//setters
void Producto::SetCodigoTipoProducto(string codigoTipoProducto, vector <TipoProducto *> newRegistro){
	//se evalua si la categoria existe para enlazar los modulos
	if(!TipoProducto::ValidarCodigo(codigoTipoProducto, newRegistro)){
		this -> codigoTipoProducto = CodigoTipoProducto;
	}else{
		cout << "Codigo No existe" << endl;
		this -> codigoTipoProducto = "No existe";
	}
}
void Producto::SetMarcaProducto(string marcaProducto){
	this -> marcaProducto = marcaProducto;
}
void Producto::SetExistenciaBodegaPrincipal(int existenciaBodegaPrincipal){
	this -> existenciaBodegaPrincipal = existenciaBodegaPrincipal;
}
void Producto::SetExistenciaBodegaEnfermeria(int existenciaBodegaEnfermeria){
	this -> existenciaBodegaEnfermeria = existenciaBodegaEnfermeria;
}
//getters
string Producto::GetCodigoTipoProducto(){
	return this -> CodigoTipoProducto;
}
string Producto::GetMarcaProducto(){
	return this -> marcaProducto;
}
int Producto::GetExistenciaBodegaPrincipal(){
	return this -> existenciaBodegaPrincipal;
}
int Producto::GetExistenciaBodegaEnfermeria(){
	return this -> existenciaBodegaEnfermeria;
}
//otros metodos
bool Producto::ValidarCodigo(string codigo, vector <Producto *> newRegistro){ //Valida si un codigo ya existe

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
void Producto::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << "Codigo Tipo Producto: " << this -> GetCodigoTipoProducto() << endl;
	cout << "Marca Producto: " << this -> GetMarcaProducto() << endl;
	cout << "Existencia BP: " << this -> GetExistenciaBodegaPrincipal() << endl;
	cout << "Existencia BE: " << this -> GetExistenciaBodegaEnfermeria() << endl;
}

