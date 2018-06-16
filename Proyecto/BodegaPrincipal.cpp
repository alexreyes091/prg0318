#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "BodegaPrincipal.h"
#include "BodegaEnfermeria.h"

using namespace std;

//constructores y destructores
BodegaPrincipal::BodegaPrincipal(){};
BodegaPrincipal::~BodegaPrincipal(){};
BodegaPrincipal::BodegaPrincipal(string codigo, string descripcion,string codigoProducto, int existencia,
									 vector <Producto *> registro) : Bodega(codigo, descripcion, codigoProducto, existencia, registro){
}
//otros metodos
bool BodegaPrincipal::ValidarCodigoProductoBodega(BodegaPrincipal * bodega, vector <BodegaPrincipal *> bodegaPrincipal){
	
	for(int x=0; x < bodegaPrincipal.size(); x++){
		if(bodegaPrincipal.size() != 0){		
			if(bodega -> GetCodigoProducto() == bodegaPrincipal[x] -> GetCodigoProducto()){
				return true; //Retorna verdadero si lo encuentra
			}else{	
				return false;
			}
		}
		return false; //Retorna falso si no lo encuentra
	}
}
bool BodegaPrincipal::ValidarCodigoProductoBodega(BodegaPrincipal * bodega,  vector <BodegaEnfermeria *> bodegaEnfermeria){
	
	for(int x=0; x < bodegaEnfermeria.size(); x++){
		if(bodegaEnfermeria.size() != 0){		
			if(bodega -> GetCodigoProducto() == bodegaEnfermeria[x] -> GetCodigoProducto()){
				return true; //Retorna verdadero si lo encuentra
			}else{	
				return false;
			}
		}
		return false; //Retorna falso si no lo encuentra
	}
}

void BodegaPrincipal::Transferencia(BodegaPrincipal * bodega, vector <BodegaPrincipal *> &bodegaPrincipal, vector <BodegaEnfermeria *> bodegaEnfermeria){
	
	if(ValidarCodigoProductoBodega(bodega, bodegaEnfermeria) == true 
		&& ValidarCodigoProductoBodega(bodega, bodegaPrincipal) == true){
			
		cout << "Obj Bodega" << bodega -> GetExistencia() << endl;				
		
	}
	
	if(ValidarCodigoProductoBodega(bodega, bodegaEnfermeria) == true){
			
		cout << "Principal" << bodega -> GetExistencia() << endl;				
		
	}
	
	if(ValidarCodigoProductoBodega(bodega, bodegaPrincipal) == false){
		
		bodegaPrincipal.push_back(bodega);	
		cout << "Enfermeria"<< bodega -> GetExistencia() << endl;				
		
	}
}

//void BodegaPrincipal::ActualizarBodega(Compra *, vector <BodegaPrincipal *>){
//}
