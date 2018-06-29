#ifndef BODEGA_HPP
#define BODEGA_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Inventario.h"
#include "Producto.h"

using namespace std;

class Bodega : public Inventario{
	private:
		string codigoProducto;
		int existencia;
		bool validarCodigoProducto;
		
	public:
		//constructores y destructores
		Bodega();
		~Bodega();
		Bodega(string, string, string, int, vector <Producto *>);//De la clase heredada + la actual
		Bodega(string, string, string, string, string, string, int, vector <Producto *>);//De la clase heredada + la actual
		//setters
		void SetCodigoProducto(string, vector <Producto *>);
		void SetExistencia(int);
		//getters
		string GetCodigoProducto();
		bool GetValidarCodigoProducto();
		int GetExistencia();
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //BODEGA_HPP
