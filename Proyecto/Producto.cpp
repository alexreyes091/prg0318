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
//Validaciones
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
//Acciones Posibles
void Producto::BuscarProducto(string codigoProducto, vector <Producto *> registroProducto){
	char op;
	bool codEncontrado;
	//Busqueda de datos:
	while(true){
		for(int x=0; x < registroProducto.size(); x++){
			if(codigoProducto == registroProducto[x] -> GetCodigo()){
				registroProducto[x] -> MostrarInfo();
				codEncontrado = true;
			}
		}
		if(!codEncontrado){
			cout << " --" << endl;
			cout << " | REGISTRO NO ENCONTRADO." << endl;
			cout << " -------------------------" << endl;
		}
		cout << " --" << endl;
		cout << " | SEGUIR BUSCANDO [S/N]: "; cin >> op;
		cout << " --" << endl;
		if(op == 'N' || op == 'n'){
			cout << " --" << endl;
			cout << " | BUSQUEDA FINALIZADA." << endl;
			cout << " ----------------------" << endl;
			system("pause");
			return;
		}else{
			cout << " -- " << endl;
			cout << " * Buscar Codigo: "; cin >> codigoProducto;
			cout << " -- " << endl;
			codEncontrado = false;
		}
	}
	
}

void Producto::CargarProducto(Producto * newRegistro, vector <Producto *> &registroProducto){
	
	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroProducto)){ //Validamos si ya existe el codigo
		if(newRegistro -> GetValidarCodigoTipoProducto()){
			registroProducto.push_back(newRegistro);
			cout << " -- " << endl;
			cout << " -> PRODUCTO AGREGADO EXITOSAMENTE." << endl; 
			cout << " ----------------------------------" << endl;
			system("pause");
		}else{
			cout << " -- " << endl;
			cout << " * ADVERTENCIA: El tipo de producto ingresado no existe." << endl;
			cout << " -------------------------------------------------------" << endl;
			system("pause");
		}
	}else{
		cout << " -- " << endl;
		cout << " * ADVERTENCIA: El registro ya existe, por lo cual el dato no fue guardado." << endl;
		cout << " --------------------------------------------------------------------------" << endl;
		system("pause");
	}
}
void Producto::EliminarProducto(string codigoProducto, vector <Producto *> &registroProducto){
	char op;
	bool codEncontrado = false;
	//Eliminacion de datos:
	while(true){
		for(int x=0; x < registroProducto.size(); x++){
			if(codigoProducto == registroProducto[x] -> GetCodigo()){
				registroProducto.erase(registroProducto.begin() + x);
				cout << " --" << endl;
				cout << " | REGISTRO ELIMINADO CON EXITO." << endl;
				cout << " -------------------------------" << endl;
				codEncontrado = true;
			}
		}
		if(!codEncontrado){
			cout << " --" << endl;
			cout << " | REGISTRO NO ENCONTRADO." << endl;
			cout << " -------------------------" << endl;
		}
		cout << " --" << endl;
		cout << " | SEGUIR ELIMINANDO [S/N]: "; cin >> op;
		cout << " --" << endl;
		if(op == 'N' || op == 'n'){
			cout << " --" << endl;
			cout << " | ELIMINACION FINALIZADA." << endl;
			cout << " -------------------------" << endl;
			system("pause");
			return;
		}else{
			cout << " -- " << endl;
			cout << " * Buscar Codigo: "; cin >> codigoProducto;
			cout << " -- " << endl;
			codEncontrado = false;
		}
	}
}
void Producto::MostrarInfo(vector <Producto *> registroProducto){
	cout << "\n | REGISTRO PRODUCTOS:" << endl;
	cout << " ----------------------"<< endl;
	cout << setw(10) << " | Codigo: " << setw(20) << " | Descripcion: ";
	cout << setw(15) << " | Codigo TP: " << setw(15) << " | Marca: " << setw(10) << " | Precio: "<< endl;
	cout << " -- " << endl;
	for(int x=0; x < registroProducto.size(); x++){
		cout << left << " - " << setw(8) << registroProducto[x] -> GetCodigo();
		cout << left << " - " << setw(18) << registroProducto[x] -> GetDescripcion();
		cout << left << " - " << setw(13) << registroProducto[x] -> GetCodigoTipoProducto(); 
		cout << left << " - " << setw(13) << registroProducto[x] -> GetMarca();
		cout << left << " - " << setw(8) << registroProducto[x] -> GetPrecio() << endl;
	}
	cout << " ------------------------------------------------------------------------" << endl;
}
void Producto::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << " -- " << endl;
	cout << left << setw(15) << " | Codigo TP: " << left << setw(15) << " | Marca: " << left << setw(20) << " | Precio: "<< endl;
	cout << left << " - " << setw(12) <<  this -> GetCodigoTipoProducto();
	cout << left << " - " << setw(12) <<  this -> GetMarca();
	cout << left << " - " << setw(17) <<  this -> GetPrecio() << endl;
}

