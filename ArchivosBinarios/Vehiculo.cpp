#include <iostream>
#include <string>
#include <cstring>

#include "Vehiculo.h"

//Constructores y Destructores
Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
Vehiculo::Vehiculo(int codigo, string marca, string modelo, int anio){
	this ->	SetCodigo(codigo);
	this -> SetMarca(marca);
	this -> SetModelo(modelo);
	this -> SetAnio(anio);
}

//Setters
void Vehiculo::SetCodigo(int codigo){
	this -> codigo = codigo;
}

void Vehiculo::SetMarca(string pMarca){
	const char *ptrMarca = pMarca.data();
    int longitudMarca = strlen(ptrMarca);
    // Verifique que nombre tiene 20 elementos maximo.
    longitudMarca = longitudMarca<20 ?
                     longitudMarca:19;
    strncpy(marca, ptrMarca, longitudMarca);
    marca[longitudMarca] = '\0';
}

void Vehiculo::SetModelo(string pModelo){
	const char *ptrModelo = pModelo.data();
    int longitudModelo = strlen(ptrModelo);
    // Verifique que nombre tiene 20 elementos maximo.
    longitudModelo = longitudModelo<20 ?
                     longitudModelo:19;
    strncpy(modelo, ptrModelo, longitudModelo);
    marca[longitudModelo] = '\0';
}

void Vehiculo::SetAnio(int anio){
	this -> anio = anio;
}

//Getters
int Vehiculo::GetCodigo(){
	return this -> codigo;
}

string Vehiculo::GetMarca(){
	return this -> marca;
}

string Vehiculo::GetModelo(){
	return this -> modelo;
}

int Vehiculo::GetAnio(){
	return this -> anio;
}

