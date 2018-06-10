#include <iostream>
#include <string>

#include "RespuestasOpcionales.h"

using namespace std;

RespuestasOpcionales::RespuestasOpcionales(){}
RespuestasOpcionales::~RespuestasOpcionales(){}
RespuestasOpcionales::RespuestasOpcionales(string respuestaOpcional){
	this -> SetRespuestaOpcional(respuestaOpcional);
}
RespuestasOpcionales::RespuestasOpcionales(int nCategoria, string respuestaOpcional) : Categorias(nCategoria){
	this -> SetRespuestaOpcional(respuestaOpcional);
}

//Setters y Getters
void RespuestasOpcionales::SetRespuestaOpcional(string respuestaOpcional){
	this -> respuestaOpcional = respuestaOpcional;
}
string RespuestasOpcionales::GetRespuestaOpcional(){
	return this -> respuestaOpcional;
}

//Otros Metodos
void RespuestasOpcionales::MostrarRespuestaOpcional(){
	cout << "Id Categoria: " << GetNCategoria() << endl;
	cout << "Respuesta Opcional: " << GetRespuestaOpcional() << endl;
}
