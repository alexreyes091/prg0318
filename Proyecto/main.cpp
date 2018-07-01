#include <iostream>
#include <string>

#include "Compras.h"
#include "Bodega.h"
#include "Inventario.h"
#include "Producto.h"
#include "TipoProducto.h"

using namespace std;
//Prototipos de Funcion

/*
void CargarRegistroInventario(Inventario * newRegistro);
void CargarRegistroInventario(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion);
*/

//Registro tipos de Productos.

//Control de Compras
void CargarRegistroCompra(string, string, string);
void BuscarCodigoCompra(string);
void EliminarcodigoCompra();
void MostrarRegistroCompra();

//Control de Bodegas
void CargarRegistroBodega(); //Cargo las compras a la bodega principal completa
void CargarRegistroBodega(Compras *); //Cargo las compras a la bodega principal de forma individual
void CargarRegistroTipoBodega(string codigo, string descripcion); //Registro el tipo de bodega creado, por defecto 2
void BuscarCodigoBodega(vector <Bodega *>); //Busco existencia dentro de las bodegas.
void EliminarCodigoBodega(vector <Bodega *> &); //Elimino datos dentro de la bodega.
void MostrarRegistroBodega(vector <Bodega *>); //Muestro el listado de todos los datos agregados a la Bodega.
void TransferirBodegaBodega(Producto *, vector <Bodega *> &, Bodega *, vector <Bodega *> &); //Transfiere de una bodega a otra.

//Control de Productos
void CargarRegistroProducto(string, string, string, string, string, string, double, string, vector <TipoProducto *>); //Registra Productos
void CargarRegistroTipoProducto(string, string, string, string, string); //Registra tipos de Producto disponibles
void BuscarCodigoProducto(); //Busca el detalle de los productos.
void EliminarCodigoProducto(); //Elimina algun producto.
void MostrarProductos(); //Muestra el listado de todos los productos agregados.


//Variables globales
//Vectores donde almacenaremos los datos
//vector <Inventario * > registroInventario;
vector <Bodega *> registroTipoBodega;
vector <Bodega *> bodegaEnfermeria;
vector <Bodega *> bodegaPrincipal;
vector <Compras *> registroCompra;
vector <TipoProducto * > registroTipoProducto; 
vector <Producto * > registroProducto;


int main() {
	CargarRegistroTipoBodega("BP01", "Principal"); //Creamos el tipo de Bodega Principal
	CargarRegistroTipoBodega("BE01", "Enfermeria"); //creamos el tipo de Bodega Enfermeria
	CargarRegistroTipoProducto("Areyes091", "2018/06/11", "Inventario", "KCR508", "Agujas Siliconadas");
	CargarRegistroTipoProducto("Areyes091", "2018/06/11", "Inventario", "KCR505", "Agujas Cromadas");
	CargarRegistroProducto("Areyes091", "2018/06/11", "Inventario", "G1511", "Droxemorfina", "Carel", 10.50, "KCR505", registroTipoProducto);
	CargarRegistroProducto("Areyes091", "2018/06/11", "Inventario", "G1512", "Jeringas", "Carel", 5.30, "KCR505", registroTipoProducto);
	/*
	MostrarProductos();
	EliminarCodigoProducto();
	MostrarProductos();
	*/
	CargarRegistroCompra("Areyes091", "2018/06/11", "Inventario");
	CargarRegistroCompra("Areyes091", "2018/06/11", "Inventario");
	BuscarCodigoCompra("F1001");
	BuscarCodigoCompra("F1002");
	MostrarRegistroCompra();
	
	CargarRegistroBodega();
	/*
	for(int i=0; i < registroCompra.size(); i++){
		registroCompra[i] -> MostrarInfo();
	}*/
		
	MostrarRegistroBodega(bodegaPrincipal);
//	EliminarCodigoBodega(bodegaPrincipal);
//	BuscarCodigoBodega(bodegaPrincipal);
//	MostrarRegistroBodega(bodegaPrincipal);
	
	TransferirBodegaBodega(registroProducto[0], bodegaPrincipal, registroTipoBodega[1], bodegaEnfermeria);
	TransferirBodegaBodega(registroProducto[0], bodegaPrincipal, registroTipoBodega[1], bodegaEnfermeria);
	
	//newRegistro -> MostrarInfo(bodegaPrincipal, registroProducto);
	
	
	for(int i=0; i < bodegaPrincipal.size(); i++){
		bodegaPrincipal[i] -> MostrarInfo();
	}
	
	for(int i=0; i < bodegaEnfermeria.size(); i++){
		bodegaEnfermeria[i] -> MostrarInfo();
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

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Control de registro para Compras
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Funcion para registrar unicamente datos de compras
void CargarRegistroCompra(string usuario, string fecha, string tipoTransaccion){
	Compras * temp = new Compras(); //Registramos un objeto
	temp -> CargarCompra(usuario, fecha, tipoTransaccion, registroProducto, registroCompra); //Cargamos a Bodega
	delete temp; //Elimino el registro temporal
}
//Funcion para buscar facturas
void BuscarCodigoCompra(string codigoCompra){
	for(int x=0; x < registroCompra.size(); x++){
		if(codigoCompra == registroCompra[x] -> GetCodigo()){
			registroCompra[x] -> BuscarCompra(codigoCompra, registroCompra, registroProducto);
			return;
		}
	}
}
//Funcion para listar todas las facturas
void MostrarRegistroCompra(){
	string temp = "temporal";
	for(int x=0; x < registroCompra.size(); x++){
		if(temp !=  registroCompra[x] -> GetCodigo()){
			registroCompra[x] -> BuscarCompra(registroCompra[x] -> GetCodigo(), registroCompra, registroProducto);
		}
		temp =  registroCompra[x] -> GetCodigo();
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Control de registro de Bodegas
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Funcion para registrar unicamente los datos de Tipos de Bodegas
void CargarRegistroTipoBodega(string codigo, string descripcion){
	Bodega * newRegistro = new Bodega(codigo, descripcion); //Registramos el objeto
	registroTipoBodega.push_back(newRegistro); //Lo cargamos al vector
}
//Funcion para registrar unicamente los datos de productos a la Bodega
void CargarRegistroBodega(){
	for(int x=0; x < registroCompra.size(); x++){
		if(!registroCompra[x] -> GetEstadoCompra()){
			CargarRegistroBodega(registroCompra[x]); //Cargo los que no estan procesados	
		}
	}
	for(int x=0; x < registroCompra.size(); x++){
		if(!registroCompra[x] -> GetEstadoCompra()){
			registroCompra[x] -> SetEstadoCompra(true); //Pasa la compra a procesada	
		}
	}
}
void CargarRegistroBodega(Compras * objCompra){
	Bodega * temp = new Bodega(); //Registramos un objeto
	temp -> CargarProducto(objCompra, registroTipoBodega[0], bodegaPrincipal, registroCompra); //Cargamos a Bodega
	delete temp; //Elimino el registro temporal
}
void BuscarCodigoBodega(vector <Bodega *> registroBodega){
	//Buscar Codigo en Bodega
	string codigoProducto;
	cout << " -- " << endl;
	cout << " | BUSCAR REGISTRO EN BODEGA." << endl; 
	cout << " ----------------------------" << endl;
	cout << " * Buscar Codigo: "; cin >> codigoProducto;
	//Creamos un objeto temporal para utilizar la funcion buscar
	Bodega * temp = new Bodega();
	//Mandamos el contenedor de productos
	temp -> BuscarProductoBodega(codigoProducto, registroBodega);
	//Eliminamos el dato temporal
	delete temp;
}
void EliminarCodigoBodega(vector <Bodega *> &registroBodega){
	string codigoProducto;
	cout << " -- " << endl;
	cout << " | ELIMINAR REGISTRO DE BODEGA." << endl; 
	cout << " ------------------------------" << endl;
	cout << " * Buscar Codigo: "; cin >> codigoProducto;
	//Creamos un objeto temporal para utilizar la funcion buscar
	Bodega * temp = new Bodega();
	//Mandamos el contenedor de productos
	temp -> EliminarProductoBodega(codigoProducto, registroBodega);
	//Eliminamos el dato temporal
	delete temp;
}
void MostrarRegistroBodega(vector <Bodega *> registroBodega){
	//Creamos un objeto temporal para utilizar la funcion mostrar
	Bodega * temp = new Bodega();
	//Mandamos el contenedor de productos en bodega
	temp -> MostrarInfo(registroBodega, registroProducto);
	//Eliminamos el dato temporal
	delete temp;
}
void TransferirBodegaBodega(Producto * objProducto, vector <Bodega *> &xBodega, Bodega * tipoBodega, vector <Bodega *> &yBodega){
	//Creamos un objeto temporal para utilizar la funcion mostrar
	Bodega * temp = new Bodega();
	//Mandamos el contenedor de productos en bodega
	temp -> Transferir(objProducto, xBodega, tipoBodega, yBodega);
	//Eliminamos el dato temporal
	delete temp;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Control de registros de Productos.
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Funcion para registrar nuevos productos
void CargarRegistroProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, 
							string marca, double precio, string codigoTipoProducto, vector <TipoProducto *> registro){
	//Creamos un objeto para enviar el dato a cargarlo.
	Producto * newRegistro = new Producto(usuario, fecha, tipoTransaccion, codigo, descripcion, marca, precio, codigoTipoProducto, registro); //Registramos el objeto
	//Enviamos el Objeto con el contenedor de productos.
	newRegistro -> CargarProducto(newRegistro, registroProducto);
}
//Funcion para registrar unicamente datos de Tipos de Productos
void CargarRegistroTipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion){
	
	TipoProducto * newRegistro = new TipoProducto(usuario, fecha, tipoTransaccion, codigo, descripcion); //Registramos el objeto

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
//funcion para buscar codigos de productos
void BuscarCodigoProducto(){
	string codigoProducto;
	cout << " -- " << endl;
	cout << " | BUSCAR REGISTRO DE PRODUCTOS." << endl; 
	cout << " -------------------------------" << endl;
	cout << " * Buscar Codigo: "; cin >> codigoProducto;
	//Creamos un objeto temporal para utilizar la funcion buscar
	Producto * temp = new Producto();
	//Mandamos el contenedor de productos
	temp -> BuscarProducto(codigoProducto, registroProducto);
	//Eliminamos el dato temporal
	delete temp;
}
void EliminarCodigoProducto(){
	string codigoProducto;
	cout << " -- " << endl;
	cout << " | ELIMINAR REGISTRO DE PRODUCTOS." << endl; 
	cout << " ---------------------------------" << endl;
	cout << " * Buscar Codigo: "; cin >> codigoProducto;
	//Creamos un objeto temporal para utilizar la funcion buscar
	Producto * temp = new Producto();
	//Mandamos el contenedor de productos
	temp -> EliminarProducto(codigoProducto, registroProducto);
	//Eliminamos el dato temporal
	delete temp;
}
void MostrarProductos(){
	//Creamos un objeto temporal para utilizar la funcion mostrar
	Producto * temp = new Producto();
	//Mandamos el contenedor de productos
	temp -> MostrarInfo(registroProducto);
	//Eliminamos el dato temporal
	delete temp;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------



