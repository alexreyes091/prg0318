#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Vehiculo.h"

using namespace std;

//Prototipo de Funcion
void Menu();

string RepitC(char, int);
int CrearArchivo(string);
int NuevoVehiculo(string) ;
int ListarVehiculos(string);
int EliminarVehiculo(string);


int main() {
	int op=0;
	string archivo = "datos.dat";
	CrearArchivo(archivo);
	Menu();
	cin >> op;
	
	while(op != 4){
		switch(op){
			case 1:
				system("cls");
				NuevoVehiculo(archivo);
				system("pause");
				break;
				
			case 2:
				system("cls");
				ListarVehiculos(archivo);
				system("pause");
				break;
			
			case 3:
				system("cls");
				EliminarVehiculo(archivo);
				system("pause");
				break;
			
			default:
				cout << "Error: Opcion no valida." << endl;
				system("pause");
				break;		
		}
		//Volvemos a consultar opcion
		system("cls");
		Menu();
		cin >> op;
	}
	
	
	return 0;
}

void Menu(){
	cout << " **   MENU PRINCIPAL   ** " << endl;
	cout << RepitC( '-', 25) << endl;
	cout << " 01. Nuevo Vehiculo. " << endl;
	cout << " 02. Listar Vehiculos. "<< endl;
	cout << " 03. Eliminar Vehiculo." << endl;
	cout << " 04. Salir." << endl;
	cout << RepitC( '-', 25) << endl;
	cout << " >> ";
}

string RepitC(char c, int n)
{
    string str="";
    
    if(n>0)
        for(int i=0; i<n; i++)
            str += c;
        
    return str;
}

int CrearArchivo(string path)
{
    ofstream archivo;
    Vehiculo blanco(0,"","",0);
    //Vehiculo blanco();
    
    // 1. Apertura del archivo.
    archivo.open(path.data(),
                 ios::out | ios::binary | ios::app);
                 
    if(!archivo)
        return 1; // 1 para error.
    
    // 2. Uso del archivo
    for(int i=0; i<10;i++) 
        archivo.write( 
           reinterpret_cast<const char *>(&blanco),
           sizeof(Vehiculo));   
    
    // Cierre del archivo.
    archivo.close();
    
    return 0; // 0 para exito.
    // destructor cierra el archivo.
    
} // Fin crearArchivo

int NuevoVehiculo(string path)
{
    ofstream archivo;
    int codigo, anio;
    string marca, modelo;
    Vehiculo vehiculo;
    
    archivo.open( path.data(), ios::out | 
                               ios::in | 
                               ios::binary |
							   ios::app);
    if(!archivo)
        return 1; // 1 para error.
    
    cout << "Ingrese [0] para salir!" << endl;
    cout << RepitC('-', 25) << endl;
    cout <<" Codigo: ";   	cin >> codigo;
    
    while( codigo > 0 && codigo <= 10) 
    {
        cout <<"  Marca: ";		cin >> marca;
        cout <<" Modelo: ";		cin >> modelo;
        cout <<"   Anio: ";		cin >> anio;
        
        vehiculo.SetCodigo(codigo);
        vehiculo.SetMarca(marca);
        vehiculo.SetModelo(modelo);
        vehiculo.SetAnio(anio);
            
        archivo.seekp( 
          (vehiculo.GetCodigo()-1) *
           sizeof(Vehiculo));
    
        archivo.write( 
          reinterpret_cast<const char *>(&vehiculo),
          sizeof(Vehiculo));
          
        cout << RepitC('-', 25) << endl;
        cout <<"\n Codigo: ";   	cin >> codigo;
    } // Fin while

    archivo.close();
    
    return 0; // 0 para exito.
    // destructor cierra el archivo.    
} // Fin guardarCuentas

int ListarVehiculos(string path)
{
    ifstream archivo;
    Vehiculo vehiculo;

    archivo.open(path.data(), ios::in | 
                              ios::binary |
							  ios::app);
    if(!archivo) // Verificar apertura de archivo.
        return 1; // 1 para error.
    
    cout << fixed
         << setw(10) << "Codigo "
         << setw(20) << "Marca "
         << setw(20) << "Modelo"
         << setw(10) << "Anio"
         << endl;
	cout << RepitC('-',60) << endl;
    
    // Leer primer registro del archivo.
    archivo.read( 
        reinterpret_cast< char *>(&vehiculo),
        sizeof(Vehiculo));
    
    // Leer todos los registros.
    while(archivo && !archivo.eof()) 
    {                         
         if(vehiculo.GetCodigo() != -1)
         {
         	cout << left 
                  << setw(10) 
                  <<vehiculo.GetCodigo()
                  << setw(20) 
                  << vehiculo.GetMarca()
                  << setw(20) 
                  << vehiculo.GetModelo()
                  << setw(10) 
                  << vehiculo.GetAnio()
                  << endl;
                  
         } // Fin if
         
         // Leer siguiente entrada.
         archivo.read( 
             reinterpret_cast< char *>(&vehiculo),
             sizeof(Vehiculo));
    } // Fin while
    system("pause");
    
    archivo.close();         
    
    return 0; // 0 para exito.
    // destructor cierra el archivo.
    
} // Fin leerCuentas

int EliminarVehiculo(string path){
	ofstream archivo;
    int codigo, anio=0, temp;
    string marca="", modelo="";
    Vehiculo vehiculo;
    
    archivo.open( path.data(), ios::out | 
                               ios::in | 
                               ios::binary |
							   ios::app );
    if(!archivo)
        return 1; // 1 para error.
    
    cout << "Ingrese [0] para salir!" << endl;
    cout << RepitC('-', 25) << endl;
    cout <<" Codigo: ";   	cin >> codigo;
    
    
    while( codigo > 0 && codigo <= 10) 
    {        
    	temp = vehiculo.GetCodigo();
    	
        vehiculo.SetCodigo(0);
        vehiculo.SetMarca(marca);
        vehiculo.SetModelo(modelo);
        vehiculo.SetAnio(anio);
            
        archivo.seekp( 
          (temp - 1) *
           sizeof(Vehiculo));
    
        archivo.write( 
          reinterpret_cast<const char *>(&vehiculo),
          sizeof(Vehiculo));
          
        cout << RepitC('-', 25) << endl;
        cout << " * REGISTRO ELIMINADO CON EXITO." << endl;
        cout << RepitC('-', 25) << endl;
        
        cout <<"\n Codigo: ";   	cin >> codigo;
    } // Fin while

    archivo.close();
    
    return 0; // 0 para exito.
}
