#include <iostream>

#include "Base.h"

using namespace std;

//constructores y destructores
Base::Base(){};
Base::~Base(){};
Base::Base( char tipo, int familiar){
	this -> SetTipo(tipo);
	this -> SetFamiliar(familiar);
}
//setters
void Base::SetTipo(char tipo){
	this -> tipo = tipo;
}
void Base::SetFamiliar(int familiar){
	this -> familiar = familiar;
}
//getters
char Base::GetTipo(){
	return this -> tipo;
}
int Base::GetFamiliar(){
	return this -> familiar;
}

