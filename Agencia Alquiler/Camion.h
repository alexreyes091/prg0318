#ifndef CAMION_HPP
#define CAMION_HPP

#include <iostream>
#include <string>

#include "Vehiculo.h"

using namespace std;

class Camion : public Vehiculo{
	private:
		//atributos
		double precioDia;
		double totalPago;
		int diaAlquiler;
		int diaDevolucion;
		int diaAcumulado;
		
	public:
		//constructores
		Camion();
		Camion(string, bool, double);
		~Camion();
		
		//setters
		void SetPrecioDia(double);
		void SetDiaAlquiler(int);
		void SetDiaDevolucion(int);
		void SetDiaAcumulado(int);
		
		//getters
		double GetPrecioDia();
		int GetDiaAlquiler();
		int GetDiaDevolucion();
		int GetDiaAcumulado();
				
		//metodos
		virtual void AlquilarVehiculo(int);
		virtual void DevolverVehiculo(int);
		virtual void ShowInfo();
	
};

#endif // CAMION_HPP
