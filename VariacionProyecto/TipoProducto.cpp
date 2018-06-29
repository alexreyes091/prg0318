#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "TipoProducto.h"

using namespace std;

//constructores y destructores
TipoProducto::TipoProducto(){};
TipoProducto::~TipoProducto(){};
TipoProducto::TipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion) 
							: Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){}
							
//otros metodos
bool TipoProducto::ValidarCodigo(string codigo, vector <TipoProducto *> newRegistro){ //Valida si un codigo ya existe

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
void TipoProducto::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
}

