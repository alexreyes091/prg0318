#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Producto.h"

using namespace std;

//constructores y destructores
Producto::Producto(){};
Producto::~Producto(){};
Producto::Producto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string marca, double precio,
				string codigoTipoProducto, vector <TipoProducto *> registro) : Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetCodigoTipoProducto(codigoTipoProducto, registro);
	this -> SetMarca(marca);
	this -> SetPrecio(precio);
}
//setters
void Producto::SetCodigoTipoProducto(string codigoTipoProducto, vector <TipoProducto *> registro){
	//se evalua si la categoria existe para enlazar los modulos
	
	TipoProducto * newRegistro = new TipoProducto; //Creo un objeto vacio solo para poder buscar el codigo en el registro de tipos de productos
	
	if(newRegistro -> ValidarCodigo(codigoTipoProducto, registro)){
		this -> codigoTipoProducto = codigoTipoProducto; //Si es verdadero registra el codigo del tipo de producto.
		this -> validarCodigoTipoProducto = true;
	}else{
		this -> validarCodigoTipoProducto = false;
	}
	
	delete newRegistro;
}
void Producto::SetMarca(string marca){
	this -> marca = marca;
}
void Producto::SetPrecio(double precio){
	this -> precio = precio;
}
//getters
string Producto::GetCodigoTipoProducto(){
	return this -> codigoTipoProducto;
}
bool Producto::GetValidarCodigoTipoProducto(){
	return this -> validarCodigoTipoProducto;
}
string Producto::GetMarca(){
	return this -> marca;
}
double Producto::GetPrecio(){
	return this -> precio;
}
//otros metodos
bool Producto::ValidarCodigo(string codigo, vector <Producto *> newRegistro){ //Valida si un codigo ya existe

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
void Producto::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << setw(23) << "Codigo TP: " << this -> GetCodigoTipoProducto() << endl;
	cout << setw(23) << "Marca: " << this -> GetMarca() << endl;
	cout << setw(23) << "Precio: " << this -> GetPrecio() << endl;
}

