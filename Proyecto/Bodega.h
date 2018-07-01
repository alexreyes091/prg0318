#ifndef BODEGA_HPP
#define BODEGA_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Compras.h"
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
		//Otros metodos	
		//Validaciones
		virtual bool ValidarCodigo(string, vector <Producto *>); //Valida si un codigo ya existe
		bool ValidarCodigoProductoBodega(Bodega *, vector <Bodega *>); //Valida si el codigo esta en bodega
		bool ValidarCodigoProductoBodega(Compras *, vector <Bodega *>); //Valida si el codigo esta en bodega
		bool ValidarCodigoProductoBodega(Producto *, vector <Bodega *>); //Valida si el codigo esta en bodega
		bool ValidarCantidadTraslado(int, int); //Valida que la cantidad a trasladar no sea negativa o mayor de la posible
	
		//Acciones posibles
		void BuscarProductoBodega(string, vector <Bodega *>);
		void CargarProducto(Compras *, Bodega *, vector <Bodega *> &, vector <Compras *> &); //Cargamos productos a la bodega que deseamos
		void EliminarProductoBodega(string, vector <Bodega *> &);
		//void CargarProducto(Producto *, Bodega *, vector <Bodega *> &); //Cargamos productos a la bodega que deseamos
		void Transferir(Producto *, vector <Bodega *> &, Bodega *, vector <Bodega *> &); //Tansferimos productos de una bodega a otra
		
		//Testeo de Informacion
		virtual void MostrarInfo(); //Solo para fines de pruebavoid Cargar()
		virtual void MostrarInfo(vector <Bodega *>, vector <Producto *>);
};

#endif //BODEGA_HPP
