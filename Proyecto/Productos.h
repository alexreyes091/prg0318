#ifndef TIPOPRODUCTO_HPP
#define TIPOPRODUCTO_HPP

#include <iostream>
#include <string>
#include <vector>

#include "TipoProducto.h"

using namespace std;

class Producto : public TipoProducto{
	private:
		string nombreProducto;
		string marcaProducto;
		int existenciaBodegaPrincipal;
		int existenciaBodegaEnfermeria;
		
	public:
		//constructores y destructores
		Producto();
		~Producto();
		Producto(string, string, int, int); //De la clase actual
		Producto(string, string, string, string, string, string, string, string, int, int);//De la clase heredada + la actual
		//setters
		void SetNombreProducto(string);
		void SetMarcaProducto(string);
		void SetExistenciaBodegaPrincipal(int);
		void SetExistenciaBodegaEnfermeria(int);
		//getters
		string GetNombreProducto();
		string GetMarcaProducto();
		int GetExistenciaBodegaPrincipal();
		int GetExistenciaBodegaEnfermeria;
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //TIPOPRODUCTO_HPP
