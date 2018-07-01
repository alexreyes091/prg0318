#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Compras.h"

using namespace std;

//constructores y destructores
Compras::Compras(){};
Compras::~Compras(){};
Compras::Compras(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string codigoProducto, int cantidadCompra, 
				double precioCompra, vector <Producto *> registro)
				: Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetCodigoProducto(codigoProducto, registro);
	this -> SetCantidadCompra(cantidadCompra);
	this -> SetPrecioCompra(precioCompra);
	this -> SetTotalCompra(totalCompra);
	this -> SetEstadoCompra(false);
	CalcularTotalCompra(precioCompra,cantidadCompra);
}
//setters
void Compras::SetCodigoProducto(string codigoProducto, vector <Producto *> registro){
	//Se evalua si el producto existe para enlazar los modulos
	
	Producto * newRegistro = new Producto; //Creo un objeto vacio solo para poder buscar el codigo en el registro de tipos de productos
	
	if(newRegistro -> ValidarCodigo(codigoProducto, registro)){
		this -> codigoProducto = codigoProducto; //Si es verdadero registra el codigo del tipo de producto.
		this -> validarCodigoProducto = true;
	}else{
		this -> validarCodigoProducto = false;
	}
	
	delete newRegistro;
}
void Compras::SetCantidadCompra(int cantidadCompra){
	this -> cantidadCompra = cantidadCompra;
}
void Compras::SetPrecioCompra(double precioCompra){
	this -> precioCompra = precioCompra;
}
void Compras::SetTotalCompra(double totalCompra){
	this -> totalCompra = totalCompra;
}
void Compras::SetEstadoCompra(bool estadoCompra){
	this -> estadoCompra = estadoCompra;
}
//getters
string Compras::GetCodigoProducto(){
	return this -> codigoProducto;
}
bool Compras::GetValidarCodigoProducto(){
	return this -> validarCodigoProducto;
}
int Compras::GetCantidadCompra(){
	return this -> cantidadCompra;
}
double Compras::GetPrecioCompra(){
	return this -> precioCompra;
}
double Compras::GetTotalCompra(){
	return this -> totalCompra;
}
bool Compras::GetEstadoCompra(){
	return this -> estadoCompra;
}
//otros metodos

//Validaciones
bool Compras::ValidarCodigo(string codigo, vector <Compras *> newRegistro){ //Valida si un codigo ya existe

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
bool Compras::ValidarCodigo(string codigo, vector <Producto *> newRegistro){ //Valida si un codigo ya existe

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
void Compras::CalcularTotalCompra(double precioCompra, int cantidadCompra){ //Calcula el total de la compra por producto
	SetTotalCompra(precioCompra * cantidadCompra);
}
//Funcion para agregar compras
void Compras::CargarCompra(string usuario, string fecha, string tipoTransaccion, vector <Producto *> registroProducto, vector <Compras *> &registroCompra){
	string codigo, descripcion, codigoProducto;
	int cantidadCompra;
	double precioCompra;
	bool continuar = true;

	cout << " | REGISTRAR COMPRA:" << endl; 
	cout << " -----------------------------------" << endl; 
	cout << " * Cod Factura: "; cin >> codigo;
	
	Compras * temp = new Compras(); //Temporal solo para evaluaciones.
	if(!temp -> ValidarCodigo(codigo, registroCompra)){ //Evaluo si la factura no fue ingresada antes.
		cout << " * Descripcion: "; cin >> descripcion;
		cout << " -----------------------------------" << endl;
		cout << "   [Ingrese cero (0) para dejar de" << endl;
		cout << "    agregar articulos a la Compra]" << endl;
		cout << " -----------------------------------" << endl; 
		while(continuar){
			cout << " * Cod Producto: "; cin >> codigoProducto;
			if(codigoProducto != "0"){
				if(temp -> ValidarCodigo(codigoProducto, registroProducto)){//Si el codigo existe continuo
					cout << " * Cantidad: "; cin >> cantidadCompra;
					cout << " * Precio: "; cin >> precioCompra;
					cout << " -----------------------------------" << endl;
					Compras * newRegistro = new Compras(usuario, fecha, tipoTransaccion, codigo, descripcion, codigoProducto,
											 cantidadCompra, precioCompra, registroProducto);
					registroCompra.push_back(newRegistro);
				}else{
					cout << " -- " << endl;
					cout << " | ADVERTENCIA: Codigo no registrado." << endl;
					cout << " ------------------------------------" << endl;
				}
			}else{
				continuar = false;
				return;
			}
		}
	}else{
		cout << " -- " << endl;
		cout << " -> ADVERTENCIA: El registro ya existe. Dato no guardado." << endl;
		cout << " --------------------------------------------------------" << endl;
		system("pause");
	}
		
}
void Compras::BuscarCompra(string codigoCompra, vector <Compras *> compra, vector <Producto *> producto){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << " -- " << endl;
	cout << left << setw(15) << " | Cod Producto: " << left << setw(20) << " | Descripcion: " << left << setw(10) << " | Cantidad: ";
	cout << left << setw(10) << " | Precio: " << left << setw(10) << " | Total: " << left << setw(5) << " | Estado: " << endl;
	cout << " -- " << endl;
	for(int x=0; x < compra.size(); x++){		
		if(compra[x] -> GetCodigo() == codigoCompra){
			cout << left << " - " << setw(13) << compra[x] -> GetCodigoProducto();
			for(int i=0; i < producto.size(); i++){
				if(compra[x] -> GetCodigoProducto() == producto[i] -> GetCodigo()){
					cout << left << " - " << setw(18) << producto[i] -> GetDescripcion();		
				}
			}
			cout << left << " - " << setw(9) << compra[x] -> GetCantidadCompra();
			cout << left << " - " << setw(9) << fixed << setprecision(2) << compra[x] -> GetPrecioCompra();
			cout << left << " - " << setw(9) << fixed << setprecision(2) << compra[x] -> GetTotalCompra();
			cout << left << " - " << setw(4) << compra[x] -> GetEstadoCompra() << endl;
		}
	}
	cout << " ------------------------------------------------------------------------------------------" << endl;
}
void Compras::MostrarInfo(string codigoCompra, vector <Compras *> compra, vector <Producto *> producto){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << " -- " << endl;
	cout << left << setw(15) << " | Cod Producto: " << left << setw(20) << " | Descripcion: " << left << setw(10) << " | Cantidad: ";
	cout << left << setw(10) << " | Precio: " << left << setw(10) << " | Total: " << left << setw(5) << " | Estado: " << endl;
	cout << " -- " << endl;
	for(int x=0; x < compra.size(); x++){		
		if(compra[x] -> GetCodigo() == codigoCompra){
			cout << left << " - " << setw(13) << compra[x] -> GetCodigoProducto();
			for(int i=0; i < producto.size(); i++){
				if(compra[x] -> GetCodigoProducto() == producto[i] -> GetCodigo()){
					cout << left << " - " << setw(18) << producto[i] -> GetDescripcion();		
				}
			}
			cout << left << " - " << setw(9) << compra[x] -> GetCantidadCompra();
			cout << left << " - " << setw(9) << fixed << setprecision(2) << compra[x] -> GetPrecioCompra();
			cout << left << " - " << setw(9) << fixed << setprecision(2) << compra[x] -> GetTotalCompra();
			cout << left << " - " << setw(4) << compra[x] -> GetEstadoCompra() << endl;
		}
	}
	cout << " ------------------------------------------------------------------------------------------" << endl;
}

