#include <iostream>
#include <string>
#include <vector>

#include "Producto.h"

using namespace std;

//constructores y destructores
Producto::Producto(){};
Producto::~Producto(){};
Producto::Producto(string nombreProducto, string marcaProducto, int existenciaBodegaPrincipal, int existenciaBodegaEnfermeria){
	this -> void SetNombreProducto(nombreProducto);
	this -> void SetMarcaProducto(marcaProducto);
	this -> void SetExistenciaBodegaPrincipal(existenciaBodegaPrincipal);
	this -> void SetExistenciaBodegaEnfermeria(existenciaBodegaEnfermeria);
}
Producto::TipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string tipoProducto, 
						string nombreProducto, string marcaProducto, int existenciaBodegaPrincipal, int existenciaBodegaEnfermeria) : TipoProducto(usuario, fecha, tipoTransaccion, codigo, descripcion, string tipoProducto){
	this -> void SetNombreProducto(nombreProducto);
	this -> void SetMarcaProducto(marcaProducto);
	this -> void SetExistenciaBodegaPrincipal(existenciaBodegaPrincipal);
	this -> void SetExistenciaBodegaEnfermeria(existenciaBodegaEnfermeria);
}
//setters
void Producto::SetTipoProducto(string tipoProducto){
	this -> tipoProducto = tipoProducto;
}
//getters
string Producto::GetTipoProducto(){
	return this -> tipoProducto;
}
//otros metodos
bool Producto::ValidarCodigo(string codigo, vector <TipoProducto *> newRegistro){ //Valida si un codigo ya existe

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
	cout << "TipoProducto: " << this -> GetTipoProducto() << endl;
}

