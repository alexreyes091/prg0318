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
//Validaciones
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
bool Bodega::ValidarCodigoProductoBodega(Compras * objProducto, vector <Bodega *> bodega){
	
	for(int x=0; x < bodega.size(); x++){
		if(bodega.size() != 0){		
			if(objProducto -> GetCodigoProducto() == bodega[x] -> GetCodigoProducto()){
				return true; //Retorna verdadero si lo encuentra
			}
		}
	}
	return false; //Retorna falso si no lo encuentra
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

//Acciones Posibles
void Bodega::BuscarProductoBodega(string codigoProducto, vector <Bodega *> bodega){
	char op;
	bool codEncontrado;
	//Busqueda de datos:
	while(true){
		for(int x=0; x < bodega.size(); x++){
			if(codigoProducto == bodega[x] -> GetCodigoProducto()){
				bodega[x] -> MostrarInfo();
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
		}
	}
	
}
void Bodega::CargarProducto(Compras * newCompra, Bodega * tipoBodega, vector <Bodega *> &bodega, vector <Compras *> &compra){
	//Carga de Datos desde las compras
	if(!newCompra -> GetEstadoCompra()){
		if(ValidarCodigoProductoBodega(newCompra, bodega) == false){
			Bodega * newRegistroBodega = new Bodega(tipoBodega -> GetCodigo(), tipoBodega -> GetDescripcion(),
											newCompra -> GetCodigoProducto(), newCompra -> GetCantidadCompra()); //Creamos el objeto para cargar el registro							
			bodega.push_back(newRegistroBodega); //Cargamos el registro a la bodega
			//delete newRegistroBodega;//Eliminamos el objeto creado. ***Eliminarlo al final del programa
			
			for(int x=0; x < compra.size(); x++){//Recorre los datos de compras 
				if(newCompra -> GetCodigoProducto() == compra[x] -> GetCodigoProducto()){
				}
			}
			cout << " -- " << endl;
			cout << " -> REGISTRO DE DATO COMPLETADO." << endl;
			cout << " -------------------------------" << endl;
			system("pause");			
		}else{
			for(int x=0; x < bodega.size(); x++){
				if(newCompra -> GetCodigoProducto() == bodega[x] -> GetCodigoProducto() &&  newCompra -> GetCantidadCompra() >= 0){
					bodega[x] -> SetExistencia(bodega[x] -> GetExistencia() +newCompra -> GetCantidadCompra());
					cout << " -- " << endl;
					cout << " -> ACTUALIZACION DE DATO COMPLETADO." << endl;
					cout << " ------------------------------------" << endl;
					system("pause");
					return;
				}
			}
			cout << " -- " << endl;
			cout << " | ADVERTENCIA:" << endl;
			cout << " --------------" << endl;
			cout << " * La cantidad a trasladar es invalida." << endl;
			system("pause");
		}
	}else{
		cout << " -- " << endl;
		cout << " -> ADVERTENCIA: Esta factura ya ha sido cargada." << endl; 
		cout << " ------------------------------------------------" << endl;
		system("pause");
	}
	
}/*
void Bodega::CargarProducto(Producto * newProducto, Bodega * tipoBodega, vector <Bodega *> &bodega){
	int cantidadExistencia = 50;
	//Transferencia de datos:
	
	if(ValidarCodigoProductoBodega(newProducto, bodega) == false){
		Bodega * newRegistroBodega = new Bodega(tipoBodega -> GetCodigo(), tipoBodega -> GetDescripcion(),
										newProducto -> GetCodigo(), cantidadExistencia); //Creamos el objeto para cargar el registro							
		bodega.push_back(newRegistroBodega); //Cargamos el registro a la bodega
		//delete newRegistroBodega;//Eliminamos el objeto creado. ***Eliminarlo al final del programa
		cout << " -- " << endl;
		cout << " -> REGISTRO DE DATO COMPLETADO." << endl;
		cout << " -------------------------------" << endl;
		system("pause");			
	}else{
		for(int x=0; x < bodega.size(); x++){
			if(newProducto -> GetCodigo() == bodega[x] -> GetCodigoProducto() && cantidadExistencia >= 0){
				bodega[x] -> SetExistencia(bodega[x] -> GetExistencia() + cantidadExistencia);
				cout << " -- " << endl;
				cout << " -> ACTUALIZACION DE DATO COMPLETADO." << endl;
				cout << " ------------------------------------" << endl;
				system("pause");
				return;
			}
		}
		cout << " -- " << endl;
		cout << " | ADVERTENCIA:" << endl;
		cout << " --------------" << endl;
		cout << " * La cantidad a trasladar es invalida." << endl;
		system("pause");
	}
}*/
void Bodega::EliminarProductoBodega(string codigoProducto, vector <Bodega *> &bodega){
	char op;
	bool codEncontrado = false;
	//Eliminacion de datos:
	while(true){
		for(int x=0; x < bodega.size(); x++){
			if(codigoProducto == bodega[x] -> GetCodigoProducto()){
				bodega.erase(bodega.begin() + x);
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
void Bodega::Transferir(Producto * objProducto, vector <Bodega *> &xBodega, Bodega * tipoBodega, vector <Bodega *> &yBodega){
	int cantidadTraslado; //Existencia de registro
	//En caso de que el producto exista en ambas bodegas, unicamente se actualziara su valor.
	if(ValidarCodigoProductoBodega(objProducto, xBodega) == true 
		&& ValidarCodigoProductoBodega(objProducto, yBodega) == true){
		for(int x=0; x < xBodega.size(); x++){ //Recorro nuevamente la bodega para preparar la actualizacion.
			if(objProducto -> GetCodigo() == xBodega[x] -> GetCodigoProducto()){		
			
				//Transferencia de datos:
				cout << " \n -- " << endl;
				cout << " | DETALLE DE ACTUALIZACION:" << endl;
				cout << " --------------------------- " << endl;
				cout << "  * De Bodega " << xBodega[x] -> GetDescripcion() << endl;
				cout << "  * A Bodega " << tipoBodega -> GetDescripcion() << endl;
				cout << " -- " << endl;
				cout << " | DETALLE DEL PRODUCTO:" << endl;
				cout << " -----------------------" << endl;
				cout << "  * Codigo Producto: " << objProducto -> GetCodigo() << endl;
				cout << "  * Bodega: " << xBodega[x] -> GetDescripcion() << endl; 
				cout << "  * Descripcion General: " << objProducto -> GetDescripcion() << endl;
				cout << "  * Cantidad a trasladar: "; cin >> cantidadTraslado;
				//Validamos la cantidad a trasladar
				if(ValidarCantidadTraslado(xBodega[x] -> GetExistencia(), cantidadTraslado)){
					//Como ya se valido que el producto existe en ambas bodegas, simplemente debemos de actualziar los datos.
					//Para ello debemos recorrer las bodegas y encontrar los articulos.
					if(objProducto -> GetCodigo() == xBodega[x] -> GetCodigoProducto()){
						xBodega[x] -> SetExistencia(xBodega[x] -> GetExistencia() - cantidadTraslado); //Actualizamos el valor en la bodega y
					}
					//Encontramos el producto en la bodega y
					for(int y=0; y < yBodega.size(); y++){
						if(objProducto -> GetCodigo() == yBodega[y] -> GetCodigoProducto()){
							yBodega[y] -> SetExistencia(yBodega[y] -> GetExistencia() + cantidadTraslado); //Actualizamos el valor en la bodega y
						}
					}	
					cout << " -- " << endl;
					cout << " -> TRANSFERENCIA COMPLETADA." << endl;
					cout << " ----------------------------" << endl;
					system("pause");
				}else{
					cout << " -- " << endl;
					cout << " | ADVERTENCIA:" << endl;
					cout << " --------------" << endl;
					cout << " * La cantidad a trasladar es invalida." << endl;
					system("pause");
				}
			}
		}
	}else if(ValidarCodigoProductoBodega(objProducto, xBodega) == true
		&& ValidarCodigoProductoBodega(objProducto, yBodega) == false){	//Valido si existe el codigo de producto.
		for(int x=0; x < xBodega.size(); x++){ //Recorro nuevamente la bodega para preparar la transferencia.
			if(objProducto -> GetCodigo() == xBodega[x] -> GetCodigoProducto()){
				
				//Transferencia de datos:
				cout << " \n -- " << endl;
				cout << " | DETALLE DE LA TRANSFERENCIA:" << endl;
				cout << " ------------------------------ " << endl;
				cout << "  * De Bodega " << xBodega[x] -> GetDescripcion() << endl;
				cout << "  * A Bodega " << tipoBodega -> GetDescripcion() << endl;
				cout << " -- " << endl;
				cout << " | DETALLE DEL PRODUCTO:" << endl;
				cout << " -----------------------" << endl;
				cout << "  * Codigo Producto: " << objProducto -> GetCodigo() << endl; 
				cout << "  * Bodega: " << xBodega[x] -> GetDescripcion() << endl; 
				cout << "  * Descripcion: " << objProducto -> GetDescripcion() << endl;
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
	cout << "\n | REGISTRO DE BODEGA:" << endl;
	cout << " ----------------------"<< endl;
	cout << left << setw(15) << " | Codigo: " << left << setw(20) << " | Descripcion: " << endl;
	cout << left << " - " << setw(12) << Inventario::GetCodigo();
	cout << left << " - " << setw(17) << Inventario::GetDescripcion() << endl;
	cout << " -- " << endl;
	cout << left << setw(15) << " | Cod Producto: " << setw(10) << " | Existencia: "<< endl;
	cout << left << " - " << setw(14) <<  this -> GetCodigoProducto();
	cout << left << " - " << setw(10)  << this -> GetExistencia() << endl;
}

void Bodega::MostrarInfo(vector <Bodega *> bodega, vector <Producto *> producto){
	cout << "\n | REGISTRO DE BODEGA:" << endl;
	cout << " -- " << endl;
	cout << left << setw(10) << " | Codigo: " << left << setw(20) << " | Descripcion: ";
	cout << left << setw(15) << " | Cod Producto: " << left << setw(20) << " | Descripcion: " << left << setw(15) << " | Existencia: "<< endl;
	cout << " -- " << endl;
	for(int x=0; x < bodega.size(); x++){
		cout << left << " - " << setw(8) << bodega[x] -> GetCodigo() << left << " - " << setw(18) << bodega[x] -> GetDescripcion();
		cout << left << " - " << setw(13) << bodega[x] -> GetCodigoProducto();
		for(int i=0; i < producto.size(); i++){
			if(bodega[x] -> GetCodigoProducto() == producto[i] -> GetCodigo()){
				cout << left << " - " << setw(18) << producto[i] -> GetDescripcion();		
			}
		}
		cout << left << " - " << setw(13) << bodega[x] -> GetExistencia() << endl;
	}
}

