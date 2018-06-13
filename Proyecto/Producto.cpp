#include <iostream>
#include <string>
#include <vector>

#include "Producto.h"

using namespace std;

//constructores y destructores
Producto::Producto(){};
Producto::~Producto(){};
Producto::Producto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string marcaProducto, string codigoTipoProducto){
	Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion);
	TipoProducto(codigoTipoProducto);
	this -> SetMarcaProducto(marcaProducto);
	this -> SetExistenciaBodegaPrincipal(0);
	this -> SetExistenciaBodegaEnfermeria(0);
}
//setters
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
	cout << "Marca Producto: " << this -> GetMarcaProducto() << endl;
	cout << "Existencia BP: " << this -> GetExistenciaBodegaPrincipal() << endl;
	cout << "Existencia BE: " << this -> GetExistenciaBodegaEnfermeria() << endl;
}

