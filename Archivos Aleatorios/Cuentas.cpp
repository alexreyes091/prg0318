/* Uso de archivos aleatorios.
   Clase Cuentas
   Implementación Cuentas.cpp
   (c) CEUTEC 2010
   Diciembre 1, 2010.
   Por: Ing. Rafael Cerrato
*/

#include <iostream>
#include <cstring>

using namespace std;

#include "Cuentas.h"

Cuentas::Cuentas( int id, string pNombre,
                  string pApellido,
                  double pSaldo )
{
    establecerIdCuenta( id );
    establecerNombre( pNombre);
    establecerApellido( pApellido );
    establecerSaldo( pSaldo );
} // Fin del constructor.

// Métodos de acceso.
void Cuentas::establecerIdCuenta( int id )
{
    idCuenta = id > 1 ? id:1;
}

int Cuentas::obtenerIdCuenta() const
{
    return idCuenta;
}

void Cuentas::establecerNombre( string pNombre)
{
    const char *ptrNombre = pNombre.data();
    int longitudNombre = strlen(ptrNombre);
    // Verifique que nombre tiene 20 elementos maximo.
    longitudNombre = longitudNombre<20 ?
                     longitudNombre:19;
    strncpy(nombre, ptrNombre, longitudNombre);
    nombre[longitudNombre] = '\0';
}

string Cuentas::obtenerNombre() const
{
    return nombre;
}

void Cuentas::establecerApellido( string pApellido)
{
    const char *ptrApellido = pApellido.data();
    int longitudApellido = strlen(ptrApellido);
    // Verifique que Apellido tiene 20 elementos maximo.
    longitudApellido = longitudApellido<20 ?
                     longitudApellido:19;
    strncpy(apellido, ptrApellido, longitudApellido);
    nombre[longitudApellido] = '\0';
}

string Cuentas::obtenerApellido() const
{
    return apellido;
}

void Cuentas::establecerSaldo( double pSaldo )
{
    saldo = pSaldo; // Puede ser negativo.
}

double Cuentas::obtenerSaldo() const
{
    return saldo;
}


      
