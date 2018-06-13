#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Producto.h"

using namespace std;

//constructores y destructores
Producto::Producto(){};
Producto::~Producto(){};
Producto::Producto(string marca, int existenciaBodegaPrincipal, int existenciaBodegaEnfermeria){
	this -> SetMarca(marca);
	this -> SetExistenciaBodegaPrincipal(existenciaBodegaPrincipal);
	this -> SetExistenciaBodegaEnfermeria(existenciaBodegaEnfermeria);
}
Producto::Producto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string marca, double precio,
				string codigoTipoProducto, vector <TipoProducto *> registro) : Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetCodigoTipoProducto(codigoTipoProducto, registro);
	this -> SetMarca(marca);
	this -> SetPrecio(precio);
	this -> SetExistenciaBodegaPrincipal(0);
	this -> SetExistenciaBodegaEnfermeria(0);
}
//setters
void Producto::SetCodigoTipoProducto(string codigoTipoProducto, vector <TipoProducto *> registro){
	//se evalua si la categoria existe para enlazar los modulos
	
	TipoProducto * newRegistro = new TipoProducto; //Creo un objeto vacio solo para poder buscar el codigo en el registro de tipos de productos
	
	if(newRegistro -> ValidarCodigo(codigoTipoProducto, registro)){
		this -> codigoTipoProducto = codigoTipoProducto; //Si es verdadero registra el codigo del tipo de producto.
		this -> validarCodigoTipoproducto = true;
	}else{
		this -> validarCodigoTipoproducto = false;
	}
	
	delete newRegistro;
}
void Producto::SetMarca(string marca){
	this -> marca = marca;
}
void Producto::SetPrecio(double precio){
	this -> precio = precio;
}
void Producto::SetExistenciaBodegaPrincipal(int existenciaBodegaPrincipal){
	this -> existenciaBodegaPrincipal = existenciaBodegaPrincipal;
}
void Producto::SetExistenciaBodegaEnfermeria(int existenciaBodegaEnfermeria){
	this -> existenciaBodegaEnfermeria = existenciaBodegaEnfermeria;
}
//getters
string Producto::GetCodigoTipoProducto(){
	return this -> codigoTipoProducto;
}
bool Producto::GetValidarCodigoTipoProducto(){
	return this -> validarCodigoTipoproducto;
}
string Producto::GetMarca(){
	return this -> marca;
}
double Producto::GetPrecio(){
	return this -> precio;
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
	cout << setw(23) << "Existencia BP: " << this -> GetExistenciaBodegaPrincipal() << endl;
	cout << setw(23) << "Existencia BE: " << this -> GetExistenciaBodegaEnfermeria() << endl;
}

