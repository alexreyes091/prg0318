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
		Bodega(string, string);//Crear simplemente las bodegas
		Bodega(string, string, string, int);//Crea el objeto que registrara en bodega.
		Bodega(string, string, string, int, vector <Producto *>);//De la clase actual
		Bodega(string, string, string, string, string, string, int, vector <Producto *>);//De la clase heredada + la actual
		//setters
		void SetCodigoProducto(string);
		void SetCodigoProducto(string, vector <Producto *>);
		void SetExistencia(int);
		//getters
		string GetCodigoProducto();
		bool GetValidarCodigoProducto();
		int GetExistencia();
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		bool ValidarCodigoProductoBodega(Bodega *, vector <Bodega *>); //Valida si el codigo esta en bodega
		bool ValidarCodigoProductoBodega(Producto *, vector <Bodega *>); //Valida si el codigo esta en bodega
		bool ValidarCantidadTraslado(int, int);
	
		void CargarProducto(Producto *, Bodega *, vector <Bodega *> &); //Cargamos productos a la bodega que deseamos
		void Transferir(Producto *, vector <Bodega *> &, Bodega *, vector <Bodega *> &); //Tansferimos productos de una bodega a otra
		
		virtual void MostrarInfo(); //Solo para fines de pruebavoid Cargar()
};

#endif //BODEGA_HPP
