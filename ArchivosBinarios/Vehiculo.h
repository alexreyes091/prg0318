#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
	protected:
		//atributos
		int codigo;
		char marca[20];
		char modelo[20];
		int anio;
		
	public:
		//constructores
		Vehiculo();
		Vehiculo(int, string, string, int);
		~Vehiculo();
		
		//setters
		void SetCodigo(int);
		void SetMarca(string);
		void SetModelo(string);
		void SetAnio(int);
		
		//getters
		int GetCodigo();
		string GetMarca() ;
		string GetModelo() ;
		int GetAnio();
	
};

#endif // VEHICULO_HPP
