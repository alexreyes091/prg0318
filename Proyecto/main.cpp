#include <iostream>
#include <string>

#include "Colores.h"
#include "Compras.h"
#include "Bodega.h"
#include "Inventario.h"
#include "Producto.h"
#include "TipoProducto.h"

using namespace std;
//----------------------------------------------------------------------------------------------------------------------
//PROTOTIPOS DE FUNCION
//----------------------------------------------------------------------------------------------------------------------
void InicioSistema();
void MenuPrincipal();
void MenuInventario();
void MenuInventarioProductos(); 
void MenuInventarioTipoProductos(); 
void MenuInventarioCompras(); 
void MenuEnfermeria();
void MenuEnfermeriaBodega();
/*
void CargarRegistroInventario(Inventario * newRegistro);
void CargarRegistroInventario(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion);
*/

//Registro tipos de Productos.

//Control de Compras
void CargarRegistroCompra();
void BuscarCodigoCompra();
//void EliminarCodigoCompra();
void MostrarRegistroCompra();

//Control de Bodegas
void CargarRegistroBodega(); //Cargo las compras a la bodega principal completa
void CargarRegistroBodega(Compras *); //Cargo las compras a la bodega principal de forma individual
void CargarRegistroTipoBodega(string codigo, string descripcion); //Registro el tipo de bodega creado, por defecto 2
void BuscarCodigoBodega(vector <Bodega *>); //Busco existencia dentro de las bodegas.
void EliminarCodigoBodega(vector <Bodega *> &); //Elimino datos dentro de la bodega.
void MostrarRegistroBodega(vector <Bodega *>); //Muestro el listado de todos los datos agregados a la Bodega.
void TransferirBodegaBodega(vector <Bodega *> &, Bodega *, vector <Bodega *> &); //Transfiere de una bodega a otra.


//Control de Productos
void AgregarProducto();
void CargarRegistroProducto(string, string, string, string, string, string, double, string, vector <TipoProducto *>); //Registra Productos
void BuscarCodigoProducto(); //Busca el detalle de los productos.
void EliminarCodigoProducto(); //Elimina algun producto.
void MostrarProductos(); //Muestra el listado de todos los productos agregados.

//Control de Tipos de Producto
void AgregarTipoProducto();
void CargarRegistroTipoProducto(string, string, string, string, string); //Registra tipos de Producto disponibles
void BuscarTipoProducto();
void EliminarTipoProducto();
void MostrarTipoProducto();

//Variables globales
//Vectores donde almacenaremos los datos
//vector <Inventario * > registroInventario;
RegistroBase * registroBase = new RegistroBase();
vector <Bodega *> registroTipoBodega;
vector <Bodega *> bodegaEnfermeria;
vector <Bodega *> bodegaPrincipal;
vector <Compras *> registroCompra;
vector <TipoProducto * > registroTipoProducto; 
vector <Producto * > registroProducto;


int main() {
	color(0,15);
	//variables
	int op;
	//registro inicial
	InicioSistema(); //Registro de datos por inicio.
	system("cls");
	CargarRegistroTipoBodega("BP01", "Principal"); //Creamos el tipo de Bodega Principal
	CargarRegistroTipoBodega("BE01", "Enfermeria"); //creamos el tipo de Bodega Enfermeria
	//Menu Principal
	MenuPrincipal();
	cin >> op;

	while(op != -1){
		switch(op){
			case 1:
				system("cls");
				MenuInventario(); //Carga de Menu
				cin >> op; //Opcion de Menu
				while(op != -1){
					switch(op){
						case 1:
							system("cls");
							MenuInventarioProductos(); //Carga de Menu
							cin >> op; //Opcion de Menu
							while(op != -1){
								switch(op){
									case 1:
										system("cls");
										AgregarProducto();
										break;
									case 2:
										system("cls");
										BuscarCodigoProducto();
										break;
									case 3:
										system("cls");
										EliminarCodigoProducto();
										break;
									case 4:
										system("cls");
										MostrarProductos();
										system("pause");
										break;
									case -1:
										break;
									default:
										color(0,11);
										cout << " | ADVERTENCIA: Opcion no valida." << endl;
										color(0,15);
										system("pause");
										system("cls");
										break;
								}
								system("cls");
								MenuInventarioProductos(); //Carga de Menu
								cin >> op; //Opcion de Menu
							}
							system("cls");
							break;
						case 2:
							system("cls");
							MenuInventarioTipoProductos(); //Carga de Menu
							cin >> op; //Opcion de Menu
							while(op != -1){
								switch(op){
									case 1:
										system("cls");
										AgregarTipoProducto();
										break;
									case 2:
										system("cls");
										BuscarTipoProducto();
										break;
									case 3:
										system("cls");
										EliminarTipoProducto();
										break;
									case 4:
										system("cls");
										MostrarTipoProducto();
										system("pause");
										break;
									case -1:
										break;
									default:
										color(0,11);
										cout << " | ADVERTENCIA: Opcion no valida." << endl;
										color(0,15);
										system("pause");
										system("cls");
										break;
								}
								system("cls");
								MenuInventarioTipoProductos(); //Carga de Menu
								cin >> op; //Opcion de Menu
							}
							system("cls");
							break;
						case 3:
							system("cls");
							MenuInventarioCompras(); //Carga de Menu
							cin >> op; //Opcion de Menu
							while(op != -1){
								switch(op){
									case 1:
										system("cls");
										CargarRegistroCompra();
										break;
									case 2:
										system("cls");
										BuscarCodigoCompra();
										system("pause");
										break;
									case 3:
										system("cls");
										MostrarRegistroCompra();
										system("pause");
										break;
									case -1:
										break;
									default:
										color(0,11);
										cout << " | ADVERTENCIA: Opcion no valida." << endl;
										color(0,15);
										system("pause");
										system("cls");
										break;
								}
								system("cls");
								MenuInventarioCompras(); //Carga de Menu
								cin >> op; //Opcion de Menu
							}
							system("cls");
							break;
						case -1:
							break;
						default:
							color(0,11);
							cout << " | ADVERTENCIA: Opcion no valida." << endl;
							color(0,15);
							system("pause");
							system("cls");
							break;
					}
					MenuInventario(); //Carga de Menu
					cin >> op; //Opcion de Menu
				}
				system("cls");
				break;
			case 2:
				system("cls");
				MenuEnfermeria(); //Carga de Menu
				cin >> op; //Opcion de Menu
				while(op != -1){
					switch(op){
						case 1:
							system("cls");
							MenuEnfermeriaBodega(); //Carga de Menu
							cin >> op; //Opcion de Menu
							while(op != -1){
								switch(op){
									case 1:
										system("cls");
										CargarRegistroBodega(); //Cada vez que salga de Compras, que e registre a Bodega
										break;
									case 2:
										system("cls");
										cout << endl;
										cout << " |SELECCIONE LA BODEGA CON LA QUE DESEA BUSCAR EL PRODUCTO " << endl;
										cout << " --------------------------------------------------------- " << endl;
										cout << " | [01] -> Bodega Principal | [02] -> Bodega Enfermeria  | " << endl;
										cout << " ---------------------------------------------------------" << endl;
										cout << " | OPCION: "; cin >> op;
										while(true){
											if(op == 1){
												BuscarCodigoBodega(bodegaPrincipal);	
												break;
											} if(op == 2){
												BuscarCodigoBodega(bodegaEnfermeria);	
												break;
											}else{
												cout << " -- " << endl;
												cout << " | ADVERTENCIA: Esta opcion no es valida." << endl;
												cout << " -- " << endl;
												system("puse");
											}
										}
										system("cls");
										system("puse");
										break;
									case 3:
										system("cls");
										cout << endl;
										cout << " |SELECCIONE LA OPCION DE BODEGA PARA TRANSFERENCIA " << endl;
										cout << " ---------------------------------------------------" << endl;
										cout << " | [01] -> Bodega Principal a Bodega Enfermeria    |" << endl;
										cout << " | [02] -> Bodega Enfermeria a Bodega Principal    |" << endl;
										cout << " ---------------------------------------------------" << endl;
										cout << " | OPCION: "; cin >> op;
										while(true){
											if(op == 1){
												TransferirBodegaBodega( bodegaPrincipal, registroTipoBodega[0], bodegaEnfermeria);	
												break;
											} if(op == 2){
												TransferirBodegaBodega( bodegaEnfermeria, registroTipoBodega[1], bodegaPrincipal);	
												break;
											}else{
												cout << " -- " << endl;
												cout << " | ADVERTENCIA: Esta opcion no es valida." << endl;
												cout << " -- " << endl;
												system("puse");
											}
										}
										//system("cls");
										system("puse");
										break;
									case 4:
										system("cls");
										cout << endl;
										cout << " |SELECCIONE LA BODEGA PARA VISUALIZAR LOS PRODUCTOS " << endl;
										cout << " --------------------------------------------------------- " << endl;
										cout << " | [01] -> Bodega Principal | [02] -> Bodega Enfermeria  | " << endl;
										cout << " ---------------------------------------------------------" << endl;
										cout << " | OPCION: "; cin >> op;
										while(true){
											if(op == 1){
												MostrarRegistroBodega(bodegaPrincipal);	
												break;
											} if(op == 2){
												MostrarRegistroBodega(bodegaEnfermeria);	
												break;
											}else{
												cout << " -- " << endl;
												cout << " | ADVERTENCIA: Esta opcion no es valida." << endl;
												cout << " -- " << endl;
											}
										}
										//system("cls");
										system("pause");
										break;
									case -1:
										break;
									default:
										color(0,11);
										cout << " | ADVERTENCIA: Opcion no valida." << endl;
										color(0,15);
										system("pause");
										system("cls");
										break;
								}
								system("cls");
								MenuEnfermeriaBodega(); //Carga de Menu
								cin >> op; //Opcion de Menu
							}
							system("cls");
							break;
						case 2:
							break;
						case 3:
							break;
						case -1:
							break;
						default:
							color(0,11);
							cout << " | ADVERTENCIA: Opcion no valida." << endl;
							color(0,15);
							system("pause");
							system("cls");
							break;
					}
					MenuEnfermeria(); //Carga de Menu
					cin >> op; //Opcion de Menu
				}
				system("cls");
				break;
			case 3:
				break;
			case -1:
				break;
			default:
				color(0,11);
				cout << " | ADVERTENCIA: Opcion no valida." << endl;
				color(0,15);
				system("pause");
				system("cls");
				break;
		}
		MenuPrincipal();
		cin >> op;
	}
	/*
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
	
	CargarRegistroCompra("Areyes091", "2018/06/11", "Inventario");
	CargarRegistroCompra("Areyes091", "2018/06/11", "Inventario");
	BuscarCodigoCompra("F1001");
	BuscarCodigoCompra("F1002");
	MostrarRegistroCompra();
	
	CargarRegistroBodega();
	/*
	for(int i=0; i < registroCompra.size(); i++){
		registroCompra[i] -> MostrarInfo();
	}
		
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
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Control de Interfaz
//--------------------------------------------------------------------------------------------------------------------------------------------------------
void MenuPrincipal(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO." << endl;
	color(0,15);
	cout << " ---------------------------------" << endl;
	cout << " | [01] -> Inventario" << endl;
	cout << " | [02] -> Enfermeria" << endl;
	cout << " | [03] -> Atencion al cliente" << endl;
	cout << " ---------------------------------" << endl;
	color(0,12);
	cout << " | [-1] -> SALIR." << endl;
	color(0,15);
	cout << " ---------------------------------" << endl;
	cout << " | OPCION: ";
}
void MenuInventario(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / INVENTARIO" << endl;
	color(0,15);
	cout << " ---------------------------------" << endl;
	cout << " | [01] -> Productos" << endl;
	cout << " | [02] -> Tipos de Productos" << endl;
	cout << " | [03] -> Compras" << endl;
	cout << " ---------------------------------" << endl;
	color(0,11);
	cout << " | [-1] -> REGRESAR." << endl;
	color(0,15);
	cout << " ---------------------------------" << endl;
	cout << " | OPCION: ";
}
void MenuInventarioProductos(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / PRODUCTOS" << endl;
	color(0,15);
	cout << " ---------------------------------" << endl;
	cout << " | [01] -> Agregar Productos" << endl;
	cout << " | [02] -> Buscar Productos" << endl;
	cout << " | [03] -> Eliminar Productos" << endl;
	cout << " | [04] -> Listar Productos" << endl;
	cout << " ---------------------------------" << endl;
	color(0,11);
	cout << " | [-1] -> REGRESAR." << endl;
	color(0,15);
	cout << " ---------------------------------" << endl;
	cout << " | OPCION: ";
}
void MenuInventarioTipoProductos(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / TIPO PRODUCTOS" << endl;
	color(0,15);
	cout << " -----------------------------------" << endl;
	cout << " | [01] -> Agregar Tipo Productos" << endl;
	cout << " | [02] -> Buscar Tipo Productos" << endl;
	cout << " | [03] -> Eliminar Tipo Productos" << endl;
	cout << " | [04] -> Listar Tipo Productos" << endl;
	cout << " -----------------------------------" << endl;
	color(0,11);
	cout << " | [-1] -> REGRESAR." << endl;
	color(0,15);
	cout << " -----------------------------------" << endl;
	cout << " | OPCION: ";
}
void MenuInventarioCompras(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / COMPRAS" << endl;
	color(0,15);
	cout << " ----------------------------" << endl;
	cout << " | [01] -> Agregar Compras" << endl;
	cout << " | [02] -> Buscar Compra" << endl;
	cout << " | [03] -> Listar Compras" << endl;
	cout << " ---------------------------" << endl;
	color(0,11);
	cout << " | [-1] -> REGRESAR." << endl;
	color(0,15);
	cout << " ---------------------------" << endl;
	cout << " | OPCION: ";
}
void MenuEnfermeria(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / ENFERMERIA" << endl;
	color(0,15);
	cout << " ----------------------------------" << endl;
	cout << " | [01] -> Carga de Inventario" << endl;
	cout << " | [02] -> Carga a cuenta Paciente" << endl;
	cout << " | [03] -> Alta de Paciente" << endl;
	cout << " ----------------------------------" << endl;
	color(0,11);
	cout << " | [-1] -> REGRESAR." << endl;
	color(0,15);
	cout << " ----------------------------------" << endl;
	cout << " | OPCION: ";
}
void MenuEnfermeriaBodega(){
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / CARGA INVENTARIO" << endl;
	color(0,15);
	cout << " ---------------------------------------" << endl;
	cout << " | [01] -> Cargar Compras a Bodega" << endl;
	cout << " | [02] -> Buscar Producto en Bodega" << endl;
	cout << " | [03] -> Transferir Productos" << endl;
	cout << " | [04] -> Listar Productos" << endl;
	cout << " ---------------------------------------" << endl;
	color(0,11);
	cout << " | [-1] -> REGRESAR." << endl;
	color(0,15);
	cout << " ---------------------------------------" << endl;
	cout << " | OPCION: ";
}

void InicioSistema(){ //Solo por estetica / No tiene vlaidaciones
	string idRegistro, fecha;
	color(0,14);
	cout << "\n | CLINICA NURI-YO." << endl;
	color(0,15);
	cout << " --------------------------------------" << endl;
	cout << " |      ID Registro: "; cin >> idRegistro;
	cout << " | Fecha [dd/mm/aa]: "; cin >> fecha;
	cout << " --------------------------------------" << endl;
	registroBase -> SetUsuario(idRegistro);
	registroBase -> SetFecha(fecha);
	registroBase -> SetTipoTransaccion(" ");
	color(0,10);
	cout << " |                  -> INICIO COMPLETO." << endl;
	color(0,15);
	cout << " --------------------------------------" << endl;
	system("pause");
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Control de registro para Compras
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Funcion para registrar unicamente datos de compras
void CargarRegistroCompra(){
	registroBase -> SetTipoTransaccion("INVENTARIO");
	Compras * temp = new Compras(); //Registramos un objeto
	temp -> CargarCompra(registroBase -> GetUsuario(), registroBase -> GetFecha(), registroBase -> GetTipoTransaccion(), registroProducto, registroCompra); //Cargamos a Bodega
	delete temp; //Elimino el registro temporal
}
//Funcion para buscar facturas
void BuscarCodigoCompra(){
	//Buscar Codigo en Compras
	string codigoCompra;
	cout << " -- " << endl;
	cout << " | BUSCAR REGISTRO DE COMPRAS." << endl; 
	cout << " ----------------------------" << endl;
	cout << " * Buscar Codigo Compra: "; cin >> codigoCompra;

	for(int x=0; x < registroCompra.size(); x++){
		if(codigoCompra == registroCompra[x] -> GetCodigo()){
			registroCompra[x] -> BuscarCompra(codigoCompra, registroCompra, registroProducto);
			return;
		}
	}
	cout << " -- " << endl;
	cout << " | ADVERTENCIA: Codigo de compra no encontrado." << endl; 
	cout << " ----------------------------------------------" << endl;
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
//funcion para registrar las compras a la bodega
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
void TransferirBodegaBodega(){
	
}
void TransferirBodegaBodega(vector <Bodega *> &xBodega, Bodega * tipoBodega, vector <Bodega *> &yBodega){
	string codigoProducto;
	cout << " | Ingrese Codigo: "; cin >> codigoProducto;
	
	for(int x = 0; x < registroProducto.size(); x++){
		if(registroProducto[x] -> GetCodigo() == codigoProducto){
			//Creamos un objeto temporal para utilizar la funcion mostrar
			Bodega * temp = new Bodega();
			//Mandamos el contenedor de productos en bodega
			temp -> Transferir(registroProducto[x], xBodega, tipoBodega, yBodega);
			//Eliminamos el dato temporal
			delete temp;
			return;
		}
	}

	cout << " -- " << endl;
	cout << " | ADVERTENCIA: El codigo no existe en bodega." << endl;
	cout << " -- " << endl;

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Control de registros de Productos.
//--------------------------------------------------------------------------------------------------------------------------------------------------------
void AgregarProducto(){
	string codigo, descripcion, marca, codigoTipoProducto;
	double precio;
	registroBase -> SetTipoTransaccion("INVENTARIO");
	
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / AGREGAR PRODUCTO." << endl;
	color(0,15);	
	cout << " --------------------------------------" << endl;
	cout << " | * Codigo Producto: "; 	   cin >> codigo;
	cout << " | * Descripcion: "; 		   cin >> descripcion;
	cout << " | * Marca Producto: "; 	   cin >> marca;
	cout << " | * Codigo Tipo Producto: "; cin >> codigoTipoProducto;
	cout << " | * Precio Producto: "; 	   cin >> precio;
	cout << " --------------------------------------" << endl;
	CargarRegistroProducto(registroBase -> GetUsuario(), registroBase -> GetFecha(), registroBase -> GetTipoTransaccion(), codigo,
							 descripcion, marca, precio, codigoTipoProducto, registroTipoProducto);			
}
//Funcion para registrar nuevos productos
void CargarRegistroProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion, 
							string marca, double precio, string codigoTipoProducto, vector <TipoProducto *> registro){
	//Creamos un objeto para enviar el dato a cargarlo.
	Producto * newRegistro = new Producto(usuario, fecha, tipoTransaccion, codigo, descripcion, marca, precio, codigoTipoProducto, registro); //Registramos el objeto
	//Enviamos el Objeto con el contenedor de productos.
	newRegistro -> CargarProducto(newRegistro, registroProducto);
}
//Funcion para agregar tipos de productos
void AgregarTipoProducto(){
	string codigo, descripcion;
	registroBase -> SetTipoTransaccion("INVENTARIO");
	cout << endl;
	color(0,14);
	cout << " | CLINICA NURI-YO. / AGREGAR TIPO PROD" << endl;
	color(0,15);	
	cout << " --------------------------------------" << endl;
	cout << " | * Codigo TP: "; 	cin >> codigo;
	cout << " | * Descripcion: "; 	cin >> descripcion;
	cout << " --------------------------------------" << endl;
	CargarRegistroTipoProducto(registroBase -> GetUsuario(), registroBase -> GetFecha(), registroBase -> GetTipoTransaccion(), codigo, descripcion);	
}
//Funcion para registrar unicamente datos de Tipos de Productos
void CargarRegistroTipoProducto(string usuario, string fecha, string tipoTransaccion, string codigo, string descripcion){
	//Creamos un objeto para enviar el dato a cargarlo.
	TipoProducto * newRegistro = new TipoProducto(usuario, fecha, tipoTransaccion, codigo, descripcion); //Registramos el objeto
	//Enviamos el Objeto con el contenedor de productos.
	newRegistro -> CargarTipoProducto(newRegistro, registroTipoProducto);
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
void BuscarTipoProducto(){
	string codigoTipoProducto;
	cout << " -- " << endl;
	cout << " | BUSCAR REGISTRO DE TIPOS DE PRODUCTO." << endl; 
	cout << " --------------------------------------" << endl;
	cout << " * Buscar Codigo: "; cin >> codigoTipoProducto;
	//Creamos un objeto temporal para utilizar la funcion buscar
	TipoProducto * temp = new TipoProducto();
	//Mandamos el contenedor de productos
	temp -> BuscarTipoProducto(codigoTipoProducto, registroTipoProducto);
	//Eliminamos el dato temporal
	delete temp;
}
//Funcion para eliminar productos
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
void EliminarTipoProducto(){
	string codigoTipoProducto;
	cout << " -- " << endl;
	cout << " | ELIMINAR REGISTRO DE PRODUCTOS." << endl; 
	cout << " ---------------------------------" << endl;
	cout << " * Buscar Codigo: "; cin >> codigoTipoProducto;
	//Creamos un objeto temporal para utilizar la funcion buscar
	TipoProducto * temp = new TipoProducto();
	//Mandamos el contenedor de productos
	temp -> EliminarTipoProducto(codigoTipoProducto, registroTipoProducto);
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
void MostrarTipoProducto(){
	//Creamos un objeto temporal para utilizar la funcion mostrar
	TipoProducto * temp = new TipoProducto();
	//Mandamos el contenedor de productos
	temp -> MostrarInfo(registroTipoProducto);
	//Eliminamos el dato temporal
	delete temp;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------



