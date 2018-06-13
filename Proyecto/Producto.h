#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Inventario.h"
#include "TipoProducto.h"

using namespace std;

class Producto : public Inventario{
	private:
		string codigoTipoProducto;
		string marca;
		double precio;
		int existenciaBodegaPrincipal;
		int existenciaBodegaEnfermeria;
		bool validarCodigoTipoproducto;
		
	public:
		//constructores y destructores
		Producto();
		~Producto();
		Producto(string, int, int); //De la clase actual
		Producto(string, string, string, string, string, string, double, string, vector <TipoProducto *>);//De la clase heredada + la actual
		//setters
		void SetCodigoTipoProducto(string, vector <TipoProducto *>);
		void SetMarca(string);
		void SetPrecio(double);
		void SetExistenciaBodegaPrincipal(int);
		void SetExistenciaBodegaEnfermeria(int);
		//getters
		string GetCodigoTipoProducto();
		bool GetValidarCodigoTipoProducto();
		string GetMarca();
		double GetPrecio();
		int GetExistenciaBodegaPrincipal();
		int GetExistenciaBodegaEnfermeria();
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //PRODUCTO_HPP
