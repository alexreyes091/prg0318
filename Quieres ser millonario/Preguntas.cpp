#include <iostream>
#include <string>

#include "Preguntas.h"

using namespace std;

Preguntas::Preguntas(){}
Preguntas::~Preguntas(){}
Preguntas::Preguntas(int nCategoria, int nivel, string pregunta, string respuesta) : Categorias(nCategoria){
	this -> SetNivelPregunta(nivel);
	this -> SetPregunta(pregunta);
	this -> SetRespuesta(respuesta);
}

//Setters y Getters
void Preguntas::SetNivelPregunta(int nivel){
	this -> nivel = nivel;
}

void Preguntas::SetPregunta(string pregunta){
	this -> pregunta = pregunta;
}

void Preguntas::SetRespuesta(string respuesta){
	this -> respuesta = respuesta;
}

int Preguntas::GetNivelPregunta(){
	return this -> nivel;
}

string Preguntas::GetPregunta(){
	return this -> pregunta;
}

string Preguntas::GetRespuesta(){
	return this -> respuesta;
}

//Otros Metodos
void Preguntas::MostrarPregunta(){
	cout << "Id Categoria: " << GetNCategoria() << endl;
	cout << "Nivel Pregunta: " << GetNivelPregunta() << endl;
	cout << "Pregunta: " << GetPregunta() << endl;
	cout << "Respuesta: " << GetRespuesta() << endl;
}
