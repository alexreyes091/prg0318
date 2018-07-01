#ifndef COMPRAS_HPP
#define COMPRAS_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Inventario.h"
#include "Producto.h"

using namespace std;

class Compras : public Inventario{
	private:
		string codigoProducto;
		int cantidadCompra;
		double precioCompra;
		double totalCompra;
		bool estadoCompra;
		bool validarCodigoProducto;
		bool validarCodigoCompra;
		
	public:
		//constructores y destructores
		Compras();
		~Compras();
		Compras(string, string, string, string, string, string, int, double, vector <Producto *>);//De la clase heredada + la actual
		//setters
		void SetCodigoProducto(string, vector <Producto *>);
		void SetCantidadCompra(int);
		void SetPrecioCompra(double);
		void SetTotalCompra(double);
		void SetEstadoCompra(bool);
		//getters
		string GetCodigoProducto();
		bool GetValidarCodigoProducto();
		bool GetValidarCodigoCompra();
		int GetCantidadCompra();
		double GetPrecioCompra();
		double GetTotalCompra();
		bool GetEstadoCompra();
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Compras *>);//Valida si una compra ya existe
		virtual bool ValidarCodigo(string, vector <Producto *>);//Valida si un codigo ya existe
		void CalcularTotalCompra(double, int);
		
		void CargarCompra(string, string, string, vector <Producto *>, vector <Compras *>&);
		void BuscarCompra(string, vector <Compras *>, vector <Producto *>);
		//void EliminarCompra(string, vector <Compras *>);
		virtual void MostrarInfo(string, vector <Compras *>, vector <Producto *>); //Solo para fines de prueba
};

#endif //COMPRAS_HPP
