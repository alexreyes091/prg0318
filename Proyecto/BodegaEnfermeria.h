#ifndef BODEGAENFERMERIA_HPP
#define BODEGAENFERMERIA_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Bodega.h"

using namespace std;

class BodegaPrincipal; //Dependencia ciclica

class BodegaEnfermeria : public Bodega{				
	public:
		//constructores y destructores
		BodegaEnfermeria();
		~BodegaEnfermeria();
		BodegaEnfermeria(string, string, string, int, vector <Producto *>);//De la clase heredada + la actual
		//otros metodos
		bool ValidarCodigoProductoBodega(BodegaEnfermeria *, vector <BodegaPrincipal *>);
		bool ValidarCodigoProductoBodega(BodegaEnfermeria *, vector <BodegaEnfermeria *>);
		void Transferencia(BodegaEnfermeria *, vector <BodegaPrincipal *>, vector <BodegaEnfermeria *>);
};
#endif //BODEGAENFERMERIA_HPP
