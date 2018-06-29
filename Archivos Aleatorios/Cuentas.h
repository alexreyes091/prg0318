/* Uso de archivos aleatorios.
   Clase Cuentas
   Archivo Cuentas.h
   (c) CEUTEC 2010
   Diciembre 1, 2010.
   Por: Ing. Rafael Cerrato
*/

#ifndef CUENTAS_H
#define CUENTAS_H

#include <string>

using namespace std;

class Cuentas {
    
public:
    // Constructor predeterminado.
    // Inicializa valores para idCuenta,
    // nombre, apellido y saldo.
    Cuentas( int = 0, string = "",
                     string = "",
                     double = 0.0 );
    // Métodos de acceso.
    void establecerIdCuenta( int );
    int  obtenerIdCuenta() const;
    
    void   establecerNombre( string );
    string obtenerNombre() const;
    
    void   establecerApellido( string );
    string obtenerApellido() const;
    
    void   establecerSaldo( double );
    double obtenerSaldo() const;
    
private:
    int idCuenta;
    char nombre[20], apellido[20];
    double saldo;
}; // Fin de la clase Cuenta

#endif
