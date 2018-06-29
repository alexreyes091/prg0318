#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehiculo{
	private:
		string codigo;
		string marca;
		string modelo;
		int anio;
		double precio;		
	public:
		//constructores y destructores
		Vehiculo();
		~Vehiculo();
		Vehiculo(string);
		Vehiculo(string, string, string, int, double);
		//setters
		void SetCodigo(string);
		void SetMarca(string);
		void SetModelo(string);
		void SetAnio(int);
		void SetPrecio(double);
		//getters
		string GetCodigo();
		string GetMarca();
		string GetModelo();
		int GetAnio();
		double GetPrecio();
		//Otros Metodos
		bool ValidarCodigo(string, vector <Vehiculo *>);
		void AgregarVehiculo(Vehiculo *, vector<Vehiculo *> &);
		void EliminarVehiculo(string,  vector<Vehiculo *> &);
		void MostrarVehiculo();
};

#endif
