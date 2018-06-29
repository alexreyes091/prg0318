#ifndef TIPOPRODUCTO_HPP
#define TIPOPRODUCTO_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Inventario.h"

using namespace std;

class TipoProducto : public Inventario{	
	public:
		//constructores y destructores
		TipoProducto();
		~TipoProducto();
		TipoProducto(string, string, string, string, string);//De la clase heredada + la actual
		//otros metodos
		virtual bool ValidarCodigo(string, vector <TipoProducto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //TIPOPRODUCTO_HPP
