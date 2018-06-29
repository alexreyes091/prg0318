/* Uso de archivos aleatorios.
   Programa Principal
   Archivo Principal.cpp
   (c) CEUTEC 2010
   Diciembre 1, 2010.
   Por: Ing. Rafael Cerrato
*/

#include "Cuentas.h"
#include <cstdlib> // Para usar exit
#include <iostream>
#include <iomanip>
#include <constream>
#include <string>
#include <fstream>


using namespace std;
using namespace conio;

//void mostrarCuenta();
void mostrarMenu();
string repetirCaracter( char, int );
// Prototipos para archivos.
int crearArchivo( string );
int guardarCuentas( string );
int leerCuentas( string );
void borrarArea( int, int, int, int );

int main(int argc, char *argv[])
{
    Cuentas cta;
    int opcion;
    string archivo;
    
    archivo = "Rafael.dat";
    
    do { // Menu persistente.
        mostrarMenu();
        borrarArea(5,5,70,21);    
        do {        
           cout << setxy(1,24)
                << repetirCaracter(' ', 50)
                << '\r'
                << "Introduzca numero de opcion: ";
           cin >> opcion;
        } while(opcion<1 || opcion>5 ); // Fin while
          
        cout << setxy(1,24)
             << repetirCaracter(' ',80);
        switch(opcion) {
             case 1:
                  cout << setxy(5,5)
                       << setattr(WHITE)
                       << "Nombre archivo: "
                       << normvideo;
                  cin >> archivo;
                  if(crearArchivo( archivo ))
                       cout << setxy(53,24)
                            << setattr(LIGHTGREEN)
                            << "Error. Archivo no creado..."
                            << normvideo;
                  break;
             case 2:
                  if(guardarCuentas( archivo ))
                       cout << setxy(53,24)
                            << setattr(LIGHTGREEN)
                            << "Error. Cuenta no guardada..."
                            << normvideo;
                  break;
             case 3:
                  cout << setxy(5,5)
                       << setattr(WHITE)
                       << "Nombre archivo: "
                       << normvideo;
                  cin >> archivo;
                  if(leerCuentas(archivo))
                       cout << setxy(53,24)
                            << setattr(LIGHTGREEN)
                            << "Error. Cuenta no guardada..."
                            << normvideo;
                  break;
        } // Fin switch.
    } while(!(opcion == 5)); // Fin while externo
        
    return EXIT_SUCCESS;
    
} // Fin main

string repetirCaracter( char c, int n )
{
    string str="";
    
    if(n>0)
        for(int i=0; i<n; i++)
            str += c;
        
    return str;
}

void borrarArea( int col1, int fil1,
                 int col2, int fil2 )
{    
     int temp=col1;

     // Validar argumentos.
     if( col1>0 && col2>0 && fil1>0 && fil2>0 ) 
     {
         if( col1 > col2) {
             col1 = col2;
             col2 = temp;
         }
         temp=fil1;
         if( fil1 > fil2) {
             fil1 = fil2;
             fil2 = temp;
         }
         for(int i=0; i<fil2-fil1;i++)
             cout << setxy(col1, fil1+i)
                  << repetirCaracter(' ', col2-col1);       
     }
}
void mostrarMenu()
{
    cout << setattr(WHITE) 
         << setxy(23,2) 
         << "Actualizacion de Cuentas Corrientes"
         << setxy(1,3) 
         << repetirCaracter('_',80)
         << setxy(1,22) << "1. Crear Archivo "
         << "2. Guardar Cuenta "
         << "3. Leer Cuentas "
         << "4. Borrar Cuenta "
         << "5. Salir"
         << setxy(1,23) 
         << repetirCaracter('_',80)
         << normvideo;
} // Fin del metodo Menu.

int crearArchivo( string path )
{
    ofstream archivo;
    Cuentas blanco;
    
    // 1. Apertura del archivo.
    archivo.open(path.data(),
                 ios::out | ios::binary );
                 
    if(!archivo)
        return 1; // 1 para error.
    
    // 2. Uso del archivo
    for(int i=0; i<200;i++) 
        archivo.write( 
           reinterpret_cast<const char *>(&blanco),
           sizeof(Cuentas));   
    
    // Cierre del archivo.
    archivo.close();
    
    return 0; // 0 para exito.
    // destructor cierra el archivo.
    
} // Fin crearArchivo

int guardarCuentas( string path )
{
    ofstream archivo;
    int cuenta;
    string nombre, apellido;
    double saldo;
    Cuentas cta;
    
    archivo.open( path.data(), ios::out | 
                               ios::in | 
                               ios::binary );
    if(!archivo)
        return 1; // 1 para error.

    cout << setxy(1,24)
         << "Introduzca datos, cuenta 0 para terminar...";
         
    cout << setxy(5,5)
         << "No. cuenta: ";
    cin >> cuenta;
    
    while( cuenta > 0 && cuenta <= 200) 
    {
        cout << setxy(5,6)
             << "Nombre y apellido: ";
        cin >> nombre >> apellido;
        cout << setxy(5,7)
             << "Saldo cuenta: ";
        cin >> saldo;
        cta.establecerIdCuenta(cuenta);
        cta.establecerNombre(nombre);
        cta.establecerApellido(apellido);
        cta.establecerSaldo(saldo);
            
        archivo.seekp( 
          (cta.obtenerIdCuenta()-1) *
           sizeof(Cuentas));
    
        archivo.write( 
          reinterpret_cast<const char *>(&cta),
          sizeof(Cuentas));
        
        borrarArea(5,5,70,20);  
        cout << setxy(5,5)
             << "No. cuenta: ";
        cin >> cuenta;
    } // Fin while

    archivo.close();
    
    return 0; // 0 para exito.
    // destructor cierra el archivo.    
} // Fin guardarCuentas

int leerCuentas( string path )
{
    ifstream archivo;
    Cuentas cta;

    archivo.open(path.data(), ios::in | 
                              ios::binary );
    if(!archivo) // Verificar apertura de archivo.
        return 1; // 1 para error.
    
    cout << fixed
         << setattr(WHITE) 
         << left << setxy(5,5)
         << setw(10) << "Cuenta"
         << setw(20) << "Nombre"
         << setw(20) << "Apellido"
         << setw(10) << right << "Saldo"
         << setxy(5,6) << repetirCaracter('-',60)
         << normvideo << endl;
    
    // Leer primer registro del archivo.
    archivo.read( 
        reinterpret_cast< char *>(&cta),
        sizeof(Cuentas));
    
    // Leer todos los registros.
    int i = 2;
    while(archivo && !archivo.eof()) 
    {
         if(i == 15) // Bloque de registros.
         {
             cout << setxy(1,24);
             system("pause");
             borrarArea(5,7,70,20);
             cout << setxy(5,7);
             i=2;
         }
                           
         // Mostrar datos del registro.
         if(cta.obtenerIdCuenta() != -1)
         {
             cout << left << setxy(5,5+i)
                  << setw(10) 
                  << cta.obtenerIdCuenta()
                  << setw(20) 
                  << cta.obtenerNombre()
                  << setw(20) 
                  << cta.obtenerApellido()
                  << setw(10) << right 
                  << setprecision(2)
                  << cta.obtenerSaldo()
                  << endl;
             ++i;
         } // Fin if
         
         // Leer siguiente entrada.
         archivo.read( 
             reinterpret_cast< char *>(&cta),
             sizeof(Cuentas));
    } // Fin while
    
    cout << setxy(1,24);
    system("pause");
    borrarArea(5,5,70,20); 
    
    archivo.close();         
    
    return 0; // 0 para exito.
    // destructor cierra el archivo.
    
} // Fin leerCuentas


