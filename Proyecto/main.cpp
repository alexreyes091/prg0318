#include <iostream>
#include <string>

#include "Inventario.h"
#include "TipoProducto.h"

using namespace std;
//Prototipos de Funcion
void CargarRegistroInventario(Inventario * newRegistro);
void CargarRegistroInventario(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion);

//Registro tipos de Productos.
void CargarRegistroTipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string tipoProducto);

//Variables globales
vector <Inventario * > registroInventario;
vector <TipoProducto * > registroTipoProducto;

int main() {
	
	CargarRegistroTipoProducto("Areyes091", "2018/06/11", "Inventario", "KCR503", "Agujas Siliconadas", "Agujas");
	CargarRegistroTipoProducto("Areyes091", "2018/06/11", "Inventario", "KCR505", "Agujas Cromadas", "Agujas");
	
	/*
	CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR0127", "Albondigas");
	CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR0127", "Albondigas");
	
	Inventario * newRegistro1 = new Inventario("Areyes091", "2018/06/11", "Inventario", "ASR0126", "Albondigas");
	CargarRegistroInventario(newRegistro1);
	Inventario * newRegistro2 = new Inventario("Areyes091", "2018/06/11", "Inventario", "ASR0126", "Albondigas");
	CargarRegistroInventario(newRegistro2);
	*/
	
	
	for(int i=0; i < registroTipoProducto.size(); i++){
		registroTipoProducto[i] -> MostrarInfo();
	}
	
	
	//CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR00127", "Albondigas", registroInventario);	
	//CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR00125", "Albondigas", registroInventario);
	//CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR00125", "Albondigas", registroInventario);
	
	return 0;
}
//Funcion para registrar unicamente datos sencillos de Inventarios - Prueba
void CargarRegistroInventario(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion){
	
	Inventario * newRegistro = new Inventario(usuario, fecha, tipoTransaccion, codigo, descripcion); //Registramos el objeto
	
	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroInventario)){ //Validamos si ya existe el codigo
		registroInventario.push_back(newRegistro);
		cout << "Registro guardado con exito" << endl;
	}else{
		cout << "Advertencia: El registro ya existe, por lo cual el dato no fue guardado" << endl;
	}
}

//Funcion para registrar unicamente datos de Tipos de Productos
void CargarRegistroTipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, string tipoProducto){
	
	TipoProducto * newRegistro = new TipoProducto(usuario, fecha, tipoTransaccion, codigo, descripcion, tipoProducto); //Registramos el objeto

	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroTipoProducto)){ //Validamos si ya existe el codigo
		registroTipoProducto.push_back(newRegistro);
		cout << "Registro guardado con exito" << endl;
	}else{
		cout << "Advertencia: El registro ya existe, por lo cual el dato no fue guardado" << endl;
	}
}

//Otra forma de cargar los objetos
void CargarRegistroInventario(Inventario * newRegistro){
	
	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroInventario)){
		registroInventario.push_back(newRegistro);
		cout << "Registro guardado con exito" << endl;
	}else{
		cout << "Advertencia: El registro ya existe, por lo cual el dato no fue guardado" << endl;
	}
}
