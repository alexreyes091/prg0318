#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
	private:
		//atributos
		string matricula;
		string vehiculo;
		bool alquilado;
		
	public:
		//constructores
		Vehiculo();
		Vehiculo(string, bool);
		Vehiculo(string, string, bool);
		~Vehiculo();
		
		//setters
		void SetMatricula(string);
		void SetVehiculo(string);
		void SetAlquilado(bool);
		
		//getters
		string GetMatricula();
		string GetVehiculo();
		bool GetAlquilado();
		
		//metodos
		virtual void AlquilarVehiculo();
		virtual void DevolverVehiculo();
		virtual void ShowInfo();
	
};

#endif // VEHICULO_HPP
