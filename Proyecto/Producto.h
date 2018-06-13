#ifndef TIPOPRODUCTO_HPP
#define TIPOPRODUCTO_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Inventario.h"
#include "TipoProducto.h"

using namespace std;

class Producto : public Inventario{
	private:
		string codigoTipoProducto;
		string marcaProducto;
		int existenciaBodegaPrincipal;
		int existenciaBodegaEnfermeria;
		
	public:
		//constructores y destructores
		Producto();
		~Producto();
		Producto(string, int, int); //De la clase actual
		Producto(string, string, string, string, string, string, string, vector <TipoProducto *>);//De la clase heredada + la actual
		//setters
		void SetCodigoTipoProducto(string, vector <TipoProducto *>);
		void SetMarcaProducto(string);
		void SetExistenciaBodegaPrincipal(int);
		void SetExistenciaBodegaEnfermeria(int);
		//getters
		string GetCodigoTipoProducto();
		string GetMarcaProducto();
		int GetExistenciaBodegaPrincipal();
		int GetExistenciaBodegaEnfermeria;
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //TIPOPRODUCTO_HPP
