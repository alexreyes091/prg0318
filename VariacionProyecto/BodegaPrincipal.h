#ifndef BODEGAPRINCIPAL_HPP
#define BODEGAPRINCIPAL_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Bodega.h"

using namespace std;

class BodegaEnfermeria; //Dependencia ciclica

class BodegaPrincipal : public Bodega{		
	public:
		//constructores y destructores
		BodegaPrincipal();
		~BodegaPrincipal();
		BodegaPrincipal(string, string, string, int, vector <Producto *>);//De la clase heredada + la actual
		//otros metodos
		bool ValidarCodigoProductoBodega(BodegaPrincipal *, vector <BodegaPrincipal *>);
		bool ValidarCodigoProductoBodega(BodegaPrincipal *, vector <BodegaEnfermeria *>);
		void Transferencia(BodegaPrincipal *, vector <BodegaPrincipal *> &, vector <BodegaEnfermeria *>);
		//void ActualizarBodega(Compra *, vector <BodegaPrincipal *>);
};
#endif //BODEGAPRINCIPAL_HPP
