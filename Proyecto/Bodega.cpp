#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Bodega.h"

using namespace std;

//constructores y destructores
Bodega::Bodega(){};
Bodega::~Bodega(){};
Bodega::Bodega(string codigo, string descripcion) : Inventario(codigo, descripcion){};//Crea simplemente las bodegas
Bodega::Bodega(string codigo, string descripcion, string codigoProducto, int existencia)//Crea el objeto que registrara en bodega.
				: Inventario(codigo, descripcion){
	this -> SetCodigoProducto(codigoProducto);
	this -> SetExistencia(existencia);
}
Bodega::Bodega(string codigo, string descripcion, string codigoProducto, int existencia, 
				vector <Producto *> registro) : Inventario(codigo, descripcion){
	this -> SetCodigoProducto(codigoProducto, registro);
	this -> SetExistencia(existencia);
}
Bodega::Bodega(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion,	string codigoProducto, 
				int existencia, vector <Producto *> registro) : Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion){
	this -> SetCodigoProducto(codigoProducto, registro);
	this -> SetExistencia(existencia);
}
//setters
void Bodega::SetCodigoProducto(string codigoProducto){
	//unicamente setea el codigo;
	this -> codigoProducto = codigoProducto; //Si es verdadero registra el codigo del tipo de producto.
}

void Bodega::SetCodigoProducto(string codigoProducto, vector <Producto *> registro){
	//se evalua si el codigo del producto existe para enlazar los modulos
	
	Producto * newRegistro = new Producto; //Creo un objeto vacio solo para poder buscar el codigo en el registro de tipos de productos
	
	if(newRegistro -> ValidarCodigo(codigoProducto, registro)){
		this -> codigoProducto = codigoProducto; //Si es verdadero registra el codigo del tipo de producto.
		this -> validarCodigoProducto = true;
	}else{
		this -> validarCodigoProducto = false;
	}
	
	delete newRegistro;
}

void Bodega::SetExistencia(int existencia){
	this -> existencia = existencia;
}

//getters
string Bodega::GetCodigoProducto(){
	return this -> codigoProducto;
}
bool Bodega::GetValidarCodigoProducto(){
	return this -> validarCodigoProducto;
}
int Bodega::GetExistencia(){
	return this -> existencia;
}
//otros metodos
bool Bodega::ValidarCodigo(string codigo, vector <Producto *> newRegistro){ //Valida si un codigo ya existe

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

bool Bodega::ValidarCodigoProductoBodega(Bodega * objBodega, vector <Bodega *> bodega){
		
	for(int x=0; x < bodega.size(); x++){
		if(bodega.size() != 0){		
			if(objBodega -> GetCodigoProducto() == bodega[x] -> GetCodigoProducto()){
				return true; //Retorna verdadero si lo encuentra
			}else{	
				return false;
			}
		}
		return false; //Retorna falso si no lo encuentra
	}
}
bool Bodega::ValidarCodigoProductoBodega(Producto * objProducto, vector <Bodega *> bodega){
		
	for(int x=0; x < bodega.size(); x++){
		if(bodega.size() != 0){		
			if(objProducto -> GetCodigo() == bodega[x] -> GetCodigoProducto()){
				return true; //Retorna verdadero si lo encuentra
			}
		}
	}
	return false; //Retorna falso si no lo encuentra
}

//Validar si la trasnferencia es mayor que cero:
bool Bodega::ValidarCantidadTraslado(int existencia, int transferencia){
	
	if((existencia - transferencia) < 0 || transferencia < 0){
		return false; //Retorna falso si es menor que cero
	}else{
		return true; // Retorna verdadero si es mayor o igual que cero
	}
}


void Bodega::CargarProducto(Producto * newProducto, Bodega * tipoBodega, vector <Bodega *> &bodega){
	int cantidadExistencia = 50;
	
	if(ValidarCodigoProductoBodega(newProducto, bodega) == false){
			
		Bodega * newRegistroBodega = new Bodega(tipoBodega -> GetCodigo(), tipoBodega -> GetDescripcion(),
										newProducto -> GetCodigo(), cantidadExistencia); //Creamos el objeto para cargar el registro
										
		bodega.push_back(newRegistroBodega); //Cargamos el registro a la bodega
		
		//delete newRegistroBodega;//Eliminamos el objeto creado. ***Eliminarlo al final del programa
		
		cout << "El producto se registro con exito." << endl;				
	}else{
		cout << "El producto ya existe." << endl;
	}
}

void Bodega::Transferir(Producto * objProducto, vector <Bodega *> &xBodega, Bodega * tipoBodega, vector <Bodega *> &yBodega){
	int cantidadTraslado;
	//En caso de que el producto exista en ambas bodegas, unicamente se actualziara su valor.
	if(ValidarCodigoProductoBodega(objProducto, yBodega) == true 
		&& ValidarCodigoProductoBodega(objProducto, xBodega) == true){

		for(int x=0; x < xBodega.size(); x++){ //Recorro nuevamente la bodega para preparar la transferencia.
			if(objProducto -> GetCodigo() == xBodega[x] -> GetCodigoProducto()){
				
				if(ValidarCantidadTraslado(xBodega[x] -> GetExistencia(), cantidadTraslado)){
					xBodega[x] -> SetExistencia((xBodega[x] -> GetExistencia() - cantidadTraslado)); //Actualizamos el valor en la bodega x
					
					for(int y=0; y < yBodega.size(); y++){
						if(objProducto -> GetCodigo() == yBodega[y] -> GetCodigoProducto()){
							yBodega[y] -> SetExistencia(yBodega[y] -> GetExistencia() + cantidadTraslado); //Actualizamos el valor en la bodega y
						}
					}
				}
								
				
			}
		}
						
		
		
		return;			
	}	
	
	if(ValidarCodigoProductoBodega(objProducto, xBodega) == true){	//Valido si existe el codigo de producto.
		for(int x=0; x < xBodega.size(); x++){ //Recorro nuevamente la bodega para preparar la transferencia.
			if(objProducto -> GetCodigo() == xBodega[x] -> GetCodigoProducto()){
				
				//Transferencia de datos:
				cout << " \n -- " << endl;
				cout << " | DETALLE DE LA TRANSFERENCIA:" << endl;
				cout << " ------------------------------ " << endl;
				cout << "  * De: " << xBodega[x] -> GetDescripcion() << endl;
				cout << "  * A: " << tipoBodega -> GetDescripcion() << endl;
				cout << " -- " << endl;
				cout << " | DETALLE DEL PRODUCTO:" << endl;
				cout << " -----------------------" << endl;
				cout << "  * Codigo Producto: " << objProducto -> GetCodigo() << "\t* Bodega: " << xBodega[x] -> GetDescripcion() << endl; 
				cout << "  * Descripcion General: " << objProducto -> GetDescripcion() << endl;
				cout << "  * Cantidad a trasladar: "; cin >> cantidadTraslado;
				
				if(ValidarCantidadTraslado(xBodega[x] -> GetExistencia(), cantidadTraslado)){
					Bodega * temp = new Bodega(xBodega[x] -> GetCodigo(), tipoBodega -> GetDescripcion(), 
										xBodega[x] -> GetCodigoProducto(), cantidadTraslado); //Trasladamos el producto a la bodega y
					yBodega.push_back(temp); //Lo agregamos de cero.
				
					xBodega[x] -> SetExistencia((xBodega[x] -> GetExistencia() - cantidadTraslado)); //Actualizamos el valor en la bodega x
					
					cout << " -- " << endl;
					cout << " -> TRANSFERENCIA COMPLETADA." << endl;
					cout << " ----------------------------" << endl;
				}else{
					cout << " -- " << endl;
					cout << " | ADVERTENCIA:" << endl;
					cout << " --------------" << endl;
					cout << " * La cantidad a trasladar es invalida." << endl;
				}
				system("pause");
				
				
				
			}
		}
	}
}

void Bodega::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
	cout << setw(23) << "Codigo Producto: " << this -> GetCodigoProducto() << endl;
	cout << setw(23) << "Existencia: " << this -> GetExistencia() << endl;
}

