#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <iostream>
#include <string>
#include <vector>

#include "RegistroBase.h"

using namespace std;

class Inventario : public RegistroBase{
	private:
		string codigo;
		string descripcion;
	
	public:
		//constructores y destructores
		Inventario();
		~Inventario();
		Inventario(string);
		Inventario(string, string); //De la clase actual
		Inventario(string, string, string, string, string);//De la clase heredada + la actual
		//setters
		void SetCodigo(string);
		void SetDescripcion(string);
		//getters
		string GetCodigo();
		string GetDescripcion();
		//otros metodos
		virtual bool ValidarCodigo(string, vector <Inventario *>); //Valida si un codigo ya existe
		//bool ValidarCodigo(string, vector <TipoProducto *>); //Valida si un codigo ya existe
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif //INVENTARIO_HPP
