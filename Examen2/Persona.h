#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Base.h"

using namespace std;

class Persona : public Base{
	private:
		int codigo;
		string nombre;
		int edad;
	public:
		Persona();
		~Persona();
		Persona(int, string, int); 
		Persona(int, string, int, char, int);
		//setters
		void SetCodigo(int);
		void SetNombre(string);
		void SetEdad(int);
		//getters
		int GetCodigo();
		string GetNombre();
		int GetEdad();
		//Validaciones
		bool ValidarEleccionPadre(int, vector <Persona *>);
		bool ValidarEleccionCodigo(int, vector <Persona *>);
		//Aciones
		void MostrarPersonas();
		void MostrarPadres(vector <Persona*>);
		void MostrarHijos(vector <Persona*>);
		void ListarPadres(vector <Persona*>);
};

#endif // PERSONA_HPP


