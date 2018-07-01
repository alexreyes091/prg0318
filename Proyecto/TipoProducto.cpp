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
//Validaciones
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
//Acciones disponibles
void TipoProducto::BuscarTipoProducto(string codigoTipoProducto, vector <TipoProducto *> registroTipoProducto){
	char op;
	bool codEncontrado;
	//Busqueda de datos:
	while(true){
		for(int x=0; x < registroTipoProducto.size(); x++){
			if(codigoTipoProducto == registroTipoProducto[x] -> GetCodigo()){
				registroTipoProducto[x] -> MostrarInfo();
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
			cout << " * Buscar Codigo: "; cin >> codigoTipoProducto;
			cout << " -- " << endl;
			codEncontrado = false;
		}
	}
}
void TipoProducto::CargarTipoProducto(TipoProducto * newRegistro, vector <TipoProducto *> &registroTipoProducto){
	
	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroTipoProducto)){ //Validamos si ya existe el codigo
		registroTipoProducto.push_back(newRegistro);
		cout << " -- " << endl;
		cout << " -> REGISTRO AGREGADO EXITOSAMENTE." << endl;
		cout << " ----------------------------------" << endl;
		system("pause");
	}else{
		cout << " -- " << endl;
		cout << " -> ADVERTENCIA: El registro ya existe. Dato no guardado." << endl;
		cout << " --------------------------------------------------------" << endl;
		system("pause");
	}
}
void TipoProducto::EliminarTipoProducto(string codigoTipoProducto, vector <TipoProducto *> &registroTipoProducto){
	char op;
	bool codEncontrado = false;
	//Eliminacion de datos:
	while(true){
		for(int x=0; x < registroTipoProducto.size(); x++){
			if(codigoTipoProducto == registroTipoProducto[x] -> GetCodigo()){
				registroTipoProducto.erase(registroTipoProducto.begin() + x);
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
			cout << " * Buscar Codigo: "; cin >> codigoTipoProducto;
			cout << " -- " << endl;
			codEncontrado = false;
		}
	}
}
void TipoProducto::MostrarInfo(vector <TipoProducto * > registroTipoProducto){ 
	cout << "\n | REGISTRO TIPO PRODUCTOS:" << endl;
	cout << " ----------------------------"<< endl;
	cout << left << setw(10) << " | Codigo: " << left << setw(20) << " | Descripcion: " << endl;
	cout << " -- " << endl;
	for(int x=0; x < registroTipoProducto.size(); x++){
		cout << left << " - " << setw(10) << registroTipoProducto[x] -> GetCodigo();
		cout << left << " - " << setw(18) << registroTipoProducto[x] -> GetDescripcion() << endl;
	}
	cout << " --------------------------------------" << endl;
}
void TipoProducto::MostrarInfo(){ //Solo para fines de prueba
	Inventario::MostrarInfo();
}

