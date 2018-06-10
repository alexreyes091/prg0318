#ifndef RESPESTASOPCIONALES_HPP
#define RESPESTASOPCIONALES_HPP

#include <iostream>
#include "Categorias.h"

using namespace std;

class RespuestasOpcionales : public Categorias{
	private:
		string respuestaOpcional;
		
	public:
		//Constructores y Destructores
		RespuestasOpcionales();
		~RespuestasOpcionales();
		RespuestasOpcionales(string);
		RespuestasOpcionales(int, string);
		
		//Setters y Getters
		void SetRespuestaOpcional(string);
		string GetRespuestaOpcional();
		
		void MostrarRespuestaOpcional();
};

#endif //RESPESTASOPCIONALES_HPP
