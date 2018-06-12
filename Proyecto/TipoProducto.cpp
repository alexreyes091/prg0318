#include <iostream>
#include <string>
#include <vector>

#include "TipoProducto.h"

using namespace std;

//constructores y destructores
TipoProducto::TipoProducto(){};
TipoProducto::~TipoProducto(){};
TipoProducto::TipoProducto(string codigo, string descripcion, string tipoProducto) : Inventario(codigo, descripcion){
	this -> SetTipoProducto(tipoProducto);
}
TipoProducto::TipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string tipoProducto) : Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetTipoProducto(tipoProducto);
}
//setters
void TipoProducto::SetTipoProducto(string tipoProducto){
	this -> tipoProducto = tipoProducto;
}
//getters
string TipoProducto::GetTipoProducto(){
	return this -> tipoProducto;
}
//otros metodos
bool TipoProducto::ValidarCodigo(string codigo, vector <TipoProducto *> newRegistro){ //Valida si un codigo ya existe

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
void TipoProducto::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << "TipoProducto: " << this -> GetTipoProducto() << endl;
}

