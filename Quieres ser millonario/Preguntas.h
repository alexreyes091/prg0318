#ifndef PREGUNTAS_HPP
#define PREGUNTAS_HPP

#include <iostream>
#include "Categorias.h"

using namespace std;

class Preguntas : public Categorias{
	private:
		int nivel;
		string pregunta;
		string respuesta;
		
	public:
		//Constructores y Destructores
		Preguntas();
		~Preguntas();
		Preguntas(int, int, string, string);
		
		//Setters y Getters
		void SetNivelPregunta(int);
		void SetPregunta(string);
		void SetRespuesta(string);
		
		int GetNivelPregunta();
		string GetPregunta();
		string GetRespuesta();
		
		void MostrarPregunta();
};

#endif //PREGUNTAS_HPP
