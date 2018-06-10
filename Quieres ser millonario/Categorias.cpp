#include <iostream>
#include <string>

#include "Categorias.h"

using namespace std;

Categorias::Categorias(){}
Categorias::~Categorias(){}

Categorias::Categorias(int nCategoria){
	this -> SetNCategoria(nCategoria);
}
Categorias::Categorias(int nCategoria, string dCategoria){
	this -> SetNCategoria(nCategoria);
	this -> SetDCategoria(dCategoria);
}

//Setters y Getters
void Categorias::SetNCategoria(int nCategoria){
	this -> nCategoria = nCategoria;
}

void Categorias::SetDCategoria(string dCategoria){
	this -> dCategoria = dCategoria;
}

int Categorias::GetNCategoria(){
	return this -> nCategoria;
}

string Categorias::GetDCategoria(){
	return this -> dCategoria;
}

//Otros Metodos
void Categorias::MostrarCategoria(){
	cout << "#Categoria : " << this -> GetNCategoria() << endl;
	cout << "Descreipcion: " << this -> GetDCategoria() << endl;
}
