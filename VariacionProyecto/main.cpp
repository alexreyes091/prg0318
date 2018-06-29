#include <iostream>
#include <string>

#include "Inventario.h"
#include "Producto.h"
#include "TipoProducto.h"
#include "BodegaPrincipal.h"
#include "BodegaEnfermeria.h"

using namespace std;
//Prototipos de Funcion

/*
void CargarRegistroInventario(Inventario * newRegistro);
void CargarRegistroInventario(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion);
*/

//Registro tipos de Productos.
void CargarRegistroTipoProducto(string, string, string, string, string);
void CargarRegistroProducto(string, string, string, string, string, string, double, string, vector <TipoProducto *>);

//Variables globales
//Vectores donde almacenaremos los datos
//vector <Inventario * > registroInventario;
vector <TipoProducto * > registroTipoProducto; 
vector <Producto * > registroProducto;
vector <BodegaPrincipal *> bodegaPrincipal;
vector <BodegaEnfermeria *> bodegaEnfermeria;

int main() {
	
	CargarRegistroTipoProducto("Areyes091", "2018/06/11", "Inventario", "KCR508", "Agujas Siliconadas");
	CargarRegistroTipoProducto("Areyes091", "2018/06/11", "Inventario", "KCR505", "Agujas Cromadas");
	CargarRegistroProducto("Areyes091", "2018/06/11", "Inventario", "G151260", "Droxemorfina", "Carel", 10.50, "KCR505", registroTipoProducto);
	CargarRegistroProducto("Areyes091", "2018/06/11", "Inventario", "G151260", "Droxemorfina", "Carel", 15.30, "KCR505", registroTipoProducto);
	
	BodegaPrincipal * newregistro = new BodegaPrincipal("BP01", "Bodega Principal", "G151260", 250, registroProducto);
	
	newregistro -> Transferencia(newregistro, bodegaPrincipal, bodegaEnfermeria);
	
	for(int i=0; i < bodegaPrincipal.size(); i++){
		bodegaPrincipal[i] -> MostrarInfo();
	}
	
	
	/*
	CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR0127", "Albondigas");
	CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR0127", "Albondigas");
	
	Inventario * newRegistro1 = new Inventario("Areyes091", "2018/06/11", "Inventario", "ASR0126", "Albondigas");
	CargarRegistroInventario(newRegistro1);
	Inventario * newRegistro2 = new Inventario("Areyes091", "2018/06/11", "Inventario", "ASR0126", "Albondigas");
	CargarRegistroInventario(newRegistro2);
	*/
	
	/*
	for(int i=0; i < registroProducto.size(); i++){
		registroProducto[i] -> MostrarInfo();
	}
	
	for(int i=0; i < registroTipoProducto.size(); i++){
		registroTipoProducto[i] -> MostrarInfo();
	}*/
	
	
	//CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR00127", "Albondigas", registroInventario);	
	//CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR00125", "Albondigas", registroInventario);
	//CargarRegistroInventario("Areyes091", "2018/06/11", "Inventario", "ASR00125", "Albondigas", registroInventario);
	
	return 0;
}
/*
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

//Otra forma de cargar los objetos
void CargarRegistroInventario(Inventario * newRegistro){
	
	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroInventario)){
		registroInventario.push_back(newRegistro);
		cout << "Registro guardado con exito" << endl;
	}else{
		cout << "Advertencia: El registro ya existe, por lo cual el dato no fue guardado" << endl;
	}
}
*/

//Funcion para registrar unicamente datos de Tipos de Productos
void CargarRegistroTipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion){
	
	TipoProducto * newRegistro = new TipoProducto(usuario, fecha, tipoTransaccion, codigo, descripcion); //Registramos el objeto

	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroTipoProducto)){ //Validamos si ya existe el codigo
		registroTipoProducto.push_back(newRegistro);
		cout << "Registro guardado con exito" << endl;
	}else{
		cout << "Advertencia: El registro ya existe, por lo cual el dato no fue guardado" << endl;
	}
}
//Funcion para registrar nuevos productos
void CargarRegistroProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, 
							string marca, double precio, string codigoTipoProducto, vector <TipoProducto *> registro){
	
	Producto * newRegistro = new Producto(usuario, fecha, tipoTransaccion, codigo, descripcion, marca, precio, codigoTipoProducto, registro); //Registramos el objeto

	if(!newRegistro -> ValidarCodigo(newRegistro -> GetCodigo(), registroProducto)){ //Validamos si ya existe el codigo
		if(newRegistro -> GetValidarCodigoTipoProducto()){
			registroProducto.push_back(newRegistro);
			cout << "Registro guardado con exito" << endl;
		}else{
			cout << "Advertencia: El tipo de producto ingresado no existe." << endl;
			cout << " -> Ingrese al modulo Tipo de Productos, en caso de que necesite registrar el codigo: " << codigo <<endl;
		}
	}else{
		cout << "Advertencia: El registro ya existe, por lo cual el dato no fue guardado." << endl;
	}
}
