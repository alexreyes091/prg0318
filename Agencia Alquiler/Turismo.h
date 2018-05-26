#ifndef TURISMO_HPP
#define TURISMO_HPP

#include <iostream>
#include <string>

#include "Vehiculo.h"

using namespace std;

class Turismo : public Vehiculo{
	private:
		//atributos
		double precioKm;
		int kmAlquiler;
		int kmDevolucion;
		int kmAcumulado;
		
	public:
		//constructores
		Turismo();
		Turismo(string, bool, double);
		~Turismo();
		
		//setters
		void SetPrecioKm(double);
		void SetKmAlquiler(int);
		void SetKmDevolucion(int);
		void SetKmAcumulado(int);
		
		//getters
		double GetPrecioKm();
		int GetKmAlquiler();
		int GetKmDevolucion();
		int GetKmAcumulado();
				
		//metodos
		void AlquilarVehiculo(int);
		void DevolverVehiculo(int);
		void ShowInfo();
	
};

#endif // TURISMO_HPP
