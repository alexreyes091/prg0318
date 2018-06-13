#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <iostream>
#include <string>
#include <vector>

#include "TipoProducto.h"

using namespace std;

class Producto : public TipoProducto{
	private:
		string codigoTipoProducto;
		string marcaProducto;
		int existenciaBodegaPrincipal;
		int existenciaBodegaEnfermeria;
		
	public:
		//constructores y destructores
		Producto();
		~Producto();
		Producto(string, string, string, string, string, string, string);//De la clase heredada + la actual
		//setters
		void SetMarcaProducto(string);
		void SetExistenciaBodegaPrincipal(int);
		void SetExistenciaBodegaEnfermeria(int);
		//getters
		string GetMarcaProducto();
		int GetExistenciaBodegaPrincipal();
		int GetExistenciaBodegaEnfermeria();
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //PPRODUCTO_HPP
